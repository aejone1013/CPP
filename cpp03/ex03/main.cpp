/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:38:26 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:43 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== DiamondTrap Multiple Inheritance Tests ===" << std::endl;
    
    // DiamondTrap 생성자 체이닝 테스트
    std::cout << "\n--- DiamondTrap Constructor Chaining Test ---" << std::endl;
    DiamondTrap diamond("Hybrid");
    
    // DiamondTrap 상태 확인
    std::cout << "\n--- DiamondTrap Status ---" << std::endl;
    std::cout << diamond.getName() << " - HP: " << diamond.getHitPoints() 
              << ", Energy: " << diamond.getEnergyPoints() 
              << ", Attack: " << diamond.getAttackDamage() << std::endl;
    
    // whoAmI 테스트
    std::cout << "\n--- whoAmI Test ---" << std::endl;
    diamond.whoAmI();
    
    // 공격 테스트 (ScavTrap의 attack 사용)
    std::cout << "\n--- Attack Test (ScavTrap's attack) ---" << std::endl;
    diamond.attack("Target");
    
    // 각 부모 클래스의 특수 능력 테스트
    std::cout << "\n--- Special Abilities from Parents ---" << std::endl;
    diamond.guardGate();      // ScavTrap에서
    diamond.highFivesGuys();  // FragTrap에서
    
    // 일반적인 ClapTrap 기능들
    std::cout << "\n--- Basic ClapTrap Functions ---" << std::endl;
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    // 복사 테스트
    std::cout << "\n--- Copy Tests ---" << std::endl;
    DiamondTrap diamond2(diamond);
    DiamondTrap diamond3;
    diamond3 = diamond;
    
    diamond2.whoAmI();
    diamond3.whoAmI();
    
    // 모든 타입들의 비교
    std::cout << "\n--- All Robot Types Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("WarBot");
    DiamondTrap dia("HybridBot");
    
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", Energy=" << clap.getEnergyPoints() 
              << ", Attack=" << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", Energy=" << scav.getEnergyPoints() 
              << ", Attack=" << scav.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats: HP=" << frag.getHitPoints() 
              << ", Energy=" << frag.getEnergyPoints() 
              << ", Attack=" << frag.getAttackDamage() << std::endl;
    
    std::cout << "DiamondTrap stats: HP=" << dia.getHitPoints() 
              << ", Energy=" << dia.getEnergyPoints() 
              << ", Attack=" << dia.getAttackDamage() << std::endl;
    
    // 각각의 공격 스타일
    std::cout << "\n--- Attack Style Comparison ---" << std::endl;
    clap.attack("Enemy");
    scav.attack("Enemy");
    frag.attack("Enemy");
    dia.attack("Enemy");     // ScavTrap의 attack 사용
    
    // 모든 특수 능력들
    std::cout << "\n--- All Special Abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    dia.guardGate();
    dia.highFivesGuys();
    dia.whoAmI();
    
    // 소멸자 체이닝 테스트
    std::cout << "\n--- Destructor Chaining Test ---" << std::endl;
    
    return 0;
}
