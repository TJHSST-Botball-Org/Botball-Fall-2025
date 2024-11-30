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

    mav(left_front_wheel_pin, speed*this->LEFT_FRONT_TICKS_PER_INCH);
    mav(left_back_wheel_pin, speed*this->LEFT_BACK_TICKS_PER_INCH);
    mav(right_front_wheel_pin, speed*this->RIGHT_FRONT_TICKS_PER_INCH);
    mav(right_back_wheel_pin, speed*this->RIGHT_BACK_TICKS_PER_INCH);
}

void Remy::move_distance(double distance, double speed)
{
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);

    mtp(left_front_wheel_pin, speed*this->LEFT_FRONT_TICKS_PER_INCH, distance*this->LEFT_FRONT_TICKS_PER_INCH);
    mtp(left_back_wheel_pin, speed*this->LEFT_BACK_TICKS_PER_INCH, distance*this->LEFT_BACK_TICKS_PER_INCH);
    mtp(right_front_wheel_pin, speed*this->RIGHT_FRONT_TICKS_PER_INCH, distance*this->RIGHT_FRONT_TICKS_PER_INCH);
    mtp(right_back_wheel_pin, speed*this->RIGHT_BACK_TICKS_PER_INCH, distance*this->RIGHT_BACK_TICKS_PER_INCH);

    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->left_back_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Remy::move_till_sensor(double sensor_pin, double speed)
{

}

void Remy::set_elbow(double servo_degree)
{

}

void Remy::set_claw(double servo_degree)
{
    
}

void Remy::sideways_cont(double speed){
    if (speed>0){
        mav(left_front_wheel_pin, speed*this->LEFT_FRONT_TICKS_PER_INCH);
        mav(left_back_wheel_pin, speed*this->LEFT_BACK_TICKS_PER_INCH*-1);
        mav(right_front_wheel_pin, speed*this->RIGHT_FRONT_TICKS_PER_INCH*-1);
        mav(right_back_wheel_pin, speed*this->RIGHT_BACK_TICKS_PER_INCH);
    }
    else if (speed<0){
        mav(left_front_wheel_pin, speed*this->LEFT_FRONT_TICKS_PER_INCH*-1);
        mav(left_back_wheel_pin, speed*this->LEFT_BACK_TICKS_PER_INCH);
        mav(right_front_wheel_pin, speed*this->RIGHT_FRONT_TICKS_PER_INCH);
        mav(right_back_wheel_pin, speed*this->RIGHT_BACK_TICKS_PER_INCH*-1);
    }
    else{
        mav(left_front_wheel_pin, 0);
        mav(left_back_wheel_pin, 0);
        mav(right_front_wheel_pin, 0);
        mav(right_back_wheel_pin, 0);
    }
}

void Remy::sideways_distance(double distance, double speed){
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);
    if (distance > 0) {
        mtp(left_front_wheel_pin, speed, distance*this->LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed*-1, distance*this->LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed*-1, distance*this->RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed, distance*this->RIGHT_BACK_TICKS_PER_INCH);
        
        
    }
    
    if (distance < 0) {
        mtp(left_front_wheel_pin, speed*-1, distance*this->LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed, distance*this->LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed, distance*this->RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed*-1, distance*this->RIGHT_BACK_TICKS_PER_INCH);
    }
    
    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->left_back_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin))){
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

    if (degrees < 0)
    {
        mtp(left_front_wheel_pin, speed*LEFT_FRONT_TICKS_PER_INCH, -degrees*inches_per_degree*LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed*LEFT_BACK_TICKS_PER_INCH, -degrees*inches_per_degree*LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed*RIGHT_FRONT_TICKS_PER_INCH, degrees*inches_per_degree*RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed*RIGHT_BACK_TICKS_PER_INCH, degrees*inches_per_degree*RIGHT_BACK_TICKS_PER_INCH);
    }
    else
    {
        mtp(left_front_wheel_pin, speed*LEFT_FRONT_TICKS_PER_INCH, degrees*inches_per_degree*LEFT_FRONT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed*LEFT_BACK_TICKS_PER_INCH, degrees*inches_per_degree*LEFT_BACK_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed*RIGHT_FRONT_TICKS_PER_INCH, -degrees*inches_per_degree*RIGHT_FRONT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed*RIGHT_BACK_TICKS_PER_INCH, -degrees*inches_per_degree*RIGHT_BACK_TICKS_PER_INCH);
    }

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

void Remy::open_claw()
{
    enable_servo(servo_pin);
    set_servo_position(servo_pin, open_servo_value);
    msleep(1000);
}

void Remy::close_claw()
{
    enable_servo(servo_pin);
    set_servo_position(servo_pin, close_servo_value);
    msleep(1000);
}

bool Remy::is_sensor_touch()
{
    return get_digital_value(touch_sensor_pin);
}
