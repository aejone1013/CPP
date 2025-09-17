/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:38:26 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/17 23:38:36 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== FragTrap Inheritance Tests ===" << std::endl;
    
    // 생성자 체이닝 테스트
    std::cout << "\n--- Constructor Chaining Test ---" << std::endl;
    FragTrap frag1("Destroyer");
    
    // FragTrap 능력 테스트
    std::cout << "\n--- FragTrap Status ---" << std::endl;
    std::cout << frag1.getName() << " - HP: " << frag1.getHitPoints() 
              << ", Energy: " << frag1.getEnergyPoints() 
              << ", Attack: " << frag1.getAttackDamage() << std::endl;
    
    // 공격 테스트 (ClapTrap에서 상속된 함수 - 오버라이드 안함)
    std::cout << "\n--- Attack Tests ---" << std::endl;
    frag1.attack("Enemy");
    frag1.attack("Target");
    
    // 피해와 수리 테스트 (상속된 함수)
    std::cout << "\n--- Damage and Repair Tests ---" << std::endl;
    frag1.takeDamage(40);
    frag1.beRepaired(25);
    
    // FragTrap 고유 기능 테스트
    std::cout << "\n--- Special Ability Test ---" << std::endl;
    frag1.highFivesGuys();
    
    // 복사 테스트
    std::cout << "\n--- Copy Tests ---" << std::endl;
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;
    
    // 모든 타입 비교 테스트
    std::cout << "\n--- All Robot Types Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("WarBot");
    
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", Energy=" << clap.getEnergyPoints() 
              << ", Attack=" << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", Energy=" << scav.getEnergyPoints() 
              << ", Attack=" << scav.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats: HP=" << frag.getHitPoints() 
              << ", Energy=" << frag.getEnergyPoints() 
              << ", Attack=" << frag.getAttackDamage() << std::endl;
    
    // 각각의 공격 스타일
    std::cout << "\n--- Attack Style Comparison ---" << std::endl;
    clap.attack("Target");
    scav.attack("Target");   // 오버라이드된 메시지
    frag.attack("Target");   // ClapTrap 메시지 (오버라이드 안함)
    
    // 특수 능력들
    std::cout << "\n--- Special Abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    
    // 소멸자 체이닝 테스트
    std::cout << "\n--- Destructor Chaining Test ---" << std::endl;
    
    return 0;
}
