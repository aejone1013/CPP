/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:11:18 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/12 15:11:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    typedef AForm* (*FormCreator)(const std::string&);

    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    const FormCreator creators[3] = {
        makeShrubbery,
        makeRobotomy,
        makePardon
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern: unknown form \"" << formName << "\"" << std::endl;
    return NULL;
}
