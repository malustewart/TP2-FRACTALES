#include "Mandelbrot.h"
#include "geoLib.h"


int mandelbrot_set(double real, double imaginary, double maxValue, double pasoX, double pasoY);			//Mandelbrot: pinta los pixeles del display
double profManPix(double real, double imaginary, double maxValue, int nMax);							//revisa la profundidad del algoritmo
double granulacion(double p0, double pf, double resolucion);												//Granulacion de la pantalla y los pasos



void mandelbrot(double x0, double y0, double xf, double yf)
{
	double x0 = -2.0;
	double xf = 2.0;
	double y0 = -2.0;
	double yf = 2.0;
	//ejemplo de valores*/

	al_init();
	{
		display = al_create_display(XMAX, YMAX);
		//Crea un display pre-definido
		{
			al_clear_to_color(al_map_rgb(255, 255, 255));
			double rangeX = xf - x0;									//rango en el eje X
			double rangeY = yf - y0;									//rango en el eje y
			double granX = granulacion(x0, xf, XMAX);					//granulación en el eje X real
 			double granY = granulacion(y0, yf, YMAX);					//granulación en el eje Y imaginario
			double maxValue;											//valor máximo para la convergencia
			if(rangeX <= rangeY)
			{
				maxValue = sqrt(rangeY);
			}
			else 
			{
				maxValue = sqrt(rangeX);
			}

			mandelbrot_set(x0, y0, maxValue, granX, granY);

	
			al_flip_display();

			al_rest(5.0);
		}
		al_destroy_display(display);
		
	}
}


int mandelbrot_set(double Real, double Imaginary, double maxValue, double granX, double granY)
{
	int i, j;
	int IsMandelbrot = FALSE;
	double x0 = Real;
	double y0 = Imaginary;
	for (i = 0; i< XMAX; i++)		// barrido del display
	{
		Real = i * granX + x0;					// convierte las coordenadas a numeros complejos
		for (j = YMAX; j>0; j--)
		{
			Imaginary = j * granY + y0;

			IsMandelbrot = profManPix(Real, Imaginary, maxValue, NMAX);		//se fija la convergencia del punto del mapa complejo
		
			int R = (i + j) % NMAX;
			int G = (i - j) % NMAX;
			int B = (i * j) % NMAX;
			//Variaciones de colores para los puntos que no pertenecen al mandelbrot
		
			if(IsMandelbrot == FALSE)
			{
				al_put_pixel(i, j, al_map_rgb(R, G, B));
			}
			else 
			{
				al_put_pixel(i, j, al_map_rgb(0, 0, 0));
			}
		
		}
	}
	return 0;
}

double profManPix(double real, double imaginary, double maxValue, int nMax)
{
	int n=nMax;
	double ReTemp, result;
	double x0 = real;
	double y0 = imaginary;										//x0 e y0 son el punto minimo del plano complejo elejido
	double modulo=sqrt(real * real + imaginary * imaginary);
	while (n > 0 && modulo < maxValue)							//Se busca la profundidad del punto complejo z(real,imaginary)=z(i,j)
	{
		ReTemp = real * real - imaginary * imaginary + x0;
		imaginary = 2 * real * imaginary + y0;
		real = ReTemp;
		modulo = sqrt(real * real  + imaginary * imaginary);
		n--;
	}
	
	if(modulo < maxValue)										//Si el modulo es menor al valor fijado por el plano complejo elegido, converge
	{
		result = TRUE;
	}
	else if (modulo >= maxValue)								//Si el modulo es mayor igual al valor fijado por el plano complejo elejido, diverge
	{
		result = FALSE;
	}
	return result;
}


double granulacion(double p0, double pf, double resolucion)				//calculo de la granularidad en un eje
{
	double paso = (pf - p0) / resolucion;

	return paso;
}