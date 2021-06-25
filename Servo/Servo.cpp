//
//  Servo.cpp
//  Spider v2
//
//  Created by Валентина Протасеня on 14.05.21.
//

#include "Servo.hpp"

void Servo::ChangeAngle(int angle, int delay_value)
{
    if (angle_ != 0) {
        
        const int MIN_ANGLE = 5;

        int sign =  (angle_ < angle) ? 1 : -1;
        int angle_difference = std::abs(angle_ - angle);

        int interval_counter = angle_difference / MIN_ANGLE;

        for(int i = 1; i <= interval_counter; i++){
            servoboard_->SetAngle(CHANNEL(pin_), ANGLE(angle_ + sign * MIN_ANGLE * i));
            delay(delay_value);
        }
    }
    
    servoboard_->SetAngle(CHANNEL(pin_), ANGLE(angle));
    angle_ = angle;
}

int Servo::GetAngle()
{
    return angle_;
}
