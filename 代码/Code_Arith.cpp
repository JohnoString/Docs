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
int Partitions(int a[], int low, int high)
{
	if (low >= high)     //�ȼ����������
		return -1;
	int i = low, j = high, x = a[low];
	while (i < j)
	{
		while (i < j && a[j] >= x)//���������ҵ���һ��С��x��
			j--;
		if (i < j)
			a[i++] = a[j];//���֮��i++
		while (i < j && a[i] <= x)//���������ҵ�һ������x����
			i++;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = x;     //���ʼȡ������x�ŵ�i��
	return i;
}
void QuickSort(int a[], int low, int high)
{

	if (low < high)
	{
		int q = Partitions(a, low, high);
		QuickSort(a, low, q - 1);
		QuickSort(a, q + 1, high);
	}
}

// ����

int main()
{
	int arr[10] = { 10, 4, 56, 76, 34, 23, 78, 0, -1, 43 };
	//SelectSort(arr, sizeof(arr) / sizeof(int));
	QuickSort(arr, 0, 9);
	Print(arr, sizeof(arr) / sizeof(int));
	return 0;
}
#endif

// ��
#if 0
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree tree;
	cout << "��ǰ�������ʽ������" << endl;
	//"ABDG##H###CE#I##F##";
	tree.Create();
	cout << "���ĸ߶�Ϊ��" << tree.getHeight() << endl;
	cout << "���Ľڵ�Ϊ��" << tree.getSize() << endl;
	tree.preOrder();			//ǰ�����
	tree.inOrder();				//�������
	tree.postOrder();			//�������
	tree.distroy();				//�ݻ���
	system("pause");
	return 0;
}
#endif

// ͼ
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// ���ݽṹ��������
#if 0
#include<iostream>
#include<algorithm>
#define maxn 1001   //heap's size

using namespace std;

