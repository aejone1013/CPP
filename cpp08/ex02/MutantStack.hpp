/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:12:34 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:13:02 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    
    MutantStack(MutantStack const & other) : std::stack<T>(other) {}
    
    MutantStack& operator=(MutantStack const & other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    
    ~MutantStack() {}

    // iterator 타입 정의
    // std::stack은 내부적으로 std::deque를 사용 (기본 컨테이너)
    // c는 protected 멤버로 실제 컨테이너를 가리킴
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // iterator 반환 함수들
    iterator begin() {
        return this->c.begin();
    }
    
    iterator end() {
        return this->c.end();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    
    reverse_iterator rend() {
        return this->c.rend();
    }
    
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};

#endif
