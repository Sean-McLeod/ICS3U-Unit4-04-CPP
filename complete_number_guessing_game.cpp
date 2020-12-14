// Copyright (c) 2020 Sean McLeod All rights reserved

// Created by Sean McLeod
// Created on December 2020
// This program is the number guessing game

#include <iostream>
#include <random>
#include <string>

int main()  {
    // this function can tell the user if the number they guessed is correct

    std::string guessedString;
    int guessedNumber;
    int randomNumber;

    // process
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // process and output
    while (true) {
        // input
        std::cout << "Guess a number between 0 to 9: " << std::endl;
        std::cin >> guessedString;

        try {
            guessedNumber = std::stoi(guessedString.c_str());

            if (guessedNumber >= 0 && guessedNumber <= 9) {
                if (guessedNumber == randomNumber) {
                    std::cout << "You are correct!" << "\n" << std::endl;
                    break;
                } else if (guessedNumber > randomNumber) {
                    std::cout << "Try smaller!" << "\n" << std::endl;
                } else {
                    std::cout << "Try larger!" << "\n" << std::endl;
                }
            } else {
                std::cout << "Please enter a positive integer between 0 and 9"
                          << "\n" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "This is not an integer" << "\n" << std::endl;
        }
    }
}
