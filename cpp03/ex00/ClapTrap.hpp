/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:16:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:13:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string _name;        // 이름 (생성자 매개변수로 전달)
    unsigned int _hitPoints;  // 체력 (10)
    unsigned int _energyPoints; // 에너지 (10)
    unsigned int _attackDamage; // 공격력 (0)

public:
    // Orthodox Canonical Form
    ClapTrap();                                    // 기본 생성자
    ClapTrap(const std::string& name);            // 매개변수 생성자
    ClapTrap(const ClapTrap& other);              // 복사 생성자
    ClapTrap& operator=(const ClapTrap& other);   // 대입 연산자
    ~ClapTrap();                                  // 소멸자

    // 멤버 함수들
    void attack(const std::string& target);       // 공격
    void takeDamage(unsigned int amount);         // 피해 받기
    void beRepaired(unsigned int amount);         // 수리하기

    // getter 함수들 (테스트용)
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif