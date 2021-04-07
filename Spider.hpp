//
//  Spider.hpp
//  spider
//
//  Created by Валентина Протасеня on 7.04.21.
//

#ifndef Spider_hpp
#define Spider_hpp

#include <Spider_firmware.h>
#include "Foot.hpp"

class Spider {
    
private:
    
    int pins_1[3] = {7,6,5};
    int pins_2[3] = {9,3,4};
    int pins_3[3] = {10,11,12};
    int pins_4[3] = {3,4,5};
    int pins_5[3] = {9,6,8};
    int pins_6[3] = {11,12,10};
    
    Foot spiderFoot[6];
    
public:
    
    Spider():
    spiderFoot[0] {&servo_board_0, pins_1},
    spiderFoot[1] {&servo_board_0, pins_2},
    spiderFoot[2] {&servo_board_0, pins_3},
    spiderFoot[3] {&servo_board_1, pins_4},
    spiderFoot[4] {&servo_board_1, pins_5},
    spiderFoot[5] {&servo_board_1, pins_6}
    {
    }

    void SetInitialPosition();
    void GetUp();
    
}


#endif /* Spider_hpp */
