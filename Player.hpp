#pragma once

#include "Game.hpp"
#include <string>
using namespace std;

namespace coup{
    class Game;
    class Player{
        public:
            //arguments:
            string playername; //the player name (string one not a vector)
            int coinss; // tthe coins quantity
            Game *gamee; //started game
            int HasALife; //the player has a life - he's alive
            string rolePlay;
            //to take a coin from the heap, the action has no cost , the player earns a single coin.
            void income();
            //take two coins from  the heap, the action has no cost, the player earns two coins, but
            //the role can be blocked , if it so the player's turn end.
            void foreign_aid();
            //to remove player from the game , it costs 7 coins.
            void coup(Player &playyer);
            //returns the player role.(for display)
            string role() const;
            //returns how many coins the player has.
            int coins() const;     
            //constractor
            Player(Game &game1, string const &name);
            string CurrentAction;
            bool turnCheck() const;
            Player *guest;
            void blocked();

    }; 
}