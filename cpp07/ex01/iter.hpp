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

// iter 템플릿 함수 - 배열의 모든 요소에 함수 적용
template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    if (array == NULL)
        return;
    
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

// const 배열용 iter 오버로드
template <typename T, typename F>
void iter(T const * array, size_t length, F function) {
    if (array == NULL)
        return;
    
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

#endif
