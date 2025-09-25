/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:29:28 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:38:16 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_A_HPP
# define WEAPON_A_HPP

# include <string>
#include <iostream>

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon( std::string type );
		~Weapon();
		std::string	getType() const;
		void	setType(std::string newType);
};

#endif