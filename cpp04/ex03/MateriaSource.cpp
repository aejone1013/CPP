/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:38:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/08 16:01:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone();
        } else {
            templates[i] = 0;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        clearTemplates();
        for (int i = 0; i < 4; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            } else {
                templates[i] = 0;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    clearTemplates();
}

void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
            templates[i] = 0;
        }
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cout << "Cannot learn null materia" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = materia->clone();
            std::cout << "MateriaSource learns " << materia->getType() 
                      << " at slot " << i << std::endl;
            delete materia;
            return;
        }
    }
    
    std::cout << "MateriaSource is full, cannot learn " << materia->getType() << std::endl;
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            std::cout << "MateriaSource creates " << type << std::endl;
            return templates[i]->clone();
        }
    }
    
    std::cout << "MateriaSource doesn't know " << type << std::endl;
    return 0;
}

void MateriaSource::printTemplates() const {
    std::cout << "MateriaSource templates:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "  [" << i << "]: ";
        if (templates[i]) {
            std::cout << templates[i]->getType();
        } else {
            std::cout << "empty";
        }
        std::cout << std::endl;
    }
}
