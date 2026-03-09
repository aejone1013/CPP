/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:49:52 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:00:50 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    if (array == NULL)
        return;
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

template <typename T, typename F>
void iter(T const * array, size_t length, F function) {
    if (array == NULL)
        return;
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif
