//#pragma once
#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>


ALLEGRO_DISPLAY *display;
#define XMAX 800
#define YMAX 800
#define TRUE 1
#define FALSE 0
#define NMAX 255

typedef struct {
	double x0;
	double y0;
	double xf;
	double yf;
}mandelbrot_t;



void mandelbrot (double x0, double y0, double xf, double yf);

#endif // !
