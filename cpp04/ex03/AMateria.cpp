/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:29:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 16:29:48 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// 기본 생성자
AMateria::AMateria() : type("unknown") {
    std::cout << "AMateria default constructor called" << std::endl;
}

// 타입 생성자
AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria " << type << " constructor called" << std::endl;
}

// 복사 생성자
AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

// 대입 연산자 (타입 복사는 의미없다고 했으므로 무시)
AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    (void)other;  // 타입 복사하지 않음
    return *this;
}

// 소멸자
AMateria::~AMateria() {
    std::cout << "AMateria " << type << " destructor called" << std::endl;
}

// 타입 반환
std::string const & AMateria::getType() const {
    return type;
}

// 기본 use 구현 (자식 클래스에서 오버라이드)
void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "AMateria: * does nothing *" << std::endl;
}
