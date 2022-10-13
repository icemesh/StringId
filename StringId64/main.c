/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/

#include <stdio.h>
#include <stdint.h>

inline uint64_t ToStringId64(const char* str);

int main(int argc, const char* aArgv[])
{
	if(argc <= 0x1)
	{
		 return 0;
	}
	else
	{
		for( int i = 1; i < argc; i++)
		{
			printf("#%.16llX -> %s\n", ToStringId64(aArgv[i]), aArgv[i] );
		}
		return 0;
	}
}

uint64_t ToStringId64(const char* str)
{
	uint64_t base = 0xCBF29CE484222325;
	if(*str)
	{
		do{
			base = 0x100000001B3 * (base ^ *str++);
		}while(*str);
	}
	return base;
}
