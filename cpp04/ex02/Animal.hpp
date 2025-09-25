/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:49:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:06:16 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

// 추상 클래스 - 인스턴스화 불가
class Animal {
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();  // virtual 소멸자 중요!

    // 순수 가상 함수 - 이제 Animal을 인스턴스화할 수 없음
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif

