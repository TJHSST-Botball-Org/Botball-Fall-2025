#include <iostream>
#include <kipr/wombat.h>
#include <Remy.h>

//constants for robot speed
const float slow = 200;
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
    
    //move out of start box and to botguy
    //move until you hit the front sensor on pvc pipe in front of botguy
    robot.move_till_sensor(front, medium);
    
    //backup to position arm to grab botguy
    robot.move_distance(-1, medium);

    //bring down arm of claw to the height of botguy
    robot.set_elbow(800);

    //set the claw closed around botguys eyes
    robot.set_claw(200);

    //raise arm with buy in grasp
    robot.set_elbow(1600);

    //move backwards to area to drop off botguy
    robot.move_distance(-30,slow);

    //turn towards stove
    robot.rotate(-120);

    //move towards stove
    robot.move_distance(4, slow);

    //drop off botguy
    robot.open_claw();


}
