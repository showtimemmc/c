#include <stdio.h>
#include <stdlib.h>
char* mystrcpy(const char* src,char* dest)
{
	if (!src)
	{
		return NULL;
	}
	char* cursor=src;
	int i=0;
	while(*cursor != '\0')
	{
		dest[i]=*cursor;
		i++;
		cursor++;		
	}
	return dest;
}
int main(int argc, char const *argv[])
{
	char* src="hello";
	char* dest="It is a  new world";

	mystrcpy(src,dest);
	printf("%s\n", dest);
	return 0;
}