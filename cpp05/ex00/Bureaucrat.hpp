/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:43:45 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:43:54 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;  // 상수 이름
    int _grade;               // 등급 (1~150)

    // 생성자 헬퍼 (등급 검증)
    void validateGrade(int grade);

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // 등급 증감 함수
    void incrementGrade();  // 등급 올리기 (숫자 감소)
    void decrementGrade();  // 등급 내리기 (숫자 증가)

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

// << 연산자 오버로딩
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
