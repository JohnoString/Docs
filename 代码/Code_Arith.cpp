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

// 链表基本操作
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
		cout << "栈满" << endl;
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
		cout << "栈空" << endl;
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
#if 0
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext; //指针域
	QDataType _data;        //数据域
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;  //头结点
	QNode* _rear;   //尾结点
}Queue;

//初始化队列 
void QueueInit(Queue* q){
	if (q == NULL){
		return;
	}
	q->_front = (QNode*)malloc(sizeof(QNode));
	if (q->_front == NULL || q->_rear == NULL){  //申请空间失败，直接退出
		return;
	}
	q->_rear = q->_front;       //头结点与尾结点相等时队列为空
	q->_front->_pNext = NULL;
}

// 队尾入队列 (相当于链表尾插）
void QueuePush(Queue* q, QDataType data){
	assert(q != NULL);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL){  //申请内存失败就退出
		printf("申请内存失败\n");
		return;
	}
	newnode->_data = data;
	newnode->_pNext = NULL;
	q->_rear->_pNext = newnode;
	q->_rear = newnode;
}

// 队头出队列 （相当于链表头删）
void QueuePop(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("队列为空，出队列失败\n");
		return;
	}
	QNode* cur = q->_front->_pNext->_pNext;
	free(q->_front->_pNext);
	q->_front->_pNext = cur;
	if (cur == q->_rear->_pNext){
		q->_front = q->_rear;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("队列空，获取失败");
		return 0;
	}
	return q->_front->_pNext->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("队列空，获取失败");
		return 0;
	}
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q){
	assert(q != NULL);
	QNode* cur = q->_front->_pNext;
	int count = 0;
	while (cur != NULL){
		count++;
		cur = cur->_pNext;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		return 1;
	}
	else{
		return 0;
	}
}

// 销毁队列 
void QueueDestroy(Queue* q){
	assert(q != NULL);
	QNode* cur = q->_front->_pNext;
	while (cur != NULL){
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear;
}

int main()
{
	Queue *node;
	QueueInit(node);

	return 0;
}

#endif

// 双栈实现一个队列(默认数组存储，非链表)

// 数组队列
#if 0
#include <iostream>
using namespace std;



int main()
{
	return 0;
}
#endif

// 实现链式栈

// 排序
#if 0
#include <iostream>
using namespace std;

// 冒泡排序 - 依次比较相邻两元素，若前一元素大于后一元素则交换之，直至最后一个元素即为最大；然后重新从首元素开始重复同样的操作，直至倒数第二个元素即为次大元素；依次类推。如同水中的气泡，依次将最大或最小元素气泡浮出水面。

void BabbleSort(int *arr, const int len)
{
	if (len <= 0)
		return;

	if (NULL == arr)
	{
		return;
	}

	int tmp = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void Print(const int *arr, const int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
}

// 选择排序 - 首先初始化最小元素索引值为首元素，依次遍历待排序数列，若遇到小于该最小索引位置处的元素则刷新最小索引为该较小元素的位置，直至遇到尾元素，结束一次遍历，并将最小索引处元素与首元素交换；然后，初始化最小索引值为第二个待排序数列元素位置，同样的操作，可得到数列第二个元素即为次小元素；以此类推。
void SelectSort(int *arr, const int &n)
{
	for (int i = 0; i < n - 1; ++i)
	{ 
		int j = i + 1; 
		int k = i;
		int t = arr[i];
		for (; j < n; ++j)
		{
			if (arr[j] > t)
			{
				t = arr[j];
				k = j;
			}
		}

		// 交换arr[i]跟arr[j]
		int tmp = arr[i];
		arr[i] = arr[k];
		arr[k] = tmp;
	}
}


// 简单插入排序 - 用后面所有元素跟已排好的数据从后往前依次比较，大的后移，直到遇到小的则插入之前的位置，依次类推。

void InsertSort(int *arr, const int len)
{
	for (int i = 1; i < len; ++i)
	{
		int j = i;
		int tmp = arr[j];
		for (; j > 0; --j)
		{
			if (arr[j] > arr[j - 1])
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}


// 快排

int main()
{
	int arr[10] = { 10, 4, 56, 76, 34, 23, 78, 0, -1, 43 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
	return 0;
}
#endif

// 树
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// *模式匹配算法(KMP)
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// 哈希
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// 二分查找
#if 0
#include <iostream>
using namespace std;

// 循环
// 递归

int main()
{
	return 0;
}
#endif

// 华为机试字符串
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif