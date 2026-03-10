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

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

template <typename T>
T const & max(T const & a, T const & b) {
    return (a > b) ? a : b;
}

#endif
