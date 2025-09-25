/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:49:44 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:08:28 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;  // Brain 포인터

public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    // 추상 함수 구현
    void makeSound() const;
    
    // Brain 관련 함수들
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif
