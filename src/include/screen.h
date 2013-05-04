#ifndef SCREEN_H
#define SCREEN_H

class ScreenInterface {
public:
	virtual void render() = 0;
	virtual void respondToInput() = 0;
};

#endif //SCREEN_H