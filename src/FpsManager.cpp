#include "FpsManager.h"

FpsManager::FpsManager(){
    frames_ = 0;
    skips_ = 0;
    currentFps_ = 0;
    currentUps_ = 0;
    averageFps_ = 0;
    averageUps_ = 0;
    totalTime_ = sf::Time::Zero;

    storeCount_ = 0;
    storeMax_ = 30;
    storeFull_ = false;

    resetStoredStats();
}

void FpsManager::tick(const sf::Time& delta){ 
    totalTime_ += delta;
    frames_++;

    if(totalTime_.asSeconds() > 1.0f){
        store();
    }
}

void FpsManager::store(){
	currentFps_ = frames_/totalTime_.asSeconds();
    currentUps_ = (frames_ + skips_)/totalTime_.asSeconds();

    totalTime_ = sf::Time::Zero;
	frames_ = 0;
    skips_ = 0;

    fpsStore_[storeCount_] = currentFps_;
    upsStore_[storeCount_] = currentUps_;
    storeCount_++;

    if (storeCount_ == storeMax_){
        storeCount_ = 0;
        storeFull_ = true;
    }

    float totalFps_ = 0.0f;
    float totalUps_ = 0.0f;
    int storeSize_ = storeFull_ ? storeMax_ : storeCount_;

    for (int i = 0; i < storeSize_; i++){
        totalFps_ += fpsStore_[i];
        totalUps_ += upsStore_[i];
    }

    averageFps_ = totalFps_/storeSize_;
    averageUps_ = totalUps_/storeSize_;
}

sf::Time FpsManager::getTotalTime() const {
    return totalTime_;
}

float FpsManager::getCurrentFps() const {
	return currentFps_;
}

float FpsManager::getCurrentUps() const {
    return currentUps_;
}

float FpsManager::getAverageFps() const {
    return averageFps_;
}

float FpsManager::getAverageUps() const {
    return averageUps_;
}

void FpsManager::addSkips(int skips){
    skips_ += skips;
}

void FpsManager::resetStoredStats(){
    storeCount_ = 0;
    upsStore_.resize(storeMax_);
    fpsStore_.resize(storeMax_);
    storeFull_ = false;

    for(int i = 0; i < storeMax_; i++){
        upsStore_[i] = 0.0f;
        fpsStore_[i] = 0.0f;
    }
}

void FpsManager::setStatSize(int size){
    storeMax_ = size;
    resetStoredStats();
}
