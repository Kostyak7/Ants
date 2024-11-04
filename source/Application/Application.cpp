#include "Application.h"

#include <iostream>


Application::Application()
	: m_ptr_current_state(std::make_unique<MainMenuState>(this)) {}

void Application::set_next_state(std::unique_ptr<IState>&& state) {
	m_ptr_next_state.reset();
	m_ptr_next_state = std::move(state);
}

int Application::run() {
	try {
		while (m_ptr_current_state->do_step()) {
			apply_deffer_state_change();
		}
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cout << "Unknown exception\n";
		return 2;
	}
	return 0;
}

void Application::apply_deffer_state_change() {
	if (m_ptr_next_state) {
		m_ptr_current_state.swap(m_ptr_next_state);
	}
	m_ptr_next_state.reset();
}
