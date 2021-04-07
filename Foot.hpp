//
//  Foot.hpp
//  spider
//
//  Created by Валентина Протасеня on 1.04.21.
//

#ifndef Foot_hpp
#define Foot_hpp
#include <Spider_firmware.h>

class Servo {
    
private:
    PCA9685Servo* servoboard_;
    const int pin_;
    int angle_;
    
public:
    
    Servo(int pin, PCA9685Servo* servoboard):
    servoboard_{ servoboard },
    pin_{ pin },
    angle_{ 0 }
    {
    }
    
    void ChangeAngle(int angle){
        
        servoboard_->SetAngle(CHANNEL(pin_), ANGLE(angle));
        angle_ = angle;
        
    }
    
};

class Foot {
 
private:
    Servo hip;
    Servo knee;
    Servo step;

public:
    
    Foot(PCA9685Servo* servoboard, int pin[3]):
    hip(pin[0], servoboard),
    knee(pin[1], servoboard),
    step(pin[2], servoboard)
    {
    }
    
    void ChangeFootPosition(int hip_angle, int knee_angle, int step_angle);
    
    void ChangeHip(int angle);
    void ChangeKnee(int angle);
    void ChangeStep(int angle);
    
    
};



#endif /* Foot_hpp */
