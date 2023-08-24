#include "FinishBuilding.h"

FinishBuilding::FinishBuilding(Buildings building) : targetBuilding(building) {}

bool FinishBuilding::execute(GameState& gs, int currentTimeInSeconds,
                             std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) {
    if (gs.workingfreeVillages <= 0) {
        return false;
    }
    gs.workingfreeVillages--;
    gs.freeVillages++;

    constexpr double secondsInGameYear = 60 * 12.0;  // todo check
    gs.goldConsumption += targetBuilding.getGoldUpkeep() / secondsInGameYear;
    gs.gameMap.addBuilding(targetBuilding);
    return true;
}