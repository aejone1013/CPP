/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:51:42 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 15:13:09 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;

private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif