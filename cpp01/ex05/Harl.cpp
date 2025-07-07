/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:16:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 22:26:46 by jaoh             ###   ########.fr       */
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
	void (Harl::*arr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*arr[i])();
			return ;
		}
	}
	std::cout << "[ IGNORE ]" << std::endl
		<< "Saying nonsense... There is no level \"" << level << "\"."
		<< std::endl << std::endl; 
}
