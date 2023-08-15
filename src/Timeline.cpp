#include "Timeline.h"

Timeline::Timeline(Clan clan) {
    currentTimeInSeconds = 0;
    history.push_back(clan.getStartGameState());
}

// Timeline::Timeline(Clan clan, const BuildOrder& buildOrder)
//     : buildOrder_(buildOrder) {
//     currentTimeInSeconds = 0;
//     history.push_back(clan.getStartGameState());
// }

void Timeline::calculate(int seconds) {
    while (currentTimeInSeconds < seconds) {
        GameState nextGs = getGameState();
        nextGameStateUpdate(nextGs);
        history.push_back(nextGs);
        currentTimeInSeconds++;
    }
}

void Timeline::nextGameStateUpdate(GameState& gs) {
    if (!consequences.empty() &&
        consequences.begin()->first == currentTimeInSeconds) {
        // have consequences from past
        for (const auto& consequence : consequences.begin()->second) {
            consequence->execute(gs, currentTimeInSeconds, consequences);
        }
        consequences.erase(consequences.begin());
    }
    // try to execute buildOrder while it possible
    while (!buildOrder_.completed() &&
           buildOrder_.getFirst()->execute(gs, currentTimeInSeconds,
                                           consequences)) {
        buildOrder_.completeFirstAction();
    }
    gs.food += gs.calculateFoodIncome();
}

void Timeline::setBuildOrder(const BuildOrder& buildOrder) {
    buildOrder_ = buildOrder;
}

const GameState& Timeline::getGameState() const {
    return history.at(history.size() - 1);
}
