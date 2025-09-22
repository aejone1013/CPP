/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:06:04 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 17:06:11 by jaoh             ###   ########.fr       */
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

    // 오버라이드된 함수
    void makeSound() const override;
    
    // Brain 관련 함수들
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif
