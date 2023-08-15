#pragma once
#include <set>

#include "Buildings.h"

class Tile {
    std::set<Buildings> completedBuildings;
    int maxBuildings;
    bool opened;

   public:
    Tile();
    int getMaxBuildings() const;
    bool isOpened() const;
    const std::set<Buildings>& getCompletedBuildings() const;
    void addBuilding(Buildings building);
};