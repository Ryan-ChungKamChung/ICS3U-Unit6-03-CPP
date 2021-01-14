// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program generates 10 random numbers and displays the smallest

#include <iostream>
#include <random>
#include <array>


template<size_t N>
int smallest(std::array<int, N> random_numbers) {
    // Finds the smallest number

    int single_element = 0;
    int smallest_number = random_numbers[0];

    for (int single_element : random_numbers) {
        if (smallest_number > single_element) {
            smallest_number = single_element;
        }
    }

    return smallest_number;
}


int main() {
    // Generates 10 random numbers and displays the smallest

    int smallest_number;
    std::array<int, 10> random_numbers;

    for (int loop_counter; loop_counter < 10; loop_counter++) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1.0, 100.0);  // [0,100]
        random_numbers[loop_counter] = idist(rgen);

        if (loop_counter < 9) {
            std::cout << random_numbers[loop_counter] << ", ";
        } else {
            std::cout << random_numbers[loop_counter] << std::endl;
        }
    }

    smallest_number = smallest(random_numbers);

    std::cout << "The smallest number is: " << smallest_number << std::endl;
}
