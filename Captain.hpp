#include "Player.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    //inheritance class;
    class Captain : public Player{
        public:
            //can block the theif , similar to the Ambassador.
            static void block(Player &playyer);
            //can steal 2 coins from another player.
            //This action can be blocked by an ambassador or another captain.
            void steal(Player &playyer);
            //constractor as Captain captain{game_1, "Reut"};
            Captain(Game &game1, string const &name);

    };
}