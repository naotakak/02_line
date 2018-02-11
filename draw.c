#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, A, B, d;

  if (x0 > x1) { //switch order of points
    draw_line(x1, y1, x0, y0, s, c);
  }
  x = x0;
  y = y0;
  B = -1 * (x1 - x);
  A = y1 - y;
  d = 2 * A + B;

  //octant I
  if (A >= 0 && (-1 * B) >= A) {
    while (x <= x1) {
      plot(s, c, x, y);
      if (d > 0) {
        y ++;
        d += (2 * B);
      }
      x ++;
      d += (2 * A);
    }
  }

  //octant II
  else if (A >= 0 && (-1 * B) <= A) {
    while (y <= y1) {
      plot(s, c, x, y);
      if (d < 0) {
        x ++;
        d += (2 * A);
      }
      y ++;
      d += (2 * B);
    }
  }

  //octant VIII
  else if (A < 0 && B <= A) {
    while (x <= x1) {
      plot(s, c, x, y);
      if (d > 0) {
        y --;
        d += (2 * B);
      }
      x ++;
      d -= (2 * A);
    }
  }

  //octant VII
  else if (A < 0 && B >= A) {
    while (y >= y1) {
      plot(s, c, x, y);
      if (d < 0) {
        x ++;
        d -= (2 * A);
      }
      y --;
      d += (2 * B);
    }
  }
}
