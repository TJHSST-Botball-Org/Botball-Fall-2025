#include <iostream>
#include <kipr/wombat.h>
#include <Remy.h>

int main(){
    //initialize robot
    Remy robot;
    
    robot.move_distance(6, 1);

    robot.sideways_distance(6, 1);
}
