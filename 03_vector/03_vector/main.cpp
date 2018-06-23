#include <vector>
#include <iostream>
#include <list>
using namespace std;
void test01_capacity_change()
{
	//�۲�vector�ռ�ı仯
	vector<int> v;
	for (int i = 0; i < 10;i ++){
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()����������,ָvector���ά���Ķ�̬����Ĵ�С
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
	//vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	//vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int> v2(v1.begin(),v1.end());//��v1�����ݿ�������
	printVector(v2);

	int arr[] = { 5,6,7,8 };
	vector<int> v3(arr, arr + 4);
	printVector (v3);


	//vector(n, elem);//���캯����n��elem����������
	vector<int> v4(10, 100); //10��100
	printVector(v4);

	//vector(const vector &vec);//�������캯����
	vector<int>v5(v4);
}


void test03_assign()
{
	//assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	printVector(v2);

	//assign(n, elem);//��n��elem������ֵ������
	vector<int> v3;
	v3.assign(10, 100);
	printVector(v3);

	//vector& operator=(const vector  &vec);//���صȺŲ�����
	vector<int>v4;
	v4 = v3;

	//swap(vec);// ��vec�뱾���Ԫ�ػ�����
	//v2 �� 1 2 3 4
	//v3 �� 10 ��100
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
	//size();//����������Ԫ�صĸ���
	cout << "size : " << v1.size() << endl; //�ж��ٸ���Ա,size���Ƕ���

	//capacity();//����������
	cout << "capacity : " << v1.capacity() << endl; 

	//empty();//�ж������Ƿ�Ϊ��
	if (v1.empty())
	{
		cout << "�ǿյ�" << endl;
	}
	else
	{
		cout << "�ǿ�" << endl;
	}

	//resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	//v1.resize(15);
	//printVector(v1);

	//resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
	v1.resize(15, 100);
	printVector(v1);

	v1.resize(5);
	printVector(v1);
	
	//reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
	//Ԥ��֮���Ӱ��capacity,���ǲ���Ӱ��size
	cout << "before reserve  size : " << v1.size() << " capacity : " << v1.capacity()<<endl;
	v1.reserve(100);
	cout << "after reserve  size : " << v1.size() << " capacity : " << v1.capacity()<<endl;
}

void test05_fron_back()
{
	//at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
	//operator[];//������j��idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���


	//front();//���������е�һ������Ԫ��
	//back();//�������������һ������Ԫ��
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	cout<<"front : " << v.front() << endl;
	cout<<"back : "<< v.back() << endl;

	int *p = &v[9];
	cout << *p << endl;

	v.resize(100);//���·����ڴ�,�ص���֮ǰ��ָ����Ұָ��
	cout << *p << endl;
}
void test06_insert_erase()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//��������const������ ,ͬ����cbegin��cend,���صĵ�����������const
	//for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
	//{
	//	cout << *it << endl;
	//}

	//insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
	//v : 0 1 2 3 4 5 6 7 8 9
	//��0��1�м��������100
	vector<int>::iterator it = v.begin();
	++it;
	v.insert(it, 2, 100);
	printVector(v);

	//push_back(ele); //β������Ԫ��ele
	//pop_back();//ɾ�����һ��Ԫ��
	v.pop_back();
	printVector(v);
	
	//erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
	//erase(const_iterator pos);//ɾ��������ָ���Ԫ��
	//ɾ���ղŲ��������100
	vector<int>::iterator it1 = v.begin();
	++it1;
	vector<int>::iterator it2 = it1+2;
	v.erase(it1, it2);
	printVector(v);

	//clear();//ɾ������������Ԫ��
	v.clear();
	cout << "after clear , v.size() : " << v.size() << "v.capasity():" << v.capacity() << endl;

}

void shousuoneicun(vector<int> &v)
{
	vector<int>(v).swap(v);
}
void test07_swap_memory_resize()
{
	//ͨ��swap�����ڴ�
	//�������²���,v�洢������ֻ��4��,��������>10000
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
	//vector<int> v2(v);//����һ��v2��ʱ��,��v��4��Ԫ�ؿ�������,��ʱ��v2������4
	//v2.swap(v); //swap�ײ��ԭ��,ֱ�ӽ�����������ĵ�ַ,���1200���ڴ�ռ������v2���ͷŶ��ͷ�
	shousuoneicun(v);

	cout << "after swap ,v.size() : " << v.size() << " v.capacity() : " << v.capacity() << endl;
	printVector(v);
}

void test08_reserve()
{
	//����:����100000������,�ڴ����·����˶��ٴ�?
	//ÿ�����·����ʱ��,vector��߶�̬������ĵ�ַ���
	vector<int>v;
	//һ��ʼ��ֱ�ӷ���100000�Ŀռ�
	v.reserve(100000);
	int *p = NULL;
	int count = 0;//�ڴ�������
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			//���p����������ĵ�ַ,����������һ���ڴ�
			++count;
			p = &v[0];
		}
	}
	cout << "���·����ڴ�Ĵ���:" <<count<< endl;
}

void test09_reverse_search()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//��v���з������
	//�����������Ͳ�����iterator,��reverse_iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << endl;
	}


	//�������
	//��������Ϊ����������ʵ��Լ������������
	vector<int>::iterator it = v.begin();
	cout << *(it + 5) << endl;//��������n��Ԫ�صĵ��������ǿ�������ʵĵ�����


	//����������ʵ�,����:list
	list<int> l;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i);
	}
	list<int>::iterator it2 = l.begin();
	//cout << *(it2 + 5) << endl;//������û������+�Ų�����,���ֲ���������ʵ�

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