#include <math.h>
#include "turtlec.h"

void levy (Turtle *turtle, float length, int depth) {
  if (depth == 0) {
    turtleForward(turtle, length);
    return;
  }

  turtleLeft(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleRight(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(1200, 800, "Levy Curve");//mas grande ventana para visualizar bien la curva de levy

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 800.0f, 400.0f);
  turtleLeft(t, 180);// para orientar bien la curva de levy, ya que sino sale media torcida
  turtlePenDown(t);

  turtleSetColor(t, 255, 255, 255);
  turtleSetSpeed(t, 50.0f);

  levy(t, 350.0f, 11);//fui probando valores para profundidad y largo, son los que me convencieron mas, desde 13, se extiende mucho, y con 11 creo que es buen depth 

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}


