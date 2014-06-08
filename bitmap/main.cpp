#include "bitmap.h"
#include <iostream>
template <typename Type> void print_array(Type* array,unsigned long size);
void test_contain();
void test_sort();
void test_sortfunc();

int main(int argc, char const *argv[])
{
	//test_contain();
	test_sort();

	std::cout<<"\n"<<"+++++++++test_sortfunc+++++++++"<<"\n";
	test_sortfunc();
	return 0;
}
/**
 * 功能函数
 * 输出数组的内容
 */
template <typename Type>
void print_array(Type* array,unsigned long size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
}
/**
 * 测试contain函数
 */
void test_contain()
{
	int haystack[]={1,4,9,18,23,7,6,8};
	bitmap* bm=new bitmap(23,8);

	for (int i = 0; i < 8; ++i)
	{
		bm->set(haystack[i]);
	}

	int needle;
	std::cout<<"Input needle(>=0)"<<std::endl;
	do{
		std::cin>>needle;
	}while(needle<0);

	if (bm->contain(needle))
	{
		std::cout<<"OK, you make it.CONTAIN"<<std::endl;
	}
	else
	{
		std::cout<<"Sorry"<<std::endl;
	}
}
/**
 * 测试bitmap排序
 */
void test_sort()
{
	int haystack[]={1,4,9,18,23,7,6,8};
	bitmap* bm=new bitmap(23,8);

	print_array(haystack,8);

	for (int i = 0; i < 8; ++i)
	{
		bm->set(haystack[i]);	
	}

	for (int i = 0; i < bm->size; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
				if(bm->a[i]&(1<<j))
				{
					std::cout<<i*32+j<<" ";
				}
		}
	}
	//std::cout<<std::endl;
	delete bm;

}
/**
 * 测试bitmap中的sort
 */
void test_sortfunc()
{
	unsigned long  haystack[]={1,4,9,18,23,7,6,8};
	bitmap* bm=new bitmap(23,8);
	
	unsigned long* output=new unsigned long[8];

	print_array(haystack,8);

	print_array(bm->sort(haystack,output),8);

	delete [] output;
	delete bm;
}