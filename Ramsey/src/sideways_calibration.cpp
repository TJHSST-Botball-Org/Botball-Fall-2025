#include <kipr/wombat.h>
#pragma once
#include <iostream>

int main(){
    int left_front_wheel_pin = 0;
    int left_back_wheel_pin = 1;
    int right_front_wheel_pin = 2;
    int right_back_wheel_pin = 3;
    double distance = 1.0;
    cmpc(left_front_wheel_pin);
    cmpc(left_back_wheel_pin);
    cmpc(right_front_wheel_pin);
    cmpc(right_back_wheel_pin);
    while(get_digital_value(0) = 0){
        moter_power(left_front_wheel_pin,100);
        moter_power(left_back_wheel_pin,100);
        moter_power(right_front_wheel_pin,100);
        moter_power(right_back_wheel_pin,100);
        msleep(1);
    }
    int lf_position = get_motor_position_counter(left_front_wheel_pin);
    int lb_position = get_motor_position_counter(left_back_wheel_pin);
    int rf_position = get_motor_position_counter(right_front_wheel_pin);
    int rb_position = get_motor_position_counter(right_back_wheel_pin);

    std::cout << "lf ticks per inch: " << (lf_position/distance) << std::endl;
    std::cout << "lb ticks per inch: " << (lb_position/distance) << std::endl;
    std::cout << "rf ticks per inch: " << (rf_position/distance) << std::endl;
    std::cout << "rb ticks per inch: " << (rb_position/distance) << std::endl;
}