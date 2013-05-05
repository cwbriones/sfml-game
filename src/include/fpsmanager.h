#ifndef FPS_MANAGER
#define FPS_MANAGER

#include <SFML/Graphics.hpp>

class FpsManager {
public:
	FpsManager(float fps);

	int tick();
	void reset();

	float getActualFps() const;
    sf::Time getTotalTime() const;
    sf::Time getPeriod() const;
private:
    sf::Clock clock_;
    sf::Time totalTime_;

    sf::Time period_;

	float fps_;
	int frames_;
    int skips_;

	float actualFps_;
};

#endif
