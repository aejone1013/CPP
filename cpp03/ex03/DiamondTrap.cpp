/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:41 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// 기본 생성자
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
    // DiamondTrap 명세에 따른 속성 설정
    _hitPoints = FragTrap::_hitPoints;        // FragTrap에서 체력 (100)
    _energyPoints = ScavTrap::_energyPoints;  // ScavTrap에서 에너지 (50)
    _attackDamage = FragTrap::_attackDamage;  // FragTrap에서 공격력 (30)
    
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// 매개변수 생성자
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    // DiamondTrap 명세에 따른 속성 설정
    _hitPoints = FragTrap::_hitPoints;        // FragTrap에서 체력 (100)
    _energyPoints = ScavTrap::_energyPoints;  // ScavTrap에서 에너지 (50)  
    _attackDamage = FragTrap::_attackDamage;  // FragTrap에서 공격력 (30)
    
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

// 복사 생성자
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// 대입 연산자
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

// 소멸자
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// whoAmI 함수 - DiamondTrap 이름과 ClapTrap 이름 출력
void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
