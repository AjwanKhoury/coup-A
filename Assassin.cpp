#include "Assassin.hpp"

const int Num7=7;
const int Num6=6;
using namespace std;

namespace coup{

    Assassin::Assassin(Game &game1, string const &name) : Player(game1, name){
        this->rolePlay = "Assassin";
    }

    //can oust a player from his position for only 3 coins. it can be prevent.
    void Assassin::coup(Player &playyer){
        //we must check if its the player turn at all.
        //must check if the player is alive
        //must check if the player ones 3 coins.
       if(!(turnCheck()) || playyer.HasALife==0 || this->coinss < 3 ){ throw std::invalid_argument("Its not the player turn OR The player isnt alive! OR The player outst more than 3 coins!");}
        //update the turn.
        this->gamee->update();
        //kill the player 
        playyer.HasALife=0;
        //update the guest to be the player
        this->guest = &playyer; 
        //if the player have more than 6 coins so he lost 7!
        if (this->coinss > Num6){
            this->coinss -= Num7;
        }
        else{
            //else if he had less than 7 so he lost 3!
            this->CurrentAction = "c";
            this->coinss -= 3;
        }
    }

}