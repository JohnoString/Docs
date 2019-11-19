// 单例模式
#if 0
#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
	Singleton(){ cout << "construction" << endl; }
	Singleton(const Singleton &ref){}
	Singleton &operator=(const Singleton &ref){}
	static Singleton *m_Instance;
public:
	void Destory()
	{
		cout << "destory" << endl;
		if (m_Instance != NULL)
		{
			delete m_Instance;
		}
		m_Instance = NULL;
	}
	static Singleton *GetInstance();
};

Singleton *Singleton::m_Instance = new Singleton();  // 饿汉模式;

Singleton *Singleton::GetInstance()
{
	if (NULL == m_Instance)
	{
		m_Instance = new Singleton();  // 懒汉模式
	}
	return m_Instance;
}

class singleton
{
private:
	singleton()
	{
	}

	static singleton* p;
	static mutex mutex_;
public:
	static singleton* initance()
	{
		if (p == NULL)   //p != NULL,说明对象已经创建出来了，直接返回对象的指针，没必要在加锁解锁浪费时间。
		{
			mutex_.lock();
			if (p == NULL)
			{
				p = new singleton();
			}
			mutex_.unlock();
		}
		return p;
	}
};

mutex singleton::mutex_;
singleton* singleton::p = NULL;

int main()
{
	Singleton *p = Singleton::GetInstance();
	//delete p; // (若用析构内部delete)引起无休止调析构,死循环
	//p = NULL;
	Singleton *p1 = Singleton::GetInstance();
	if (p == p1)
	{
		cout << p << endl;
		cout << p1 << endl;
	}
	p->Destory();
	return 0;
}
#endif