/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:09:44 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:09:49 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== ScavTrap Inheritance Tests ===" << std::endl;
    
    // 생성자 체이닝 테스트
    std::cout << "\n--- Constructor Chaining Test ---" << std::endl;
    ScavTrap scav1("Guardian");
    
    // ScavTrap 능력 테스트
    std::cout << "\n--- ScavTrap Status ---" << std::endl;
    std::cout << scav1.getName() << " - HP: " << scav1.getHitPoints() 
              << ", Energy: " << scav1.getEnergyPoints() 
              << ", Attack: " << scav1.getAttackDamage() << std::endl;
    
    // 공격 테스트 (오버라이드된 함수)
    std::cout << "\n--- Attack Tests ---" << std::endl;
    scav1.attack("Intruder");
    scav1.attack("Enemy");
    
    // 피해와 수리 테스트 (상속된 함수)
    std::cout << "\n--- Damage and Repair Tests ---" << std::endl;
    scav1.takeDamage(30);
    scav1.beRepaired(20);
    
    // ScavTrap 고유 기능 테스트
    std::cout << "\n--- Special Ability Test ---" << std::endl;
    scav1.guardGate();
    
    // 복사 테스트
    std::cout << "\n--- Copy Tests ---" << std::endl;
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav1;
    
    // ClapTrap과 비교 테스트
    std::cout << "\n--- ClapTrap vs ScavTrap Comparison ---" << std::endl;
    ClapTrap clap("WeakBot");
    ScavTrap scav("StrongBot");
    
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", Energy=" << clap.getEnergyPoints() 
              << ", Attack=" << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", Energy=" << scav.getEnergyPoints() 
              << ", Attack=" << scav.getAttackDamage() << std::endl;
    
    clap.attack("Target");
    scav.attack("Target");
    
    // 소멸자 체이닝 테스트
    std::cout << "\n--- Destructor Chaining Test ---" << std::endl;
    
    return 0;
}