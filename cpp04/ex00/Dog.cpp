/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:08:59 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:15:20 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// 기본 생성자
Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

// 복사 생성자
Dog::Dog(const Dog& value) : Animal(value) {
    std::cout << "Dog copy constructor called" << std::endl;
}

// 대입 연산자
Dog& Dog::operator=(const Dog& value) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &value) {
        Animal::operator=(value);
    }
    return *this;
}

// 소멸자
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

// makeSound 오버라이드
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
