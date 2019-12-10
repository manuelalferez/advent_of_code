#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

int calculate_fuel(int &mass) {
    return floor(mass / 3) - 2;
}

int main() {
    std::ifstream inputFile("../input.txt");
    std::string line;
    std::vector<int> data;

    if (inputFile.is_open()) {
        while (getline(inputFile, line))
            data.push_back(std::stoi(line));
        inputFile.close();
    }

    int sum = 0;
    for (int i = 0; i < data.size(); ++i)
        sum += calculate_fuel(data[i]);

    std::cout << sum << std::endl;
    return 0;
}