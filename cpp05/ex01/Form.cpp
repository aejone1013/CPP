/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:46:35 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:47:33 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::validateGrade(int grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

Form::Form() 
    : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
        // const 멤버는 변경 불가
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low to sign this form!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() 
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute();
    return out;
}
