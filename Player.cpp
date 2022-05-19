#include "Player.hpp"
#include "Game.hpp"

const int MaxCoup=10;
const int ItCosts=7;
using namespace std;

namespace coup{
    
    Player::Player(Game &game1, string const &name){
        this->playername=name;
        this->gamee= &game1;
        this->HasALife=1;
        this->gamee->add(this);
        this->guest=NULL;
        this->CurrentAction="";
        this->coinss=0;
    }

    //returns how many coins the player has.
    int Player::coins() const{
        return this->coinss;
    }

    //returns the player role.(for display)
    string Player::role() const{
        return this->rolePlay;
    }

    bool Player::turnCheck() const{
        bool temp= false;
        // string tmp= this->game->turn();
        if(this->playername==this->gamee->turn()) {temp=true;} 
        return temp;
        
    }

    //to remove player from the game , it costs 7 coins.
    void Player::coup(Player &playyer){
        //we must check if : 1) the coins is smaller than 7
        //                  2) if the player doesn't have a life at all 
        //if it so we must throw exeption
        if(this->coinss<ItCosts || playyer.HasALife == 0){ throw std::invalid_argument("The player must have 7 coins AND must have a life to play.");}
        //must check if the turn is the player turn at all if itn't so also we must throw exeption
        //string tmp = this->gamee->turn();
        if(!(turnCheck())) {throw std::invalid_argument("Its not the player turn");}
        //after coup we must update the life of the player as a 0 
        playyer.HasALife=0;
        //and lost a 7 coin because its costs 7.
        this-> coinss-=ItCosts;
        this->guest=&playyer;
        //update the status of the player
        this->CurrentAction="coup";
         //and the update the player turn
        this->gamee->update();
    }

    //take two coins from  the heap, the action has no cost, the player earns two coins, but
    //the role can be blocked , if it so the player's turn end.
    void Player::foreign_aid(){
        //must check if the turn is the player turn at all, if itsn't so must throw exeptions
       // string tmp = this->gamee->turn();
        if(!(turnCheck())) {throw std::invalid_argument("Its not the player turn");}
        if(this->coinss > MaxCoup) {throw std::invalid_argument("The player has more than the max ");}
        //after forregin aid , must update the game 
        this->gamee->update();
        //update the status of the player
        this->CurrentAction="foreign_aid";
        //and the player earns a single coin.
        this->coinss+=2;
    }

    //to take a coin from the heap, the action has no cost , the player earns a single coin.
    void Player::income(){
        //must check if the turn is the player turn at all, if itsn't so must throw exeptions
        // string tmp = this->gamee->turn();
        if(!(turnCheck())){ throw std::invalid_argument("Its not the player turn");}
        if(this->coinss > MaxCoup){ throw std::invalid_argument("The player has more than the max ");}
        //after forregin aid , must update the game 
        this->gamee->update();
        //update the status of the player
        this->CurrentAction="income";
        //and the player earns a single coin.
        this->coinss+=1;
    }

    //block the acction
    void Player::blocked()
    {
        //the guest own 2 coins 
        this->guest->coinss += 2;
        //after that we check if the total coins is more than 2 
        if (this->coinss > 2){
            //if it so he lose 2 coins
            this->coinss -= 2;}
        else{
            //if not so the coin is totaly 0 , he's now out!
            this->coinss = 0;}
        this->CurrentAction = "";
        this->guest = NULL;
    }

}