/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:07:40 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 15:20:02 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const	Animal*	meta = new Animal();
	const	Animal*	i = new Cat();
	const	Animal*	j = new Dog();

	Dog*	d = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "-------------Set Ideas to Brain--------------" << std::endl;
	d->createIdea("What's a Dog?");
	d->createIdea("What's a Cat?");
	d->createIdea("Am I a Dog?");
	std::cout << "Idea 1: [" << d->getIdea(0) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << d->getIdea(1) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << d->getIdea(2) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << d->getIdea(3) << "] in Dog's brain" << std::endl;
	
	// Cat 클래스 테스트 추가
	Cat* c = new Cat();
	std::cout << "-------------Set Ideas to Cat's Brain--------------" << std::endl;
	c->createIdea("I love tuna!");
	c->createIdea("Sleeping is the best!");
	c->createIdea("I'm a cat!");
	std::cout << "Idea 1: [" << c->getIdea(0) << "] in Cat's brain" << std::endl;
	std::cout << "Idea 2: [" << c->getIdea(1) << "] in Cat's brain" << std::endl;
	std::cout << "Idea 3: [" << c->getIdea(2) << "] in Cat's brain" << std::endl;
	std::cout << "-------------Check Copy of Brain--------------" << std::endl;
	Dog	e(*d);
	// e = *d;
	std::cout << "Idea 1: [" << e.getIdea(0) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << e.getIdea(1) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << e.getIdea(2) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << e.getIdea(3) << "] in Copy Dog's brain" << std::endl;

	std::cout << "-------------Check Copy2 of Brain--------------" << std::endl;
	Dog	*f = new Dog();
	*f = *d;
	std::cout << "Idea 1: [" << f->getIdea(0) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << f->getIdea(1) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << f->getIdea(2) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << f->getIdea(3) << "] in Copy2 Dog's brain" << std::endl;
	
	delete meta;
	delete i;
	delete j;
	delete d;
	delete c;  // Cat 객체 삭제 추가
	delete f;
	std::cout << "--------------Array of Animals------------------" << std::endl;
	Animal	*herd[4];
	herd[0] = new Dog();
	herd[1] = new Dog();
	herd[2] = new Cat();
	herd[3] = new Cat();

	std::cout << "----------delete the array of animals-----------" << std::endl;
	for (int z = 0; z < 4; z++) {
		delete herd[z];
	}
	return 0;
}
