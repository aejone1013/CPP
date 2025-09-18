/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:10 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;  // DiamondTrap 자체의 이름 (ClapTrap::_name과 같은 변수명)

public:
    // Orthodox Canonical Form
    DiamondTrap();                                      // 기본 생성자
    DiamondTrap(const std::string& name);              // 매개변수 생성자
    DiamondTrap(const DiamondTrap& other);             // 복사 생성자
    DiamondTrap& operator=(const DiamondTrap& other);  // 대입 연산자
    ~DiamondTrap();                                    // 소멸자

    // DiamondTrap 고유 기능
    void whoAmI();                                     // 이름들 출력

    // using 선언으로 어떤 attack을 사용할지 명시 (ScavTrap의 attack 사용)
    using ScavTrap::attack;
};

#endif
