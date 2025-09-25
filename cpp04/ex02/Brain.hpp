/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:49:35 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:06:38 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];  // 100개의 아이디어 배열

public:
    // Orthodox Canonical Form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    // 유틸리티 함수들
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
    void printIdeas() const;
};

#endif
