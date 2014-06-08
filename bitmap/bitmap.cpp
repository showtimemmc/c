#include "bitmap.h"
const int bitmap::mask=0x1f;
	//constructer
	//max is the max value of the data
	bitmap::bitmap(unsigned long max,unsigned long cap)
	{
		capacity=cap;
		size=max/32+1;
		//new 分配失败会抛异常，不需要检查返回是否为null
		_a = new int[size];
		memset(_a,0,sizeof(int)*size);
		a=_a;
	}
	//deconstructer
	bitmap::~bitmap()
	{
		delete [] _a;
	}
	//
	void bitmap::set(unsigned long input)
	{
		_a[input>>5] |= 1<<(input&bitmap::mask) ;
	}

	void bitmap::clear(unsigned long input)
	{
		_a[input>>5] &= 1<<(input&bitmap::mask);
	}

	bool bitmap::contain(unsigned long input)
	{
		if (_a[input>>5]&(1<<(input&bitmap::mask)))
		{
			return true;
		}
		return false;
	}
/**
 * [bitmap::sort 输入数组采用bitmap排序]
 * @param  input [输入数组指针]
 * @param  cap   [description]
 * @return       [排序后的数组]
 */
	unsigned long* bitmap::sort(unsigned long* input,unsigned long* output)
	{
		//unsigned long* output = new unsigned long[this->capacity];
		unsigned long* ret=output;
		//输入数组映射到bitmap的位置置1
		for (int i = 0; i < this->capacity; ++i)
		{
			this->set(*input);
			input++;
		}
		//一位一位检查是否为1，为1则填入output中
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				int result=(this->_a[i]&(1<<j));
				//std::cout<<result<<std::endl;
				if (result)
				{
					//i*32+j根据所在一维数组和数组内偏移下标计算原数字
					*output=i*32+j;
					//std::cout<<*output<<" ";
					output++;
				}
			}
		}
		//NOTICE:此时output已经指到了尾部，直接返回时，读取的是分配的内存之后的地址
		return ret;
	}
