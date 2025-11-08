/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:11:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/11/08 14:59:05 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphism Tests ===" << std::endl;
    
    // 주어진 테스트 코드
    std::cout << "\n--- Given Test Code ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    // Wrong 클래스 테스트 (다형성 안 됨)
    std::cout << "\n--- Wrong Classes Test (No Polymorphism) ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // WrongAnimal의 소리가 나와야 함!
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    // 추가 테스트들
    std::cout << "\n--- Additional Tests ---" << std::endl;
    
    // 직접 객체 생성 테스트
    std::cout << "\nDirect object creation:" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;
    
    animal.makeSound();
    dog.makeSound();
    cat.makeSound();
    
    // 다형성 배열 테스트
    std::cout << "\nPolymorphic array test:" << std::endl;
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    
    for (int idx = 0; idx < 3; idx++) {
        std::cout << "Animal " << idx << " (" << animals[idx]->getType() 
                  << "): ";
        animals[idx]->makeSound();
    }
    
    // 메모리 해제
    for (int idx = 0; idx < 3; idx++) {
        delete animals[idx];
    }
    
    // 복사 테스트
    std::cout << "\n--- Copy Tests ---" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    Dog assignedDog;
    assignedDog = originalDog;
    
    std::cout << "Original: ";
    originalDog.makeSound();
    std::cout << "Copied: ";
    copiedDog.makeSound();
    std::cout << "Assigned: ";
    assignedDog.makeSound();
    
    return 0;
}
