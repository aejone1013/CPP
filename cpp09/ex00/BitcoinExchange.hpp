/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:55:58 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 16:05:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;  // date -> price
    // 입력 라인 전처리에 사용되는 헬퍼들
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(double value) const;
    double stringToDouble(const std::string& str) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & other);
    BitcoinExchange& operator=(BitcoinExchange const & other);
    ~BitcoinExchange();

    // CSV 데이터베이스 파일을 읽어 내부 map(date->price)에 적재
    void loadDatabase(const std::string& filename);
    // 과제 입력 파일을 한 줄씩 읽어 결과를 출력(형식/범위 검증 포함)
    void processInputFile(const std::string& filename);
    // 주어진 날짜의 환율(정확히 없으면 가장 가까운 이전 날짜)을 조회
    double getRate(const std::string& date) const;
};

#endif
