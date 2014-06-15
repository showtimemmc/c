#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
template <typename object>
class Vector
{
public:
	explicit Vector(int);//单参数构造函数，使用explicit防止隐式类型转换
	~Vector();
	Vector(const & Vector);
	const & Vector operator= (const & Vector);


	bool is_empty() const;
	unsigned int size() const;
	unsigned int capacity() const;

	void resize(int);

	void push_back();
	void pop_back();
private:
	void reserve(int);

	unsigned int capacity_;//current capacity has be used
	unsigned int size_;
	object* object_;

};


#endif