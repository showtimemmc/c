//合并两个有序数组，使合并后的数组仍然有序
//如：1345   2367  合并后：12334567
//BUG:不支持长度不想等的数组合并
//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <new>
#include <exception>

int* merge_array(int* array1, int lengthOfArray1,int* array2,int lengthOfArray2)
{
	if (array1==NULL || array2 == NULL)
	{
		throw std::invalid_argument("array1 or array2 is null");
		return NULL;
	}

	int* newarray = new int[lengthOfArray1+lengthOfArray2];

	int indexOfNew=lengthOfArray1+lengthOfArray2-1;
	int indexOfArray1=lengthOfArray1-1;
	int indexOfArray2=lengthOfArray2-1;


	//从后向前合并
	//元素大的数组指针向前移动
	while(indexOfNew>=0)
	{
		//indexOfArray1<0?indexOfArray1=0:indexOfArray1;
		//indexOfArray2<0?indexOfArray2=0:indexOfArray2;

		if (array1[indexOfArray1]>array2[indexOfArray2])
		{
			newarray[indexOfNew--]=array1[indexOfArray1--];
		}
		else if (array1[indexOfArray1]<array2[indexOfArray2])		
		{
			newarray[indexOfNew--]=array2[indexOfArray2--];
		}
		else
		{//两个数组在某个位置上相等
			newarray[indexOfNew--]=array1[indexOfArray1--];
			newarray[indexOfNew--]=array2[indexOfArray2--];
			//由于元素相等，元素都减1
			//indexOfArray1--;
			//indexOfArray2--;
		}

	}

	return newarray;
}
/**********test**************/
//正常输入
//数组a和数组b元素个数相等
void test1()
{
	int a[9]={1,3,5,8,9,13,14,18,21};
	int b[9]={3,4,6,7,11,12,19,23,26};
	int *ret=NULL;
	try
	{
		ret=merge_array(a,9,b,9);
	}
	catch(std::invalid_argument err)
	{
		std::cout<<err.what()<<std::endl;
	}
	catch(std::bad_alloc ba)
	{
		std::cerr<<ba.what()<<std::endl;
	}
	catch(std::exception e)
	{
		std::cout<<"unknow exception"<<std::endl;
	}

	for (int i = 0; i < 18; ++i)
	{
		std::cout<<ret[i]<<' ';
	}
	std::cout<<std::endl;

	delete [] ret;
}
//正常输入
//数组a和数组b元素个数不相等
void test2()
{
	int a[2]={5,8};
	int b[4]={1,4,6,9};
	int *ret=NULL;
	try
	{
		ret=merge_array(b,4,a,2);
	}
	catch(std::invalid_argument err)
	{
		std::cout<<err.what()<<std::endl;
	}
	catch(std::bad_alloc ba)
	{
		std::cerr<<ba.what()<<std::endl;
	}
	catch(std::exception e)
	{
		std::cout<<"unknow exception"<<std::endl;
	}

	for (int i = 0; i < 6; ++i)
	{
		std::cout<<ret[i]<<' ';
	}
	std::cout<<std::endl;

	delete [] ret;
}

int main(int argc, char const *argv[])
{
	test1();
	//test2();
	return 0;
}

