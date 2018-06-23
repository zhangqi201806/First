#include <vector>
#include <iostream>
#include <list>
using namespace std;
void test01_capacity_change()
{
	//观察vector空间的变化
	vector<int> v;
	for (int i = 0; i < 10;i ++){
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()容器的容量,指vector里边维护的动态数组的大小
	}
	

}

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test02_contructor()
{
	//vector<T> v; //采用模板实现类实现，默认构造函数
	//vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int> v2(v1.begin(),v1.end());//将v1的内容拷贝过来
	printVector(v2);

	int arr[] = { 5,6,7,8 };
	vector<int> v3(arr, arr + 4);
	printVector (v3);


	//vector(n, elem);//构造函数将n个elem拷贝给本身。
	vector<int> v4(10, 100); //10个100
	printVector(v4);

	//vector(const vector &vec);//拷贝构造函数。
	vector<int>v5(v4);
}


void test03_assign()
{
	//assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	printVector(v2);

	//assign(n, elem);//将n个elem拷贝赋值给本身。
	vector<int> v3;
	v3.assign(10, 100);
	printVector(v3);

	//vector& operator=(const vector  &vec);//重载等号操作符
	vector<int>v4;
	v4 = v3;

	//swap(vec);// 将vec与本身的元素互换。
	//v2 是 1 2 3 4
	//v3 是 10 个100
	v2.swap(v3);
	printVector(v2);
	printVector(v3);

}

void test04_size()
{
	vector<int> v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	//size();//返回容器中元素的个数
	cout << "size : " << v1.size() << endl; //有多少个成员,size就是多少

	//capacity();//容器的容量
	cout << "capacity : " << v1.capacity() << endl; 

	//empty();//判断容器是否为空
	if (v1.empty())
	{
		cout << "是空的" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}

	//resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	//v1.resize(15);
	//printVector(v1);

	//resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
	v1.resize(15, 100);
	printVector(v1);

	v1.resize(5);
	printVector(v1);
	
	//reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
	//预留之后会影响capacity,但是不会影响size
	cout << "before reserve  size : " << v1.size() << " capacity : " << v1.capacity()<<endl;
	v1.reserve(100);
	cout << "after reserve  size : " << v1.size() << " capacity : " << v1.capacity()<<endl;
}

void test05_fron_back()
{
	//at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
	//operator[];//返回索j引idx所指的数据，越界时，运行直接报错


	//front();//返回容器中第一个数据元素
	//back();//返回容器中最后一个数据元素
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	cout<<"front : " << v.front() << endl;
	cout<<"back : "<< v.back() << endl;

	int *p = &v[9];
	cout << *p << endl;

	v.resize(100);//重新分配内存,回导致之前的指针变成野指针
	cout << *p << endl;
}
void test06_insert_erase()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//迭代器有const的类型 ,同理有cbegin和cend,返回的迭代器类型是const
	//for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
	//{
	//	cout << *it << endl;
	//}

	//insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
	//v : 0 1 2 3 4 5 6 7 8 9
	//在0和1中间插入两个100
	vector<int>::iterator it = v.begin();
	++it;
	v.insert(it, 2, 100);
	printVector(v);

	//push_back(ele); //尾部插入元素ele
	//pop_back();//删除最后一个元素
	v.pop_back();
	printVector(v);
	
	//erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
	//erase(const_iterator pos);//删除迭代器指向的元素
	//删除刚才插入的两个100
	vector<int>::iterator it1 = v.begin();
	++it1;
	vector<int>::iterator it2 = it1+2;
	v.erase(it1, it2);
	printVector(v);

	//clear();//删除容器中所有元素
	v.clear();
	cout << "after clear , v.size() : " << v.size() << "v.capasity():" << v.capacity() << endl;

}

void shousuoneicun(vector<int> &v)
{
	vector<int>(v).swap(v);
}
void test07_swap_memory_resize()
{
	//通过swap收缩内存
	//经过以下操作,v存储的数据只有4个,但是容量>10000
	vector<int> v;
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
	}
	v.clear();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << "before swap ,v.size() : " << v.size() << " v.capacity() : " << v.capacity() << endl;
	//vector<int>(v).swap(v);
	//vector<int> v2(v);//构造一个v2的时候,将v的4个元素拷贝过来,这时候v2容量是4
	//v2.swap(v); //swap底层的原理,直接交换两个数组的地址,最后1200的内存空间会随着v2的释放而释放
	shousuoneicun(v);

	cout << "after swap ,v.size() : " << v.size() << " v.capacity() : " << v.capacity() << endl;
	printVector(v);
}

void test08_reserve()
{
	//需求:插入100000个数字,内存重新分配了多少次?
	//每次重新分配的时候,vector里边动态的数组的地址会变
	vector<int>v;
	//一开始就直接分配100000的空间
	v.reserve(100000);
	int *p = NULL;
	int count = 0;//内存分配次数
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			//如果p不等于数组的地址,记它分配了一次内存
			++count;
			p = &v[0];
		}
	}
	cout << "重新分配内存的次数:" <<count<< endl;
}

void test09_reverse_search()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//对v进行反向遍历
	//迭代器的类型不再是iterator,是reverse_iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << endl;
	}


	//随机访问
	//迭代器分为可以随机访问的以及不可随机访问
	vector<int>::iterator it = v.begin();
	cout << *(it + 5) << endl;//可以跳过n个元素的迭代器就是可随机访问的迭代器


	//不可随机访问的,例子:list
	list<int> l;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i);
	}
	list<int>::iterator it2 = l.begin();
	//cout << *(it2 + 5) << endl;//迭代器没有重载+号操作符,这种不可随机访问的

}
int main()
{
	//test01_capacity_change();
	//test02_contructor();
	//test03_assign();
	//test04_size();
	//test05_fron_back();
	//test06_insert_erase();
	//test07_swap_memory_resize();
	//test08_reserve();
	test09_reverse_search();
	system("pause");
	return 0;
}