#include "Buildings.h"

int Buildings::getLumberCost() const { return lumberCost_; }

int Buildings::getGoldCost() const { return goldCost_; }

int Buildings::getTimeCost() const { return timeCost_; }

int Buildings::getGoldUpkeep() const { return goldUpkeep_; }

bool Buildings::operator<(const Buildings& other) const {
    return name_ < other.name_;
}

Buildings::Buildings(int lumberCost, int goldCost, int timeCost, int goldUpkeep,
                     const std::string& name)
    : lumberCost_(lumberCost),
      goldCost_(goldCost),
      timeCost_(timeCost),
      goldUpkeep_(goldUpkeep),
      name_(name){};

const Buildings Buildings::EXPLORATION = Buildings(0, 0, 5, 0, "EXPLORATION");
const Buildings Buildings::LUMBER = Buildings(0, 0, 0, 0, "LUMBER");
const Buildings Buildings::FISH = Buildings(0, 0, 0, 0, "FISH");
const Buildings Buildings::BREWERY = Buildings(0, 0, 0, 0, "BREWERY");
const Buildings Buildings::HIRD = Buildings(0, 0, 0, 0, "HIRD");
const Buildings Buildings::SHIP = Buildings(0, 0, 0, 0, "SHIP");
const Buildings Buildings::TOWNHALL = Buildings(0, 0, 0, 0, "TOWNHALL");
