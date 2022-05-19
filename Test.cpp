#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <string>
#include "doctest.h"

using namespace coup;

TEST_CASE("Take Some Coins")
{
	Game gamee{};
	Duke duke1{gamee, "Ajwan"};
    Duke duke2{gamee, "Nadeen"};
	Assassin assassin1{ gamee, "Lelian"};
    Assassin assassin2{ gamee, "Jemy"};
	CHECK(duke1.coins() == 0);
    CHECK(duke2.coins() == 0);
    CHECK(assassin1.coins() == 0);
    CHECK(assassin2.coins() == 0);
    duke1.income();
    duke2.income();
    assassin1.foreign_aid();
    assassin2.foreign_aid();
    CHECK(duke1.coins() == 1);
	CHECK(duke1.coins() == 1);
	CHECK(assassin1.coins() == 2);
	CHECK(assassin2.coins() == 2);
	duke1.tax(); 
    duke1.tax();
	CHECK(duke1.coins() == 7); 
	CHECK_THROWS(duke2.income());
    CHECK_THROWS(duke1.income());
}

TEST_CASE("Compleex with blocks")
{
	Game gamee{};
	Duke duke{gamee, "Ajwan"};
	Assassin assassin{gamee, "Jemy"};
	Ambassador ambassador{gamee, "Lelian"};
	Captain captain{gamee, "Nadeen"};
	Contessa contessa{gamee, "Waseem"};
    CHECK(duke.coins() == 0);
    CHECK(assassin.coins() == 0);
    CHECK(captain.coins() == 0);
    CHECK(contessa.coins() == 0);
    CHECK(ambassador.coins() == 0);
	duke.income(); 
	assassin.foreign_aid();
	ambassador.foreign_aid(); 
    CHECK_THROWS(contessa.block(ambassador));
	CHECK_THROWS(duke.block(ambassador));
    CHECK(ambassador.coins() == 0);
	captain.foreign_aid(); 
	contessa.income(); 
	duke.income();
	assassin.foreign_aid();
	ambassador.foreign_aid();
	captain.income(); 
	contessa.income(); 
	duke.income(); 
    CHECK(duke.coins() >=1);
    CHECK(ambassador.coins() >= 2);
    CHECK(captain.coins() >=2);
	CHECK(assassin.coins() > 2); 
    CHECK(contessa.coins() >=1);
	CHECK(gamee.players().size() == 5); 
    CHECK_NOTHROW(assassin.coup(duke));
}