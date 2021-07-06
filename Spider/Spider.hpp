//
//  Spider.hpp
//  Class for spider
//
//  Created by Валентина Протасеня on 7.04.21.
//

#ifndef Spider_hpp
#define Spider_hpp
#include "Foot.hpp"
#include <Spider_firmware.h>

class Spider {
    
private:
    static const int PINS_NUMBER = 3;
    static const int FOOT_NUMBER = 6;
    
    int pins_1[PINS_NUMBER] = {7,6,5};
    int pins_2[PINS_NUMBER] = {9,3,4};
    int pins_3[PINS_NUMBER] = {10,12,11};
    
    int pins_4[PINS_NUMBER] = {3,4,5};
    int pins_5[PINS_NUMBER] = {9,6,8};
    int pins_6[PINS_NUMBER] = {11,12,10};
    
    Foot spider_foot[FOOT_NUMBER];
    
public:
    
    Spider(PCA9685Servo* servo_board_0,PCA9685Servo* servo_board_1):
    spider_foot{ {servo_board_0, pins_1},
                 {servo_board_0, pins_2},
                 {servo_board_0, pins_3},
                 {servo_board_1, pins_4},
                 {servo_board_1, pins_5},
                 {servo_board_1, pins_6}}
    {
    }

    void SetInitialPosition();
    void StandUp();
    void Rise();
    void ChangeFootByHands();
    void BodyLift(int delay_value = 10, int lift_value = 30);
    void StepForward();
    void StepBackward();
};


#endif /* Spider_hpp */

