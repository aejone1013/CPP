/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:46:29 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:46:57 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;         // 폼 이름 (상수)
    bool _signed;                     // 서명 여부
    const int _gradeToSign;          // 서명 필요 등급 (상수)
    const int _gradeToExecute;       // 실행 필요 등급 (상수)

    void validateGrade(int grade);

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // 서명 함수
    void beSigned(const Bureaucrat& bureaucrat);

    // 예외 클래스들
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
