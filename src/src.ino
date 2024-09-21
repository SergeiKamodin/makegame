#include "mg.h"

Graphics gfx; Joystick joy;

void readDataJoy()
{
    joy.updatePositionXY();
    
    if (joy.pressKeyA() == true)
    {
      gfx.print(13, (String)joy.posX1 + " | " + (String)joy.posY1, 0, 13, 13, 8);
    }
    else 
    {
      gfx.print(13, "no Joy", 0, 13, 13, 8);
      u8g2.drawFrame(5, joy.posY1, 5, 15);
    }
} 

void setup()
{
    gfx.initializationSystem();
}

void loop()
{
    gfx.render(readDataJoy);
}

