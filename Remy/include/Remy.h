#pragma once

/* This robot does the food tasks */
/* Speed is measured in inches per second */

class Remy
{
private:
    // Left
    constexpr static double LEFT_FRONT_TICKS_PER_INCH = 173.64 + 12.5 - 10; //+100;
    constexpr static double LEFT_BACK_TICKS_PER_INCH = 198.8 + 12.5 - 10;

    // Right
    constexpr static double RIGHT_FRONT_TICKS_PER_INCH = 200.88 - 12.5 - 10; //-100;
    constexpr static double RIGHT_BACK_TICKS_PER_INCH = 212.16 - 12.5 - 10;  //-100;

    constexpr static double AXLE_LENGTH = 12.0; // Distance between the two wheels
    constexpr static double inches_per_degree = (3.14 * AXLE_LENGTH) / 360.0;

    constexpr static unsigned int left_front_wheel_pin = 0;
    constexpr static unsigned int left_back_wheel_pin = 1;
    constexpr static unsigned int right_front_wheel_pin = 2;
    constexpr static unsigned int right_back_wheel_pin = 3;

    constexpr static unsigned int servo_pin = 0;
    constexpr static unsigned int close_servo_value = 0;
    constexpr static unsigned int open_servo_value = 0;

    constexpr static unsigned int sensor_front_pin = 0;
    constexpr static unsigned int sensor_left_pin = 1;
    constexpr static unsigned int sensor_right_pin = 2;

    constexpr static unsigned int claw_pin = 2;
    constexpr static double claw_close_position = 0.00;
    constexpr static double claw_open_position = 0.00;

public:
    Remy();

    void move_cont(double speed);
    void move_distance(double distance, double speed);
    void move_till_sensor_forward(double speed);
    void move_till_sensor_right(double speed);
    void move_till_sensor_left(double speed);
    void set_elbow(double servo_degree);

    void sideways_cont(double speed);
    void sideways_distance(double distance, double speed);

    void rotate(double degrees, double speed); // Degrees per second
                                               // Negative is CCW, Positive is CW

    void stop();

    void set_arm(int position, int duration = 2000);

    void open_claw(int duration = 1000);
    void close_claw(int duration = 1000);
    void set_claw(int position, int duration = 1000);

    bool get_sensor_front();
    bool get_sensor_left();
    bool get_sensor_right();
};
