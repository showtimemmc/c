#include <iostream>
struct MutableArray
{
	int* array;
	size_t used;
	size_t size;//	
};
/**
 * Initinalize the mutable array
 * @param  ma             
 * @param  init_size  
 * @return      True|False    return true if it is initialized success
 */
//XXX:maybe there is a problem
bool InitMutableArray(MutableArray* pma,size_t init_size)
{
	pma->array=(int*)malloc(init_size*sizeof(int));
	if (pma->array == NULL)
	{
		std::cout<<"ERROR,mem assign failed!"<<std::endl;
		return false;
	}
	pma->used=0;
	pma->size=init_size;

	//std::cout<<"after init: "<<ma->array<<std::endl;  //new value
	//std::cout<<"after init&: "<<&ma->array<<std::endl;//same with struct address

	return true; 
}
/**
 * [FreeMutableArray description]
 * @param ma [description]
 */
void FreeMutableArray(MutableArray* pma)
{
	//if pma is not null, free it.
	if (pma)
	{
		free(pma->array);
		pma->array=NULL;
		pma->used=0;
		pma->size=0;
	}
}
/**
 * 在数组末尾添加对象
 * @param  pma     [description]
 * @param  int_obj [description]
 * @return         True|False    return true if successed
 */
bool AddObject(MutableArray* pma,int int_obj)
{
	//XXX:size会随着数组规模的扩大，成指数增长
	if (pma->used == pma->size)		
	{
		pma->size=pma->size*2;
	}
	//ma->array=realloc(ma->array,ma->size);  the address of ma->array would be lost,if the realloc failed.
	if (!(int*)realloc(pma->array,pma->size))
	{
		printf("ERROR,mem assign failed\n");
		return false;
	}
	pma->array[pma->used++]=int_obj;
	return true;
}
/**
 * 在指定位置处插入元素
 * @param  p_ma  [description]
 * @param  index index start with 0
 * @param  obj   obj to be inserted 
 * @return       true | false 
 */
bool InsertObject(MutableArray* p_ma,unsigned int index,int obj)
{
	//XXX:size会指数上涨
	if (p_ma->used == p_ma->size)		
	{
		p_ma->size*=2;
	}
	if (index > p_ma->used)
	{
		printf("ERROR,index beyond buffer\n");
		return false;	
	}
	for (int i = p_ma->used; i >= index; --i)
	{
		p_ma->array[i+1]=p_ma->array[i];
	}
	p_ma->array[index]=obj;
	p_ma->used++;

	return true;
}
/**
 * get object at index in array
 * @param  pma    [description]
 * @param  index [description]
 * @return       [description]
 */
int GetObject(const MutableArray* pma,const size_t index)
{
	if (index >= pma->used)//负数参数传入时，由于传递参数副本时进行了类型转换，负数被转换为很大的正数，所以不需要判断index小于0的状况
	{
		//printf("index:%u\n",index);
		printf("ERROR,check the param index\n");
		exit(1);
	}
	else
	{
		return pma->array[index];
	}
}
/**
 * 获取数组最后添加元素
 * @param  p_ma [description]
 * @return      数组最后一个元素
 */
int GetLastObject(const MutableArray* p_ma)
{
	if (p_ma->used == 0)
	{
		printf("The array is empty\n");
	}
	return p_ma->array[p_ma->used-1];
}
/**
 * [RemoveLastObject description]
 * @param p_ma [description]
 */
void RemoveLastObject(MutableArray* p_ma)
{
	if (p_ma->used == 0)
	{
		printf("The array is empty\n");
		return;
	}
	p_ma->used--;
}
/**
 * 打印输出数组中的内容
 * @param p_ma [description]
 */
void PrintMutableArray(const MutableArray* p_ma)
{
	for (int i = 0; i < p_ma->used; ++i)
	{
		printf("%d ", p_ma->array[i]);
	}
	printf("\n");
	return;
}
//TODO: support multi type with template
//TODO: class
int main(int argc, char const *argv[])
{
	MutableArray ma;

	//std::cout<<"&ma: "<<&ma<<std::endl;  //address of struct var ma
	//std::cout<<"before init ma.array: "<<ma.array<<std::endl; //random value
	//std::cout<<"&ma.array: "<<&ma.array<<std::endl;  //same with struct var ,ma 

	if (!InitMutableArray(&ma,5))		
	{
		printf("Initinalize Failed!\n");
		return 1;
	}
	for (size_t i = 0; i < ma.size; ++i)
	{
		ma.array[i]=i;
		ma.used++;
	}

	PrintMutableArray(&ma);
	AddObject(&ma,5);
	PrintMutableArray(&ma);

	int index;
	std::cin>>index;
	std::cout<<"get:"<<GetObject(&ma,index)<<std::endl;
	std::cout<<"Last:"<<GetLastObject(&ma)<<std::endl;

	InsertObject(&ma,index,11);
	PrintMutableArray(&ma);
	RemoveLastObject(&ma);
	std::cout<<"After remove last:"<<GetLastObject(&ma)<<std::endl;
	//std::cout<<ma.array<<std::endl;

	FreeMutableArray(&ma);
	//std::cout<<ma.array<<std::endl;
	return 0;
}

