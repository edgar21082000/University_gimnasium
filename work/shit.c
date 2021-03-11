#include <stdio.h>

int main(void)
{
	double x, y, z;
	int	i, j;
	x=10.0;
	z=5.0;
	y=15.0;
	
	for (i=0;i<100; i++)
	{
		for (j=0;j<100;j++)
		{
			y+=0.1;
			printf("%25.12lf%25.12lf%25.12lf\n", x, y, z);
		}
		y=15.0;
		z+=0.1;
	}
	return 0;
}