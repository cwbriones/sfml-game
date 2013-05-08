#include "fpsmanager.h"

FpsManager::FpsManager(float targetFps) : targetFps_(targetFps){

	frames_ = 0;
    skips_ = 0;
    actualFps_ = 0;
    totalTime_ = sf::Time::Zero;

    drawperiod_ = sf::milliseconds(0.9f*1000.0f/targetFps_);
    updateperiod_ = drawperiod_;
    clock_.restart();
}

int FpsManager::tick(){ 
    sf::Time elapsed = clock_.restart();
    totalTime_ += elapsed;
    frames_++;

    if(totalTime_.asSeconds() > 1.0f){
        reset();
    }
    
	return static_cast<int>(elapsed.asSeconds()/drawperiod_.asSeconds());	//updates missed
}

void FpsManager::reset(){
	actualFps_ = frames_/totalTime_.asSeconds();

    totalTime_ = sf::Time::Zero;
	frames_ = 0;
}

sf::Time FpsManager::getTotalTime() const {
    return totalTime_;
}

float FpsManager::getActualFps() const {
	return actualFps_;
}
