/**
 * 洗牌算法
 */
#include <iostream>
#include <ctime>
#include <string>
/* 
void shuffle(int* poker,int length)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < length; ++i)
	{
		int random=rand()%length;
		int tmp=poker[i];
		poker[i]=poker[random];
		poker[random]=tmp;
	}
}
*/
template <typename T>
void shuffle(T* poker,int length)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < length; ++i)
	{
		int random=rand()%length;
		T tmp=poker[i];
		poker[i]=poker[random];
		poker[random]=tmp;
	}
}

int main(int argc, char const *argv[])
{
	int i_poker[10]={1,2,3,4,5,6,7,8,9,10};
	char c_poker[10]={'a','b','c','d','e','f'};
	shuffle(i_poker,10);
	shuffle(c_poker,6);
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<i_poker[i]<<' ';
	}
	std::cout<<std::endl;
	for (int i = 0; i < 6; ++i)
	{
		std::cout<<c_poker[i]<<' ';
	}
	std::cout<<std::endl;
	
	return 0;
}