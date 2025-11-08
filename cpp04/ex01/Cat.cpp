/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:07:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/08 14:43:40 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();
    ideaIndex = 0;
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    ideaIndex = other.ideaIndex;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        ideaIndex = other.ideaIndex;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}

void Cat::createIdea(const std::string& idea) {
    if (ideaIndex < 0 || ideaIndex >= 100)
        ideaIndex = 0;
    brain->setIdea(ideaIndex, idea);
    ideaIndex = (ideaIndex + 1) % 100;
}

std::string Cat::getIdea(int index) const {
    return getBrainIdea(index);
}
