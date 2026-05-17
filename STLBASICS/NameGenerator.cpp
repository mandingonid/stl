#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>

class IdentityGenerator {
private:
    // First names pool
    std::vector<std::string> firstNames = {
        "Logan", "Tomas", "Mario", "Joe", "Brent", "Erik", "Evander",
        "Ada", "Grace", "Linus", "Ken", "Dennis", "Margaret", "Claude",
        "Sasha", "Mikael", "Antti", "Joonas", "Radim", "Nico", "Timo",
        "Macklin", "Ty", "William", "Adam", "Barclay","Colin", "Philipp",
        "Micheal", "Zack", "Ryan", "Pavol", "Kiefer", "Will", "Tyler", "Alexander", 
        "Vincent", "Sam", "Mario", "John", "Nick", "Shakir"
    };

    // Last names pool
    std::vector<std::string> lastNames = {
        "Celebrini", "Couture", "Hertl", "Ferraro", "Thornton", "Burns", "Karlsson", "Kane",
        "Lovelace", "Hopper", "Torvalds", "Thompson", "Ritchie", "Hamilton", "Shannon",
        "Sturm", "Granlund", "Raanta", "Korpisalo", "Simek", "Hischier", "Meier", "Celebrini",
        "Dellandrea", "Eklund", "Gaudette", "Goodrow", "Graf", "Kurashev", "Misa", "Ostapchuk",
        "Reaves", "Sherwood", "Smith", "Toffoli", "Wennberg", "Desharnals", "Dickinson",
        "Klingberg", "Mukhamadullin"
};

    std::mt19937 rng;

public:
    IdentityGenerator() {
        // Seed the engine with a non-deterministic seed
        std::random_device rd;
        rng.seed(rd());
    }

    std::string generate() {
        // Define distributions over the current vector indices
        std::uniform_int_distribution<size_t> firstDist(0, firstNames.size() - 1);
        std::uniform_int_distribution<size_t> lastDist(0, lastNames.size() - 1);
        std::uniform_int_distribution<> playerRank(1, 10);

        return firstNames[firstDist(rng)] + " " + lastNames[lastDist(rng) ] + " " + std::to_string(playerRank(rng));
    }
};

int main() {
    IdentityGenerator gen;
    const int count = 165;

    std::cout << std::left << std::setw(5) << "ID" << "NAME" << "\t\t" << "RANK" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (int i = 1; i <= count; i += 3) {
        std::cout << std::left << std::setw(5) << 2000 + i << gen.generate() << "\n";
    }

    return 0;
}