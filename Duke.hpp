#include "Player.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    //inheritance class;
    class Duke : public Player{
        public:
            //duke can take a tax of three coins from the pot(without prevent from any player)
            void tax();
            //the duke also can block double pay action (foreign_aid)
            static void block(Player &playyer);
            //constractor as Duke duke{game_1, "Moshe"};
            Duke(Game &game1,  string const &name);
    };
}