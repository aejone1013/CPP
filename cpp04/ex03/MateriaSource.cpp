/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:38:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 17:06:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// 기본 생성자
MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = 0;
    }
}

// 복사 생성자 (깊은 복사)
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

// 대입 연산자 (깊은 복사)
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

// 소멸자
MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    clearTemplates();
}

// 템플릿 정리 (내부 함수)
void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
            templates[i] = 0;
        }
    }
}

// learnMateria 구현 - materia를 복사해서 템플릿으로 저장
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
            delete materia;  // 원본은 삭제
            return;
        }
    }
    
    std::cout << "MateriaSource is full, cannot learn " << materia->getType() << std::endl;
    delete materia;  // 저장 실패시 삭제
}

// createMateria 구현 - 타입에 맞는 materia를 복사 생성
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

// 템플릿 출력 (디버깅용)
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
