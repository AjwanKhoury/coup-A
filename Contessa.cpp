#include "Contessa.hpp"
using namespace std;

namespace coup
{
    Contessa::Contessa(Game &game1, string const &name) : Player(game1, name){ 
        this->rolePlay = "Contessa";
    }


    //Can block the act of assassination.
    void Contessa::block(Player &playyer){
        //check if the play role is assassin if itsnt so we can't block it.
        if(playyer.rolePlay != "Assassin"){throw std::invalid_argument("Can't block.");}
        if(playyer.CurrentAction != "c"){throw std::invalid_argument("Can't block.");}
        //we must update the curent action to the player as an empty string because its blocked.
        playyer.CurrentAction = "";
        //update the life of the guest as a live one
        playyer.guest->HasALife = 1;
        playyer.guest = NULL;
    }

}
