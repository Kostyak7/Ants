#pragma once
#include <SFML/Graphics.hpp>


class IWindowKeeper {
public:
	IWindowKeeper(const sf::VideoMode& mode, const std::string& title);
	virtual ~IWindowKeeper() = default;
protected:
	sf::RenderWindow m_window;
	sf::Clock m_clock;

	virtual void event_handling() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};
