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

    const int LEFT_FRONT_WHEEL_PIN = 0;
    const int LEFT_BACK_WHEEL_PIN = 1;
    const int RIGHT_FRONT_WHEEL_PIN = 2;
    const int RIGHT_BACK_WHEEL_PIN = 3;


    const int TOUCH_SENSOR_PIN = 9;
    const double DISTANCE = 10;

    std::cout << "Left front wheel is " << LEFT_FRONT_WHEEL_PIN << "\n";
    std::cout << "Left back wheel is " << LEFT_BACK_WHEEL_PIN << "\n";

    std::cout << "Right front wheel is " << RIGHT_FRONT_WHEEL_PIN << "\n";
    std::cout << "Right back wheel is " << RIGHT_BACK_WHEEL_PIN << "\n";

    std::cout << "Touch sensor is " << TOUCH_SENSOR_PIN << "\n";
    std::cout << "Starting in 2 seconds." << std::endl;

    msleep(2000);

    cmpc(LEFT_FRONT_WHEEL_PIN);
    cmpc(LEFT_BACK_WHEEL_PIN);

    cmpc(RIGHT_FRONT_WHEEL_PIN);
    cmpc(RIGHT_BACK_WHEEL_PIN);
    
    motor_power(LEFT_FRONT_WHEEL_PIN, 100);
    motor_power(LEFT_BACK_WHEEL_PIN, 100);

    motor_power(RIGHT_FRONT_WHEEL_PIN, 100);
    motor_power(RIGHT_BACK_WHEEL_PIN, 100);

    while (!get_digital_value(TOUCH_SENSOR_PIN))
    {
        msleep(1);
    }

    motor_power(LEFT_FRONT_WHEEL_PIN, 0);
    motor_power(LEFT_BACK_WHEEL_PIN, 0);
    
    motor_power(RIGHT_FRONT_WHEEL_PIN, 0);
    motor_power(RIGHT_BACK_WHEEL_PIN, 0);

    std::cout << "Left front wheel ticks per inch:" << gmpc(LEFT_FRONT_WHEEL_PIN)/DISTANCE << "\n";
    std::cout << "Left back wheel ticks per inch:" << gmpc(LEFT_BACK_WHEEL_PIN)/DISTANCE << "\n";

    std::cout << "Right front wheel ticks per inch " << gmpc(RIGHT_FRONT_WHEEL_PIN)/DISTANCE << "\n";
    std::cout << "Right back wheel ticks per inch " << gmpc(RIGHT_BACK_WHEEL_PIN)/DISTANCE << "\n";
}