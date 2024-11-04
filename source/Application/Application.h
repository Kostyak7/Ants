#pragma once
#include "../BaseAbstractions/IState.h"


class Application : public IStateManager {
public:
	Application();

	void set_next_state(std::unique_ptr<IState>&& state) override;
	int run();
private:
	void apply_deffer_state_change();
private:
	std::unique_ptr<IState> m_ptr_current_state;
	std::unique_ptr<IState> m_ptr_next_state;
};
