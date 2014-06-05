/**
 * 利用异或找出不重复的数字
 */
#include <iostream>
int main(int argc, char const *argv[])
{
	int a[]={3,2,2,1,3,1,5,6,5,5,5};
	for (int i = 1; i < 11; ++i)
	{
		a[0]^=a[i];
		std::cout<<i<<" :"<<a[0]<<std::endl;
	}
	std::cout<<"Final :"<<a[0]<<std::endl;
	return 0;
}