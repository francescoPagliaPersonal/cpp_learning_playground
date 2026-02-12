#include <stdint.h>
#include <stdio.h>
uint32_t refpoint = 8;

int fixsum(float a, float b)
{
	
}

int main()
{
	//number to represent 145.32
	int int_part = 145;
	int fract_part = 32;
	int fixed = 0;
	fixed |=  int_part << 8;
	int fraction = (fract_part << 8) / 100;
	fixed |= fraction;
	return 0;
}
// printf("starting number: %d.%d\n", fixed, fraction);