struct Heap {
	int size;   // number of elements in array
	int *array;
	Heap() {    //init
		size = 0;
		array = new int[maxn];
	}
	Heap(int n) {   //init
		size = 0;
		array = new int[n];
	}
	~Heap() {   //free memory
		delete array;
	}
	bool empty() {
		if(size != 0) return false;
		return true;
	}
	void insert(int value) {
		array[++size] = value;
		int index = size;
		while(index > 1) {
			if(array[index] > array[index/2]) swap(array[index],array[index/2]);
			index /= 2;
		}
	}
	void del() 
	{
		if(empty()) return;
		swap(array[1],array[size--]);
		int index = 1;
		while(2*index <= size) 
		{
			int next = 2*index;
			if(next < size && array[next+1] > array[next]) next++;
			if(array[index] < array[next]) 
			{
				swap(array[index],array[next]);
				index = next;
			} else break;
		}
	}
	int max() {
		if(empty()) return -1;
		return array[1];
	}
};
void buildHeap(int array[],int size) {
	int i,tmp,index;
	for(i = size/2; i >= 1; i--) {
		tmp = array[i];
		index = 2*i;
		while(index <= size) {
			if(index < size && array[index+1] > array[index]) index++;
			if(array[index] < tmp) break;
			array[index/2]  = array[index];
			index *= 2;
		}
		array[index/2] = tmp;
	}
}
int main() {
	int n,i,j,k;
	cout << "input heap's size:";
	cin >> n;
	Heap H = Heap(n);
	int* array = new int[n];
	for(i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		array[i] = tmp;
		H.insert(tmp);
	}
	buildHeap(array,n);
	for(i = 1; i <= n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	//while(!H.empty()) {
	//	cout << H.max() << endl;
	//	H.del();
	//}
	return 0;
};
#endif

// *ģʽƥ���㷨(KMP)
#if 0
#include <iostream>
#include <string>
using namespace std;

// ����ƥ��
int BF(const char *str, const char *substr)   //����ƥ���㷨
{
	int i = 0, j = 0, k = i;
	while (i < strlen(str) && j < strlen(substr)) {
		if (str[i] == substr[j]) {
			++i;
			++j;
		}
		else {
			j = 0;
			i = ++k;//ƥ��ʧ�ܣ�i����������һλ�ÿ�ʼ��k�м�¼����һ�ε���ʼλ��
		}
	}
	if (j >= strlen(substr)) {
		return k;
	}
	else
		return -1;
}

// ����next����
void getNext(const char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < strlen(p) - 1)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

// KMP�㷨
int KMP(const char * t, const char * p, int next[])
{
	int i = 0;
	int j = 0;

	while (i < strlen(t) && j < strlen(p))
	{
		if (j == -1 || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == strlen(p))
		return i - j;
	else
		return -1;
}

int main()
{
	string strParent = "abababcaafjasksfajfabcdabhasdjkfhjaskdsdaaabababcabcdabdSFJAFSDASJK";
	char strSub[] = "abababca";
	int next[sizeof(strSub) - 1];
	//getNext(strSub, next);
	cout << BF(strParent.c_str(), strSub) << endl;
	//cout << KMP(strParent.c_str(), strSub, next) << endl;
	return 0;
}
#endif

// ��ϣ
#if 0
/*******************************************************************************
��    �ܣ���ϣ��������(+/- 1^2,2^2,3^2...)
����ʱ�䣺
��    �ߣ�
�޸�ʱ�䣺
��    �ߣ�
********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <malloc.h>
using namespace std;

#define MAXTABLESIZE 10000 //�����ٵ����ɢ�б���
#define KEYLENGTH 100      //�ؼ��ֵ���󳤶�

typedef int ElementType;
struct LNode
{
	ElementType data;
	LNode *next;
};
typedef LNode *PtrToNode;
typedef PtrToNode LinkList;
struct TblNode
{
	int tablesize;  //�����󳤶�
	LinkList heads; //���ɢ�е�Ԫ���ݵ�����
};
typedef struct TblNode *HashTable;

/*���ش���n�Ҳ�����MAXTABLESIZE����С����*/
int NextPrime(int n)
{
	int p = (n % 2) ? n + 2 : n + 1; //�Ӵ���n����һ��������ʼ
	int i;
	while (p <= MAXTABLESIZE)
	{
		for (i = (int)sqrt(p); i > 2; i--)
		{
			if ((p % i) == 0)
				break;
		}
		if (i == 2)
			break; //˵��������������
		else
			p += 2;
	}
	return p;
}

/*�����µĹ�ϣ��*/
HashTable CreateTable(int table_size)
{
	HashTable h = (HashTable)malloc(sizeof(TblNode));
	h->tablesize = NextPrime(table_size);
	h->heads = (LinkList)malloc(h->tablesize * sizeof(LNode));
	//��ʼ����ͷ���
	for (int i = 0; i < h->tablesize; i++)
	{
		h->heads[i].next = NULL;
	}
	return h;
}

/*�������ݵĳ�ʼλ��*/
int Hash(ElementType key, int n)
{
	//����ֻ��Դ�Сд
	return key % 11;
}

/*����Ԫ��λ��*/
LinkList Find(HashTable h, ElementType key)
{
	int pos;

	pos = Hash(key, h->tablesize); //��ʼɢ��λ��

	LinkList p = h->heads[pos].next; //������ĵ�һ���ڵ㿪ʼ
	while (p && key != p->data)
	{
		p = p->next;
	}

	return p;
}

/*�����µ�Ԫ��*/
bool Insert(HashTable h, ElementType key)
{
	LinkList p = Find(h, key); //�Ȳ���key�Ƿ����
	if (!p)
	{
		//�ؼ���δ�ҵ������Բ���
		LinkList new_cell = (LinkList)malloc(sizeof(LNode));
		new_cell->data = key;
		int pos = Hash(key, h->tablesize);
		new_cell->next = h->heads[pos].next;
		h->heads[pos].next = new_cell;
		return true;
	}
	else
	{
		cout << "��ֵ�Ѵ��ڣ�" << endl;
		return false;
	}
}

/*��������*/
void DestroyTable(HashTable h)
{
	int i;
	LinkList p, tmp;
	//�ͷ�ÿ���ڵ�
	for (i = 0; i < h->tablesize; i++)
	{
		p = h->heads[i].next;
		while (p)
		{
			tmp = p->next;
			free(p);
			p = tmp;
		}
	}
	free(h->heads);
	free(h);
}

int main(int argc, char const *argv[])
{
	int a[] = { 47, 7, 29, 29, 11, 16, 92, 22, 8, 3, 50, 37, 89, 94, 21 };
	int n = 15;
	HashTable h = CreateTable(n);
	for (int i = 0; i < n; i++)
	{
		Insert(h, a[i]); //����Ԫ��
	}
	for (int i = 0; i < h->tablesize; i++)
	{
		LinkList p = h->heads[i].next;
		while (p)
		{
			cout << p->data << " "; //��ӡ��ϣ��Ԫ��
			p = p->next;
		}
		cout << endl;
	}
	return 0;
}
#endif

// ���ֲ���
#if 0
#include <iostream>
using namespace std;

// ѭ��
int binSearch(int srcArray[], int key, int len) {
	int mid;
	int start = 0;
	int end = len - 1;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (key < srcArray[mid]) {
			end = mid - 1;
		}
		else if (key > srcArray[mid]) {
			start = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

// �ݹ�
int binSearch_(int srcArray[], int start, int end, int key) {
	int mid = (end - start) / 2 + start;
	if (srcArray[mid] == key) {
		return mid;
	}
	if (start >= end) {
		return -1;
	}
	else if (key > srcArray[mid]) {
		return binSearch_(srcArray, mid + 1, end, key);
	}
	else if (key < srcArray[mid]) {
		return binSearch_(srcArray, start, mid - 1, key);
	}

	return -1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << binSearch(arr, 7, 10) << endl;
	cout << binSearch_(arr, 0, 9, 5) << endl;

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

// MARKDOWN�ı� -> HTML����
#if 0
#include <iostream>
#include <vector>
using namespace std;

vector<string> GetHtmlTitle(const vector<string> &v)
{
	if (v.empty())
		return v;

	// ���˱���, ��ȡ���Ÿ���
	vector<string> vTmp; // ���˺��
	vector<string> vRes; // ���
	vector<int> vNum;   //���Ÿ���
	vector<string> vTitle; // ���ⲻ���ո��
	vector<string> vtxt;   // ����ո������
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].front() == '#' && v[i].find_first_of(' ') != -1)
		{
			vTmp.push_back(v[i]);
			vNum[i] = v[i].find_first_of(' ');
			vtxt.push_back(v[i].substr(vNum[i]);
		}
	}

	// ���ɱ���ͷ
	for (int j = 0; j < vTmp.size(); j += 2)
	{
		// ���Ÿ���
		vNum[j] = vTmp[j].find_first_of(' ');

		vTitle.push_back(GetLineTitle(vNum[j], vTitle[j], vNum[j + 1]));
	}

	// ���ɱ���
	for (int a = 0; a < vTmp.size(); ++a)
	{
		vRes[a] += vTitle[a];
		vRes[a] += vtxt[a];
	}

	return vRes;
}


string GetFirstLineTitle(const int &a)
{
	string sT = "1";
	for (int i = 0; i < a; i++)
	{
		sT += ".1";
	}
}

string GetLineTitle(const int &a, const string & sa, const int &b)
{
	string sb = sa;
	if (a > b)
	{
		int j = a - 1;
		for (int i = 0 ; i < a - b; i++)
		{
			j = j - 2;
		}

		sb[j] = char(sa[j] + 1);
	}
	else if (a == b)
	{
		sb[a - 1] = char(sa[a - 1] + 1);
	}
	else
	{
		for (int i = 0; i < b - a; i++)
		{
			sb += ".1";
		}
	}

	return sb;
}

int main()
{
	return 0;
}
#endif

// �˿ںϲ�
#if 0
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

typedef struct PortRange
{
	long maxPort;
	long minPort;
}Ports;

string MergePorts(const vector<string> & vs)
{
	if (vs.empty())
	{
		return "";
	}
	
	// ��ȡÿһ�ж˿�, ���ź���Ĭ���޿ո�
	vector<Ports> vPorts; // ��˿ڷ�Χ����
	map<int, vector<Ports> > mapPorts; // �������ж˿ڷ�Χ
	vector<string> vsPorts; // ��ȥ������֮����ַ�������
	int pos = 0;
	string strTmp = "";
	bool IsTrue = true;
	for (int i = 0; i < vs.size(); ++i)
	{
		// �����ַ���ȥ������
		for (int j = 0; IsTrue; j = pos + 1)
		{
			pos = vs[i].find(',', j);
			if (pos != vs[i].npos)
			{
				strTmp = vs[i].substr(j, pos - j);
				cout << strTmp << endl;
				// ���ɶ˿ڷ�Χ����
				vsPorts.push_back(strTmp);
			}
			else
			{
				strTmp = vs[i].substr(j);
				cout << strTmp << endl;
				// ���ɶ˿ڷ�Χ����
				vsPorts.push_back(strTmp);
				IsTrue = false;
				break;
			}
		}

		// �˿ڷ�Χѹ��map��ƥ��
		mapPorts[i] = vPorts;
	}

	return "";
}

// 
long StringToLong(const string & strPort)
{
	long a = 0;
	stringstream ss;
	ss << strPort;
	ss >> a;
	return a;
}
// 
string LongToString(const int & iPort)
{
	string res = "";
	stringstream ss;         
	ss << iPort;                      
	ss >> res;  
	return res;
}

int main()
{
	int n;
	cin >> n;               
	vector<string> vs;
	getchar();  
	string strTmp = "";
	for (int i = 0; i < n; i++)
	{
		getline(cin, strTmp);  // ��δ��֤�Ϸ���(Ĭ�ϺϷ�)
		vs.push_back(strTmp);
	}

	cout << MergePorts(vs) << endl;
	return 0;
}
#endif