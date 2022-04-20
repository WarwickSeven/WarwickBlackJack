#include <iostream>
#include "Game.hpp"

int main() {
    std::cout << "Welcome to BlackJack!\n\n";
    int numPlayers { 0 };
    while (numPlayers < 1 || numPlayers > 7) {
        std::cout << "How many players? (1-7): ";
        std::cin >> numPlayers;
    }
    std::vector<std::string> names;
    std::string name;
    
    for (size_t i = 1; i <= numPlayers; i++) {
        std::cout << "Enter player " << i << " name: ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << std::endl;
    
    Game aGame(names);
    char again { 'y' };
    while (again != 'n' && again != 'N') {
        aGame.play();
        std::cout << "\nWanna play one more time? (Y/N): ";
        std::cin >>again;
    }
    return 0;
}
