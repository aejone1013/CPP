/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:58:23 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 15:58:28 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <exception>

class RPN {
private:
    std::stack<int> _stack;
    
    bool isOperator(char c) const;
    bool isDigit(char c) const;
    int performOperation(int a, int b, char op) const;

public:
    RPN();
    RPN(RPN const & other);
    RPN& operator=(RPN const & other);
    ~RPN();

    int calculate(const std::string& expression);
};

#endif
