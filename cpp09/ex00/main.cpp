/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:56:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 16:05:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange btc; // 날짜-가격 DB를 내부 map에 보관하는 클래스
        btc.loadDatabase("data.csv"); // 제공된 CSV에서 기준 환율 정보를 적재
        btc.processInputFile(argv[1]); // 입력 파일을 한 줄씩 읽어 출력 형식으로 계산
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
