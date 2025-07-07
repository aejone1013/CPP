/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:16:07 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 21:52:13 by jaoh             ###   ########.fr       */
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