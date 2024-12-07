#include <Remy.h>
#include <kipr/wombat.h>
#include <iostream>

Remy::Remy()
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);
}

void Remy::move_cont(double speed)
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);

    mav(left_front_wheel_pin, speed * this->LEFT_FRONT_TICKS_PER_INCH);
    mav(left_back_wheel_pin, speed * this->LEFT_BACK_TICKS_PER_INCH);
    mav(right_front_wheel_pin, speed * this->RIGHT_FRONT_TICKS_PER_INCH);
    mav(right_back_wheel_pin, speed * this->RIGHT_BACK_TICKS_PER_INCH);
}

void Remy::move_distance(double distance, double speed)
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);

    mtp(left_front_wheel_pin, speed * this->LEFT_FRONT_TICKS_PER_INCH, distance * this->LEFT_FRONT_TICKS_PER_INCH);
    mtp(left_back_wheel_pin, speed * this->LEFT_BACK_TICKS_PER_INCH, distance * this->LEFT_BACK_TICKS_PER_INCH);
    mtp(right_front_wheel_pin, speed * this->RIGHT_FRONT_TICKS_PER_INCH, distance * this->RIGHT_FRONT_TICKS_PER_INCH);
    mtp(right_back_wheel_pin, speed * this->RIGHT_BACK_TICKS_PER_INCH, distance * this->RIGHT_BACK_TICKS_PER_INCH);

    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->left_back_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Remy::move_till_sensor_forward(double speed){
    while(!get_sensor_front()){
        msleep(1);
        move_distance(0.1, speed);
    }
}
void Remy::move_till_sensor_right(double speed){
    while(!get_sensor_front()){
        msleep(1);
        move_distance(0.1, speed);
    }
}

void Remy::move_till_sensor_left(double speed){
    while(!get_sensor_front()){
        msleep(1);
        move_distance(0.1, speed);
    }
 }

void Remy::set_elbow(double servo_degree)
{
}

void Remy::set_claw(int position, int duration)
{
    enable_servo(claw_pin);
    int startPos = get_servo_position(claw_pin);
    int endPos = position;
    double deltaPos = (endPos - startPos) / (double)  duration;

    if ( startPos <= endPos ){      
        for(double currentPos = startPos; currentPos < endPos; currentPos += deltaPos){
            int pos = currentPos;
            msleep(1);
            set_servo_position(claw_pin, pos);    
        }
    }
    else{
        for(double currentPos = startPos; currentPos > endPos; currentPos += deltaPos ){
            int pos = currentPos;
            msleep(1);
            set_servo_position(claw_pin, pos);    
        }
    }

    set_servo_position(claw_pin, position);
}
void Remy::set_arm(int position, int duration)
{
    enable_servo(arm_pin);
    int startPos = get_servo_position(arm_pin);
    int endPos = position;
    double deltaPos = (endPos - startPos) / (double)  duration;

    if ( startPos <= endPos ){      
        for(double currentPos = startPos; currentPos < endPos; currentPos += deltaPos){
            int pos = currentPos;
            msleep(1);
            set_servo_position(arm_pin, pos);    
        }
    }
    else{
        for(double currentPos = startPos; currentPos > endPos; currentPos += deltaPos ){
            int pos = currentPos;
            msleep(1);
            set_servo_position(arm_pin, pos);    
        }
    }

    set_servo_position(arm_pin, position);
}
void Remy::set_sword(int position, int duration)
{
    enable_servo(sword_pin);
    int startPos = get_servo_position(sword_pin);
    int endPos = position;
    double deltaPos = (endPos - startPos) / (double)  duration;

    if ( startPos <= endPos ){      
        for(double currentPos = startPos; currentPos < endPos; currentPos += deltaPos){
            int pos = currentPos;
            msleep(1);
            set_servo_position(sword_pin, pos);    
        }
    }
    else{
        for(double currentPos = startPos; currentPos > endPos; currentPos += deltaPos ){
            int pos = currentPos;
            msleep(1);
            set_servo_position(sword_pin, pos);    
        }
    }

    set_servo_position(sword_pin, position);
}

