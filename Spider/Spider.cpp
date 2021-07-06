//
//  Spider.cpp
//  spider
//
//  Created by Валентина Протасеня on 7.04.21.
//

#include "Spider.hpp"
#include <iostream>

void Spider::SetInitialPosition()
{
    spider_foot[0].ChangeFootPosition(65, 0, 80, 0);
    spider_foot[1].ChangeFootPosition(93, 0, 80, 0);
    spider_foot[2].ChangeFootPosition(85, 0, 80, 0);
    
    spider_foot[3].ChangeFootPosition(90, 180, 100, 0);
    spider_foot[4].ChangeFootPosition(95, 180, 100, 0);
    spider_foot[5].ChangeFootPosition(90, 180, 100, 0);
}

void Spider::Rise()
{
    delay(100);
    
    // leg 0
    spider_foot[0].ChangeFootPosition(65, 0, 90, 20);
    spider_foot[0].ChangeFootPosition(65, 45, 90, 20);

    // leg 1
    spider_foot[1].ChangeFootPosition(93, 0, 90, 20);
    spider_foot[1].ChangeFootPosition(93, 51, 90, 20);
    
    // leg 2
    spider_foot[2].ChangeFootPosition(85, 0, 90, 20);
    spider_foot[2].ChangeFootPosition(85, 44, 90, 20);

    // leg 3
    spider_foot[3].ChangeFootPosition(90, 180, 60, 20);
    spider_foot[3].ChangeFootPosition(90, 159, 60, 20);

    // leg 4
    spider_foot[4].ChangeFootPosition(95, 180, 60, 20);
    spider_foot[4].ChangeFootPosition(95, 157, 60, 20);

    // leg 5
    spider_foot[5].ChangeFootPosition(90, 180, 60, 20);
    spider_foot[5].ChangeFootPosition(90, 159, 60, 20);
}

void Spider::BodyLift(int delay_value, int lift_value)
{
    for(int i = 0; i < FOOT_NUMBER; i++)
    {
       // delay(delay_value);
        if (i < 3) {
        spider_foot[i].ChangeFootPosition(spider_foot[i].GetHipAngle(),
                                          spider_foot[i].GetKneeAngle() + lift_value,
                                          spider_foot[i].GetStepAngle());
        } else {
            spider_foot[i].ChangeFootPosition(spider_foot[i].GetHipAngle(),
                                              spider_foot[i].GetKneeAngle() - lift_value,
                                              spider_foot[i].GetStepAngle());
        }
    }
}

void Spider::StandUp()
{

    BodyLift();
    
    int delay_value = 200;
    
    // legs lifting up
    spider_foot[0].ChangeFootPosition(65, 30, 50);
    spider_foot[2].ChangeFootPosition(85, 30, 50);
    spider_foot[4].ChangeFootPosition(95, 180, 90);

    delay(delay_value);

    // stable position
    spider_foot[0].ChangeFootPosition(65, 40, 128);
    delay(100);
    spider_foot[2].ChangeFootPosition(85, 25, 128);
    delay(100);
    spider_foot[4].ChangeFootPosition(95, 146, 45);
    
    delay(delay_value);

    // legs lifting up
    spider_foot[1].ChangeFootPosition(93, 30, 50);
    spider_foot[3].ChangeFootPosition(90, 180, 90);
    spider_foot[5].ChangeFootPosition(90, 180, 90);

    delay(delay_value);

    // stable position
    spider_foot[1].ChangeFootPosition(93, 35, 131);
    delay(100);
    spider_foot[3].ChangeFootPosition(90, 146, 45);
    delay(100);
    spider_foot[5].ChangeFootPosition(90, 146, 45);
}

void Spider::ChangeFootByHands()
{
    int foot_number = 0;
    std::cout<<"Foot number: ";
    std::cin>>foot_number;
    
    int angle_arr[3];
    
    std::cout<<"Hip: ";
    std::cin>>angle_arr[0];
    std::cout<<"Knee: ";
    std::cin>>angle_arr[1];
    std::cout<<"Step: ";
    std::cin>>angle_arr[2];
    
    spider_foot[foot_number].ChangeHip(angle_arr[0]);
    spider_foot[foot_number].ChangeKnee(angle_arr[1]);
    spider_foot[foot_number].ChangeStep(angle_arr[2]);
}


