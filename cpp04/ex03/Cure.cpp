/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:32:56 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 16:33:01 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// 기본 생성자
Cure::Cure() : AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

// 복사 생성자
Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copy constructor called" << std::endl;
}

// 대입 연산자
Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

// 소멸자
Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

// clone 구현
AMateria* Cure::clone() const {
    return new Cure(*this);
}

// use 구현
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
