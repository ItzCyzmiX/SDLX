

#include <SDLX/Timer.hpp>

Timer::Timer(float p_curTime, float p_decrasingSpeed) {


    initTime = p_curTime;
    elapsedTime = p_curTime;
    curTime = p_curTime;
    decreasingSpeed = p_decrasingSpeed;
    

}

void Timer::update() {
    
    if (curTime > 0) {
        curTime -= decreasingSpeed;
    }
    
    if (elapsedTime > initTime) {
        elapsedTime = initTime - curTime;
    }
}

bool Timer::hasEndded() {
    if (curTime <= 0) {
        return true;
    }
    else {
        return false;
    }
}

