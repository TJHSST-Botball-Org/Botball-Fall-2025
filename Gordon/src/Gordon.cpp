#include "Gordon.h"
#include <kipr/wombat.h>


Gordon::Gordon()
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
}

void Gordon::move_cont(double speed)
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
    
    mav(left_wheel_pin, speed*this->LEFT_TICKS_PER_INCH);
    mav(right_wheel_pin, speed*this->RIGHT_TICKS_PER_INCH);
}

void Gordon::move_distance(double distance, double speed)
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);

    mtp(left_wheel_pin, speed*LEFT_TICKS_PER_INCH, distance*LEFT_TICKS_PER_INCH);
    mtp(right_wheel_pin, speed*RIGHT_TICKS_PER_INCH, distance*RIGHT_TICKS_PER_INCH);

    while (!(get_motor_done(this->left_wheel_pin) || get_motor_done(this->right_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Gordon::rotate(double degrees, double speed)
{
    double left_ticks_speed = speed*LEFT_TICKS_PER_INCH;
    double right_ticks_speed = speed*RIGHT_TICKS_PER_INCH;

    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);

    mtp(left_wheel_pin, left_ticks_speed, degrees*INCHES_PER_DEGREE*LEFT_TICKS_PER_INCH);
    mtp(right_wheel_pin, right_ticks_speed, -degrees*INCHES_PER_DEGREE*RIGHT_TICKS_PER_INCH);

    while (!(get_motor_done(this->left_wheel_pin) || get_motor_done(this->right_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Gordon::stop()
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);

    motor_power(left_wheel_pin, 0);
    motor_power(right_wheel_pin, 0);
}

void Gordon::open_claw()
{
    enable_servo(claw_servo_pin);
    set_servo_position(claw_servo_pin, open_servo_value);
    msleep(1000);
}

void Gordon::close_claw()
{
    enable_servo(claw_servo_pin);
    set_servo_position(claw_servo_pin, close_servo_value);
    msleep(1000);
}

void Gordon::stow_arm()
{
    enable_servo(arm_servo_pin);
    set_servo_position(arm_servo_pin, stow_servo_value);
    msleep(1000);
}

void Gordon::extend_arm()
{
    enable_servo(arm_servo_pin);
    set_servo_position(arm_servo_pin, extend_servo_value);
    msleep(1000);
}

bool Gordon::is_sensor_touch()
{
    return get_digital_value(touch_sensor_pin);
}