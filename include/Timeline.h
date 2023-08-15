#pragma once
#include <vector>

#include "BuildOrder.h"
#include "BuildAction.h"
#include "Clan.h"
#include "GameState.h"
#include "NgbConfig.h"

class Timeline {
   public:
    Timeline(Clan clan);
    // Timeline(Clan clan, const BuildOrder& buildOrder);

    void setBuildOrder(const BuildOrder& buildOrder);
    const GameState& getGameState() const;
    void calculate(int seconds);

    void nextGameStateUpdate(GameState& gs);

   private:
    std::vector<GameState> history;
    // second -> what should do in this second
    std::map<int, std::vector<std::shared_ptr<Action>>> consequences;
    BuildOrder buildOrder_;
    int currentTimeInSeconds;
};
