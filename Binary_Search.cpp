#include <iostream>
/**
 * 在数组中通过二分查找，精确查找某一数字
 * @param  array   存放数据的数组
 * @param  key     要查找的值
 * @param  length  数组长度
 * @return     0｜1   0表示查找成功，1表示查找失败
 */
int Binary_Search(const int* array,const int key,int length)
{
	std::cout<<"we are in"<<std::endl;
	int mid,lower,upper;
	lower=0;
	upper=length-1;
	while(lower<=upper)
	{
		//mid=(upper+lower)/2;upper＋lower 可能大于整形地最大值，会产生整数溢出问题
		mid=lower+(upper-lower)>>1;
		if (array[mid]>key)
		{	
			upper=mid+1;
		}
		else if (array[mid]<key)
		{
			lower=mid-1;
		}
		else
		{
			return 0;
		}

	}
	return 1;
}
//TODO 
//1. 递归版本
//2. 查找并返回位置
//3. 边界值查找
//4. 范围查找，即查找相同元素的范围
//main
int main(int argc, char const *argv[])
{
	int array[8]={1,2,3,4,5,6,7,8};
	int retVal,key;
	printf("please input the key between 1 and 8 ,which you want to search.\n");
	std::cin>>key;
	retVal=Binary_Search(array,key,8);
	if (!retVal)
	{
		printf("We found the key %i\n",key);
	}
	else
	{
		printf("We can't find it\n");
	}
	return 0;
}
