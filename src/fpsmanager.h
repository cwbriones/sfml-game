#ifndef FPS_MANAGER
#define FPS_MANAGER

#include <SFML/Graphics.hpp>
#include <vector>

class FpsManager {
public:
    FpsManager();

    void tick(const sf::Time& delta);
    void addSkips(int skips);
	void store();

    void resetStoredStats();
    void setStatSize(int size);

	float getCurrentFps() const;
    float getCurrentUps() const;
    float getAverageFps() const;
    float getAverageUps() const;

    sf::Time getTotalTime() const;
private:
    sf::Time totalTime_;

    float currentFps_;
    float currentUps_;
    float averageFps_;
    float averageUps_;

	int frames_;
    int skips_;

    std::vector<float> upsStore_;
    std::vector<float> fpsStore_;
    int storeCount_;
    int storeMax_;
    bool storeFull_;
};

#endif
