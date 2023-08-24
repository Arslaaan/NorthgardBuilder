#pragma once
#include <deque>
#include <string>

#include "Action.h"
#include "BuildAction.h"
#include "Buildings.h"
#include "NothingAction.h"

class BuildOrder {
   public:
   BuildOrder();
    // build on any free tile
    void buildFree(Buildings building);
    // do nothing some time in seconds
    void doNothing(int seconds);
    BuildOrder& operator=(const BuildOrder&);
    const std::shared_ptr<Action>& getFirst() const;
    void completeFirstAction();
    bool completed();

   private:
    std::deque<std::shared_ptr<Action>> actions;
};