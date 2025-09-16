/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:05:47 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:08:31 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:  // private에서 protected로 변경 (상속을 위해)
    std::string _name;        // 이름 (생성자 매개변수로 전달)
    unsigned int _hitPoints;  // 체력
    unsigned int _energyPoints; // 에너지
    unsigned int _attackDamage; // 공격력

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

    // getter 함수들
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif
