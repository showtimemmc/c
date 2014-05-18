#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * [st_memcpy description]
 * @param destnation [description]
 * @param source     [description]
 * @param num        num of bytes to copy
 * @return           destination is returned
 * TODO：内存重叠的判断
 */
void* st_memcpy(void* destnation,const void* source,size_t num)
{
	if (destnation == NULL||source == NULL)
	{
		return NULL;
	}

	//void指针转换char型指针，因为char刚好是一个字节
	char* tmp_src=(void*)source;
	char* tmp_dest=(void*)destnation;
//another  expression
/*	for (int i = 0; i < num; ++i)
	{
		tmp_dest[i]=tmp_src[i];
	}
*/
	while(num--)
	{
		*tmp_dest++=*tmp_src++;
	}

	return destnation;
}


/*********************************
          测试函数
**********************************/
/**
 * 数组的内存拷贝
 */
void test_array()
{	
	const int array_size=8;
	char src[array_size]={'a','b','c','d','e','f','g','h'};
	//NOTICE:不要用strlen作为size，strlen(src)不一定是正确的数组长度,可以用sizeof
	char* dest=(char*)malloc(array_size);

	printf("sizeof:%lu\n", sizeof(src));
	st_memcpy(dest,src,array_size);

	for (int i = 0; i < array_size; ++i)
	{
		printf("%d:%c ", i,dest[i]);
	}

	printf("\n");

	free(dest);
}
/**
 * struct的内存拷贝
 */
void test_struct()
{
	typedef struct 
	{
		char* name;
		int age;
	} Person;
	Person person,person_copy;
	//person={"come on boy",16};
	person.name="come on boy";
	person.age=16;
	printf("%s:", person.name);
	printf("%d\n", person.age);

	st_memcpy(&person_copy,&person,sizeof(person));

	printf("%s:", person_copy.name);
	printf("%d\n", person_copy.age);
}

int main(int argc, char const *argv[])
{
	test_array();
	test_struct();
	return 0;
}