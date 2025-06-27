/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:16:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/27 15:45:51 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "phonebook.class.hpp"

/* constructor	*/
PhoneBook::PhoneBook(void) : _index(-1), _abort(false) {
	return ;
}

/* destructor */
PhoneBook::~PhoneBook(void) {
	return ;
}

/* private */
std::string	PhoneBook::_getInput(std::string const prompt) {
	std::string	input;

	std::cout << prompt << ": " << std::endl << "> ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_abort = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trimBlank(input);
	return (input);
}

void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

void	PhoneBook::_displayContactTable(void) const {
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		_printContactInfoToTable(i);
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::_printContactInfoToTable(int const index) const {
	if (this->_contactList[index].isEmpty())
		return ;
	std::cout << "|" << std::setw(10) << index << "|";
	_printTableString(this->_contactList[index].getFirstname());
	_printTableString(this->_contactList[index].getLastname());
	_printTableString(this->_contactList[index].getNickname());
	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	return ;
}

void PhoneBook::_printTableString(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

bool	PhoneBook::_displayContactByIndex(std::string const input) const {

	int			index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_contactList[index].displayContactInfo())
				return (true);
			else {
				std::cout << "Error: No record at index [" << index << "]. Add a contact and try again." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "Error: \'" << input << "' is not a valid index (a digit 0~7). Please try again later." << std::endl;
	return (false);
}

/* public */
std::string	PhoneBook::trimBlank(std::string str) {
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

bool 	PhoneBook::addContact(void) {
	std::string	input;

	_incrementIndex();
	std::cout << std::endl << "------------ New Contact Menu -------------" << std::endl << std::endl;
	while (!_abort) {
		input = _getInput("First name");
		if (_abort || this->_contactList[_index].setFirstname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("Last name");
		if (_abort || this->_contactList[_index].setLastname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("Nickname");
		if (_abort || this->_contactList[_index].setNickname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("Phone number");
		if (_abort || this->_contactList[_index].setNumber(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("Darkest secret");
		if (_abort || this->_contactList[_index].setSecret(input))
			break ;
	}
	if (_abort) {
		_abort = false;
		return (false);
	}
	std::cout << "Contact saved." << std::endl;
	return (true);
}

void	PhoneBook::displayContact(int index) const {
	if (index >= 0 && index <= 7) {
		if (this->_contactList[index].displayContactInfo())
			return ;
	}
	std::cout << "Error: No record for the requested contact." << std::endl;
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << "-------------- Search Menu ----------------" << std::endl << std::endl;
	if (_index == -1) {
		std::cout << "No contacts in record. Add a contact first." << std::endl;
		return (true);
	}
	this->_displayContactTable();
	input = _getInput("Index of the contact to display");
	if (input.empty())
		return (false);
	this->_displayContactByIndex((std::string const)input);
	return (true);
}
