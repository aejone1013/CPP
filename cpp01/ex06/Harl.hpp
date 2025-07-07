/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:13:59 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 22:40:32 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif