/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:07:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 17:07:34 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// 기본 생성자
Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();  // new로 Brain 생성
    std::cout << "Cat constructor called" << std::endl;
}

// 복사 생성자 (깊은 복사)
Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);  // 새로운 Brain을 복사 생성
    std::cout << "Cat copy constructor called" << std::endl;
}

// 대입 연산자 (깊은 복사)
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;  // 기존 Brain 삭제
        brain = new Brain(*other.brain);  // 새로운 Brain 복사 생성
    }
    return *this;
}

// 소멸자
Cat::~Cat() {
    delete brain;  // Brain 메모리 해제
    std::cout << "Cat destructor called" << std::endl;
}

// makeSound 오버라이드
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

// Brain 관련 함수들
Brain* Cat::getBrain() const {
    return brain;
}

void Cat::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
