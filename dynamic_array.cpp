#include <iostream>
struct MutableArray
{
	int* array;
	size_t used;
	size_t size;//	
};
/**
 * Initinalize the mutable array
 * @param  ma   [description]
 * @param  size [description]
 * @return      True|False    return true if it is initialized success
 */
bool InitMutableArray(MutableArray* ma,size_t init_size)
{
	ma->array=(int*)malloc(init_size*sizeof(MutableArray));
	if (ma->array == NULL)
	{
		std::cout<<"mem assign failed!"<<std::endl;
		return false;
	}
	ma->used=0;
	ma->size=init_size;
	return true; 
}
void FreeMutableArray(MutableArray* ma)
{
	free(ma->array);
	ma->used=0;
	ma->size=0;
}
int main(int argc, char const *argv[])
{
	MutableArray ma;
	InitMutableArray(&ma,5);
	/*
	if (!InitMutableArray(ma,5))		
	{
		printf("Initinalize Failed!\n");
		return 1;
	}*/
	for (int i = 0; i < ma->used; ++i)
	{
		ma->array[i]=3;
	}
	for (int i = 0; i < ma->used; ++i)
	{
		printf("%i\n", ma->array[i]);
	}
	FreeMutableArray(&ma);
	std::cout<<ma->array<<std::endl;
	return 0;
}

