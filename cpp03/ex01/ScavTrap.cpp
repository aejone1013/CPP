/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:08:43 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:09:11 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// 기본 생성자
ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;   // ScavTrap 기본값
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// 매개변수 생성자
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;   // ScavTrap 기본값
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

// 복사 생성자
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// 대입 연산자
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// 소멸자
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

// 오버라이드된 공격 함수 (다른 메시지)
void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " fiercely attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Gate keeper 모드
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
