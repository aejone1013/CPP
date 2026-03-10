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
    std::map<std::string, double> _database;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(double value) const;
    double stringToDouble(const std::string& str) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & other);
    BitcoinExchange& operator=(BitcoinExchange const & other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    double getRate(const std::string& date) const;
};

#endif
