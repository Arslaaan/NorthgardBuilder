#pragma once
#include "Action.h"
#include "Buildings.h"
#include "FinishBuilding.h"
#include "Tile.h"

class BuildAction : public Action {
   public:
    enum Strategy {
        FREE  // build anywhere it can be build
    };

    virtual bool execute(
        GameState& gs, int currentTimeInSeconds,
        std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) override;

    BuildAction(Buildings building, Strategy strategy);

   private:
    Buildings targetBuilding;
    Strategy targetStrategy;
};