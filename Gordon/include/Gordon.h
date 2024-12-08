#pragma once

/* This robot does the food tasks */
/* Speed is measured in inches per second */

class Gordon  {
private:
    constexpr static double LEFT_TICKS_PER_INCH = 225;
    constexpr static double RIGHT_TICKS_PER_INCH = 265.5;
    constexpr static double AXLE_LENGTH = 6.5; // Distance between the two wheels
    constexpr static double INCHES_PER_DEGREE = (3.14 * AXLE_LENGTH)/360.0;

    const static unsigned int left_wheel_pin = 3;
    const static unsigned int right_wheel_pin = 0;

    const static unsigned int arm_servo_pin = 1;
    const static unsigned int claw_servo_pin = 2;

    const static unsigned int close_servo_value = 2046;
    const static unsigned int open_servo_value = 1192;

    const static unsigned int stow_servo_value = 1750;
    const static unsigned int extend_servo_value = 0;

    const static unsigned int touch_sensor_pin = 0;

    const static int left_color_sensor = 1;
    const static int right_color_sensor = 0;
    const static int color_sensor_threshold = 1000;


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

    void line_up(int speed);
};