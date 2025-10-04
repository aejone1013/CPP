/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:32:06 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 16:32:10 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// 기본 생성자
Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructor called" << std::endl;
}

// 복사 생성자
Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice copy constructor called" << std::endl;
}

// 대입 연산자
Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

// 소멸자
Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

// clone 구현
AMateria* Ice::clone() const {
    return new Ice(*this);
}

// use 구현
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
