/**
 * @brief Create this file for solve the fifth exercise of Advento 2022 (https://adventofcode.com/2022/day/5)
 * @name  --- Day 5: Supply Stacks ---
 * @author Ana Miranda
 * @date 22/09/2023
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

void readFile(std::string filename) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";
    std::string lineCrates = "";

    std::vector<std::deque<char>> vecCrates;
    std::vector<std::deque<char>> vecCrates2;
    for (size_t i = 0; i < 10; i++) {
        std::deque<char> a;
        vecCrates.push_back(a);
        vecCrates2.push_back(a);
    }

    int index = 0;
    while(getline(inputStream, lineCrates) && lineCrates[1] != '1') {
        for (size_t i = 1; i < lineCrates.size(); i += 4) {
            if (lineCrates[i] != ' ')
                vecCrates.at(index).push_back(lineCrates[i]);
                vecCrates2.at(index).push_back(lineCrates[i]);
            index++;
        }
        index = 0;
    }

    int count, from, to {0};

    while(getline(inputStream, lineCrates)) {
        sscanf(lineCrates.c_str(), "move %d from %d to %d", &count, &from, &to);
        for (size_t j = 0; j < count; j++) {

            //Part 1:
            vecCrates[to - 1].emplace_front(vecCrates[from - 1].front());
            vecCrates[from - 1].pop_front();

            //Part 2:
            vecCrates2[to - 1].emplace_front(vecCrates2[from - 1].back());
            vecCrates2[from - 1].pop_back();
        }
    }

    std::cout << "Crates ends up on top of each stack (Part 1): ";
    for (const auto item : vecCrates) {
        if (!item.empty())
            std::cout << item.front();
    }

    std::cout << "Crates ends up on top of each stack (Part 2): ";
    for (const auto item : vecCrates2) {
        if (!item.empty())
            std::cout << item.front() << std::endl;
    }
}


int main(int argc, char** argv) {
    if (argc >= 2) {
        readFile(argv[1]);
    }
    else {
        std::cout << "Puzzle input is missing. Please introduce." << std::endl;
    }

    return 0;
}