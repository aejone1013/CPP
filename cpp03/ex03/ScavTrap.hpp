/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:36:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:16:41 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {  // virtual 상속 (다이아몬드 문제 해결)
public:
    // Orthodox Canonical Form
    ScavTrap();                                    // 기본 생성자
    ScavTrap(const std::string& name);            // 매개변수 생성자
    ScavTrap(const ScavTrap& other);              // 복사 생성자
    ScavTrap& operator=(const ScavTrap& other);   // 대입 연산자
    ~ScavTrap();                                  // 소멸자

    // 오버라이드된 함수
    void attack(const std::string& target);       // 다른 메시지로 공격

    // ScavTrap 고유 기능
    void guardGate();                             // Gate keeper 모드
};

#endif
