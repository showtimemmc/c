#include "bitmap.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	int target[]={1,4,9,18,23,7,6,8};
	bitmap* bm=new bitmap(23);
	for (int i = 0; i < 8; ++i)
	{
		bm->set(target[i]);
	}
	if (bm->contain(13))
	{
		std::cout<<"OK, you make it.CONTAIN"<<std::endl;
	}
	else
	{
		std::cout<<"Sorry"<<std::endl;
	}

	return 0;
}