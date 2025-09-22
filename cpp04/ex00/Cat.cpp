/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:09:31 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:16:01 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// 기본 생성자
Cat::Cat() : Animal() {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// 복사 생성자
Cat::Cat(const Cat& value) : Animal(value) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// 대입 연산자
Cat& Cat::operator=(const Cat& value) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &value) {
        Animal::operator=(value);
    }
    return *this;
}

// 소멸자
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// makeSound 오버라이드
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
