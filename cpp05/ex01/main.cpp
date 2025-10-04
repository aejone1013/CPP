/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:46:40 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:47:46 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Form and Signing Tests ===" << std::endl;
    
    // 정상적인 Form 생성
    std::cout << "\n--- Normal Form Creation ---" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
        
        Form easyForm("Easy Form", 100, 75);
        std::cout << easyForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 잘못된 등급으로 Form 생성
    std::cout << "\n--- Invalid Form Creation ---" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm("Invalid", 50, 200);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 서명 테스트
    std::cout << "\n--- Signing Tests ---" << std::endl;
    try {
        Form form("Important Document", 50, 25);
        Bureaucrat highRank("Boss", 30);
        Bureaucrat lowRank("Intern", 100);
        
        std::cout << "\nBefore signing:" << std::endl;
        std::cout << form << std::endl;
        
        // 등급이 충분한 관료가 서명
        std::cout << "\nHigh rank bureaucrat trying to sign:" << std::endl;
        highRank.signForm(form);
        std::cout << form << std::endl;
        
        // 이미 서명된 폼에 다시 서명 시도
        std::cout << "\nTrying to sign again:" << std::endl;
        highRank.signForm(form);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 등급 부족 테스트
    std::cout << "\n--- Insufficient Grade Test ---" << std::endl;
    try {
        Form secretForm("Top Secret", 10, 5);
        Bureaucrat lowRank("Clerk", 50);
        
        std::cout << secretForm << std::endl;
        std::cout << lowRank << std::endl;
        
        // 등급이 부족한 관료가 서명 시도
        lowRank.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 복합 테스트
    std::cout << "\n--- Multiple Bureaucrats and Forms ---" << std::endl;
    try {
        Form form1("Form A", 75, 50);
        Form form2("Form B", 100, 75);
        Form form3("Form C", 25, 10);
        
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 80);
        Bureaucrat charlie("Charlie", 120);
        
        alice.signForm(form1);
        alice.signForm(form2);
        alice.signForm(form3);
        
        std::cout << std::endl;
        
        bob.signForm(form1);
        bob.signForm(form2);
        bob.signForm(form3);
        
        std::cout << std::endl;
        
        charlie.signForm(form1);
        charlie.signForm(form2);
        charlie.signForm(form3);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 등급 경계 테스트
    std::cout << "\n--- Grade Boundary Test ---" << std::endl;
    try {
        Form boundaryForm("Boundary Form", 50, 25);
        Bureaucrat exactly50("Exactly50", 50);
        Bureaucrat just51("Just51", 51);
        
        std::cout << boundaryForm << std::endl;
        
        exactly50.signForm(boundaryForm);  // 정확히 50 - 성공
        
        Form anotherForm("Another", 50, 25);
        just51.signForm(anotherForm);  // 51 - 실패
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
