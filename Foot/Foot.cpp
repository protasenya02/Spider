#include "Foot.hpp"
#include <iostream>

void Foot::ChangeFootPosition(int hip_angle, int knee_angle, int step_angle, int delay_value)
{
    hip.ChangeAngle(hip_angle, delay_value);
    knee.ChangeAngle(knee_angle, delay_value);
    step.ChangeAngle(step_angle, delay_value);
}

void Foot::ChangeHip(int angle, int delay_value)
{
    hip.ChangeAngle(angle, delay_value);
}

void Foot::ChangeKnee(int angle, int delay_value)
{
    knee.ChangeAngle(angle, delay_value);
}

void Foot::ChangeStep(int angle, int delay_value)
{
    step.ChangeAngle(angle, delay_value);
}

int Foot::GetHipAngle()
{
    return hip.GetAngle();
}

int Foot::GetKneeAngle()
{
    return knee.GetAngle();
}

int Foot::GetStepAngle()
{
    return step.GetAngle();
}


