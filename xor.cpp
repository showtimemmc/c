/**
 * 利用异或找出不重复的数字
 */
#include <iostream>
int main(int argc, char const *argv[])
{
	int a[]={3,2,2,1,3,1,5,6,6,5,5};
	
	for (int i = 1; i < 11; ++i)
	{
		a[0]^=a[i];
		std::cout<<i<<" :"<<a[0]<<std::endl;
	}
	std::cout<<"Final :"<<a[0]<<std::endl;
	return 0;
}
/*简单证明
*x^x=0,x^0=x,异或满足交换律
*所以通过交换律，只要是成对出现的数都会异或为0，结果只剩下1个不同的数
*/