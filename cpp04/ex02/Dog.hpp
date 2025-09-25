/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:49:52 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:07:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;  // Brain 포인터

public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    // 추상 함수 구현
    void makeSound() const;
    
    // Brain 관련 함수들
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif
