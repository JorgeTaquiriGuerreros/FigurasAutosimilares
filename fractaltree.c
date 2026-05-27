#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
  //caso base
  if (depth == 0 || length < 5)
    return ;
  turtleForward(turtle, length);

  //recursion
  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleRight(turtle, 60);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleLeft(turtle, 30);
  turtleBackward(turtle, length);
}

int main (void){
  TurtleApp *app = turtleAppCreate(500,500, "Fractal Tree");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  //turtleForward(t, 300.0f);
  fractalTree(t, 125.0f, 6);

 
  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}

