//#pragma once
#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "geoLib.h"


ALLEGRO_DISPLAY *display;
#define XMAX D_WIDTH
#define YMAX D_HEIGHT
#define TRUE 1
#define FALSE 0
#define NMAX 255

void mandelbrot (double x0, double y0, double xf, double yf);

#endif // !
