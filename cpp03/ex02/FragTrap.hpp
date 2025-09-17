/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:36:04 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/17 23:38:14 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    FragTrap();                                    // 기본 생성자
    FragTrap(const std::string& name);            // 매개변수 생성자
    FragTrap(const FragTrap& other);              // 복사 생성자
    FragTrap& operator=(const FragTrap& other);   // 대입 연산자
    ~FragTrap();                                  // 소멸자

    // FragTrap 고유 기능
    void highFivesGuys(void);                     // High five 요청
};

#endif