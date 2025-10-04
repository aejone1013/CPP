/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:34:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 17:06:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// 기본 생성자
Character::Character() : name("Unknown") {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

// 이름 생성자
Character::Character(const std::string& name) : name(name) {
    std::cout << "Character " << name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

// 복사 생성자 (깊은 복사)
Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = 0;
        }
    }
}

// 대입 연산자 (깊은 복사)
Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        clearInventory();  // 기존 materia들 삭제
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = 0;
            }
        }
    }
    return *this;
}

// 소멸자
Character::~Character() {
    std::cout << "Character " << name << " destructor called" << std::endl;
    clearInventory();
}

// 인벤토리 정리 (내부 함수)
void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = 0;
        }
    }
}

// getName 구현
std::string const & Character::getName() const {
    return name;
}

// equip 구현 - 첫 번째 빈 슬롯에 장착
void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "Cannot equip null materia" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << name << " equips " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

// unequip 구현 - materia를 제거하지만 삭제하지 않음
void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot: " << idx << std::endl;
        return;
    }
    
    if (!inventory[idx]) {
        std::cout << "Nothing to unequip at slot " << idx << std::endl;
        return;
    }
    
    std::cout << name << " unequips " << inventory[idx]->getType() 
              << " from slot " << idx << std::endl;
    inventory[idx] = 0;  // delete하지 않음!
}

// use 구현
void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot: " << idx << std::endl;
        return;
    }
    
    if (!inventory[idx]) {
        std::cout << "No materia at slot " << idx << std::endl;
        return;
    }
    
    inventory[idx]->use(target);
}

// 인벤토리 출력 (디버깅용)
void Character::printInventory() const {
    std::cout << name << "'s inventory:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "  [" << i << "]: ";
        if (inventory[i]) {
            std::cout << inventory[i]->getType();
        } else {
            std::cout << "empty";
        }
        std::cout << std::endl;
    }
}
