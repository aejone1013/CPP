/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:18:08 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:14:08 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    
    // 생성자 테스트
    std::cout << "\n--- Constructor Tests ---" << std::endl;
    ClapTrap clap1("Robot1");
    ClapTrap clap2("Robot2");
    
    // 상태 확인
    std::cout << "\n--- Initial Status ---" << std::endl;
    std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
              << ", Energy: " << clap1.getEnergyPoints() 
              << ", Attack: " << clap1.getAttackDamage() << std::endl;
    
    // 공격 테스트
    std::cout << "\n--- Attack Tests ---" << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Target");
    
    // 피해 테스트
    std::cout << "\n--- Damage Tests ---" << std::endl;
    clap1.takeDamage(3);
    clap1.takeDamage(5);
    
    // 수리 테스트
    std::cout << "\n--- Repair Tests ---" << std::endl;
    clap1.beRepaired(4);
    clap1.beRepaired(2);
    
    // 에너지 소진 테스트
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        clap2.attack("DummyTarget");
    }
    clap2.attack("ShouldFail"); // 에너지 부족으로 실패해야 함
    
    // 죽음 테스트
    std::cout << "\n--- Death Test ---" << std::endl;
    clap2.takeDamage(100); // 체력 0으로 만들기
    clap2.attack("ShouldFail"); // 죽었으므로 공격 불가
    clap2.beRepaired(5); // 죽었으므로 수리 불가
    
    // 복사 테스트
    std::cout << "\n--- Copy Tests ---" << std::endl;
    ClapTrap clap3(clap1);
    ClapTrap clap4;
    clap4 = clap1;
    
    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
