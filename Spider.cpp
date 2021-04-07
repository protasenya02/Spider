//
//  Spider.cpp
//  spider
//
//  Created by Валентина Протасеня on 7.04.21.
//

#include "Spider.hpp"

void Spider::SetInitialPosition()
{
    
    for(int i=0; i<3; i++){
        spiderFoot[i].ChangeFootPosition(90,0,0);
    };
    
    for(int i=3; i<3; i++){
        spiderFoot[i].ChangeFootPosition(90,180,180);
    };
}

void Spider::GetUp() { 
 
//    spiderFoot[0].ChangeFootPosition(90,0,0);
//    spiderFoot[1].ChangeFootPosition(90,0,0);
//    spiderFoot[2].ChangeFootPosition(90,0,0);
//    spiderFoot[3].ChangeFootPosition(90,0,0);
//    spiderFoot[4].ChangeFootPosition(90,0,0);
//    spiderFoot[5].ChangeFootPosition(90,0,0);
    
}

