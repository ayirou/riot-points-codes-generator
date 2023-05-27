#include <iostream>
#include <string>
#include <random>
#include <chrono>

std::string generateRandomCode() {
    std::string code = "RA-";
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937_64 generator(rd() + std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0, characters.length() - 1);

    for (int i = 0; i < 16; ++i) {
        code += characters[distribution(generator)];
    }

    return code;
}

int main() {
    std::cout << "Welcome to the Random Code Generator Chatbox!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Enter 'generate' to generate a random code or 'quit' to exit:" << std::endl;

    std::string userInput;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);

        if (userInput == "quit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        if (userInput == "generate") {
            std::string randomCode = generateRandomCode();
            std::cout << "Random Code: " << randomCode << std::endl;
        } else {
            std::cout << "Invalid command. Please type 'generate' to generate a random code or 'quit' to exit." << std::endl;
        }
    }

    return 0;
}
