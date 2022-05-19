#include "Player.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    class Ambassador : public Player {
        public:
            //can transfer a coin from one player to another.
            void transfer(Player &player1, Player &player2);
            //can prevet the theif operation
            static void block(Player &playyer);
            //constractor as Ambassador ambassador{game_1, "Meirav"};
            Ambassador(Game &game1, string const &name);
    };
}