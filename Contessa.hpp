#include "Player.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{
    //inheritance class;
    class Contessa : public Player{
        public:
            //Can block the act of assassination.
            static void block(Player &playyer);
            //constractor as Contessa contessa{game_1, "Gilad"};
            Contessa(Game &game1, string const &name);
    };
}