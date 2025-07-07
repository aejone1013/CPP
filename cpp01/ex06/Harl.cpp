/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:15:34 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 22:40:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*	Constructor	*/
Harl::Harl (){}

/*	Desctructor	*/
Harl::~Harl (){}

void	Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!"
		<< std::endl << std::endl;
}

void	Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, "
		"I wouldn't be asking for more!"
		<< std::endl << std::endl;
	return ;
}

void	Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. "
		"I've been coming for years whereas you started working here "
		"since last month."
		<< std::endl << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	for (size_t i = 0; i < level.length(); i++)
		level[i] = ::toupper(level[i]);
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int	index = 4;
	
	for (int i = 0; i < 5; i++)
	{
		if (levels[i] == level)
			index = i;
	}
	switch (index)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}
