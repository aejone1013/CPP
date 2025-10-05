/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:11:24 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:18:07 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

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
        // 입력 구간 크기 계산 후 한 번에 용량 검증
        const std::size_t distanceToAdd = static_cast<std::size_t>(std::distance(begin, end));
        if (_numbers.size() + distanceToAdd > _maxSize) {
            throw FullException();
        }
        // 일괄 삽입으로 성능 향상
        _numbers.insert(_numbers.end(), begin, end);
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
