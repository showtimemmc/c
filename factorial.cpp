/**
 * 计算阶乘
 */
#include <iostream>
#include <ctime>
 /**
  * 迭代方法计算阶乘
  * @param  factor 阶乘因子
  * @return        计算结果
  */
 int Factorial_Loop(int factor)
 {
 	if (factor<0)
 	{
 		printf("factor should be great than zero\n");
 		return -1;
 	}

 	if (factor==0)
 	{
 		return 1;
 	}

 	unsigned int product=1;
 	for (int i = 1; i <= factor; ++i)
 	{
 		product*=i;
 	}
 	return product;

 }
 /**
  * 采用普通递归方法计算
  * @param  factor  阶乘因子			
  * @return         计算结果
  */
int Factorial_Recursion(int factor)
{
	if (factor<0)
	{
		printf("factor shuould be great than zero\n");
		return -1;
	}
	if (factor==0)
	{
		return 1;
	}
	return	factor*Factorial_Recursion(factor-1);
}
/**TODO:再看下尾递归的用法
 * 尾递归计算方法
 * @param  factor   乘积因子
 * @param  facorial 乘积，保存上一次的阶乘阶乘计算的结果，初始值必须为1
 * @return          计算结果
 */
int Factorial_Tail(int factor,unsigned long facorial)
{
	if (factor<0)
	{
		printf("factor shuould be great than zero\n");
		return -1;
	}
	if (factor==0)
	{
		return facorial;
	}
	return Factorial_Tail(factor-1,factor*facorial);
}
/*
TODO:增加函数执行时间计算
 */
 int main(int argc, char const *argv[])
 {
    int factor;

 	std::cout<<"Please input the factor:"<<std::endl;
 	std::cin>>factor;

 	unsigned int start,stop;
 	
 	//start=time(0);
 	std::cout<<"Loop result:"<<Factorial_Loop(factor)<<std::endl;
 	//stop=time(0);
 	//std::cout<<"Time:"<<start<<std::endl<<std::endl;
 	//std::cout<<"Time:"<<stop<<std::endl<<std::endl;

 	std::cout<<"Recursion result:"<<Factorial_Recursion(factor)<<std::endl;
 	std::cout<<"Tail result:"<<Factorial_Tail(factor,1)<<std::endl;

 	return 0;
 }