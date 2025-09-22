/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:44:46 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 17:05:26 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();  // virtual 소멸자 중요!

    // 다형성을 위한 virtual 함수들
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
