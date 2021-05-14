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
    spider_foot[0].ChangeFootPosition(65, 30, 60);
    delay(100);
    spider_foot[0].ChangeFootPosition(65, 60, 90);
    
    spider_foot[1].ChangeFootPosition(93, 30, 60);
    delay(100);
    spider_foot[1].ChangeFootPosition(93, 60, 90);
    
    spider_foot[2].ChangeFootPosition(85, 30, 60);
    delay(100);
    spider_foot[2].ChangeFootPosition(85, 60, 90);
    
    
    spider_foot[3].ChangeFootPosition(90, 180, 90);
    delay(100);
    spider_foot[3].ChangeFootPosition(90, 150, 60);
    
    spider_foot[4].ChangeFootPosition(95, 180, 90);
    delay(100);
    spider_foot[4].ChangeFootPosition(95, 150, 60);

    spider_foot[5].ChangeFootPosition(90, 180, 90);
    delay(100);
    spider_foot[5].ChangeFootPosition(90, 150, 60);
}

void Spider::StandUp()
{
    
    // первые три ножки поднятие вверх
    spider_foot[0].ChangeFootPosition(65, 30, 50);
    spider_foot[2].ChangeFootPosition(85, 30, 50);
    spider_foot[4].ChangeFootPosition(95, 180, 90);
    
    delay(1000);
    
    // первые три ножки становление
    spider_foot[0].ChangeFootPosition(65, 40, 131);
    spider_foot[2].ChangeFootPosition(85, 25, 128);
    spider_foot[4].ChangeFootPosition(95, 146, 45);
    
    delay(500);
    
    // поднятие пузика
    spider_foot[0].ChangeFootPosition(65, 50, 131);
    spider_foot[1].ChangeFootPosition(93, 90, 90);
    spider_foot[2].ChangeFootPosition(85, 50, 128);
    
    spider_foot[3].ChangeFootPosition(90, 140, 60);
    spider_foot[4].ChangeFootPosition(95, 144, 45);
    spider_foot[5].ChangeFootPosition(90, 140, 60);
     
    
    delay(500);
    
    // вторые три ножки поднятие вверх
    spider_foot[1].ChangeFootPosition(93, 30, 50);
    spider_foot[3].ChangeFootPosition(90, 180, 90);
    spider_foot[5].ChangeFootPosition(90, 180, 90);
    
    delay(1000);
    
    // вторые три ножки становление
    spider_foot[1].ChangeFootPosition(93, 35, 131);
    spider_foot[3].ChangeFootPosition(90, 146, 45);
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

