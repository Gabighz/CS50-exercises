//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// Brick dimensions
#define BRICKWIDTH 45
#define BRICKHEIGHT 10

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // ball velocity
    double xvelocity = drand48();
    double yvelocity = drand48();
    
    //score
    points = 0;
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
    
    // PADDLE
    
        
        GEvent paddle_movement = getNextEvent(MOUSE_EVENT);

        
        if (paddle_movement != NULL)
        {
            
            if (getEventType(paddle_movement) == MOUSE_MOVED)
            {
                
                double x = getX(paddle_movement) - getWidth(paddle) / 2;
                double y = 500;
                setLocation(paddle, x, y);
            }
        }
     
    // END OF PADDLE
    
    // BALL 
     
     // move circle along x-axis and y-axis
         move(ball, xvelocity, yvelocity);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            xvelocity = -xvelocity;
        }
        
        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            xvelocity = -xvelocity;
        }
        // remove a life
        else if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            lives--;
            
            setLocation(ball, 190, 300);
            setLocation(paddle, 170,570);
            
            waitForClick();
        }
       pause(10);
       
    // END OF BALL
    
    // BALL COLLISION
   
    GObject object = detectCollision(window, ball);
    
    if (object != NULL)
    {
     
    if (object == paddle)
    {
     yvelocity= -yvelocity;
    } 
     
    else if (strcmp(getType(object), "GRect") == 0)
    {
     yvelocity = -yvelocity;
     removeGWindow(window,object);
     points = points + 1;
    }
    }
    
    // END OF BALL COLLISION
    
   
    }
    
    
 if(lives < 1)
    {
      closeGWindow(window);
      return 0;
    
    }
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
 // very proud of this !!
  for (int k = 0; k < ROWS; k++)
   {
    for (int i = 0; i < COLS; i++)
     {
     char* colors[] = { "RED","BLUE","GREEN","YELLOW","CYAN"};
     
       double x = k * BRICKWIDTH + (k*40);
       double y = i * BRICKHEIGHT + (i*10);
       
       GRect brick = newGRect(x, y, BRICKWIDTH,BRICKHEIGHT);
       setColor(brick, colors[k]);
       setFilled(brick, true);
       add(window, brick);
       
        }   
   }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(190, 300, 20, 20);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(170, 570, 50, 10);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setColor(label, "GRAY");
    setLocation(label, 200,300);
    add(window,label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
