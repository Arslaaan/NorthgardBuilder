#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "GameState.h"

class Action {
   public:
    // explicit Action() = default;
    // Action(const Action&) = delete;
    // Action operator=(const Action&) = delete;
    // Action& operator=(const Action&) = delete;
    // const Action& operator=(const Action&) = delete;
    // ~Action() = default;
    virtual bool execute(
        GameState& gs, int currentTimeInSeconds,
        std::map<int, std::vector<std::shared_ptr<Action>>>& consequences) const;
};