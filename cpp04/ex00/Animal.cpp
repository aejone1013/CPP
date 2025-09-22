/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:07:45 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:08:04 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// 기본 생성자
Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

// 복사 생성자
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// 대입 연산자
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// 소멸자 (virtual)
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// makeSound (virtual - 자식 클래스에서 오버라이드됨)
void Animal::makeSound() const {
    std::cout << "Animal makes some generic sound" << std::endl;
}

// getType
std::string Animal::getType() const {
    return type;
}
