// ����ģʽ
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

Singleton *Singleton::m_Instance = new Singleton();  // ����ģʽ;

Singleton *Singleton::GetInstance()
{
	if (NULL == m_Instance)
	{
		m_Instance = new Singleton();  // ����ģʽ
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
		if (p == NULL)   //p != NULL,˵�������Ѿ����������ˣ�ֱ�ӷ��ض����ָ�룬û��Ҫ�ڼ��������˷�ʱ�䡣
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
	//delete p; // (���������ڲ�delete)��������ֹ������,��ѭ��
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