#include "Foot.hpp"

void Foot::ChangeFootPosition(int hip_angle, int knee_angle, int step_angle)
{
    
    hip.ChangeAngle(hip_angle);
    knee.ChangeAngle(knee_angle);
    step.ChangeAngle(step_angle);
    
}

void Foot::ChangeHip(int angle)
{
    hip.ChangeAngle(angle);
}

void Foot::ChangeKnee(int angle)
{
    knee.ChangeAngle(angle);
}

void Foot::ChangeStep(int angle)
{
    step.ChangeAngle(angle);
}




