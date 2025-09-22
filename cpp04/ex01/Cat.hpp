/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:06:41 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 17:07:19 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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

    // 오버라이드된 함수
    void makeSound() const override;
    
    // Brain 관련 함수들
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif
