#include <Ramsey.h>
#include <kipr/wombat.h>


Ramsey::Ramsey()
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
}

void Ramsey::move_cont(double speed)
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
    mav(left_wheel_pin, speed*this->LEFT_TICKS_PER_INCH);
    mav(right_wheel_pin, speed*this->RIGHT_TICKS_PER_INCH);
}

void Ramsey::move_distance(double distance, double speed)
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
    mtp(left_wheel_pin, speed*this->LEFT_TICKS_PER_INCH, distance*this->LEFT_TICKS_PER_INCH);
    mtp(right_wheel_pin, speed*this->RIGHT_TICKS_PER_INCH, distance*this->RIGHT_TICKS_PER_INCH);

    if (!(get_motor_done(this->left_wheel_pin) || get_motor_done(this->right_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Ramsey::sideways_cont(double speed){
    if (speed=0){
        mav(left_front_wheel_pin, 0);
        mav(right_back_wheel_pin, 0);
        mav(right_front_wheel_pin, 0);
        mav(left_back_wheel_pin, 0);
    }
    else{
        mav(left_front_wheel_pin, speed*this->LEFT_TICKS_PER_INCH);
        mav(right_front_wheel_pin, speed*this->RIGHT_TICKS_PER_INCH*-1);
        mav(right_back_wheel_pin, speed*this->RIGHT_TICKS_PER_INCH);
        mav(left_back_wheel_pin, speed*this->LEFT_TICKS_PER_INCH*-1);
    }
}

void Ramsey::sideways_distance(double distance, double speed){
    cmpc(left_front_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_back_wheel_pin);
    if (distance > 0) {
        mtp(left_front_wheel_pin, speed, distance*this->LEFT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed, distance*this->RIGHT_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed*-1, distance*this->RIGHT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed*-1, distance*this->LEFT_TICKS_PER_INCH);
    }
    
    if (distance < 0) {
        mtp(left_front_wheel_pin, speed*-1, distance*this->LEFT_TICKS_PER_INCH);
        mtp(right_back_wheel_pin, speed*-1, distance*this->RIGHT_TICKS_PER_INCH);
        mtp(right_front_wheel_pin, speed, distance*this->RIGHT_TICKS_PER_INCH);
        mtp(left_back_wheel_pin, speed, distance*this->LEFT_TICKS_PER_INCH);
    }
    
    while (!(get_motor_done(this->left_front_wheel_pin) || get_motor_done(this->right_front_wheel_pin) || get_motor_done(this->right_back_wheel_pin) || get_motor_done(this->left_back_wheel_pin))){
        msleep(1);
    }
    stop();
}

void Ramsey::rotate(double degrees, double speed)
{
    double left_ticks_speed = speed*LEFT_TICKS_PER_INCH;
    double right_ticks_speed = speed*RIGHT_TICKS_PER_INCH;

    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);

    if (degrees < 0)
    {
        mtp(left_wheel_pin, left_ticks_speed, -degrees*inches_per_degree*LEFT_TICKS_PER_INCH);
        mtp(right_wheel_pin, right_ticks_speed, degrees*inches_per_degree*RIGHT_TICKS_PER_INCH);
    }
    else
    {
        mtp(left_wheel_pin, left_ticks_speed, degrees*inches_per_degree*LEFT_TICKS_PER_INCH);
        mtp(right_wheel_pin, right_ticks_speed, -degrees*inches_per_degree*RIGHT_TICKS_PER_INCH);
    }

    if (!(get_motor_done(this->left_wheel_pin) || get_motor_done(this->right_wheel_pin)))
    {
        msleep(1);
    }

    stop();
}

void Ramsey::stop()
{
    cmpc(left_wheel_pin);
    cmpc(right_wheel_pin);
    motor_power(left_wheel_pin, 0);
    motor_power(right_wheel_pin, 0);
}

void Ramsey::open_claw()
{
    enable_servo(servo_pin);
    set_servo_position(servo_pin, open_servo_value);
    msleep(1000);
}

void Ramsey::close_claw()
{
    enable_servo(servo_pin);
    set_servo_position(servo_pin, close_servo_value);
    msleep(1000);
}

bool Ramsey::is_sensor_touch()
{
    return get_digital_value(touch_sensor_pin);
}