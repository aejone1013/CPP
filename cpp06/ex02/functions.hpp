/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:00:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 17:04:07 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include "Base.hpp"

// 랜덤하게 A, B, C 중 하나를 생성
Base* generate(void);

// 포인터로 타입 식별
void identify(Base* p);

// 레퍼런스로 타입 식별 (포인터 사용 금지)
void identify(Base& p);

#endif
