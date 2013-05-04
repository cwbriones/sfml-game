#ifndef FPS_MANAGER
#define FPS_MANAGER

class FPSManager {
public:
	FPSManager(float fps);
	int tick(float time);
	void inc();
	void reset();
	float getActualFPS();
private:
	float fps_;
	float period_;
	int frames_;
	float lastTime_;
	float totalTime_;

	float actualFps_;
};

#endif