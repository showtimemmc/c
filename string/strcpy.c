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
	if (src ==NULL||dest==NULL)//assert(src!=NULL)&&assert(dest!=NULL)
	{
		printf("param error");
		return NULL;
	}
	int i=0;
	while(src[i] != '\0')
	{
		dest[i]=src[i];
		i++;		
	}
	dest[i]='\0';//防止输出dest地址上，新复制的字符串之后的字符
	return dest;
}

char* mystrcpy2(const char* src,char* dest)
{
	if (src== NULL||dest==NULL)
	{
		printf("param error");
		return NULL;
	}
	char* ret=dest;
	while((*dest++=*src++)!='\0');
	return ret;

}

int main(int argc, char const *argv[])
{
	char* src="hello";
	char dest[40];
	printf("%s\n", dest);
	mystrcpy(src,dest);
	printf("%s\n", dest);
	return 0;
}