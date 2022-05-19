#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::Duke(Game &game1,  string const &name) : Player(game1 ,name){
        this->rolePlay= "Duke";
    }

    //duke can take a tax of three coins from the pot(without prevent from any player)
    void Duke:: tax(){
        //we must check if its the player turn at all.
        //string tmp = this->gamee->turn();
        if(!(turnCheck())) {throw std::invalid_argument("Its not the player turn");}
        //and update the turn after the tax
        this->gamee->update();
        //take a tax of three coins
        this->coinss=coinss+3;
        this->CurrentAction="";

    }

    //the duke also can block double pay action (foreign_aid)
    void Duke::block(Player &playyer){
        //(playyer.CurrentAction == "forgin_aid")? playyer.coinss=playyer.coinss-2 : throw std::invalid_argument("it can block only forgin_aid");
        if(playyer.CurrentAction != "foreign_aid"){throw std::invalid_argument("it can block only forgin_aid");}
        playyer.CurrentAction="";
        playyer.coinss-=2;
    }   

}