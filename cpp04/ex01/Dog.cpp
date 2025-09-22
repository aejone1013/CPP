/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:06:15 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 17:06:36 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// 기본 생성자
Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();  // new로 Brain 생성
    std::cout << "Dog constructor called" << std::endl;
}

// 복사 생성자 (깊은 복사)
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);  // 새로운 Brain을 복사 생성
    std::cout << "Dog copy constructor called" << std::endl;
}

// 대입 연산자 (깊은 복사)
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;  // 기존 Brain 삭제
        brain = new Brain(*other.brain);  // 새로운 Brain 복사 생성
    }
    return *this;
}

// 소멸자
Dog::~Dog() {
    delete brain;  // Brain 메모리 해제
    std::cout << "Dog destructor called" << std::endl;
}

// makeSound 오버라이드
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// Brain 관련 함수들
Brain* Dog::getBrain() const {
    return brain;
}

void Dog::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
