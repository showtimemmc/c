
/**
 * TODO:
 * 1.二进制位输出函数
 * 2.排序函数封装
 * 3.支持多种bit container
 */
#include <iostream>

class bitmap
{

private:
	int* _a;

public:
	static const int mask;
	unsigned long size;//size of int array
	unsigned long capacity;
	int* a;


	bitmap(unsigned long,unsigned long);
	~bitmap();

	/**
	 * 输入值映射的bit清0
	 * @param input 输入值
	 */
	void clear(unsigned long);
	/**
	 * 输入值映射的bit置1
	 * @param input 输入值
	 */
	void set(unsigned long);
	/**
	 * bitmap中是否包含某个数
	 * @param  input  输入值
	 * @return      包含则返回true
	 */
	bool contain(unsigned long);

	/**
 	* [bitmap::sort 输入数组采用bitmap排序]
 	* @param  input  [输入数组指针]
 	* @param  output [返回值指针]
 	* @return        [排序后的数组]
 	*/
	unsigned long* sort(unsigned long*,unsigned long*);

};

