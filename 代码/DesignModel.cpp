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

// 装饰模式
#if 0
#include <iostream>
#include <string>
using namespace std;

class Component { // 接口
public:
	virtual void Operation() = 0;
	virtual ~Component() {}
};

class ConcreteComponent : public Component { // 具体实现对象，需要被装饰的类
public:
	void Operation() { cout << "ConcreteComponent" << endl; }
};

class Decorator : public Component {
private:
	Component* component;
public:
	void SetComponent(Component* c) { component = c; }  // 设置Component
	virtual void Operation() {
		if (component) component->Operation();
	}
};

class ConcreteDecoratorA : public Decorator {
private:
	string addedState;   // 本类独有功能
public:
	void Operation() {
		Decorator::Operation();
		addedState = "New state";
		cout << "ConcreteDecoratorA: " << addedState << endl;
	}
};

class ConcreteDecoratorB : public Decorator {
private:
	void AddedBehavior() { cout << "ConcreteDecoratorB: AddedBehavior" << endl; }   // 本类特有方法
public:
	void Operation() {
		Decorator::Operation();
		AddedBehavior();
	}
};

int main() {
	Component* c = new ConcreteComponent();

	Decorator* d1 = new ConcreteDecoratorA();
	d1->SetComponent(c);
	d1->Operation();  // ConcreteComponent
	// ConcreteDecoratorA: New state
	Decorator* d2 = new ConcreteDecoratorB();
	d2->SetComponent(c);
	d2->Operation();  // ConcreteComponent
	// ConcreteDecoratorB: AddedBehavior
	delete d1;
	delete d2;
	delete c;
	return 0;
}
#endif