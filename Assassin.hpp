#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup{
    //inheritance class;
    class Assassin : public Player {
        public:
            //can oust a player from his position for only 3 coins. it can be prevent.
            void coup(Player &playyer);
            //constractor as Assassin assassin{game_1, "Yossi"};
            Assassin(Game &game1, string const &name);

    };
}