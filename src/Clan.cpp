#include "Clan.h"

GameState Clan::getStartGameState() { return startGs; }

Clan::Clan(std::set<Buildings> additionalBuildings,
           std::set<Buildings> missingBuildings, GameState startGameState)
    : allowedBuildings({// default buildings in all clans
                        Buildings::EXPLORATION, Buildings::BREWERY,
                        Buildings::HIRD, Buildings::LUMBER}),
      startGs(startGameState) {
    for (const auto& building : additionalBuildings) {
        allowedBuildings.insert(building);
    }
    for (const auto& building : missingBuildings) {
        allowedBuildings.erase(building);
    }
}

Clan Clan::initKraken() {
    GameState gs;

    gs.ghosts = NgbConfig::getInstance().getInt("krakenStartGhosts");

    return Clan({Buildings::FISH, Buildings::HIRD},
                {Buildings::BREWERY, Buildings::SHIP}, gs);
}

const Clan Clan::KRAKEN = Clan::initKraken();