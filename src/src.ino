#include "mg.h"

Graphics gfx;
Joystick joy;

int BallX = 63;
int BallY = 32;
int dx = 1, dy = 1;

short speedBallX = 2; short speedBallY = 1;


void drawRakets()
{
    joy.updatePositionXY();
    u8g2.drawFrame(5, joy.posY0, 5, 10);
    u8g2.drawFrame(117, joy.posY1, 5, 10);
}

void drawBall()
{
    u8g2.drawBox(BallX, BallY, 3, 3);
    
    if (BallX > 127 - 3)
    {
        dx = -1;
    }

    if (BallX < 0)
    {
        dx = 1;
    }

    if (BallY > 63  - 3)
    {
        dy = -1;
    }

    if (BallY < 0)
    {
        dy = 1;
    }

    BallX = BallX + speedBallX * dx;
    BallY = BallY + speedBallY * dy;
}

void drawField()
{
    u8g2.drawHLine(0, 0, 127);
    u8g2.drawHLine(0, 63, 127);
    for (int i = 0; i < 63; i += 6)
    {
        u8g2.drawVLine(63, i, 4);
    }
}

void Game()
{
    drawField();
    drawRakets();
    drawBall();
}

void setup()
{
    gfx.initializationSystem();
}

void loop()
{
    gfx.render(Game);
}
