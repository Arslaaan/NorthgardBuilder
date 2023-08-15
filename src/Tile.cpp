#include "Tile.h"

Tile::Tile() {
    // todo refactor after several tile support
    opened = true;
    completedBuildings.insert(Buildings::TOWNHALL);
}

int Tile::getMaxBuildings() const { return maxBuildings; }

bool Tile::isOpened() const { return opened; }

const std::set<Buildings>& Tile::getCompletedBuildings() const {
    return completedBuildings;
}

void Tile::addBuilding(Buildings building) {
    completedBuildings.insert(building);
}
