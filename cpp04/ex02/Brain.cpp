/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:49:31 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:16:57 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

// 기본 생성자
Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::ostringstream oss;
        oss << "Default idea " << i;
        ideas[i] = oss.str();
    }
}

// 복사 생성자 (깊은 복사)
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

// 대입 연산자 (깊은 복사)
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// 소멸자
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// 아이디어 설정
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

// 아이디어 가져오기
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}

// 아이디어 출력 (처음 5개만)
void Brain::printIdeas() const {
    std::cout << "Brain ideas (first 5):" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  [" << i << "]: " << ideas[i] << std::endl;
    }
}
