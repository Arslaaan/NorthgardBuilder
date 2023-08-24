#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "GameState.h"

class Action {
   public:
    virtual bool execute(
        GameState& gs, int currentTimeInSeconds,
        std::map<int, std::vector<std::shared_ptr<Action>>>& consequences);
};