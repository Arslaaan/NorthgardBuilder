#pragma once
#include "NgbConfig.h"
#include "Tile.h"

struct GameState {
    double food;
    double gold;
    double lumber;

    double goldConsumption; // goldConsumption in second

    int freeVillages;
    int allVilages;
    int workingfreeVillages;
    int ghosts;

    Tile gameMap; // todo add support several tiles
    // common state for all clans
    GameState();

    double calculateFoodIncome();
};