#pragma once
#include "NgbConfig.h"
#include "Tile.h"

struct GameState {
    double food;
    double gold;
    double lumber;

    double goldConsumption; // goldConsumption in second todo delete and do gold calculate like food

    int freeVillages; // not working
    int allVilages;
    int workingfreeVillages; // free but building something
    int maxVillages; // max current size of villages
    int ghosts;


    Tile gameMap; // todo add support several tiles
    // common state for all clans
    GameState();

    double calculateFoodIncome();
};