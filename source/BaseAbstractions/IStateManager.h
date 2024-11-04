#pragma once
#include <memory>

class IState;

class IStateManager {
public:
	IStateManager() = default;
	virtual ~IStateManager() = default;
	virtual void set_next_state(std::unique_ptr<IState>&& state) = 0;
};
