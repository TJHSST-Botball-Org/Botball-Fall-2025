#include <iostream>
#include <kipr/wombat.h>
#include <Remy.h>

//constants for robot speed
const float slow = 400;
const float medium = 400;
const float fast = 800;
//constants for sensor ports
const float front = 0;
const float left_side = 1;
const float right_side = 2;
void p(std::string out) {
    std::cout << out << std::endl;
}

int main(){
    //initialize robot
    Remy robot;
    robot.set_arm(900, 1000);
    robot.set_claw(1200, 1000);
    //move out of start box and to botguy
    //move until you hit the front sensor on pvc pipe in front of botguy
    robot.rotate(108,medium);
    robot.move_till_sensor_forward(medium);
    
    //backup to position arm to grab botguy
    
    robot.move_distance(-1, medium);

    //bring down arm of claw to the height of botguy
    robot.set_arm(1900, 2000);
    robot.set_claw(750, 1000);
    
    robot.set_arm(1300, 1000);
	

    //move backwards to area to drop off botguy
    robot.move_distance(-27,medium);
    robot.rotate(-130, medium);
    robot.move_till_sensor_forward(medium);
    robot.set_arm(1800, 2000);
    robot.set_claw(1500, 1000);
    
    robot.move_distance(-1, medium);
    robot.rotate(108,medium);
    robot.move_till_sensor_forward(medium);
    

    //turn towards stove

    //move towards stove

    //drop off botguy
    robot.reset();

}
