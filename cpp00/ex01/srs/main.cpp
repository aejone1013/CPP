/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:16:33 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/27 13:51:00 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

std::string	getInput(PhoneBook *book) {
	std::string	userInput;

	if (!std::getline(std::cin, userInput) || std::cin.eof()) {
		std::cout << "EXIT" << std::endl;
		return ("EXIT");
	}
	userInput = book->trimBlank(userInput);
	for (std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
			*it = std::toupper(*it);
	return (userInput);
}

int	main(void) {
	PhoneBook	book;
	std::string	userInput;

	while (true) {
		std::cout 	<< std::endl
					<< "Please enter one of the following:" << std::endl
					<< std::endl
					<< "\tADD\t: add a contact" << std::endl
					<< "\tSEARCH\t: search contact list" << std::endl
					<< "\tEXIT\t: exit" << std::endl << "> ";
		userInput = getInput(&book);
		if (userInput == "EXIT")
			break ;
		else if (userInput == "ADD") {
			if (!book.addContact())
				break ;
		}			
		else if (userInput == "SEARCH") {
			if (!book.searchContact())
				break ;
		}
		else
			std::cout	<< std::endl << "Wrong input!!!!" << std::endl;
	}
	return (0);
}