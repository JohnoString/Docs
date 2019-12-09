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
int Partitions(int a[], int low, int high)
{
	if (low >= high)     //先检查左右条件
		return -1;
	int i = low, j = high, x = a[low];
	while (i < j)
	{
		while (i < j && a[j] >= x)//从右向左找到第一个小于x的
			j--;
		if (i < j)
			a[i++] = a[j];//填坑之后i++
		while (i < j && a[i] <= x)//从左向右找第一个大于x的数
			i++;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = x;     //把最开始取出来的x放到i处
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

// 堆排

int main()
{
	int arr[10] = { 10, 4, 56, 76, 34, 23, 78, 0, -1, 43 };
	//SelectSort(arr, sizeof(arr) / sizeof(int));
	QuickSort(arr, 0, 9);
	Print(arr, sizeof(arr) / sizeof(int));
	return 0;
}
#endif

// 树
#if 0
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree tree;
	cout << "按前序遍历方式创建树" << endl;
	//"ABDG##H###CE#I##F##";
	tree.Create();
	cout << "树的高度为：" << tree.getHeight() << endl;
	cout << "树的节点为：" << tree.getSize() << endl;
	tree.preOrder();			//前序遍历
	tree.inOrder();				//中序遍历
	tree.postOrder();			//后序遍历
	tree.distroy();				//摧毁树
	system("pause");
	return 0;
}
#endif

// 图
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// 数据结构——》堆
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

// *模式匹配算法(KMP)
#if 0
#include <iostream>
#include <string>
using namespace std;

// 暴力匹配
int BF(const char *str, const char *substr)   //暴力匹配算法
{
	int i = 0, j = 0, k = i;
	while (i < strlen(str) && j < strlen(substr)) {
		if (str[i] == substr[j]) {
			++i;
			++j;
		}
		else {
			j = 0;
			i = ++k;//匹配失败，i从主串的下一位置开始，k中记录了上一次的起始位置
		}
	}
	if (j >= strlen(substr)) {
		return k;
	}
	else
		return -1;
}

// 计算next数组
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

// KMP算法
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

// 哈希
#if 0
/*******************************************************************************
功    能：哈希表——链表法(+/- 1^2,2^2,3^2...)
创建时间：
作    者：
修改时间：
作    者：
********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <malloc.h>
using namespace std;

#define MAXTABLESIZE 10000 //允许开辟的最大散列表长度
#define KEYLENGTH 100      //关键字的最大长度

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
	int tablesize;  //表的最大长度
	LinkList heads; //存放散列单元数据的数组
};
typedef struct TblNode *HashTable;

/*返回大于n且不超过MAXTABLESIZE的最小素数*/
int NextPrime(int n)
{
	int p = (n % 2) ? n + 2 : n + 1; //从大于n的下一个奇数开始
	int i;
	while (p <= MAXTABLESIZE)
	{
		for (i = (int)sqrt(p); i > 2; i--)
		{
			if ((p % i) == 0)
				break;
		}
		if (i == 2)
			break; //说明是素数，结束
		else
			p += 2;
	}
	return p;
}

/*创建新的哈希表*/
HashTable CreateTable(int table_size)
{
	HashTable h = (HashTable)malloc(sizeof(TblNode));
	h->tablesize = NextPrime(table_size);
	h->heads = (LinkList)malloc(h->tablesize * sizeof(LNode));
	//初始化表头结点
	for (int i = 0; i < h->tablesize; i++)
	{
		h->heads[i].next = NULL;
	}
	return h;
}

/*查找数据的初始位置*/
int Hash(ElementType key, int n)
{
	//这里只针对大小写
	return key % 11;
}

/*查找元素位置*/
LinkList Find(HashTable h, ElementType key)
{
	int pos;

	pos = Hash(key, h->tablesize); //初始散列位置

	LinkList p = h->heads[pos].next; //从链表的第一个节点开始
	while (p && key != p->data)
	{
		p = p->next;
	}

	return p;
}

/*插入新的元素*/
bool Insert(HashTable h, ElementType key)
{
	LinkList p = Find(h, key); //先查找key是否存在
	if (!p)
	{
		//关键词未找到，可以插入
		LinkList new_cell = (LinkList)malloc(sizeof(LNode));
		new_cell->data = key;
		int pos = Hash(key, h->tablesize);
		new_cell->next = h->heads[pos].next;
		h->heads[pos].next = new_cell;
		return true;
	}
	else
	{
		cout << "键值已存在！" << endl;
		return false;
	}
}

/*销毁链表*/
void DestroyTable(HashTable h)
{
	int i;
	LinkList p, tmp;
	//释放每个节点
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
		Insert(h, a[i]); //插入元素
	}
	for (int i = 0; i < h->tablesize; i++)
	{
		LinkList p = h->heads[i].next;
		while (p)
		{
			cout << p->data << " "; //打印哈希表元素
			p = p->next;
		}
		cout << endl;
	}
	return 0;
}
#endif

// 二分查找
#if 0
#include <iostream>
using namespace std;

// 循环
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

// 递归
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

// 华为机试字符串
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// MARKDOWN文本 -> HTML标题
#if 0
#include <iostream>
#include <vector>
using namespace std;

vector<string> GetHtmlTitle(const vector<string> &v)
{
	if (v.empty())
		return v;

	// 过滤标题, 获取井号个数
	vector<string> vTmp; // 过滤后的
	vector<string> vRes; // 结果
	vector<int> vNum;   //井号个数
	vector<string> vTitle; // 标题不含空格后
	vector<string> vtxt;   // 标题空格后内容
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].front() == '#' && v[i].find_first_of(' ') != -1)
		{
			vTmp.push_back(v[i]);
			vNum[i] = v[i].find_first_of(' ');
			vtxt.push_back(v[i].substr(vNum[i]);
		}
	}

	// 生成标题头
	for (int j = 0; j < vTmp.size(); j += 2)
	{
		// 井号个数
		vNum[j] = vTmp[j].find_first_of(' ');

		vTitle.push_back(GetLineTitle(vNum[j], vTitle[j], vNum[j + 1]));
	}

	// 生成标题
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

// 端口合并
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
	
	// 截取每一行端口, 逗号后面默认无空格
	vector<Ports> vPorts; // 存端口范围数组
	map<int, vector<Ports> > mapPorts; // 存所有行端口范围
	vector<string> vsPorts; // 存去掉逗号之后的字符串数组
	int pos = 0;
	string strTmp = "";
	bool IsTrue = true;
	for (int i = 0; i < vs.size(); ++i)
	{
		// 解析字符串去掉逗号
		for (int j = 0; IsTrue; j = pos + 1)
		{
			pos = vs[i].find(',', j);
			if (pos != vs[i].npos)
			{
				strTmp = vs[i].substr(j, pos - j);
				cout << strTmp << endl;
				// 生成端口范围数组
				vsPorts.push_back(strTmp);
			}
			else
			{
				strTmp = vs[i].substr(j);
				cout << strTmp << endl;
				// 生成端口范围数组
				vsPorts.push_back(strTmp);
				IsTrue = false;
				break;
			}
		}

		// 端口范围压入map待匹配
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
		getline(cin, strTmp);  // 暂未验证合法性(默认合法)
		vs.push_back(strTmp);
	}

	cout << MergePorts(vs) << endl;
	return 0;
}
#endif