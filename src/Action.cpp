#include "Action.h"

bool Action::execute(GameState& gs, int currentTimeInSeconds, std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) const {
    std::cout << "Abstract action trying to execute" << std::endl;
    return false;
}
