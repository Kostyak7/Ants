#pragma once
#include "IState.h"
#include "IEvent.h"


class ICommand {
public:
	ICommand() = default;
	virtual ~ICommand() = default;
	virtual void execute() {}
};


class IChangeStateCommand : public ICommand {
public:
	IChangeStateCommand(IStateManager* state_manager)
		: m_state_manager(state_manager) {}
protected:
	IStateManager* m_state_manager;
};


class IEventCommand : public ICommand {
public:
	IEventCommand(std::unique_ptr<IEvent>&& event, Context* context)
		: m_event(std::move(event)), m_context(context) {}
	void execute() override {
		m_event->handle(m_context);
	}
protected:
	std::unique_ptr<IEvent> m_event;
	Context* m_context;
};
