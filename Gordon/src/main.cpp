#include <kipr/wombat.h>
#include "Gordon.h"

int main()
{
    Gordon robot;
    
    robot.rotate(90, 3);
    msleep(1000);
    robot.rotate(-90,3);
    
    return 0;
}
