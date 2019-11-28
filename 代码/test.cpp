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
//4d1 活动安排问题 贪心算法
#include <iostream> 
using namespace std; 
 
const int N = 11;

int GreedySelector(int n, int s[], int f[], bool A[])
{
	A[1]=true;
	int j=1;//记录最近一次加入A中的活动
	int num = 1;
	for (int i=2;i<=n;i++)//依次检查活动i是否与当前已选择的活动相容
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
	//下标从1开始,存储活动开始时间
	int s[] = {0,1,3,0,5,3,5,6,8,8,2,12};
 
	//下标从1开始,存储活动结束时间
	int f[] = {0,4,5,6,7,8,9,10,11,12,13,14};
 
	bool A[N+1];
 
	cout<<"各活动的开始时间,结束时间分别为："<<endl;
	for(int i=1;i<=N;i++)
	{
		cout<<"["<<i<<"]:"<<"("<<s[i]<<","<<f[i]<<")"<<endl;
	}
	cout << GreedySelector(N,s,f,A) << endl;
	cout<<"最大相容活动子集为："<<endl;
	for(int i=1;i<=N;i++)
	{
		if(A[i]){
			cout<<"["<<i<<"]:"<<"("<<s[i]<<","<<f[i]<<")"<<endl;
		}
	}
 
	return 0;
}
#endif

// 动态规划——计算岛屿数量
#if 0
#include <iostream>
using namespace std;

int main()
{
	return 0;
}
#endif

// 创建图:将抽象数据结构具象为数组存储数据
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
	cout << "输入顶点个数跟边数" << endl;
	scanf("%d%d", &G.vexnum, &G.arcnum);	

	cout << "初始化顶点" << endl;
	for (i = 0; i < G.vexnum; i++)	
	{
		scanf("%d", &G.vexs[i]);	
	}		
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;	

	cout << "初始化边, 不能重复" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%d%d", &v1, &v2);			
		i = LocateVex(G, v1);				
		j = LocateVex(G, v2);				
		G.arcs[i][j] = G.arcs[j][i] = 1;	
	}

	return 1;
}

// 邻接矩阵广度优先遍历连通图
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

/*广度优先搜索非连通图*/
void BFSTraverse(AMGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;							//将visited数组初始化
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) BFS_AM(G, G.vexs[v]);	                        //对尚未访问的顶点调用BFS
}

// 邻接矩阵深度优先遍历
void DFS_AM(AMGraph &G, int v)
{
	int w;
	printf("%d ", G.vexs[v]);
	visited[v] = 1;
	for (w = 0; w < G.vexnum; w++)
		if (G.arcs[v][w]&&!visited[w]) //递归调用
			DFS_AM(G,w);
}

// 最小生成树


int main()
{
	AMGraph amG;
	if (CreateUDG_1(amG))
	{
		BFS_AM(amG, 1); // 第二个参数指的是顶点值
	}
	
	cout << endl;

	DFS_AM(amG, 1); // 第二个参数指的是下标
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
    cin >> n;               // 吞噬回车键
	//scanf_s("%d", &n);
	getchar();             // 需加吞噬字符操作
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
int binarySearch(int *arr , int low , int high , int target)//递归实现
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
 
int binarySearch1(int a[], int n , int target)//循环实现
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


// 二维矩阵最短路径
#if 0
#include<iostream>
using namespace std;
const int maxn = 1001;                      //行列最大值
int M,N,K=0;                                //M行N列，路径有K个结点
int D[maxn][maxn];                          //存储原始矩阵值
int dp[maxn][maxn];                         //从D[0][0]到D[i][j]路径最小值
int mp[maxn];                               //保存路径中的结点值
int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            cin >> D[i][j];
    dp[0][0]=D[0][0];
    for(int i=1; i<M; i++)
        dp[i][0] = dp[i-1][0]+ D[i][0];     //对于第一列的点D[i][0]，只可能是从上面的点D[i-1][0]往下走
    for(int j=1; j<N; j++)
        dp[0][j] = dp[0][j-1]+ D[0][j];     //对于第一行的点D[0][j]，只可能是从左边的点D[0][j-1]往右走
    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)              //点D[i][j]，是从D[i][j-1]和D[i-1][j]较小的而来
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + D[i][j];
    int i=M-1,j=N-1;
    mp[K++]=D[i][j];
    while(i>=0 && j>=0){                    //倒着找路径上的点
        if(i==0 && j==0){
            break;
        } else if(i==0){                    //在第一行上，那么上一个点只能是左边的点
            mp[K++]=D[i][j-1];
            j--;
        } else if(j==0){                    //在第一列上，那么上一个点只能是上面的点
            mp[K++]=D[i-1][j];
            i--;
        } else {                            //否则就找左边和上面的dp最小对应的那个点D
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
	//*p = 0;                    //不能变
	//p = (const char*)0x00123;  //可以变
	//char str[100] = "asf";
	//char* const q = str:
	//q = 0x1231232123;

	void * (*(*fp1)(int))[10]; 
	float (*(*fp2)(int,int,int))(int);
	int (*(*fp3)())[10](); 

	return 0;
}

#endif