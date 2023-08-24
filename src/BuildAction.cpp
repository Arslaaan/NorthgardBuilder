#include "BuildAction.h"

bool BuildAction::execute(
    GameState& gs, int currentTimeInSeconds,
    std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) {
        //todo add tile size check
    if (gs.freeVillages == 0 || gs.gold - targetBuilding.getGoldCost() < 0 ||
        gs.lumber - targetBuilding.getLumberCost() < 0) {
        return false;
    }
    gs.freeVillages--;
    gs.workingfreeVillages++;
    gs.gold -= targetBuilding.getGoldCost();
    gs.lumber -= targetBuilding.getLumberCost();
    consequences[currentTimeInSeconds + targetBuilding.getTimeCost()].push_back(
        std::make_shared<FinishBuilding>(targetBuilding));
    return true;
}

BuildAction::BuildAction(Buildings target, Strategy strategy)
    : targetBuilding(target), targetStrategy(strategy) {}