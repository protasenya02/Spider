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
    
    void ChangeFootPosition(int hip_angle, int knee_angle, int step_angle);
    void ChangeHip(int angle);
    void ChangeKnee(int angle);
    void ChangeStep(int angle);
};

#endif /* Foot_hpp */
