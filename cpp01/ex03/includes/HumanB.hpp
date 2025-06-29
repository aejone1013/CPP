/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:29:20 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:31:23 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon	*_weapon;
		std::string	_name;

	public:
		HumanB(std::string newName);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &newWeapon);
};

#endif