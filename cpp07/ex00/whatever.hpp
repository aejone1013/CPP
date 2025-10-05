/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:45:09 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:49:38 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// swap 템플릿 함수 - 두 값을 교환
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// min 템플릿 함수 - 두 값 중 작은 값 반환 (같으면 두 번째 값 반환)
template <typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

// max 템플릿 함수 - 두 값 중 큰 값 반환 (같으면 두 번째 값 반환)
template <typename T>
T const & max(T const & a, T const & b) {
    return (a > b) ? a : b;
}

#endif
