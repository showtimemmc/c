//从小到大，冒泡排序
#include "../share/utils.h"
#include <iostream>
#include <vector>

int loop_count=0;
int swap_count=0;
//基本的冒泡排序
void bubble_sort1(std::vector<int> &vec)
{
	print_vector(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		/*
		//注意从后向前循环，小的数向前交换，一趟比较后，较小的元素出现在第一位，第二趟后，第二小的元素出现在第二位
		for (int j = vec.size()-1; j>i; --j)
		{
			if (vec[j]<vec[j-1])
			{
				swap(vec[j],vec[j-1]);	
				swap_count++;
			}
			loop_count++;
		}
		*/
		//从前向后循环.大的数字向后交换，一趟比较后，较大的元素就放在了最后一位上。第二趟第二大的元素在导数第二的位置上
		//注意j的执行条件，vec.size()-i-1表示的是每趟比较最终大的元素放置的位置
		for (int j = 0; j < vec.size()-i-1; ++j)
		{
			if (vec[j]>vec[j+1])
			{
				swap(vec[j],vec[j+1]);
				swap_count++;
			}
			loop_count++;
		}
	}
}
//增加标识位进行优化，如果序列已经排序，就不会再进行循环比较了
void bubble_sort(std::vector<int> &vec)
{
	print_vector(vec);
	bool flag=true;
	for (int i = 1; i < vec.size() && flag; ++i)
	{
		flag=false;
		for (int j = vec.size()-1; j>=i; --j)
		{
			if(vec[j]<vec[j-1])
			{
				swap(vec[j],vec[j-1]);
				flag=true;
				swap_count++;
			}
			loop_count++;
		}
	}
}

int main(int argc, char const *argv[])
{
	//int test_input[]={9,1,5,8,8,7,4,6,2};
	int test_input[]={1,3,2,8,6};
	std::vector<int> input(test_input,test_input+sizeof(test_input)/sizeof(int));
	bubble_sort2(input);
    
	print_vector(input);
	std::cout<<"loop_count:"<<loop_count<<std::endl;
	std::cout<<"swap_count:"<<swap_count<<std::endl;
	return 0;
}







