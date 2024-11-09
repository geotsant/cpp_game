#pragma once
#include <chrono>
#include <random>
#include <thread>

inline void sleep(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline float getRandomNumber() {
	std::random_device rd;   // Seed for random number generator
	std::mt19937 gen(rd());  // Mersenne Twister engine
	std::uniform_real_distribution<float> dis(0.1f, 1.0f);  // Range [0.1, 1.0]

	return dis(gen);
}

#define CANVAS_WIDTH 34.0f
#define CANVAS_HEIGHT 34.0f
//#define CANVAS_CENTER_X = CANVAS_WIDTH / 2
//#define CANVAS_CENTER_Y = CANVAS_HEIGHT / 2

#define ASSET_PATH ".\\assets\\"    //-------------------------------------------------------------------edw------------------------------------------------

#define PLAYER_SIZE 2.0f

#define SETCOLOR(c,r,g,b) {c[0] = r; c[1] = g; c[2] = b;}
#define RAND0TO1() (rand()/(float)RAND_MAX)

inline float distance(float x1, float y1, float x2, float y2) {
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}
