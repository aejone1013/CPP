/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:10:40 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:16:44 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Orthodox Canonical Form
    WrongCat();
    WrongCat(const WrongCat& value);
    WrongCat& operator=(const WrongCat& value);
    ~WrongCat();

    // virtual 키워드 없음 - 오버라이드 안 됨
    void makeSound() const;
};

#endif
