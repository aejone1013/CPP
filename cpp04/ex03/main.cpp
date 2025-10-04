/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:38:41 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/01 17:13:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "=== Interface & Materia System Tests ===" << std::endl;
    
    // 주어진 테스트 코드
    std::cout << "\n--- Given Test Code ---" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    
    // 추가 테스트들
    std::cout << "\n--- Extended Tests ---" << std::endl;
    
    // MateriaSource 테스트
    std::cout << "\nMateriaSource learning test:" << std::endl;
    MateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());  // 가득 참 - 실패해야 함
    
    // 존재하지 않는 타입 생성 시도
    std::cout << "\nCreating unknown materia:" << std::endl;
    AMateria* unknown = source->createMateria("fire");
    if (!unknown) {
        std::cout << "✓ Correctly returned nullptr for unknown type" << std::endl;
    }
    
    // Character 인벤토리 테스트
    std::cout << "\n--- Character Inventory Tests ---" << std::endl;
    Character* hero = new Character("Hero");
    
    AMateria* ice1 = source->createMateria("ice");
    AMateria* cure1 = source->createMateria("cure");
    AMateria* ice2 = source->createMateria("ice");
    AMateria* cure2 = source->createMateria("cure");
    AMateria* ice3 = source->createMateria("ice");  // 5번째 - 실패해야 함
    
    hero->equip(ice1);
    hero->equip(cure1);
    hero->equip(ice2);
    hero->equip(cure2);
    hero->equip(ice3);  // 인벤토리 가득 참
    
    if (ice3) delete ice3;  // 장착 실패했으므로 삭제
    
    hero->printInventory();
    
    // unequip 테스트 (메모리 누수 방지)
    std::cout << "\n--- Unequip Test ---" << std::endl;
    AMateria* floor[4] = {0};  // 바닥에 떨어진 materia들
    
    hero->unequip(0);
    floor[0] = ice1;  // 바닥에 보관
    hero->unequip(1);
    floor[1] = cure1;
    
    hero->printInventory();
    
    // 떨어진 materia 사용 시도
    std::cout << "\nTrying to use unequipped materia:" << std::endl;
    hero->use(0, *hero);  // 빈 슬롯
    
    // 다시 장착
    hero->equip(floor[0]);
    hero->use(0, *hero);
    floor[0] = 0;
    
    // 바닥 정리
    for (int i = 0; i < 4; i++) {
        if (floor[i]) delete floor[i];
    }
    
    // 잘못된 인덱스 테스트
    std::cout << "\n--- Invalid Index Tests ---" << std::endl;
    hero->use(-1, *hero);
    hero->use(10, *hero);
    hero->unequip(-1);
    hero->unequip(10);
    
    // 깊은 복사 테스트
    std::cout << "\n--- Deep Copy Test (Character) ---" << std::endl;
    Character original("Original");
    original.equip(source->createMateria("ice"));
    original.equip(source->createMateria("cure"));
    
    original.printInventory();
    
    Character copied(original);
    std::cout << "\nAfter copying:" << std::endl;
    copied.printInventory();
    
    // 대입 테스트
    Character assigned("Assigned");
    assigned = original;
    std::cout << "\nAfter assignment:" << std::endl;
    assigned.printInventory();
    
    // 캐릭터간 사용 테스트
    std::cout << "\n--- Character Interaction Test ---" << std::endl;
    Character wizard("Wizard");
    Character warrior("Warrior");
    
    wizard.equip(source->createMateria("ice"));
    wizard.equip(source->createMateria("cure"));
    
    warrior.equip(source->createMateria("ice"));
    
    wizard.use(0, warrior);  // Wizard가 Warrior에게 ice 사용
    wizard.use(1, warrior);  // Wizard가 Warrior를 cure
    warrior.use(0, wizard);  // Warrior가 Wizard에게 ice 사용
    
    // MateriaSource 깊은 복사 테스트
    std::cout << "\n--- Deep Copy Test (MateriaSource) ---" << std::endl;
    MateriaSource originalSource;
    originalSource.learnMateria(new Ice());
    originalSource.learnMateria(new Cure());
    
    MateriaSource copiedSource(originalSource);
    
    AMateria* fromOriginal = originalSource.createMateria("ice");
    AMateria* fromCopied = copiedSource.createMateria("ice");
    
    if (fromOriginal && fromCopied) {
        std::cout << "✓ Both sources can create materias independently" << std::endl;
        delete fromOriginal;
        delete fromCopied;
    }
    
    // 메모리 정리
    delete hero;
    delete source;
    
    std::cout << "\n--- Cleanup Complete ---" << std::endl;
    
    return 0;
}
