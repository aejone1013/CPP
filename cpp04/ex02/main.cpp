/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:46:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/23 15:17:23 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Abstract Class Tests ===" << std::endl;
    
    // Animal 인스턴스화 불가 테스트 (컴파일 에러)
    // Animal animal; // 이 줄은 컴파일 에러를 발생시킴
    // Animal* animal = new Animal(); // 이것도 컴파일 에러
    
    std::cout << "\n--- Abstract Animal Test ---" << std::endl;
    std::cout << "Cannot instantiate Animal directly (pure virtual function)" << std::endl;
    
    // 다형성은 여전히 작동
    std::cout << "\n--- Polymorphism Still Works ---" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    // 동물 배열 테스트
    std::cout << "\n--- Animal Array Test ---" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    // Dog과 Cat으로 배열 채우기
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    // 다형성 테스트
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // 메모리 해제
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    // 깊은 복사 테스트
    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog originalDog;
    originalDog.setBrainIdea(0, "I'm the original dog!");
    
    Dog copiedDog(originalDog);
    copiedDog.setBrainIdea(0, "I'm the copied dog!");
    
    std::cout << "Original: " << originalDog.getBrainIdea(0) << std::endl;
    std::cout << "Copied: " << copiedDog.getBrainIdea(0) << std::endl;
    
    // Brain 주소 확인
    if (originalDog.getBrain() != copiedDog.getBrain()) {
        std::cout << "✓ Deep copy successful!" << std::endl;
    } else {
        std::cout << "✗ Shallow copy detected!" << std::endl;
    }
    
    // Cat 테스트
    std::cout << "\n--- Cat Test ---" << std::endl;
    Cat myCat;
    myCat.setBrainIdea(0, "I love tuna!");
    myCat.setBrainIdea(1, "Sleeping is the best!");
    myCat.getBrain()->printIdeas();
    myCat.makeSound();
    
    return 0;
}
