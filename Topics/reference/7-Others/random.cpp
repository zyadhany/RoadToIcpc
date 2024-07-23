#include <iostream>
#include <random>

int main() {
    // Seed with a real random value, if available
    std::random_device rd;
    
    // Choose a random number between 1 and 1,000,000
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine
    std::uniform_int_distribution<> distrib(1, 1000000);

    int random_number = distrib(gen);
    std::cout << "Random number between 1 and 1,000,000: " << random_number << std::endl;

    return 0;
}
