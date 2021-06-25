//
//  Foot.hpp
//  Class for one foot
//
//  Created by Валентина Протасеня on 1.04.21.
//

#ifndef Foot_hpp
#define Foot_hpp
#include <Spider_firmware.h>
#include "Servo.hpp"

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
    
    void ChangeFootPosition(int hip_angle, int knee_angle, int step_angle, int delay_value = 32);
    void ChangeHip(int angle, int delay_value = 5);
    void ChangeKnee(int angle, int delay_value = 5);
    void ChangeStep(int angle, int delay_value = 5);
    int GetHipAngle();
    int GetKneeAngle();
    int GetStepAngle();

    
};

#endif /* Foot_hpp */
