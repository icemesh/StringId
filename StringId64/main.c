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
	puts("========= StringId (FNV-1a) generator by icemesh =========");
	if(argc <= 0x1)
	{
		printf("%s usage: input_text ... \n", aArgv[0] );
		return 1;
	}
	else
	{
		for( int i = 1; i < argc; i++)
		{
#ifdef __WIN32__
			printf("%s -> #%.16llX\n",aArgv[i] ,ToStringId64(aArgv[i]) );
#else
			printf("%s -> #%.16lX\n",aArgv[i] ,ToStringId64(aArgv[i]) );
#endif
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
