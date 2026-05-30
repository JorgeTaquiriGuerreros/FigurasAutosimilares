#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;
  //establece color verde ramas, tronco marron
  if (depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else
    turtleSetColor(turtle, 0, 200, 0);
  
  turtleForward(turtle, length);

  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.7, depth - 1);
  
  turtleRight(turtle, 60);
  fractalTree(turtle, length * 0.7, depth - 1);
  
  turtleLeft(turtle, 30);
  
  if (depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else
    turtleSetColor(turtle, 0, 200, 0);
  //se fija color para las ramas y tronco
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
