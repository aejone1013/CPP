/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:16:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 19:16:05 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
Harl::Harl (void)
{
	return ;
}

/*	Desctructor	*/
Harl::~Harl (void)
{
	return ;
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/
void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!"
		<< std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, "
		"I wouldn't be asking for more!"
		<< std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. "
		"I've been coming for years whereas you started working here "
		"since last month."
		<< std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Harl::complain( std::string level )
{
	typedef void ( Harl::*fptr )( void );
	
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	fptr		complaints[4] = { &Harl::_debug, &Harl::_info,
								&Harl::_warning, &Harl::_error };
	
	for ( int i = 0; i < 4; i++ )
	{
		if ( levels[i] == level )
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "Son of a member function pointer! There is no level \"" << level << "\"." << std::endl; 
	return ;
}
