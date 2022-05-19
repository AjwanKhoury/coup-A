#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Player;
    class Game{

        public:
            //arguments:
            int PlayerNum; //the players number (Quantity)
            int startPlay; //symbol that help to configure if the game start at all.
            Game();
            //vector that contains a player pointer.
            vector<Player *> PlayerList;
            // vector that contains the players name.(the actives one)
            vector<string> players(); 
            //return the player's name such as: cout << game_1.turn() << endl; prints moshe.
            string turn();
            //return the winner's name. throw error if the game isn't over.
            string winner();
            unsigned int PlayerIndex; //the player Index.
            void update(); //update the turn for each player.
            void add(Player *P); //to add a player to the list

    };

}