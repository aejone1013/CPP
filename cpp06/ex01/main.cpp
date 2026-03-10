/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:24:06 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 16:24:23 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    std::cout << "=== Serialization Tests ===" << std::endl;

    Data originalData;
    originalData.name = "Test Data";
    originalData.value = 42;
    originalData.price = 99.99;

    std::cout << "\n--- Original Data ---" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << "Price: " << originalData.price << std::endl;

    std::cout << "\n--- Serialization ---" << std::endl;
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Serialized hex: 0x" << std::hex << serialized << std::dec << std::endl;

    std::cout << "\n--- Deserialization ---" << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;

    std::cout << "\n--- Comparison ---" << std::endl;
    if (deserializedPtr == &originalData) {
        std::cout << "Success: Pointers are equal!" << std::endl;
    } else {
        std::cout << "Failure: Pointers are different!" << std::endl;
    }

    std::cout << "\n--- Deserialized Data Access ---" << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Value: " << deserializedPtr->value << std::endl;
    std::cout << "Price: " << deserializedPtr->price << std::endl;

    std::cout << "\n--- Modification Test ---" << std::endl;
    deserializedPtr->value = 100;
    std::cout << "Modified value through deserialized pointer: "
              << deserializedPtr->value << std::endl;
    std::cout << "Original data value: " << originalData.value << std::endl;

    if (originalData.value == 100) {
        std::cout << "Both values changed (same object)" << std::endl;
    }

    std::cout << "\n--- Multiple Objects Test ---" << std::endl;
    Data data1, data2, data3;
    data1.name = "First";
    data1.value = 1;
    data2.name = "Second";
    data2.value = 2;
    data3.name = "Third";
    data3.value = 3;

    uintptr_t ser1 = Serializer::serialize(&data1);
    uintptr_t ser2 = Serializer::serialize(&data2);
    uintptr_t ser3 = Serializer::serialize(&data3);

    Data* deser1 = Serializer::deserialize(ser1);
    Data* deser2 = Serializer::deserialize(ser2);
    Data* deser3 = Serializer::deserialize(ser3);

    std::cout << "Object 1: " << deser1->name << " = " << deser1->value << std::endl;
    std::cout << "Object 2: " << deser2->name << " = " << deser2->value << std::endl;
    std::cout << "Object 3: " << deser3->name << " = " << deser3->value << std::endl;

    if (deser1 == &data1 && deser2 == &data2 && deser3 == &data3) {
        std::cout << "All pointers correctly restored!" << std::endl;
    }

    std::cout << "\n=== End of Tests ===" << std::endl;

    return 0;
}
