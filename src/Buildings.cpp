#include "Buildings.h"

int Buildings::getLumberCost() const { return lumberCost_; }

int Buildings::getGoldCost() const { return goldCost_; }

int Buildings::getTimeCost() const { return timeCost_; }

int Buildings::getGoldUpkeep() const { return goldUpkeep_; }

bool Buildings::operator<(const Buildings& other) const {
    return name_ < other.name_;
}

Buildings::Buildings(const std::string& name)
    : lumberCost_(NgbConfig::getInstance().getInt(name + "Lumber")),
      goldCost_(NgbConfig::getInstance().getInt(name + "Gold")),
      timeCost_(NgbConfig::getInstance().getInt(name + "Time")),
      goldUpkeep_(NgbConfig::getInstance().getInt(name + "UpkeepD1")), // todo choose difficilty
      name_(name){};

const Buildings Buildings::EXPLORATION = Buildings("scoutCamp");
const Buildings Buildings::LUMBER = Buildings("woodCutter");
const Buildings Buildings::FISH = Buildings("fishingCabin");
const Buildings Buildings::BREWERY = Buildings("brewery");
const Buildings Buildings::HIRD = Buildings("herg");
const Buildings Buildings::SHIP = Buildings("longshipDock");
const Buildings Buildings::TOWNHALL = Buildings("townHall");
