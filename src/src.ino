#include "mg.h"

Graphics gfx; Joystick joy; int score1{}, score2{};

void drawField()
{
  u8g2.drawHLine(0, 0, 128);
  u8g2.drawHLine(0, 63, 128);

  for (int i = 0; i <= 64; i = i + 6)
  {
    u8g2.drawVLine(64, i, 4);
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
  u8g2.drawBox(xBall, yBall, 4, 4); xBall += xx; yBall += yy;

  /* x */
  if (xBall > 127) xx = -2;
  //if (xBall < 0) xx = 2;
  /* y */
  if (yBall > 63) yy = -1;
  if (yBall < 0) yy = 1;
}

void calculation()
{
  //0
  if ((xBall < 10) && (xBall > 5))
  {
    if ((yBall == joy.posY0) && yBall <= (joy.posY0 + 10)) xx = 2;
  }
  
  //1
  if ((xBall > 117) && (xBall < 122))
  {
    if ((yBall == joy.posY1) && yBall <= (joy.posY1 + 10)) xx = -2;
  }

  
  //если мячик улетел то сбрасываем координаты мячика
}

void gamePong()
{
  drawField();
  drawRackets();
  drawBall(); calculation();
}

void setup()
{
  gfx.initializationSystem();
}

void loop()
{
  gfx.render(gamePong, 10);
}