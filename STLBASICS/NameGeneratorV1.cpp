#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

class NameGenerator {
private:
    std::vector<std::string> prefixes = { "Sil", "Val", "Kor", "Dra", "Zen", "Aet" };
    std::vector<std::string> middles  = { "van", "den", "ron", "lis", "tor" };
    std::vector<std::string> suffixes = { "-Thal", " Wave", "stone", "forge", "bound" };

    // The Engine: Mersenne Twister
    std::mt19937 rng;

public:
    NameGenerator() {
        // Seed the generator with the current time
        rng.seed(static_cast<unsigned int>(std::time(nullptr)));
    }

    std::string generate() {
        // Think of this like a firmware check: 
        // We define the distribution range [0, size-1]
        std::uniform_int_distribution<size_t> distPre(0, prefixes.size() - 1);
        std::uniform_int_distribution<size_t> distMid(0, middles.size() - 1);
        std::uniform_int_distribution<size_t> distSuf(0, suffixes.size() - 1);

        // Concatenate the selected elements
        return prefixes[distPre(rng)] + middles[distMid(rng)] + suffixes[distSuf(rng)];
    }
};

int main() {
    NameGenerator gen;
    const int numNames = 11;
    std::cout << "--- Generated Names ---" << std::endl;
    for (int i = 0; i < numNames; ++i) {
        std::cout << i + 1 << ": " << gen.generate() << std::endl;
    }

    return 0;
}