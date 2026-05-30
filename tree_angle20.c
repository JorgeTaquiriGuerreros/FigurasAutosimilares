#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;
  
  turtleForward(turtle, length);
  turtleLeft(turtle, 20);
  fractalTree(turtle, length * 0.7, depth - 1);
  
  turtleRight(turtle, 40);
  fractalTree(turtle, length * 0.7, depth - 1);
  
  turtleLeft(turtle, 20);
  turtleBackward(turtle, length);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(1000, 800, "Fractal Tree");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 500.0f, 750.0f);
  turtleLeft(t, 90);
  turtlePenDown(t);

  turtleSetColor(t, 120, 70, 20);
  turtleSetSpeed(t, 7.0f);

  fractalTree(t, 120.0f, 8);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
