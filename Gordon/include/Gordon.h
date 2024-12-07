#pragma once

/* This robot does the food tasks */
/* Speed is measured in inches per second */

class Gordon  {
private:
    constexpr static double LEFT_TICKS_PER_INCH = 257.56;
    constexpr static double RIGHT_TICKS_PER_INCH = 235.793;
    constexpr static double AXLE_LENGTH = 6.5; // Distance between the two wheels
    constexpr static double INCHES_PER_DEGREE = (3.14 * AXLE_LENGTH)/360.0;

    constexpr static unsigned int left_wheel_pin = 0;
    constexpr static unsigned int right_wheel_pin = 3;

    constexpr static unsigned int arm_servo_pin = 0;
    constexpr static unsigned int claw_servo_pin = 0;
    constexpr static unsigned int close_servo_value = 0;
    constexpr static unsigned int open_servo_value = 0;

    constexpr static unsigned int touch_sensor_pin = 0;

public:
    Gordon();

    void move_cont(double speed);
    void move_distance(double distance, double speed);

    void rotate(double degrees, double speed); // Degrees per second
                                               // Negative is CCW, Positive is CW

    void stop();

    void open_claw();
    void close_claw();

    void stow_arm();
    void extend_arm();

    bool is_sensor_touch();
};