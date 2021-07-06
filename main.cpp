#include <Spider_firmware.h>
#include "Spider.hpp"
#include <iostream>

void SpiderMenu(Spider *spider);

int main(int argc, char **argv) {
    
    
    if (getuid() != 0) {
            fprintf(stderr, "Program is not started as \'root\' (sudo)\n");
            return -1;
    }
     
    if (bcm2835_init() != 1) {
            fprintf(stderr, "bcm2835_init() failed\n");
            return -2;
    }
    
    PCA9685Servo servo_board_0(0x40);
    PCA9685Servo servo_board_1(0x41);
    
    //servo board 0  baud rate init
    servo_board_0.SetLeftUs(600);
    servo_board_0.SetRightUs(2700);
    //servo board 1 baud rate init
    servo_board_1.SetLeftUs(600);
    servo_board_1.SetRightUs(2700);

    servo_board_0.Dump();
    servo_board_1.Dump();

    Spider spider(&servo_board_0, &servo_board_1);
    SpiderMenu(&spider);

    return 0;
}


void SpiderMenu(Spider *spider) {
    
    int answer;
    bool is_exit = false;
    
    while(!is_exit) {
        
        std::cout<<"1. Initial position\n";
        std::cout<<"2. Rise\n";
        std::cout<<"3. Stand up\n";
        std::cout<<"4. Step forward\n";
        std::cout<<"5. Step backward\n";
        std::cout<<"6. Change foot by hands\n";
        std::cout<<"7. Exit\n\n";
        
        std::cin>>answer;

        switch (answer) {
            case 1:
                spider->SetInitialPosition();
                break;
                
            case 2:
                spider->Rise();
                break;
        
            case 3:
                spider->StandUp();
                break;
                
            case 4:
                spider->StepForward();
                break;
                
            case 5:
                spider->StepBackward();
                break;
                
            case 6:
                spider->ChangeFootByHands();
                break;
                
            case 7:
                is_exit = true;
                break;
        }
    }
}

