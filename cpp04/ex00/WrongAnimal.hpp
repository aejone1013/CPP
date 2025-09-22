/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:10:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/22 16:16:19 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    WrongAnimal();
    WrongAnimal(const WrongAnimal& value);
    WrongAnimal& operator=(const WrongAnimal& value);
    ~WrongAnimal();  // virtual 키워드 없음 (의도적)

    // virtual 키워드 없음 (의도적) - 다형성 안 됨
    void makeSound() const;
    std::string getType() const;
};

#endif
