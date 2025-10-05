/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:11:24 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:11:32 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int N);
    Span(Span const & other);
    Span& operator=(Span const & other);
    ~Span();

    // 숫자 추가
    void addNumber(int number);
    
    // 범위 추가 (iterator 사용)
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        while (begin != end) {
            addNumber(*begin);
            ++begin;
        }
    }

    // span 계산
    int shortestSpan() const;
    int longestSpan() const;

    // 예외 클래스들
    class FullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
