#include "mg.h"

Graphics gfx; Joystick joy;

void drawField()
{
  u8g2.drawHLine(0, 0, 128);
  u8g2.drawHLine(0, 64, 128);

  for (int i = 0; i <= 64; i = i + 6)
  {
    u8g2.drawVLine(64, 0, 4);
  }
}

void drawRackets()
{
  joy.updatePositionXY();                // update sticks

  u8g2.drawFrame(5, joy.posY0, 5, 10);   // l-stick
  u8g2.drawFrame(117, joy.posY1, 5, 10); // r-stick
}

int xBall{63}; int yBall{31}; int xx = 2, yy = 1;

void drawBall()
{
  u8g2.drawBox(xBall, yBall, 2, 2); xBall += xx; yBall += yy;

  /* x */
  if (xBall > 128) xx = -2;
  if (xBall < 0) xx = 2;
  /* y */
  if (yBall > 64) yy = -1;
  if (yBall < 0) yy = 1;
}

void gamePong()
{
  drawField();
  drawRackets();
  drawBall();
}

void setup()
{
  gfx.initializationSystem();
}

void loop()
{
  gfx.render(gamePong, 10);
}