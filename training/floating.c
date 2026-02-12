#include <stdio.h>
#include <stdint.h>
#include <string.h>

float str2float(const char str[34])
{
	uint32_t	nbr = 0;
	float		result;
	int i = 0;
	int j = 0;
	while (i < 34)
	{
		if (str[i] != ' '){
			nbr |= (uint32_t)(str[i] == '1') << (31 - j);
			j++;
		}
		i++;
	}
	memcpy(&result, &nbr, sizeof(float));
	printf("string: %s\tvalue: %2.90f\n", str, result);
	return (result);
}


int main()
{
	float zero;
	uint32_t int_rep;
	
	str2float( "1 01111111 00000000000000000000000");
	str2float( "0 00000000 00000000000000000000000");
	str2float( "0 01111111 00000000000000000000000");
	str2float( "0 11111111 00000000000000000000000");
	str2float( "1 11111111 00000000000000000000000");
	str2float( "0 11111111 00000000000000000000001");
	str2float( "0 01111111 00000000000000000000001");
	str2float( "0 00000000 00000000000000000000001");
	str2float( "0 00000001 00000000000000000000001");
	str2float( "0 00000101 01000000000011111111111");
	str2float( "0 00001111 00000000000000000000001");
	str2float("0 10000000 00000000000000000000001");
	str2float("0 01111111 00000000000000000000000"); //01
	str2float("0 10000000 00000000000000000000000"); //02
	str2float("0 10000000 10000000000000000000000"); //03
	str2float("0 10000001 00000000000000000000000"); //04
	str2float("0 10000001 10000000000000000000000"); //06
	str2float("0 10000010 10000000000000000000000"); //12
	str2float("0 10000011 10000000000000000000000"); //24

	return (0);
}
// int_rep = 0 | (1u << 22);
// int_rep |= (1u << 25);
// memcpy(&zero, &int_rep, sizeof(zero));

// printf("value: %.50f\n", zero);