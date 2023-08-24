#include "NothingAction.h"

bool NothingAction::execute(
    GameState& gs, int currentTimeInSeconds,
    std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) {
    if (--secondsLeft <= 0) {
        return true;
    }
    return false;
}

NothingAction::NothingAction(int seconds) : secondsLeft(seconds) {}