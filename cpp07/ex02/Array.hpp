/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:51:50 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:51:56 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    // 기본 생성자 - 빈 배열 생성
    Array() : _elements(NULL), _size(0) {}
    
    // unsigned int 매개변수 생성자 - n개 요소의 배열 생성
    Array(unsigned int n) : _elements(NULL), _size(n) {
        if (n > 0) {
            _elements = new T[n]();  // () 로 기본값 초기화
        }
    }
    
    // 복사 생성자 - 깊은 복사
    Array(Array const & other) : _elements(NULL), _size(0) {
        *this = other;
    }
    
    // 대입 연산자 - 깊은 복사
    Array& operator=(Array const & other) {
        if (this != &other) {
            // 기존 메모리 해제
            if (_elements != NULL) {
                delete[] _elements;
            }
            
            // 새로운 배열 할당
            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }
    
    // 소멸자
    ~Array() {
        if (_elements != NULL) {
            delete[] _elements;
        }
    }
    
    // [] 연산자 - 인덱스 접근
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }
    
    // const [] 연산자
    T const & operator[](unsigned int index) const {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }
    
    // size() 함수 - 배열 크기 반환
    unsigned int size() const {
        return _size;
    }
    
    // 예외 클래스
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index out of bounds";
        }
    };
};

#endif
