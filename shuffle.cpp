/**
 * 洗牌算法
 */
#include <iostream>
#include <ctime>
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

int main(int argc, char const *argv[])
{
	int poker[10]={1,2,3,4,5,6,7,8,9,10};
	shuffle(poker,10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<poker[i]<<' ';
	}
	std::cout<<std::endl;
	return 0;
}