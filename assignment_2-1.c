/* Name : Arijit Ghosh
Dept. - CSE
Roll : 35000121017
To do operations with Complex numbers
*/

#include <stdio.h>
#include <math.h>

struct complex
{
	float real;
	float img;
} c1, c2;

int main()
{
	float mod1, argu1, mod2, argu2;

	printf("** Enter Complex Number -1 **\n");
	printf("-- Real Part: ");
	scanf("%f", &c1.real);
	printf("-- Imaginary Part: ");
	scanf("%f", &c1.img);
	printf("** Enter Complex Number -2 **\n");
	printf("-- Real Part: ");
	scanf("%f", &c2.real);
	printf("-- Imaginary Part: ");
	scanf("%f", &c2.img);

	printf("Complex Number -1 : C1 - (%f) + (%f)i\n", c1.real, c1.img);
	printf("Complex Number -2 : C2 - (%f) + (%f)i\n", c2.real, c2.img);

	mod1 = pow((pow(c1.real, 2) + pow(c1.img, 2)), 0.5);
	mod2 = pow((pow(c2.real, 2) + pow(c2.img, 2)), 0.5);

	argu1 = atan(c1.img / c1.real);
	argu2 = atan(c2.img / c2.real);

	printf("Modulus of Complex Number-1 : |C1| - %f\n", mod1);
	printf("Modulus of Complex Number-2 : |C2| - %f\n", mod2);

	printf("Conjugate of Complex Number-1: C1 = (%f) + (%f)i\n", c1.real, -1 * c1.img);
	printf("Conjugate of Complex Number-2: C2 = (%f) + (%f)i\n", c2.real, -1 * c2.img);

	printf("Argument of Complex Number-1: ARG(C1)= %f\n", argu1);
	printf("Argument of Complex Number-2: ARG(C1) = %f\n", argu2);

	printf("Complex Number after Addition: (C1+C2) = (%f) + (%f)i\n", c1.real + c2.real, c1.img + c2.img);
	printf("Complex Number after Subtraction: (C1-C2) = (%f) + (%f)i\n", c1.real - c2.real, c1.img - c2.img);
	printf("Complex Number after Multiplication: (C1*C2) = (%f) + (%f)i\n", (c1.real * c2.real - c1.img * c2.img), (c1.real * c2.img + c2.real * c1.img));
	printf("Complex Number after Divison: (C1/C2) = (%f) + (%f)i\n", (c1.real * c2.real + c1.img * c2.img) / (pow(c2.real, 2) + pow(c2.img, 2)), (c1.img * c2.real - c1.real * c2.img) / (pow(c2.real, 2) + pow(c2.img, 2)));
	printf("Square of Complex Number-1 : C1^2 - (%f) + (%f)i\n", pow(c1.real, 2) - pow(c1.img, 2), 2 * c1.real * c1.img);
	printf("Square of Complex Number-2 : C2^2 - (%f) + (%f)i\n", pow(c2.real, 2) - pow(c2.img, 2), 2 * c2.real * c2.img);

	printf("Cube of Complex Number-1 : C1^3 - (%f) + (%f)i\n", (pow(c1.real, 3) - 3 * c1.real * pow(c1.img, 2)), 3 * pow(c1.real, 2) * c1.img - pow(c1.img, 3));
	printf("Cube of Complex Number-2 : C2^3 - (%f) + (%f)i\n", (pow(c2.real, 3) - 3 * c2.real * pow(c2.img, 2)), 3 * pow(c2.real, 2) * c2.img - pow(c2.img, 3));

	if (c1.img < 0)
		printf("Square root of Complex Number-1 : SQRT(C1) = (+/-) [(%f) + -(%f)i]\n", sqrt((c1.real + sqrt(pow(c1.real, 2) + pow(c1.img, 2))) / 2), sqrt((-c1.real + sqrt(pow(c1.real, 2) + pow(c1.img, 2))) / 2));
	else
		printf("Square root of Complex Number-1 : SQRT(C1) = (+/-) [(%f) + (%f)i]\n", sqrt((c1.real + sqrt(pow(c1.real, 2) + pow(c1.img, 2))) / 2), sqrt((-c1.real + sqrt(pow(c1.real, 2) + pow(c1.img, 2))) / 2));

	if (c2.img < 0)
		printf("Square root of Complex Number-2 : SQRT(C2) = (+/-) [(%f) + -(%f)i]\n", sqrt((c2.real + sqrt(pow(c2.real, 2) + pow(c2.img, 2))) / 2), sqrt((-c2.real + sqrt(pow(c2.real, 2) + pow(c2.img, 2))) / 2));
	else
		printf("Square root of Complex Number-2 : SQRT(C2) = (+/-) [(%f) + (%f)i]\n", sqrt((c2.real + sqrt(pow(c2.real, 2) + pow(c2.img, 2))) / 2), sqrt((-c2.real + sqrt(pow(c2.real, 2) + pow(c2.img, 2))) / 2));

	printf("Reciprocal of Complex Number-1 : 1/C1 = (%f) + (%f)i\n", c1.real / (pow(c1.real, 2) + pow(c1.img, 2)), -c1.img / (pow(c1.real, 2) + pow(c1.img, 2)));
	printf("Reciprocal of Complex Number-2 : 1/C2 = (%f) + (%f)i\n", c2.real / (pow(c2.real, 2) + pow(c2.img, 2)), -c2.img / (pow(c2.real, 2) + pow(c2.img, 2)));

	printf("Exponential of Complex Number-1 : e^-C1 = (%f) + (%f)i\n", exp(c1.real) * cos(c1.img), exp(c1.real) * sin(c1.img));
	printf("Exponential of Complex Number-1 : e^-C2 = (%f) + (%f)i\n", exp(c2.real) * cos(c2.img), exp(c2.real) * sin(c2.img));

	return 0;
}
