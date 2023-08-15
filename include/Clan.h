#pragma once
#include <set>

#include "Buildings.h"
#include "GameState.h"
#include "NgbConfig.h"

class Clan {
   public:
    static const Clan KRAKEN;

    GameState getStartGameState();

   private:
    Clan(std::set<Buildings> additionalBuildings,
         std::set<Buildings> missingBuildings, GameState startGameState);

    std::set<Buildings> allowedBuildings;
    GameState startGs;

    static Clan initKraken();
};