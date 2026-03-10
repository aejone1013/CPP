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
    Span();
    Span(unsigned int N);
    Span(Span const & other);
    Span& operator=(Span const & other);
    ~Span();

    void addNumber(int number);
    
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        const std::size_t distanceToAdd = static_cast<std::size_t>(std::distance(begin, end));
        if (_numbers.size() + distanceToAdd > _maxSize) {
            throw FullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

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
