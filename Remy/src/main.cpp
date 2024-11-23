#include <iostream>
#include <kipr/wombat.h>
#include <Remy.h>

void p(std::string out) {
    std::cout << out << std::endl;
}

int main(){
    Remy robot;
    
    p("Moving forward");

    robot.move_distance(5, 1);
    robot.stop();
    
    p("Waiting 3 seconds");
    msleep(3000);

    p("Sideways for 3 seconds")
    robot.sideways_cont(1);
    msleep(3000);

    robot.stop();

}