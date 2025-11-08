/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:34:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/08 14:43:40 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Unknown") {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

Character::Character(const std::string& name) : name(name) {
    std::cout << "Character " << name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

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

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        clearInventory();
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

Character::~Character() {
    std::cout << "Character " << name << " destructor called" << std::endl;
    clearInventory();
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = 0;
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

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
    inventory[idx] = 0;
}

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