void Remy::sideways_cont(double speed)
{
    if (speed > 0)
    {
        mav(left_front_wheel_pin, speed * this->LEFT_FRONT_TICKS_PER_INCH);
        mav(left_back_wheel_pin, speed * this->LEFT_BACK_TICKS_PER_INCH * -1);
        mav(right_front_wheel_pin, speed * this->RIGHT_FRONT_TICKS_PER_INCH * -1);
        mav(right_back_wheel_pin, speed * this->RIGHT_BACK_TICKS_PER_INCH);
    }
    else if (speed < 0)
    {
        mav(left_front_wheel_pin, speed * this->LEFT_FRONT_TICKS_PER_INCH * -1);
        mav(left_back_wheel_pin, speed * this->LEFT_BACK_TICKS_PER_INCH);
        mav(right_front_wheel_pin, speed * this->RIGHT_FRONT_TICKS_PER_INCH);
        mav(right_back_wheel_pin, speed * this->RIGHT_BACK_TICKS_PER_INCH * -1);
    }
    else
    {
        mav(left_front_wheel_pin, 0);
        mav(left_back_wheel_pin, 0);
        mav(right_front_wheel_pin, 0);
        mav(right_back_wheel_pin, 0);
    }
}

void Remy::sideways_distance(double distance, double speed)
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);
    if (distance > 0)
    {
        mtp(left_front_wheel_pin, speed*LEFT_FRONT_TICKS_PER_INCH, distance * this->LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed *LEFT_BACK_TICKS_PER_INCH, -1* distance * this->LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed *RIGHT_FRONT_TICKS_PER_INCH, -1* distance * this->RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed*RIGHT_BACK_TICKS_PER_INCH, distance * this->RIGHT_BACK_TICKS_PER_INCH);
    }

    if (distance < 0)
    {
        mtp(left_front_wheel_pin, speed * LEFT_FRONT_TICKS_PER_INCH, distance * this->LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed * LEFT_BACK_TICKS_PER_INCH, -1*distance * this->LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed * RIGHT_FRONT_TICKS_PER_INCH, -1*distance * this->RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed * RIGHT_BACK_TICKS_PER_INCH, distance * this->RIGHT_BACK_TICKS_PER_INCH);
    }

    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->left_back_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin)))
    {
        msleep(1);
    }
    stop();
}

void Remy::rotate(double degrees, double speed)
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);

    mtp(left_front_wheel_pin, speed * LEFT_FRONT_TICKS_PER_INCH, degrees * inches_per_degree * LEFT_FRONT_TICKS_PER_INCH);
    mtp(left_back_wheel_pin, speed * LEFT_BACK_TICKS_PER_INCH, degrees * inches_per_degree * LEFT_BACK_TICKS_PER_INCH);
    mtp(right_front_wheel_pin, speed * RIGHT_FRONT_TICKS_PER_INCH, -degrees * inches_per_degree * RIGHT_FRONT_TICKS_PER_INCH);
    mtp(right_back_wheel_pin, speed * RIGHT_BACK_TICKS_PER_INCH, -degrees * inches_per_degree * RIGHT_BACK_TICKS_PER_INCH);

    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->left_back_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Remy::stop()
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);
    motor_power(left_front_wheel_pin, 0);
    motor_power(left_back_wheel_pin, 0);
    motor_power(right_front_wheel_pin, 0);
    motor_power(right_back_wheel_pin, 0);
}

void Remy::open_claw(int duration)
{
    set_claw(claw_close_position, duration);
}

void Remy::close_claw(int duration)
{
    set_claw(claw_open_position, duration);
}

bool Remy::get_sensor_front()
{
    return get_digital_value(sensor_front_pin);
}

bool Remy::get_sensor_left()
{
    return get_digital_value(sensor_left_pin);
}

bool Remy::get_sensor_right()
{
    return get_digital_value(sensor_right_pin);
}
