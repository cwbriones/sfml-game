#include "fpsmanager.h"

FpsManager::FpsManager(float fps) : fps_(fps){

	frames_ = 0;
    skips_ = 0;
    totalTime_ = sf::Time::Zero;
    clock_.restart();

    period_ = sf::milliseconds(0.9f*1000.0f/fps_);
}

int FpsManager::tick(){ 
    sf::Time elapsed = clock_.restart();

	totalTime_ += elapsed;
    frames_++;
    
	return static_cast<int>(elapsed.asSeconds()/period_.asSeconds());	//updates missed
}

void FpsManager::reset(){
	actualFps_ = frames_/totalTime_.asSeconds();

    totalTime_ = sf::Time::Zero;
	frames_ = 0;
}


sf::Time FpsManager::getTotalTime() const {
    return totalTime_;
}

sf::Time FpsManager::getPeriod() const {
    return period_;
}

float FpsManager::getActualFps() const {
	return actualFps_;
}
