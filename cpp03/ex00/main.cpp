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
    
    // Constructor tests
    std::cout << "\n--- Constructor Tests ---" << std::endl;
    ClapTrap clap1("Robot1");
    ClapTrap clap2("Robot2");
    
    // Initial status
    std::cout << "\n--- Initial Status ---" << std::endl;
    std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
              << ", Energy: " << clap1.getEnergyPoints() 
              << ", Attack: " << clap1.getAttackDamage() << std::endl;
    
    // Attack tests
    std::cout << "\n--- Attack Tests ---" << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Target");
    
    // Damage tests
    std::cout << "\n--- Damage Tests ---" << std::endl;
    clap1.takeDamage(3);
    clap1.takeDamage(5);
    
    // Repair tests
    std::cout << "\n--- Repair Tests ---" << std::endl;
    clap1.beRepaired(4);
    clap1.beRepaired(2);
    
    // Energy depletion test
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        clap2.attack("DummyTarget");
    }
    clap2.attack("ShouldFail"); // Should fail due to lack of energy
    
    // Death test
    std::cout << "\n--- Death Test ---" << std::endl;
    clap2.takeDamage(100); // Reduce hit points to 0
    clap2.attack("ShouldFail"); // Cannot attack because it's dead
    clap2.beRepaired(5); // Cannot repair because it's dead
    
    // Copy tests
    std::cout << "\n--- Copy Tests ---" << std::endl;
    ClapTrap clap3(clap1);
    ClapTrap clap4;
    clap4 = clap1;
    
    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
