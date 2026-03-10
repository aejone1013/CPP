/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:12:25 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:13:13 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "=== MutantStack Tests ===" << std::endl;
    
    std::cout << "\n--- Given Test Code ---" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    std::cout << "\n--- Same Test with std::list ---" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    
    ++lit;
    --lit;
    
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    std::cout << "\n--- Additional Tests ---" << std::endl;
    
    std::cout << "\nCopy test:" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(1);
    mstack2.push(2);
    mstack2.push(3);
    
    MutantStack<int> mstack3(mstack2);
    
    std::cout << "Original: ";
    for (MutantStack<int>::iterator it2 = mstack2.begin(); it2 != mstack2.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy: ";
    for (MutantStack<int>::iterator it3 = mstack3.begin(); it3 != mstack3.end(); ++it3) {
        std::cout << *it3 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nReverse iterator test:" << std::endl;
    MutantStack<int> mstack4;
    mstack4.push(10);
    mstack4.push(20);
    mstack4.push(30);
    mstack4.push(40);
    
    std::cout << "Normal order: ";
    for (MutantStack<int>::iterator it4 = mstack4.begin(); it4 != mstack4.end(); ++it4) {
        std::cout << *it4 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse order: ";
    for (MutantStack<int>::reverse_iterator rit = mstack4.rbegin(); rit != mstack4.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nString test:" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");
    
    std::cout << "Strings: ";
    for (MutantStack<std::string>::iterator sit = strStack.begin(); sit != strStack.end(); ++sit) {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nConst iterator test:" << std::endl;
    MutantStack<int> const constStack(mstack4);
    
    std::cout << "Const stack: ";
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nEmpty stack test:" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    std::cout << "Empty stack begin == end: " 
              << (emptyStack.begin() == emptyStack.end() ? "true" : "false") << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
