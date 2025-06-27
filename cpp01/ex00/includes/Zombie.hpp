/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:51:42 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/27 14:51:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class	Zombie
{
	private:
		std::string	_name;
		std::string	_getName( void ) const;

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void		announce( void );
};

#endif