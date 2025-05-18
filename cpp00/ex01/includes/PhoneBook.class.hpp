/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:15:15 by jaoh              #+#    #+#             */
/*   Updated: 2025/05/18 16:15:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		bool	_abort;
		Contact	_contactList[8];

		std::string	_getInput(std::string const prompt);
		void		_incrementIndex(void);
		bool		_displayContactByIndex(std::string const input) const;
		void		_displayContactTable(void) const;
		void		_printContactInfoToTable(int const index) const;
		void		_printTableString(std::string str) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimBlank(std::string str);
		bool		addContact(void);
		void		displayContact(int index) const;
		bool		searchContact(void);
};

#endif