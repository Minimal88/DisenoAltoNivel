/* Tarea 5 - Técnicas de Adquisición y Procesamiento de Datos
 * Estudiante: Fabricio Quirós Corella
 * Fecha: 24-03-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Initial conditions equal zero */

/* Constants */
#define P 3 /* O, IIR filter order, following bi-quad configuration */
#define F 50.5 /* generate a random-float input signal */

/* Vectors initialization*/
int b[P] = {0}; /* p, coefficients vector */
int a[P] = {1, 0, 0}; /* q, coefficients vector */

int main ()
{
	srand((unsigned int)time(NULL));
	/* Constants */
	int order = P;
	
	/* User inputs */
	int size = 0;
	int b_coeff = 0;
	int a_coeff = 0;
	
	/* User interaction */
	printf("-- IIR Filter bi-quad implementation --");
	printf("\nEnter input size (N): ");
	scanf("%d", &size);
	printf("\nYou've entered the following size: %d\n\nFilling randomly the input vector ...\n", size);
	
	/* Update vectors - Memory allocation */
	float x[size]; /* input signal vector */
	memset(x, 0.0, size*sizeof(int));
	float y[size]; /* IIR filter output signal vector */
	memset(y, 0.0, size*sizeof(int));
	
	printf("x[n = %d] = %f\n", 0, x[0]);
	for (int in = 1 ; in < size ; in++)
	{
		/* Filling input vector */
		/* Random-float operation */
		x[in] = ((float)rand()/(float)(RAND_MAX)) * F;
		printf("x[n = %d] = %f\n", in, x[in]);
	}
	
	/* Update coefficients */
	for (int b_cont = 0 ; b_cont < order ; b_cont++)
	{
		printf("\nEnter b%d value: ", b_cont);
		scanf("%d", &b_coeff);
		b[b_cont] = b_coeff;
	}
	
	for (int a_cont = 1 ; a_cont < order ; a_cont++)
	{
		printf("\nEnter a%d value: ", a_cont);
		scanf("%d", &a_coeff);
		a[a_cont] = a_coeff;
	}
	
	printf("\nFilling coefficients 'b' and 'a' vectors ...\n");
	for (int print = 0 ; print < order ; print++)
	{	
		printf("b[p = %d] = %d   ||   a[q = %d] = %d\n", print, b[print], print, a[print]);
	}
	
	/* IIR Filter implementation */
	printf ("\n-- IIR filter output --\n");
	for (int n = 0 ; n < size ; n++)
	{
		float xN = 0; /* each value of FIR filter output vector  (first stage output) */
		float yN = 0; /* each value of IIR filter output vector  (second stage output) */
		
		/* IIR filter */
		for (int i = 0 ; i < order ; i++)
		{
			xN += b[i] * x[n-i];
		}
		
		for (int j = 1 ; j < order ; j++)
		{
			yN += a[j] * y[n-j];
		}
		
		yN = xN - yN;
		printf("y[n = %d] = %f\n", n, yN);
		y[n] = yN;
	}
	
	
	return 0;
}
