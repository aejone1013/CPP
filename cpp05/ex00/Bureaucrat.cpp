/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:44:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/12 15:11:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Grade validation helper
void Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    validateGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " (grade " << _grade 
              << ") constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Copy assignment operator (name remains const)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// Destructor
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

// Promote by decreasing the numeric grade
void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade--;
    std::cout << _name << "'s grade incremented to " << _grade << std::endl;
}

// Demote by increasing the numeric grade
void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade++;
    std::cout << _name << "'s grade decremented to " << _grade << std::endl;
}

// GradeTooHighException implementation
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum grade is 1)";
}

// GradeTooLowException implementation
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum grade is 150)";
}

// Overload of the stream insertion operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
