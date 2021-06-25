//
//  Servo.hpp
//  Class for one foot part
//
//  Created by Валентина Протасеня on 14.05.21.
//

#ifndef Servo_hpp
#define Servo_hpp
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
    
    void ChangeAngle(int angle, int delay_value = 32);
    int GetAngle();
};


#endif /* Servo_hpp */

