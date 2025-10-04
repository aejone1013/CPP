/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:44:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:44:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// 등급 검증 헬퍼 함수
void Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// 기본 생성자
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// 매개변수 생성자
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    validateGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " (grade " << _grade 
              << ") constructor called" << std::endl;
}

// 복사 생성자
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// 대입 연산자 (name은 const라 복사 안 함)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
        // _name은 const라 변경 불가
    }
    return *this;
}

// 소멸자
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// 등급 올리기 (숫자 감소: 3 -> 2)
void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade--;
    std::cout << _name << "'s grade incremented to " << _grade << std::endl;
}

// 등급 내리기 (숫자 증가: 3 -> 4)
void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade++;
    std::cout << _name << "'s grade decremented to " << _grade << std::endl;
}

// GradeTooHighException 구현
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum grade is 1)";
}

// GradeTooLowException 구현
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum grade is 150)";
}

// << 연산자 오버로딩
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
