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
    for (int mass: data) {
        int fuel = calculate_fuel(mass);
        int fuel_sum = 0;
        while (fuel > 0) {
            fuel_sum += fuel;
            fuel = calculate_fuel(fuel);
        }
        sum += fuel_sum;
    }

    std::cout << sum << std::endl;
    return 0;
}