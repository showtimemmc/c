//从小到大，选择排序
#include "../share/utils.h"
#include <iostream>
#include <vector>

int loop_count=0;
int swap_count=0;

//优化后的选择排序
//通过只记录最小元素索引，并在每一趟i循环之后判断是否需要交换
void selection_sort(std::vector<int> &vec)
{
	int min=0;
	for (int i = 0; i < vec.size(); ++i)
	{
		//记录每一趟比较的最小值的位置
		min=i;
		for (int j = i+1; j < vec.size(); ++j)
		{
			if (vec[j]<vec[min])
			{
				//只记录最小值的位置
				min=j;
			}
			loop_count++;
		}
		//判断是否需要交换
		if (min!=i)
		{
			swap(vec[i],vec[min]);
			swap_count++;
		}
	}
}

int main(int argc, char const *argv[])
{
	
	//int test_input[]={9,1,5,8,8,7,4,6,2};
	int test_input[]={1,3,2,8,6};
	std::vector<int> input(test_input,test_input+sizeof(test_input)/sizeof(int));
	selection_sort(input);
    
	print_vector(input);
	std::cout<<"loop_count:"<<loop_count<<std::endl;
	std::cout<<"swap_count:"<<swap_count<<std::endl;
	return 0;
}