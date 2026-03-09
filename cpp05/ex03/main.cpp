/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:00:37 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/12 15:11:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern intern;

    std::cout << "--- Shrubbery Creation ---" << std::endl;
    AForm* f1 = intern.makeForm("shrubbery creation", "garden");
    if (f1) {
        Bureaucrat b("Bob", 140);
        b.signForm(*f1);
        b.executeForm(*f1);
        delete f1;
    }

    std::cout << "\n--- Robotomy Request ---" << std::endl;
    AForm* f2 = intern.makeForm("robotomy request", "Bender");
    if (f2) {
        Bureaucrat b("Alice", 40);
        b.signForm(*f2);
        b.executeForm(*f2);
        delete f2;
    }

    std::cout << "\n--- Presidential Pardon ---" << std::endl;
    AForm* f3 = intern.makeForm("presidential pardon", "Arthur");
    if (f3) {
        Bureaucrat b("President", 1);
        b.signForm(*f3);
        b.executeForm(*f3);
        delete f3;
    }

    std::cout << "\n--- Unknown Form ---" << std::endl;
    AForm* f4 = intern.makeForm("vacation request", "Me");
    if (f4)
        delete f4;

    return 0;
}
