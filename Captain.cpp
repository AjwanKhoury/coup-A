#include "Captain.hpp"
using namespace std;

namespace coup{

    Captain::Captain(Game &game1, string const &name) : Player(game1, name){
        this->rolePlay= "Captain";
    }

    //can steal 2 coins from another player.
    //This action can be blocked by an ambassador or another captain.
    void Captain::steal(Player &playyer){
        //we must check if its the player turn at all.
        // string tmp = this->gamee->turn();
        if(!(turnCheck())) {throw std::invalid_argument("Its not the player turn");}
        //bwt check if the play is alive
        //and update the turn.
        this->gamee->update();
        if(playyer.HasALife==0) {throw std::invalid_argument("The player isnt alive!");}
        //if the player own more than 1 coin so:
        if (playyer.coinss >= 1){
            //if he own 1 coin:
            if(playyer.coinss==1){
                this->guest = &playyer;
                //he lost 1 coin
                playyer.coinss -= 1;
                //and the guest get 1
                this->coinss += 1;
                //now the acttion is 1
                this->CurrentAction = "EQUAL 1";
            }
            else{
                //else if he had 2 or more coins
                this->guest = &playyer;
                //so the player loss 2 coins
                playyer.coinss -= 2;
                //and the guest get them
                this->coinss += 2;
                //now the action is more than 2
                this->CurrentAction = "More Than 1";
            }
        }
        else{
            //else if he had no coin so he already steal!
            this->CurrentAction = "Steal";
            this->guest = &playyer;
        }
    }

    //can block the theif , similar to the Ambassador.
    void Captain::block(Player &playyer){
        // if(playyer.CurrentAction != "steal"){ throw std::invalid_argument("Can't block theif");}
        // playyer.coinss-=2;
        //if he had more than 1 coin so:
        if(playyer.CurrentAction== "More Than 1"){
            //the guest get the two coins
            playyer.guest->coinss += 2;
            //from the playyer so the playyer lose them.
            playyer.coinss-=2;
        }
        //if he had just one coin so:
        else if(playyer.CurrentAction== "EQUAL 1"){
            //the guest get this coin 
            playyer.guest->coinss += 1;
            //from the playyer so the playyer lose them.
            playyer.coinss-=1;
        }
        //if he already stole so there's nothing we can do.
        else if(playyer.CurrentAction=="steal"){ return;}
        //else he can't be blocked!
        else{throw std::invalid_argument("can't block ");
        }
    }
}
