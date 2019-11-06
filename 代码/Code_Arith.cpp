#if 0
// 实现strcpy函数
#include <iostream>
#include <cassert>
using namespace std;

char *strcpy(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL)); // 2分
	char *address = strDest; // 2分
	while ((*strDest++ = *strSrc++) != '\0') // 2分
		NULL;
	return address; // 2分
}

void * my_memcpy(void *dst, const void *src, unsigned int count)
{
	assert(dst);
	assert(src);
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))//源地址和目的地址不重叠，低字节向高字节拷贝  
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else                       //源地址和目的地址重叠，高字节向低字节拷贝  
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}

int main()
{

	return 0;
}

#endif

#if 0
// 链表

#include<iostream>
using namespace std;

typedef int DataType;
#define Node ElemType
#define ERROR NULL

class Node
{
public:
	int data;    
	Node * next; 
};

class LinkList
{
public:
	LinkList();					  
	~LinkList();                     
	void TravalLinkList();        
	int GetLength();              
	bool IsEmpty();               
	ElemType * Find(DataType data); 
	void InsertElemAtEnd(DataType data);            
	void InsertElemAtIndex(DataType data, int n);    
	void InsertElemAtHead(DataType data);           
	void DeleteElemAtEnd();       
	void DeleteAll();             
	void DeleteElemAtPoint(DataType data);     
	void DeleteElemAtHead(); 
	void Reverse_Dir();
	ElemType *Reverse_Recursion(ElemType *pNode);
	void Reverse_Recursion_(ElemType *pNode);
	void Print();
	ElemType *GetHead();
private:
	ElemType * head;              //头结点
};

ElemType *LinkList::GetHead()
{
	return head;
}

LinkList::LinkList()
{
	head = new ElemType;
	head->data = -1;
	head->next = NULL;
}

LinkList::~LinkList()
{
	if (head)
	{
		delete head;
		head = NULL;
	}
}

void LinkList::InsertElemAtEnd(DataType data)
{
	ElemType *node = new ElemType;
	node->data = data;
	ElemType *pNode = head;
	if (!head)
	{
		head = node;
	}
	else
	{
		while (pNode->next)
		{
			pNode = pNode->next;
		}

		node->next = NULL;
		pNode->next = node;
	}
}

void LinkList::Print()
{
	ElemType *pNode = head;
	while (pNode)
	{
		cout << pNode->data << ", ";
		pNode = pNode->next;
	}
	cout << endl;
}

void LinkList::InsertElemAtHead(DataType data)
{
	ElemType *node = new ElemType;
	node->data = data;

	ElemType *pNode = head;
	if (!head)
	{
		head = node;
	}
	else
	{
		ElemType *pNode_ = head->next;
		pNode->next = node;
		node->next = pNode_;
	}
}

void LinkList::DeleteElemAtEnd()
{
	if (!head)
	{
		return ;
	}
	else if (!head->next)
	{
		return ;
	}
	ElemType *pNode = new ElemType;
	ElemType *pTmp = NULL;
	pNode = head->next;
	while (pNode->next)
	{
		pTmp = pNode;
		pNode = pNode->next;
	}

	delete pNode;
	pNode = NULL;
	pTmp->next = NULL;
}

void LinkList::DeleteElemAtHead()
{
	if (!head)
	{
		return;
	}
	else if (!head->next) //链表空
	{
		return;
	}

	ElemType *pNode = head->next;
	head->next = pNode->next;
	delete pNode;
	pNode = NULL;

}

// 就地头插
void LinkList::Reverse_Dir()
{
	if (!head || !head->next)
	{
		return;
	}
	else
	{
		ElemType *p = head->next;
		ElemType *q = NULL;
		while (p->next)
		{
			q = p->next;
			p->next = q->next;
			q->next = head->next;
			head->next = q;
		}
	}
}

// 带返回值
ElemType *LinkList::Reverse_Recursion(ElemType *pNode)
{
	if (NULL == pNode || NULL == pNode->next)
		return pNode;

	ElemType *newhead = Reverse_Recursion(pNode->next);
	if (pNode != head){
		pNode->next->next = pNode;
		pNode->next = NULL;
		return newhead;
	}
	else {
		pNode->next = newhead;
		return pNode;
	}
}

// 无返回值
void LinkList::Reverse_Recursion_(ElemType *pNode)
{
	if (NULL == pNode || NULL == pNode->next)
		return;

	Reverse_Recursion_(pNode->next);
	if (pNode != head){
		pNode->next->next = pNode;
		pNode->next = NULL;
		return;
	}
	else {
		pNode->next = head;
		return;
	}
}


// 无头节点递归逆序


int main()
{
	//带头节点的单链表，头节点数据域为-1
	LinkList l;
	l.InsertElemAtEnd(1);
	l.InsertElemAtEnd(2);
	l.InsertElemAtHead(0);
	l.InsertElemAtEnd(3);
	l.InsertElemAtEnd(4);
	l.Print();
	l.DeleteElemAtEnd();
	l.Print();
	l.DeleteElemAtHead();
	l.Print();
	l.Reverse_Dir();
	l.Print();
	l.Reverse_Recursion(l.GetHead());
	l.Print();
	//l.Reverse_Recursion_(l.GetHead());
	l.Print();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <set>
using namespace std;

void Print(set<int> &s)
{
	set<int>::iterator iterB = s.begin();
	set<int>::iterator iterE = s.end();
	for (; iterB != iterE; ++iterB)
	{
		cout << *iterB << ",";
	}
	cout << endl;
}

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(5);
	s.insert(0);
	Print(s);
	return 0;
}
#endif

// 实现栈(默认数组存储，非链表)
#if 0
#include <iostream>
using namespace std;

typedef int DataType;
const int MAXSIZE = 5;

class Stack{
public:
	// 栈初始化
	void Init();
	// 入栈
	void Push(DataType data);
	// 出栈
	void Pop();
	// 栈满
	bool IsFull();
	// 栈空
	bool IsEmpty();
	// 获取头部
	DataType GetHead();
	// 栈的大小
	int GetSize();
	// 打印栈信息
	void Print();
private:
	int m_top;
	DataType m_stack[MAXSIZE];
};

void Stack::Init()
{
	m_top = 0;
}

bool Stack::IsEmpty()
{
	if (0 == m_top)
		return true;
	else
		return false;
}

bool Stack::IsFull()
{
	if (m_top > MAXSIZE)
		return true;
	else
		return false;
}

void Stack::Push(DataType data)
{
	if (!IsFull())
	{
		m_stack[m_top++] = data;
	}
	else
	{
		cout << "队列满" << endl;
	}
}

void Stack::Pop()
{
	DataType x;
	if (!IsEmpty())
	{
		x = m_stack[--m_top];
	}
	else
	{
		cout << "队列空" << endl;
	}
}

int Stack::GetSize()
{
	return m_top;
}

DataType Stack::GetHead()
{
	if (!IsEmpty())
	{
		return m_stack[m_top - 1];
	}
	else
	{
		cout << "队列空" << endl;
		return -1;
	}
}

void Stack::Print()
{
	while (!IsEmpty())
	{
		cout << m_stack[--m_top] << ",";
	}
	cout << endl;
}

int main()
{
	Stack s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	s.Pop();
	cout << s.GetHead() << endl;
	return 0;
}
#endif

// 实现队列(默认数组存储，非链表)

// 双栈实现一个队列(默认数组存储，非链表)

// 实现链式队列

// 实现链式栈