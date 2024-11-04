#pragma once
#include <memory>

class Context;

class IGameEvent {
public:
	virtual void handle(Context* context) = 0;
};