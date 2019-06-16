#include<iostream>
#include<string>
#include"function.h"
#ifdef ONLINE_JUDGE
#include"NTHUOJLock"
#endif

namespace oj
{
	Int::Int()
		:val(0){}	//set val as 0
	
	Int::Int(const int val_)
		:val(val_){}
	
	Int::Int(const Int &rhs)
		:val(rhs.val){}	//copy from rhs.val

	Int& Int::operator=(const Int &rhs)
	{
		val=rhs.val;	//copy from rhs.val
		return *this;
	}

	Vector::Vector()
		:begin_(NULL),end_(NULL),last_(NULL){}

	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(std::size_t i(0);i!=vec.size();++i)
			os<<vec[i]<<' ';
		return os;
	}
}

int main()
{
	using namespace std;
	{
		oj::Vector v;
		string command;

		for(oj::data_t n;cin>>command;)
		{
			if(command=="pop_back")
			{
				v.pop_back();
				cout<<v<<endl;
			}
			else if(command=="push_back")
			{
				cin>>n;
				v.push_back(n);
				cout<<v<<endl;
			}
			else if(command=="capacity")
				cout<<v.capacity()<<endl;
			else if(command=="size")
				cout<<v.size()<<endl;
			else if(command=="reserve")
			{
				cin>>n;
				v.reserve(n);
				cout<<v<<endl;
			}
		}
		cout<<v<<endl;
	}
	oj::memory_leak_count_check();	//you don't have to pay attention on this
#ifdef ONLINE_JUDGE
	nthuoj_unlock();
#endif
}

namespace oj
{
	Memory_leak_count::Memory_leak_count()
	{
		++count_;	//memory request + 1
	}

	Memory_leak_count::~Memory_leak_count()
	{
		--count_;	//memory request - 1
	}

	unsigned Memory_leak_count::count_(0);

	void memory_leak_count_check()
	{
		if(Memory_leak_count::count_!=0)	//memory leak if count_ is not equal to 0
			std::cout<<"memory leak"<<std::endl;
	}
}