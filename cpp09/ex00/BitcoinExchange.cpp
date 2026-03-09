/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:55:47 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 16:05:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && std::isspace(str[start]))
        start++;
    
    while (end > start && std::isspace(str[end - 1]))
        end--;
    
    return str.substr(start, end - start);
}

double BitcoinExchange::stringToDouble(const std::string& str) const {
    std::istringstream iss(str);
    double value;
    iss >> value;
    
    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Invalid number format");
    }
    
    return value;
}

// 날짜 형식과 합리적 범위를 검증(윤년/월별 일수 간략 검증)
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year  = (date[0]-'0')*1000 + (date[1]-'0')*100
              + (date[2]-'0')*10  + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day   = (date[8]-'0')*10 + (date[9]-'0');
    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2: {
            bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
            daysInMonth = isLeap ? 29 : 28;
            break;
        }
        default:
            return false;
    }
    if (day < 1 || day > daysInMonth)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(double value) const {
    return value <= 1000;
}

// CSV 파일(예: data.csv)을 읽어 날짜-가격 맵을 구성
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    
    std::string line;
    std::getline(file, line); // 첫 줄 헤더 스킵
    
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        try {
            double value = stringToDouble(valueStr);
            _database[date] = value; // 동일 날짜가 여러 번 나오면 마지막 값으로 덮어씀
        }
        catch (...) {
            // 숫자 파싱 실패는 무시하고 다음 라인 처리
            continue;
        }
    }
    
    file.close();
}

// 정확한 날짜가 없으면 바로 이전 날짜의 환율을 사용
double BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
        return it->second;

    if (it == _database.begin())
        throw std::runtime_error("No data available for this date");

    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // 첫 줄 헤더 스킵
    
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        double value;
        try {
            value = stringToDouble(valueStr);
        }
        catch (...) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (!isValidValue(value)) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        try {
            double rate = getRate(date);
            double result = value * rate;
            // 형식: "YYYY-MM-DD => value = 결과"
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    
    file.close();
}
