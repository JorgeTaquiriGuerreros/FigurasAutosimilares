#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;

  if (depth >= 7)
    turtleSetColor(turtle, 90, 50, 20); //tronco marron
  else if (depth >= 4)
    turtleSetColor(turtle, 150, 90, 40); //ramas medianas marron clarito
  else
    turtleSetColor(turtle, 40, 180, 40); // ramas peque;as verdess

  turtleForward(turtle, length);

  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleRight(turtle, 60);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleLeft(turtle, 30);

  if (depth >= 7)
    turtleSetColor(turtle, 90, 50, 20);
  else if (depth >= 4)
    turtleSetColor(turtle, 150, 90, 40);
  else
    turtleSetColor(turtle, 40, 180, 40);

  turtleBackward(turtle, length); //para evitar que todo se repinte del mismo color
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

  turtleSetSpeed(t, 7.0f);

  fractalTree(t, 120.0f, 8);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
