#include <gtest/gtest.h>

#include "BuildOrder.h"
#include "Clan.h"
#include "NgbConfig.h"
#include "Timeline.h"

// Test current food without action on 4 villages after minute
TEST(Food, NoBuildings) {
    Timeline tl(Clan::KRAKEN);
    BuildOrder buildOrder;

    tl.setBuildOrder(buildOrder);
    tl.calculate(60);

    double villageConsumption = 4.81 / (4 * 10);
    double freeVillageFoodIncome =
        NgbConfig::getInstance().getDouble("basicVillageFoodIncome") -
        villageConsumption;
    ASSERT_DOUBLE_EQ(tl.getGameState().food, 60 * 4 * freeVillageFoodIncome);
}

// Test current food (with building exploration point at 0 second) after minute
// (4 villages)
TEST(Food, OneBuilding) {
    BuildOrder buildOrder;
    buildOrder.buildFree(Buildings::EXPLORATION);

    Timeline tl(Clan::KRAKEN);
    tl.setBuildOrder(buildOrder);
    tl.calculate(60);

    double villageConsumption = 4.81 / (4 * 10);
    double freeVillageFoodIncome =
        NgbConfig::getInstance().getDouble("basicVillageFoodIncome") -
        villageConsumption;
    ASSERT_DOUBLE_EQ(tl.getGameState().food,
                     (60 - Buildings::EXPLORATION.getTimeCost()) * 4 *
                             freeVillageFoodIncome +
                         Buildings::EXPLORATION.getTimeCost() *
                             (3 * freeVillageFoodIncome - villageConsumption));
}
