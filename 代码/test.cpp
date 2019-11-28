#if 0
#include <iostream>
using namespace std;

int GetLeastCommonMultiple(const int &m, const int &n)
{
    if (0 == m || 0 == n)
    {
        return 0;
    }
    
    if (1 == m)
    {
        return n; 
    }
    
    if (1 == n)
    {
        return m;
    }
    
    int t;
	int nt = n;
	int mt = m;
    while (mt % nt != 0)
    {
        t = mt % nt;
        mt = nt;
        nt = t;
    }
    
    return m * n / nt;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << GetLeastCommonMultiple(m, n) << endl;
    return 0;
}
#endif

#if 0
//4d1 ��������� ̰���㷨
#include <iostream> 
using namespace std; 
 
const int N = 11;

int GreedySelector(int n, int s[], int f[], bool A[])
{
	A[1]=true;
	int j=1;//��¼���һ�μ���A�еĻ
	int num = 1;
	for (int i=2;i<=n;i++)//���μ��i�Ƿ��뵱ǰ��ѡ��Ļ����
	{
		if (s[i]>=f[j])
		{ 
			A[i]=true;
			j=i;

		}
		else
		{
			A[i]=false;
			num++;
		}
	}

	return num;
}

int main()
{
	//�±��1��ʼ,�洢���ʼʱ��
	int s[] = {0,1,3,0,5,3,5,6,8,8,2,12};
 
	//�±��1��ʼ,�洢�����ʱ��
	int f[] = {0,4,5,6,7,8,9,10,11,12,13,14};
 
	bool A[N+1];
 
	cout<<"����Ŀ�ʼʱ��,����ʱ��ֱ�Ϊ��"<<endl;
	for(int i=1;i<=N;i++)
	{
		cout<<"["<<i<<"]:"<<"("<<s[i]<<","<<f[i]<<")"<<endl;
	}
	cout << GreedySelector(N,s,f,A) << endl;
	cout<<"������ݻ�Ӽ�Ϊ��"<<endl;
	for(int i=1;i<=N;i++)
	{
		if(A[i]){
			cout<<"["<<i<<"]:"<<"("<<s[i]<<","<<f[i]<<")"<<endl;
		}
	}
 
	return 0;
}
#endif

// ��̬�滮�������㵺������
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// ����ͼ:���������ݽṹ����Ϊ����洢����
#if 0
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

queue<char> q;				
#define MVNum 7			
int visited[MVNum];		

typedef struct AMGraph
{
	int vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

int LocateVex(AMGraph &G, char v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
}

int CreateUDG_1(AMGraph &G)
{
	int i, j, k;
	int v1, v2;
	cout << "���붥�����������" << endl;
	scanf("%d%d", &G.vexnum, &G.arcnum);	

	cout << "��ʼ������" << endl;
	for (i = 0; i < G.vexnum; i++)	
	{
		scanf("%d", &G.vexs[i]);	
	}		
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;	

	cout << "��ʼ����, �����ظ�" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%d%d", &v1, &v2);			
		i = LocateVex(G, v1);				
		j = LocateVex(G, v2);				
		G.arcs[i][j] = G.arcs[j][i] = 1;	
	}

	return 1;
}

// �ڽӾ��������ȱ�����ͨͼ
void BFS_AM(AMGraph &G,char v0)
{

	int u,i,v,w;
	v = LocateVex(G,v0);
	printf("%d ", v0); 
	visited[v] = 1;		
	q.push(v0);			
 
	while (!q.empty())
	{
		u = q.front();				
		v = LocateVex(G, u);			
		q.pop();				
		for (i = 0; i < G.vexnum; i++)
		{
			w = G.vexs[i];
			if (G.arcs[v][i] && !visited[i])
			{
				printf("%d ", w);	
				q.push(w);		
				visited[i] = 1;		
			}
		}
	}
}

/*���������������ͨͼ*/
void BFSTraverse(AMGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;							//��visited�����ʼ��
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) BFS_AM(G, G.vexs[v]);	                        //����δ���ʵĶ������BFS
}

// �ڽӾ���������ȱ���
void DFS_AM(AMGraph &G, int v)
{
	int w;
	printf("%d ", G.vexs[v]);
	visited[v] = 1;
	for (w = 0; w < G.vexnum; w++)
		if (G.arcs[v][w]&&!visited[w]) //�ݹ����
			DFS_AM(G,w);
}

// ��С������


