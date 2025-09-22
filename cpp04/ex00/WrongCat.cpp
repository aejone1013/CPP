/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:11:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:16:50 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// 기본 생성자
WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

// 복사 생성자
WrongCat::WrongCat(const WrongCat& value) : WrongAnimal(value) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

// 대입 연산자
WrongCat& WrongCat::operator=(const WrongCat& value) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &value) {
        WrongAnimal::operator=(value);
    }
    return *this;
}

// 소멸자
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

// makeSound (virtual 아님 - 다형성 안 됨)
void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow! Meow!" << std::endl;
}
