#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  clear_screen(s);

  //triangle
  draw_line(200, 200, 300, 200, s, c);
  draw_line(250, 300, 300, 200, s, c);
  draw_line(200, 200, 250, 300, s, c);

  //ray
  draw_line(0, 200, 225, 250, s, c);

  //refract I
  for (int i = -10; i < 10; i += 4) {
    draw_line(225, 250, 250, 250 + i, s, c);
  }

  //refract II
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  for (int i = 0; i < 5; i ++) {
    draw_line(270 + i, 260 - i, 500, 225 - i, s, c);
  }

  c.green = 153;
  for (int i = 0; i < 5; i ++) {
    draw_line(273 + i, 255 - i, 500, 220 - i, s, c);
  }

  c.green = 255;
  for (int i = 0; i < 5; i ++) {
    draw_line(276 + i, 250 - i, 500, 215 - i, s, c);
  }

  c.red = 0;
  c.green = 102;
  for (int i = 0; i < 5; i ++) {
    draw_line(279 + i, 245 - i, 500, 210 - i, s, c);
  }

  c.red = 51;
  c.green = 153;
  c.blue = 255;
  for (int i = 0; i < 5; i ++) {
    draw_line(282 + i, 240 - i, 500, 205 - i, s, c);
  }

  c.red = 153;
  c.green = 51;
  c.blue = 255;
  for (int i = 0; i < 5; i ++) {
    draw_line(285 + i, 235 - i, 500, 200 - i, s, c);
  }

  display(s);
  save_extension(s, "lines.png");
}
