#pragma once
#include <deque>
#include <string>

#include "Action.h"
#include "BuildAction.h"
#include "Buildings.h"

class BuildOrder {
   public:
   BuildOrder();
    void buildFree(Buildings building);
    BuildOrder& operator=(const BuildOrder&);
    const std::shared_ptr<Action>& getFirst() const;
    void completeFirstAction();
    bool completed();

   private:
    std::deque<std::shared_ptr<Action>> actions;
};