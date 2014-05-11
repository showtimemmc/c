#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * [mystrcpy description]
 * @param  src  [description]
 * @param  dest [description]
 * @return      [description]
 * BUGFIX:当有内存重叠时，拷贝出错
 */
char* mystrcpy1(const char* src,char* dest)
{
	if (NULL == src || NULL == dest)//assert(src!=NULL)&&assert(dest!=NULL)  最好不哟啊写成!srcd的方式。隐式4类型转换有时会有依法发生
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
	if (NULL == src || NULL == dest)
	{
		printf("param error");
		return NULL;
	}
	char* ret=dest;//重要点：＋＋过后指针就移走了。所以要保留指针的初始位置
	while((*dest++=*src++)!='\0');
	
	return ret;
}
/*
char* strcpy(const char* src,char* dest)
{
	assert(src!=NULL)&&assert(dest!=NULL);
	unsigned int size = strlen(src)+1;//strlen 不计算'\0'
	if (src == dest)
	{
		return src;
	}
	else if (src > dest+size || src < dest-size)//不重叠
	{
		char* ret=dest;
		while((*dest++=*src++)!='\0')
		{
			return ret;
		}
	}
	else//重叠
	{
		char* s=src+size;
		char* d=dest+size;
		while(size--)
		{
			*d-- = *s--;
		}
		return dest;
	}
}*/
/*********************************
          测试函数
**********************************/
/**
 * 测试两个地址发生重叠时的场景
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test_mem_overlap(char* (*pfunc)(const char*,char*),char* src)
{

	printf("test_mem_overlap: ");
	char* dest=src+1;
	pfunc(src,dest);

    printf("%s\n", dest);
}
/**
 *测试dest为数组时的情况
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test_array(char* (*pfunc)(const char*,char*),char* src)
{
	printf("test_array: ");
	char dest[20]="yyyyyyyy";
	pfunc(src,dest);

	printf("%s\n", dest);
}


int main(int argc, char const *argv[])
{
	char* src="hello";

	//test_mem_overlap(mystrcpy1,src);
	test_array(mystrcpy1,src);
	return 0;
}