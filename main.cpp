#include <signal.h>
#include <iostream>
#include <stdint-gcc.h>

#include "ansi.hpp"

using namespace std;

bool running = true;

void sigIntHandler(int s){
    running = false;
}

float randFloat() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int main()
{
    srand(time(0));

    signal(SIGINT, sigIntHandler);

    std::cout << ansi::hide_cursor() << ansi::cursor_pos(1, 1) << ansi::erase_in_display();

    std::string iterationsMsg = "Total Iterations:   ";
    std::string pearlAvgMsg   = "Ender Pearl Avg.:   ";
    std::string rodsAvgMsg    = "Blaze Rod Avg.:     ";
    std::string pearlMaxMsg   = "Ender Pearl Max:    ";
    std::string rodsMaxMsg    = "Blaze Rod Max:      ";
    std::string pearlMsg      = "Ender Pearls:       ";
    std::string rodsMsg       = "Blaze Rods:         ";

    std::cout << "+------------------------+" << std::endl << // Line 1
                "|          Total         |" << std::endl <<  // Line 2
                "+------------------------+" << std::endl <<  // Line 3
                iterationsMsg << std::endl <<                 // Line 4
                pearlAvgMsg << std::endl <<                   // Line 5
                rodsAvgMsg << std::endl <<                    // Line 6
                pearlMaxMsg << std::endl <<                   // Line 7
                rodsMaxMsg << std::endl <<                    // Line 8
                "Dream Ender Pearls: 42" << std::endl <<      // Line 9
                "Dream Blaze Rods:   211" << std::endl <<     // Line 10
                "+------------------------+" << std::endl <<  // Line 11
                "|     This Iteration     |" << std::endl <<  // Line 12
                "+------------------------+" << std::endl <<  // Line 13
                pearlMsg << std::endl <<                      // Line 14
                rodsMsg << std::endl <<                       // Line 15
                std::endl;

    int64_t iterations = 0;
    int64_t maxPearls = 0;
    int64_t maxRods = 0;
    int64_t pearlSum = 0;
    int64_t rodsSum = 0;

    while(running) {
        iterations++;
        // Iterations Message
        std::cout << ansi::cursor_pos(4, iterationsMsg.length() + 1) << ansi::erase_in_line() << iterations << std::endl;

        int64_t numPearls = 0;
        for (int i = 0; i < 262; i++) {
            if (randFloat() <= 0.0473f) {
                numPearls++;
            }
        }
        pearlSum += numPearls;
        maxPearls = std::max(maxPearls, numPearls);
        // Pearl Message
        std::cout << ansi::cursor_pos(14, pearlMsg.length() + 1) << ansi::erase_in_line() << numPearls << std::endl;

        int64_t numRods = 0;
        for (int i = 0; i < 305; i++) {
            if (randFloat() <= 0.5f) {
                numRods++;
            }
        }
        rodsSum += numRods;
        maxRods = std::max(maxRods, numRods);
        // Rods Message
        std::cout << ansi::cursor_pos(15, rodsMsg.length() + 1) << ansi::erase_in_line() << numRods << std::endl;

        // Pearl Avg Message
        std::cout << ansi::cursor_pos(5, pearlAvgMsg.length() + 1) << ansi::erase_in_line() << pearlSum * 1.0 / iterations << std::endl;
        // Rods Avg Message
        std::cout << ansi::cursor_pos(6, rodsAvgMsg.length() + 1) << ansi::erase_in_line() << rodsSum * 1.0 / iterations << std::endl;
        // Pearl Max Message
        std::cout << ansi::cursor_pos(7, pearlMaxMsg.length() + 1) << ansi::erase_in_line() << maxPearls << std::endl;
        // Rods Max Message
        std::cout << ansi::cursor_pos(8, rodsMaxMsg.length() + 1) << ansi::erase_in_line() << maxRods << std::endl;
    }

    std::cout << std::endl << "SIGINT Detected" << ansi::show_cursor() << std::endl;

    return 0;
}
