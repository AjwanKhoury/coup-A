#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game &game1, string const &name): Player(game1, name){
        this->rolePlay = "Ambassador";
    }

    //can prevet the theif operation
    void Ambassador::block(Player &playyer){
        //if he had more than 1 coin so:
        if(playyer.CurrentAction == "More Than 1"){
            //the guest get the two coins
            playyer.guest->coinss += 2;
            //from the playyer so the playyer lose them.
            playyer.coinss-=2;
        }
        else if(playyer.CurrentAction == "EQUAL 1"){
            //the guest get this coin 
            playyer.guest->coinss += 1;
            //from the playyer so the playyer lose them.
            playyer.coinss -= 1;
        }
        //if he already stole so there's nothing we can do.
        else if (playyer.CurrentAction == "Steal"){return;}
        //else he can't be blocked!
        else{throw std::invalid_argument("can't block!");}
    }

    //can transfer a coin from one player to another.
    void Ambassador::transfer(Player &player1, Player &player2){
       //check if its the player turn , bwt we check also if the player had money at all.
        if(!(turnCheck()) || player1.coinss == 0){ throw std::invalid_argument("not the player turn OR Have no money");}
        player2.coinss++;
        player1.coinss--;
        this->gamee->update(); // change the curr player turn:
    }

}