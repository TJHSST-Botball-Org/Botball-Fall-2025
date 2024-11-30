#include <iostream>
#include <kipr/wombat.h>

int main()
{
    /*
    This code figures out the right ticks per inch values for both motors.

    1. Wire both motors so that a power of 100 for both motors is forward.
    2. Configure the pin variables.
    3. Move the robot a certain distance from a wall. Measure and record this 
       distance and store it into the DISTANCE constant.
    4. Run the program.
    */

    const int LEFT_WHEEL_PIN = 0;
    const int RIGHT_WHEEL_PIN = 3;
    const int TOUCH_SENSOR_PIN = 0;
    const double DISTANCE = 2;

    std::cout << "Left wheel is " << LEFT_WHEEL_PIN << "\n";
    std::cout << "Right wheel is " << RIGHT_WHEEL_PIN << "\n";
    std::cout << "Touch sensor is " << TOUCH_SENSOR_PIN << "\n";
    std::cout << "Starting in 2 seconds." << std::endl;

    msleep(2000);

    cmpc(LEFT_WHEEL_PIN);
    cmpc(RIGHT_WHEEL_PIN);
    motor_power(LEFT_WHEEL_PIN, 75);
    motor_power(RIGHT_WHEEL_PIN, 75);

    while (!get_digital_value(TOUCH_SENSOR_PIN))
    {
        msleep(1);
    }
    motor_power(LEFT_WHEEL_PIN, 0);
    motor_power(RIGHT_WHEEL_PIN, 0);

    std::cout << "Left wheel ticks per inch:" << gmpc(LEFT_WHEEL_PIN)/DISTANCE << "\n";
    std::cout << "Right wheel ticks per inch " << gmpc(RIGHT_WHEEL_PIN)/DISTANCE << "\n";
}