void Spider::StepForward()
{
    
    int delay_value = 150;
    int shift_value = 25;
    
    //-------------------------------------------------------------------------------
    // first pair 0,2,4
        
    // legs lifting up
    spider_foot[0].ChangeKnee(0);
    spider_foot[2].ChangeKnee(0);
    spider_foot[4].ChangeKnee(180);
    
    delay(delay_value);

    // legs move forward
    spider_foot[0].ChangeHip(spider_foot[0].GetHipAngle() - shift_value);
    spider_foot[2].ChangeHip(spider_foot[2].GetHipAngle() - shift_value);
    spider_foot[4].ChangeHip(spider_foot[4].GetHipAngle() + shift_value);

    delay(delay_value);

    // legs move backward
    spider_foot[1].ChangeHip(spider_foot[1].GetHipAngle() + shift_value);
    spider_foot[3].ChangeHip(spider_foot[3].GetHipAngle() - shift_value);
    spider_foot[5].ChangeHip(spider_foot[5].GetHipAngle() - shift_value);

    delay(delay_value);

    // legs move down
    spider_foot[0].ChangeKnee(40);
    spider_foot[2].ChangeKnee(25);
    spider_foot[4].ChangeKnee(146);

    delay(delay_value);

    //-------------------------------------------------------------------------------
    // second pair 1,3,5

    // legs lifting up
    spider_foot[1].ChangeKnee(0);
    spider_foot[3].ChangeKnee(180);
    spider_foot[5].ChangeKnee(180);

    delay(delay_value);

    // legs move forward
    spider_foot[1].ChangeHip(spider_foot[1].GetHipAngle() - shift_value);           // 93
    spider_foot[3].ChangeHip(spider_foot[3].GetHipAngle() + shift_value);           // 90
    spider_foot[5].ChangeHip(spider_foot[5].GetHipAngle() + shift_value);           // 90

    delay(delay_value);

    // legs move backward
    spider_foot[0].ChangeHip(spider_foot[0].GetHipAngle() + shift_value);           // 65
    spider_foot[2].ChangeHip(spider_foot[2].GetHipAngle() + shift_value);           // 85
    spider_foot[4].ChangeHip(spider_foot[4].GetHipAngle() - shift_value);           // 95

    delay(delay_value);

    // legs move down
    spider_foot[1].ChangeKnee(35);
    spider_foot[3].ChangeKnee(146);
    spider_foot[5].ChangeKnee(146);
    

    delay(delay_value);
}


void Spider::StepBackward()
{
    int delay_value = 150;
    int shift_value = 25;
    
    //-------------------------------------------------------------------------------
    // second pair 1,3,5

    // legs lifting up
    spider_foot[1].ChangeKnee(0);
    spider_foot[3].ChangeKnee(180);
    spider_foot[5].ChangeKnee(180);

    delay(delay_value);

    // legs move forward
    spider_foot[1].ChangeHip(spider_foot[1].GetHipAngle() + shift_value);           // 93
    spider_foot[3].ChangeHip(spider_foot[3].GetHipAngle() - shift_value);           // 90
    spider_foot[5].ChangeHip(spider_foot[5].GetHipAngle() - shift_value);           // 90

    delay(delay_value);

    // legs move backward
    spider_foot[0].ChangeHip(spider_foot[0].GetHipAngle() - shift_value);           // 65
    spider_foot[2].ChangeHip(spider_foot[2].GetHipAngle() - shift_value);           // 85
    spider_foot[4].ChangeHip(spider_foot[4].GetHipAngle() + shift_value);           // 95

    delay(delay_value);

    // legs move down
    spider_foot[1].ChangeKnee(35);
    spider_foot[3].ChangeKnee(146);
    spider_foot[5].ChangeKnee(146);
    

    delay(delay_value);
    
    //-------------------------------------------------------------------------------
    // first pair 0,2,4
        
    // legs lifting up
    spider_foot[0].ChangeKnee(0);
    spider_foot[2].ChangeKnee(0);
    spider_foot[4].ChangeKnee(180);
    
    delay(delay_value);

    // legs move forward
    spider_foot[0].ChangeHip(spider_foot[0].GetHipAngle() + shift_value);
    spider_foot[2].ChangeHip(spider_foot[2].GetHipAngle() + shift_value);
    spider_foot[4].ChangeHip(spider_foot[4].GetHipAngle() - shift_value);

    delay(delay_value);

    // legs move backward
    spider_foot[1].ChangeHip(spider_foot[1].GetHipAngle() - shift_value);
    spider_foot[3].ChangeHip(spider_foot[3].GetHipAngle() + shift_value);
    spider_foot[5].ChangeHip(spider_foot[5].GetHipAngle() + shift_value);

    delay(delay_value);

    // legs move down
    spider_foot[0].ChangeKnee(40);
    spider_foot[2].ChangeKnee(25);
    spider_foot[4].ChangeKnee(146);

    delay(delay_value);
    
}
