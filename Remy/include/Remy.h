#pragma once

/* This robot does the food tasks */
/* Speed is measured in inches per second */

class Remy  {
private:
    // Left
    constexpr static double LEFT_FRONT_TICKS_PER_INCH = 173.4222222;
    constexpr static double LEFT_BACK_TICKS_PER_INCH = 210.4;

    // Right
    constexpr static double RIGHT_FRONT_TICKS_PER_INCH = 195.8666667;
    constexpr static double RIGHT_BACK_TICKS_PER_INCH = 211.5111111;

    constexpr static double AXLE_LENGTH = 8.0; // Distance between the two wheels
    constexpr static double inches_per_degree = (3.14 * AXLE_LENGTH)/360.0;

    constexpr static unsigned int left_front_wheel_pin = 1;
    constexpr static unsigned int right_front_wheel_pin = 0;
    constexpr static unsigned int right_back_wheel_pin = 2;
    constexpr static unsigned int left_back_wheel_pin = 3;

    constexpr static unsigned int servo_pin = 0;
    constexpr static unsigned int close_servo_value = 0;
    constexpr static unsigned int open_servo_value = 0;

    constexpr static unsigned int touch_sensor_pin = 0;

public:
    Remy();

    void move_cont(double speed);
    void move_distance(double distance, double speed);
    void move_till_sensor(double sensor_pin, double speed);
    void set_elbow(double servo_degree);

    void sideways_cont(double speed);
    void sideways_distance(double distance, double speed);

    void rotate(double degrees, double speed); // Degrees per second
                                               // Negative is CCW, Positive is CW

    void stop();

    void open_claw();
    void close_claw();
    void set_claw(servo_angle);

    bool is_sensor_touch();
};
