#include "GameState.h"

GameState::GameState() {
    freeVillages = NgbConfig::getInstance().getInt("startVillages");
    allVilages = freeVillages;
}

double GameState::calculateFoodIncome() {
    // todo
    double income =
        NgbConfig::getInstance().getDouble("basicVillageFoodIncome");
    return income * freeVillages -
           (0.01 * allVilages * allVilages + 1.35 * allVilages - 0.75) / 10;
}
