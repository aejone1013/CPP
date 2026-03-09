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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== AForm and Concrete Forms Tests ===" << std::endl;
    
    std::cout << "\n--- Shrubbery Creation Form Test ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 140);
        ShrubberyCreationForm shrub("home");
        
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Robotomy Request Form Test ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Presidential Pardon Form Test ---" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Unsigned Form Execution Test ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm unsigned_form("garden");
        
        boss.executeForm(unsigned_form);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Insufficient Grade to Execute Test ---" << std::endl;
    try {
        Bureaucrat lowGrade("LowGrade", 100);
        Bureaucrat highGrade("HighGrade", 1);
        RobotomyRequestForm form("Target");
        
        highGrade.signForm(form);
        lowGrade.executeForm(form);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- All Forms Test ---" << std::endl;
    try {
        Bureaucrat vip("VIP", 1);
        
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Employee");
        PresidentialPardonForm pardon("Criminal");
        
        vip.signForm(shrub);
        vip.signForm(robot);
        vip.signForm(pardon);
        
        std::cout << "\nExecuting all forms:" << std::endl;
        vip.executeForm(shrub);
        vip.executeForm(robot);
        vip.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
