#include "fpsmanager.h"

FPSManager::FPSManager(float fps) : fps_(fps), period_(1.0/fps){
	frames_ = 0;
	lastTime_ = 0;
	totalTime_ = 0;
}

int FPSManager::tick(float time){
	float delta = time - lastTime_;
	lastTime_ = time;

	totalTime_ += delta;

	return int(delta * period_);	//updates missed
}

void FPSManager::reset(){
	actualFps_ = frames_/totalTime_;

	frames_ = 0;
	totalTime_ = 0;
}

void FPSManager::inc(){
	frames_++;
}

inline float FPSManager::getActualFPS(){
	return actualFps_;
}