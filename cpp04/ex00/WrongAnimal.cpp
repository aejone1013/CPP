/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:10:19 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:16:33 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// 기본 생성자
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// 복사 생성자
WrongAnimal::WrongAnimal(const WrongAnimal& value) : type(value.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// 대입 연산자
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& value) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &value) {
        type = value.type;
    }
    return *this;
}

// 소멸자 (virtual 아님)
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// makeSound (virtual 아님 - 다형성 안 됨)
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes wrong sound" << std::endl;
}

// getType
std::string WrongAnimal::getType() const {
    return type;
}
