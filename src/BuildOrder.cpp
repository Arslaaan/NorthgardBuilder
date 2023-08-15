#include "BuildOrder.h"

BuildOrder::BuildOrder() {}

void BuildOrder::buildFree(Buildings building) {
    actions.push_back(
        std::make_unique<BuildAction>(building, BuildAction::Strategy::FREE));
}

BuildOrder& BuildOrder::operator=(const BuildOrder& other) {
    for (const auto& p : other.actions) {
        actions.push_back(p); // todo check
    }
    return *this;
}

const std::shared_ptr<Action>& BuildOrder::getFirst() const {
    return actions.front();
}
void BuildOrder::completeFirstAction() { actions.pop_front(); }
bool BuildOrder::completed() { return actions.empty(); };