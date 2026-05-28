#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;
  
  turtleForward(turtle, length);
  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.6, depth - 1);
  
  turtleRight(turtle, 60);
  fractalTree(turtle, length * 0.6, depth - 1);
  
  turtleLeft(turtle, 30);
  turtleBackward(turtle, length);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(600, 600, "Fractal Tree");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 300.0f, 500.0f);
  turtlePenDown(t);

  turtleSetColor(t, 120, 70, 20);
  turtleSetSpeed(t, 5.0f);
  
  fractalTree(t, 100.0f, 7);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
