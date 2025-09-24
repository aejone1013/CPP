/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:28:31 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:33:36 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon	&_weapon;
		
	public:
		HumanA(std::string newName, Weapon &newWeapon);
		~HumanA();
		void	attack();
};

#endif