#pragma once
#include "Action.h"
#include "Buildings.h"

class FinishBuilding : public Action {
   public:
    FinishBuilding(Buildings building);
    virtual bool execute(GameState& gs, int currentTimeInSeconds,
                         std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) override;

   private:
    Buildings targetBuilding;
};