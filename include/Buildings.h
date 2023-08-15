#pragma once
#include <string>

class Buildings {
   public:
    static const Buildings EXPLORATION;
    static const Buildings LUMBER;
    static const Buildings FISH;
    static const Buildings BREWERY;
    static const Buildings HIRD;  // mb rename
    static const Buildings SHIP;
    static const Buildings TOWNHALL;

    int getLumberCost() const;
    int getGoldCost() const;
    int getTimeCost() const;
    int getGoldUpkeep() const;

    bool operator<(const Buildings& other) const;

   private:
    Buildings(int lumberCost, int goldCost, int timeCost, int goldUpkeep, const std::string& name);
        
    int lumberCost_;
    int goldCost_;
    int timeCost_;  // todo const for all clans ?
    int goldUpkeep_; // gold upkeep for year
    std::string name_; // preferly for sorting
};

// todo init buildings