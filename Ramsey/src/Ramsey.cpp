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

void Ramsey::sideways_cont(){
    
}

void Ramsey::sideways_distance(double distance, double speed){

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