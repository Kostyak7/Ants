#pragma once
#include "IStateManager.h"


class IState {
public:
	IState(IStateManager* state_manager = nullptr)
		: m_state_manager(state_manager) {}
	virtual ~IState() = default;

	virtual bool do_step() = 0;
protected:
	IStateManager* m_state_manager;
};
