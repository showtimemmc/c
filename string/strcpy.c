#include <stdio.h>
#include <stdlib.h>
/**
 * [mystrcpy description]
 * @param  src  [description]
 * @param  dest [description]
 * @return      [description]
 * BUGFIX:两个字符串地址重合时，拷贝出错
 */
char* mystrcpy(const char* src,char* dest)
{
	if (!src)
	{
		printf("src is null");
		return NULL;
	}
	int i=0;
	while(src[i] != '\0')
	{
		dest[i]=src[i];
		i++;		
	}
	return dest;
}
int main(int argc, char const *argv[])
{
	char* src="hello";
	char dest[]="aha bingo";
	printf("%s\n", dest);
	mystrcpy(src,dest);
	printf("%s\n", dest);
	return 0;
}