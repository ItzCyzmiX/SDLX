#ifndef TIMER_HPP
#define TIMER_HPP

class Timer {
public:
    
    float initTime;
    float elapsedTime;
    float curTime;
    float decreasingSpeed;
    
    
    Timer(float p_curTime, float p_decrasingSpeed);
    
        
    bool hasEndded();

    void update();
    
private:


    
};

#endif /* TIMER_HPP */

