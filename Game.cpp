#include "Game.hpp"

namespace coup{
    
    const int maxplayer = 6;
    const int minplayer = 2;

    Game:: Game(){
        this->PlayerNum=0;
        this->startPlay=0;
        this->PlayerIndex=0;
    }

    // vector that contains the players name.(the actives one)
    vector<string> Game:: players(){
        vector<string> v;
        for(unsigned int i=0; i<  this->PlayerList.size(); i++){
        //    (this->PlayerList.at(i)->HasALife==1)? v.push_back(this->PlayerList.at(i)->playername) : break
        if(this->PlayerList.at(i)->HasALife==1){v.push_back(this->PlayerList.at(i)->playername); }
        }
        return v;
    }

    //return the player's name such as: cout << game_1.turn() << endl; prints moshe.
    string Game::turn(){
        //we must check if the vector is empty(the list of the players pointer) , if it so throw exception
        //else we must return the list.
        //(!this->PlayerList.empty())? throw std::invalid_argument("There's no player!") : this->PlayerList.at(PlayerIndex)->playername;
        if(this->PlayerList.empty()){
            throw std::invalid_argument("There's no player!");
        }
        return this->PlayerList.at(PlayerIndex)->playername;   
    }

    //return the winner's name.
    string Game::winner(){
        //we must check 1) if the vector is empty(the list of the players pointer)
        //              2) if the game started 
        //              3) if there is more than one player - so the game isnt over yet
        if(this->players().empty() || this->startPlay==0 || this->players().size() != 1) {
            throw std::invalid_argument("There's no player OR the game doesn't start at all OR The game isn't over");
        }
        //else we have to return the winner  (using the vector for the player)
        return this->players().at(0);
    }

    //update the player turn
    void Game::update(){
        do{ this->PlayerIndex = (this->PlayerIndex + 1) % this->PlayerList.size();
        } while (this->PlayerList.at(PlayerIndex)->HasALife == 0);
            
            //we check if the player at the index +1 mod the size of the playerlist has a life, if 
            //it not so we stop.
          // if(this->PlayerList.at((this->PlayerIndex+1)% this->PlayerList.size())->HasALife){break;}
            if(this->PlayerNum < minplayer) {
                throw std::invalid_argument("Check the player num!");
            }
            if(this->PlayerNum > maxplayer){
                throw std::invalid_argument("Check the player num!");
            }
            if(this->startPlay==0){ this->startPlay=1;}
    }


    //add a player to the list - to the game
    void Game::add(Player *P){
        //first we must check if the player num is not maxiumum. 
        if(this->PlayerNum >= maxplayer || this->startPlay==1){ throw std::invalid_argument("Cann't add! the maximum number of players is 6 OR the game is already started");}
        //push the new player to the list
        this->PlayerList.push_back(P);
        //must increase the player number after adding a new one
        this->PlayerNum++;
    }

}
