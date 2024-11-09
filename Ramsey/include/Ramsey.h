#pragma once

/* This robot does the food tasks */
/* Speed is measured in inches per second */

class Ramsey  {
private:
    const static double LEFT_TICKS_PER_INCH = 0;
    const static double RIGHT_TICKS_PER_INCH = 0;

    const unsigned int left_wheel_pin = 0;
    const unsigned int right_wheel_pin = 0;

    const unsigned int servo_pin = 0;
    const unsigned int close_servo_value = 0;
    const unsigned int open_servo_value = 0;

    const unsigned int touch_sensor_pin = 0;

public:
    Ramsey();

    void move_cont(double speed);
    void move_distance(double distance, double speed);

    void sideways_cont(double speed);
    void sideways_distance(double distance, double speed);

    void rotate(double degrees, double speed); // Degrees per second

    void open_claw();
    void close_claw();

    void is_sensor_touch();
};