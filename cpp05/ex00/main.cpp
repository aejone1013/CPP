/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:44:44 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:44:51 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Bureaucrat Exception Tests ===" << std::endl;
    
    // 정상적인 Bureaucrat 생성
    std::cout << "\n--- Normal Bureaucrat Creation ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 너무 높은 등급으로 생성 시도
    std::cout << "\n--- Too High Grade Test ---" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 너무 낮은 등급으로 생성 시도
    std::cout << "\n--- Too Low Grade Test ---" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 등급 증가 테스트
    std::cout << "\n--- Increment Grade Test ---" << std::endl;
    try {
        Bureaucrat worker("Worker", 3);
        std::cout << worker << std::endl;
        
        worker.incrementGrade();  // 3 -> 2
        std::cout << worker << std::endl;
        
        worker.incrementGrade();  // 2 -> 1
        std::cout << worker << std::endl;
        
        worker.incrementGrade();  // 1 -> 0 (예외 발생!)
        std::cout << worker << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 등급 감소 테스트
    std::cout << "\n--- Decrement Grade Test ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 148);
        std::cout << intern << std::endl;
        
        intern.decrementGrade();  // 148 -> 149
        std::cout << intern << std::endl;
        
        intern.decrementGrade();  // 149 -> 150
        std::cout << intern << std::endl;
        
        intern.decrementGrade();  // 150 -> 151 (예외 발생!)
        std::cout << intern << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 복합 테스트
    std::cout << "\n--- Complex Test ---" << std::endl;
    try {
        Bureaucrat manager("Manager", 50);
        std::cout << "Initial: " << manager << std::endl;
        
        for (int i = 0; i < 10; i++) {
            manager.incrementGrade();
        }
        std::cout << "After 10 increments: " << manager << std::endl;
        
        for (int i = 0; i < 15; i++) {
            manager.decrementGrade();
        }
        std::cout << "After 15 decrements: " << manager << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 복사 테스트
    std::cout << "\n--- Copy Test ---" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Before assignment: " << assigned << std::endl;
        
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 다중 예외 처리 테스트
    std::cout << "\n--- Multiple Exception Handling ---" << std::endl;
    try {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);
        
        std::cout << high << std::endl;
        std::cout << low << std::endl;
        
        high.incrementGrade();  // 예외 발생
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Specific exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Specific exception caught: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Generic exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
