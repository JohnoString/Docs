#if 0
// ʵ��strcpy����
#include <iostream>
#include <cassert>
using namespace std;

char *strcpy(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL)); // 2��
	char *address = strDest; // 2��
	while ((*strDest++ = *strSrc++) != '\0') // 2��
		NULL;
	return address; // 2��
}

void * my_memcpy(void *dst, const void *src, unsigned int count)
{
	assert(dst);
	assert(src);
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))//Դ��ַ��Ŀ�ĵ�ַ���ص������ֽ�����ֽڿ���  
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else                       //Դ��ַ��Ŀ�ĵ�ַ�ص������ֽ�����ֽڿ���  
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

// �����������
#if 0
// ����

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
	ElemType * head;              //ͷ���
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
	else if (!head->next) //�����
	{
		return;
	}

	ElemType *pNode = head->next;
	head->next = pNode->next;
	delete pNode;
	pNode = NULL;

}

// �͵�ͷ��
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

// ������ֵ
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

// �޷���ֵ
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


// ��ͷ�ڵ�ݹ�����


int main()
{
	//��ͷ�ڵ�ĵ�����ͷ�ڵ�������Ϊ-1
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

// ʵ��ջ(Ĭ������洢��������)
#if 0
#include <iostream>
using namespace std;

typedef int DataType;
const int MAXSIZE = 5;

class Stack{
public:
	// ջ��ʼ��
	void Init();
	// ��ջ
	void Push(DataType data);
	// ��ջ
	void Pop();
	// ջ��
	bool IsFull();
	// ջ��
	bool IsEmpty();
	// ��ȡͷ��
	DataType GetHead();
	// ջ�Ĵ�С
	int GetSize();
	// ��ӡջ��Ϣ
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
		cout << "ջ��" << endl;
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
		cout << "ջ��" << endl;
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
		cout << "���п�" << endl;
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

// ʵ�ֶ���(Ĭ������洢��������)
#if 0
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext; //ָ����
	QDataType _data;        //������
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;  //ͷ���
	QNode* _rear;   //β���
}Queue;

//��ʼ������ 
void QueueInit(Queue* q){
	if (q == NULL){
		return;
	}
	q->_front = (QNode*)malloc(sizeof(QNode));
	if (q->_front == NULL || q->_rear == NULL){  //����ռ�ʧ�ܣ�ֱ���˳�
		return;
	}
	q->_rear = q->_front;       //ͷ�����β������ʱ����Ϊ��
	q->_front->_pNext = NULL;
}

// ��β����� (�൱������β�壩
void QueuePush(Queue* q, QDataType data){
	assert(q != NULL);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL){  //�����ڴ�ʧ�ܾ��˳�
		printf("�����ڴ�ʧ��\n");
		return;
	}
	newnode->_data = data;
	newnode->_pNext = NULL;
	q->_rear->_pNext = newnode;
	q->_rear = newnode;
}

// ��ͷ������ ���൱������ͷɾ��
void QueuePop(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("����Ϊ�գ�������ʧ��\n");
		return;
	}
	QNode* cur = q->_front->_pNext->_pNext;
	free(q->_front->_pNext);
	q->_front->_pNext = cur;
	if (cur == q->_rear->_pNext){
		q->_front = q->_rear;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("���пգ���ȡʧ��");
		return 0;
	}
	return q->_front->_pNext->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("���пգ���ȡʧ��");
		return 0;
	}
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		return 1;
	}
	else{
		return 0;
	}
}

// ���ٶ��� 
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

// ˫ջʵ��һ������(Ĭ������洢��������)

// �������
#if 0
#include <iostream>
using namespace std;



int main()
{
	return 0;
}
#endif

// ʵ����ʽջ

// ����
#if 0
#include <iostream>
using namespace std;

// ð������ - ���αȽ�������Ԫ�أ���ǰһԪ�ش��ں�һԪ���򽻻�֮��ֱ�����һ��Ԫ�ؼ�Ϊ���Ȼ�����´���Ԫ�ؿ�ʼ�ظ�ͬ���Ĳ�����ֱ�������ڶ���Ԫ�ؼ�Ϊ�δ�Ԫ�أ��������ơ���ͬˮ�е����ݣ����ν�������СԪ�����ݸ���ˮ�档

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

// ѡ������ - ���ȳ�ʼ����СԪ������ֵΪ��Ԫ�أ����α������������У�������С�ڸ���С����λ�ô���Ԫ����ˢ����С����Ϊ�ý�СԪ�ص�λ�ã�ֱ������βԪ�أ�����һ�α�����������С������Ԫ������Ԫ�ؽ�����Ȼ�󣬳�ʼ����С����ֵΪ�ڶ�������������Ԫ��λ�ã�ͬ���Ĳ������ɵõ����еڶ���Ԫ�ؼ�Ϊ��СԪ�أ��Դ����ơ�
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

		// ����arr[i]��arr[j]
		int tmp = arr[i];
		arr[i] = arr[k];
		arr[k] = tmp;
	}
}


// �򵥲������� - �ú�������Ԫ�ظ����źõ����ݴӺ���ǰ���αȽϣ���ĺ��ƣ�ֱ������С�������֮ǰ��λ�ã��������ơ�

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


// ����

int main()
{
	int arr[10] = { 10, 4, 56, 76, 34, 23, 78, 0, -1, 43 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
	return 0;
}
#endif

// ��
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// *ģʽƥ���㷨(KMP)
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// ��ϣ
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// ���ֲ���
#if 0
#include <iostream>
using namespace std;

// ѭ��
// �ݹ�

int main()
{
	return 0;
}
#endif

// ��Ϊ�����ַ���
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif