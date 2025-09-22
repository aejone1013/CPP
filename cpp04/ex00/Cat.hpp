/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:09:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:15:10 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& value);
    Cat& operator=(const Cat& value);
    ~Cat();

    // 오버라이드된 함수
    void makeSound() const;
};

#endif