int main()
{
	AMGraph amG;
	if (CreateUDG_1(amG))
	{
		BFS_AM(amG, 1); // �ڶ�������ָ���Ƕ���ֵ
	}
	
	cout << endl;

	DFS_AM(amG, 1); // �ڶ�������ָ�����±�
	return 0;
}

#endif

#if 0
#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
#define M  100000
#define len 22
using namespace std;
string str[1005];

int cmp(string a, string b)
{
    return a.compare(b) < 0;
}

int main()
{
    int n;
    cin >> n;               // ���ɻس���
	//scanf_s("%d", &n);
	getchar();             // ��������ַ�����
    for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
	}

    sort(str, str + n, cmp);
	
	for (int j = 0; j < n; j++)
	{
		cout << str[j] << endl;
	}

    return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
int binarySearch(int *arr , int low , int high , int target)//�ݹ�ʵ��
{
	int middle = (low + high)/2;
	if(low > high)
		return -1;
	if(arr[middle] == target)
		return middle;
	if(arr[middle] > target)
		return binarySearch( arr , low , middle - 1 , target);
	if(arr[middle] < target)
		return binarySearch( arr , middle + 1 , high , target);
 
};
 
int binarySearch1(int a[], int n , int target)//ѭ��ʵ��
{
	int low = 0 ,high = n , middle;
	while(low < high)
	{
	   middle = (low + high)/2;
       if(target == a[middle])
		   return middle;
	   else if(target > a[middle])
		   low = middle +1;
	   else if(target < a[middle])
		   high = middle;
	}
	return -1;
};
 
int main()
{
	int a[10] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int index = binarySearch( a , 0 , 9 , 12);
	cout<<index<< endl;
	int index2 = binarySearch1(a,10,12);
	cout<<index2<< endl;
	system("pause");
}
#endif


// ��ά�������·��
#if 0
#include<iostream>
using namespace std;
const int maxn = 1001;                      //�������ֵ
int M,N,K=0;                                //M��N�У�·����K�����
int D[maxn][maxn];                          //�洢ԭʼ����ֵ
int dp[maxn][maxn];                         //��D[0][0]��D[i][j]·����Сֵ
int mp[maxn];                               //����·���еĽ��ֵ
int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            cin >> D[i][j];
    dp[0][0]=D[0][0];
    for(int i=1; i<M; i++)
        dp[i][0] = dp[i-1][0]+ D[i][0];     //���ڵ�һ�еĵ�D[i][0]��ֻ�����Ǵ�����ĵ�D[i-1][0]������
    for(int j=1; j<N; j++)
        dp[0][j] = dp[0][j-1]+ D[0][j];     //���ڵ�һ�еĵ�D[0][j]��ֻ�����Ǵ���ߵĵ�D[0][j-1]������
    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)              //��D[i][j]���Ǵ�D[i][j-1]��D[i-1][j]��С�Ķ���
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + D[i][j];
    int i=M-1,j=N-1;
    mp[K++]=D[i][j];
    while(i>=0 && j>=0){                    //������·���ϵĵ�
        if(i==0 && j==0){
            break;
        } else if(i==0){                    //�ڵ�һ���ϣ���ô��һ����ֻ������ߵĵ�
            mp[K++]=D[i][j-1];
            j--;
        } else if(j==0){                    //�ڵ�һ���ϣ���ô��һ����ֻ��������ĵ�
            mp[K++]=D[i-1][j];
            i--;
        } else {                            //���������ߺ������dp��С��Ӧ���Ǹ���D
            if(dp[i-1][j]<dp[i][j-1]){
                mp[K++]=D[i-1][j];
                i--;
            } else {
                mp[K++]=D[i][j-1];
                j--;
            }
        }
    }
 
    cout << endl << dp[M-1][N-1] <<endl;
    return 0;
}
#endif

#if 0
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(0);
	s.insert(1);
	s.insert(1);

	set<int>::iterator iBegin = s.begin();
	set<int>::iterator iEnd = s.end();
	for (; iBegin != iEnd; ++iBegin)
	{
		cout << *iBegin << endl;
	}

	return 0;
}
#endif

#if 1
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	//const char * p = NULL;
	//*p = 0;                    //���ܱ�
	//p = (const char*)0x00123;  //���Ա�
	//char str[100] = "asf";
	//char* const q = str:
	//q = 0x1231232123;

	void * (*(*fp1)(int))[10]; 
	float (*(*fp2)(int,int,int))(int);
	int (*(*fp3)())[10](); 

	return 0;
}

#endif