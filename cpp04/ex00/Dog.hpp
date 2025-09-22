/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:08:14 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:30:34 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& value);
    Dog& operator=(const Dog& value);
    ~Dog();

    // 오버라이드된 함수
    void makeSound() const;
};

#endif
