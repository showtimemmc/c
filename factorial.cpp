/**
 * 计算阶乘
 */
#include <iostream>
 int Factorial_Loop(int factor)
 {
 	if (factor<0)
 	{
 		printf("factor should be \n");
 		return -1;
 	}

 	if (factor==0)
 	{
 		printf("factor is 0\n");
 		return 1;
 	}

 	unsigned int product=1;
 	for (int i = 1; i <= factor; ++i)
 	{
 		product*=i;
 	}
 	return product;

 }
 
 int main(int argc, char const *argv[])
 {
    int factor;
 	std::cout<<"Please input the factor:"<<std::endl;
 	std::cin>>factor;
 	std::cout<<"result:"<<Factorial_Loop(factor)<<std::endl;
 	return 0;
 }