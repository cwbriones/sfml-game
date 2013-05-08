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
private:
    sf::Time totalTime_;
    sf::Clock clock_;

    sf::Time drawperiod_;
    sf::Time updateperiod_;

	float targetFps_;
    float actualFps_;
	int frames_;
    int skips_;
};

#endif
