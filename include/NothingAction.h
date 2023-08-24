#pragma once
#include "Action.h"
#include "Buildings.h"
#include "FinishBuilding.h"
#include "Tile.h"

class NothingAction : public Action {
   public:
    virtual bool execute(GameState& gs, int currentTimeInSeconds,
                         std::map<int, std::vector<std::shared_ptr<Action>>>&
                             consequences) override;

    NothingAction(int seconds);

   private:
    int secondsLeft;
};