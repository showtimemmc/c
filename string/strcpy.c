#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
 * mystrcpy1 & mystrcpy2没有考虑内存可能有重叠的问题
 * @param  src  [description]
 * @param  dest [description]
 * @return      [description]
 * BUGFIX:当有内存重叠时，拷贝出错
 */
char* mystrcpy1(const char* src,char* dest)
{
	if (NULL == src || NULL == dest)//assert(src!=NULL),assert(dest!=NULL)  最好不哟啊写成!srcd的方式。隐式4类型转换有时会有依法发生
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
/**
 * 考虑内存重叠，错误提示，由用户自行调整
 * memcpy会自动为用户重新分配内存
 * @param  src  [description]
 * @param  dest [description]
 * @return      [description]
 */
char* mystrcpy(const char* src,char* dest)
{
	//assert(src!=NULL)&&assert(dest!=NULL);
	//地址重叠判断
	unsigned int size = strlen(src);//strlen 不计算'\0'
/*	
	if (dest<(src+size)||src<(dest+size))
	{
		printf("mem overlap\n");
		return NULL;
	}

	char* ret=dest;
	while((*dest++=*src++)!='\0');

	return ret;

*/
	if (dest>src+size||src>dest+size)
	{
		char* ret=dest;
		while((*dest++=*src++)!='\0');
		
		return ret;
		
	}
	else
	{
		printf("mem overlap\n");
		return NULL;
	}
	
}
/*********************************
          测试函数
**********************************/
/**
 * 输出数组内容
 * @param array [description]
 * @param size  [description]
 */
void printf_array(char* array,int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d:%c  ", i,array[i]);
	}
	printf("\n");
	return;
}
/**
 * 测试两个地址发生重叠时的场景
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test_mem_overlap(char* (*pfunc)(const char*,char*),char* src)
{

	printf("\n+++++++++++++test_mem_overlap:++++++++++++\n ");
	char* dest=src+1;
	pfunc(src,dest);

    int size=strlen(dest);
    printf_array(dest,size);
}
/**
 * 测试两个地址发生重叠的边界情况，即src+size=dest
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test_mem_overlap_boundary(char* (*pfunc)(const char*,char*),char* src)
{
	printf("\n+++++++++++++test_mem_overlap_boundary:++++++++++++\n ");
	unsigned int size=strlen(src);
	char* dest=src+size;
	pfunc(src,dest);

	int dest_size=strlen(dest);
	printf_array(dest,dest_size);

}

/**
 *测试dest为数组时的情况
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test(char* (*pfunc)(const char*,char*),char* src)
{
	printf("\n+++++++++++++++++test_array:+++++++++++++\n");
	char dest[20]="11111111111111";



	int size=strlen(dest);
	printf("%d\n", size);

	pfunc(src,dest);

	//printf("%s\n", dest);
	//printf("Last:%c\n", dest[6]);
	
	printf_array(dest,size);
}
/**
 *测试原地址和目标地址相同
 *@param 函数指针，指向调用的strcpy版本
 *@param src 源地址
 */
void test_equal(char* (*pfunc)(const char*,char*),char* src)
{
	printf("\n+++++++++++++++++test_equal:+++++++++++++\n");
	char *dest=src;

	pfunc(src,dest);

}

int main(int argc, char const *argv[])
{
	char* src="hello";
	//char array[6]={'a','b','c','d','e','f'};
	//test_mem_overlap(mystrcpy1,src);
	test_equal(mystrcpy,src);
	//test(mystrcpy,src);
	//test_mem_overlap_boundary(mystrcpy,src);
	//test_mem_overlap(mystrcpy,src);
	return 0;
}