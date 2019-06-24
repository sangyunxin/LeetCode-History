### trick
* 善用打表
* 不要把问题复杂化
* 忽略警告：在文件最上面加上`#define _CRT_SECURE_NO_DEPRECATE`
* 需要循环计算多个cases的题目，一定记得在每次进入一个新的case的时候把之前使用的变量还原。
* 注意数据取值范围。int 类型的数据取值在2^31-1~-2^31之间，即：-2147483648 ~ 2147483647；无符号unsigned范围：2^32-1 ~ 0，即：0 ~ 4294967295
* C++中局部数组不会进行初始化！自己初始化要初始整个数组！
* 所有的全局变量在main函数里都要进行一次初始化。
* 两个参数没有明确说明大小顺序，一定要用swap固定大小顺序！
* 使用memset时要加上`#include <cstring>`
* WA的时候多考虑一下起始点和边界条件是否正确
* 图的问题中两个节点间可能存在多条边，存最短的那一条
* 注意数据范围！

### 查找
```C++
if (find(m.begin(), m.end(), "hello") == m.end())
    cout << "no" << endl;
else
    cout << "yes" << endl;
```

### map数据结构的使用
* 插入数值
    ```C++
    map<int, float, greater<int> > res; //默认按键值。降序排列，使用greater<int>改为升序
    map<int, float>::iterator iter;
    iter = res.find(N);
    if(iter != res.end())
        res[N] += a;
    else
        res[N] = a;
    ```
* 遍历
    ```C++
    for(map<int, float>::iterator iter = res.begin(); iter != res.end(); iter++){
        printf(" %d %.1f", iter->first, iter->second);
    }
    ```

### 字符串
* 常用字符处理函数（`#include <cstring>`）
	```C++
	int isdigit(int c)	//判断c是否是数字字符
	int isalpha(int c)	//判断c是否是一个字母
	int isalnum(int c)	//判断c是否是一个数字或字母
	int islower(int c)	//判断c是否是一个小写字母
	int isupper(int c)	//判断c是否是一个大写字母
	int toupper(int c)	//转化为大写字母
	int tolower(int c)	//转换为小写字母
	```
* 常用字符串处理函数
	```C++
	char * strchr(char * s, int c)	//如果s中包含字符c，则返回一个指向s第一次出现的该字符的指针，否则返回NULL
	char * strstr(char * s1, char * s2)	//s1中是否包含s2子串，返回指针或NULL
	char * strlwr(char * s)	//将s中的字母变成小写
	char * strupr(char * s)	//将s中的字母变为大写
	char * strcpy(char * s1, char * s2)	//将字符串s1的内容复制到s2中去
	char * strncpy(char * s1, char * s2, int n)	//将s2中最多n个字节复制到s1中去，如果复制字节数达到n,不会向s1的结尾写入'\0'
	char * strcat(char * s1, char * s2)	//将字符串s2添加到s2末尾
	char * strncat(char * d, char * s, size_t count)	//将字符串s的前count个字符添加到d末尾
	int strcmp(char * s1, char * s2)	//比较两个字符串
	int stricmp(char * s1, char * s2)	//比较两个字符串，大小写无关
	int strncmp(char * s1, char * s2, size_t count)	//比较字符串s1和s2的前count个字符
	int strlen(char * s)	//计算字符串长度
	char * strrev(char * s)	//将字符串s前后颠倒
	void memset(void * s, int c, int n)	//将内存地址s开始的n个字节全部置为c
	```
* 字符串转换函数
	```C++
	int atoi(char * s)	//转化为整数
	double atof(char * s)	//转化为浮点数
	char * itoa(int value, char * string, int radix)	//将整数型value以radix进制表示法写入string
	```
* 数字转化为字符串：
    ```C++
    char s[10];
    int a = 123456;
    sprintf(s, "%d", a);
    ```
* 使用`strlen(s)`获得字符串的长度(**不包含/0**)
* 常见ASCII编码：'A' = 65    'a' = 97    '0' = 48    '\0' = 0

### 比较函数sort
* 使用需要加上头文件`#include <algorithm>`
* 默认按升序排列，自定义小于比较函数升序，自定义大于比较函数降序。如下：
    ```C++
    bool cmp(dui a, dui b) {
        return a.num < b.num;
    }

    stable_sort(d, d + m, cmp);
    ```
* 使用stable_sort进行稳定排序
* 优先队列默认为大顶堆，修改为小顶堆需自定义比较函数（const不能省略）
    ```C++
    bool operator <(const node & a, const node & b){
        return a.s > b.s;
    }
    ```

### 广度优先搜索
* 每次入队时设置节点为已访问

### 判断素数
```C++
bool isPrime(int num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}
	for (int i = 5; i*i <= num; i += 6)
	{
		if (num % i == 0 || num % (i+2) == 0)
		{
			return false;
		}
	}
	return true;
}
```

### 欧拉线性筛法
```C++
const int MAXN=3000001;
int prime[MAXN];//保存素数
bool vis[MAXN];//初始化
int Prime(int n)
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<n;i++)
	{
		if(!vis[i])
		prime[cnt++]=i;
		for(int j=0;j<cnt&&i*prime[j]<n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)//关键
			break;
		}
	}
	return cnt;//返回小于n的素数的个数
}
```

### dijkstra算法。。
* dist数组索引应该从1开始
```C++
void dijkstra(){
    memset(dist, MAX, sizeof(dist));
    dist[1] = 0;

    for(int i = 1; i <= N; i++){
        int mind = MAX;
        int v = -1;
        for(int j = 1; j <= N; j++){
            if(vis[j] == 0 && dist[j] < mind)
                mind = dist[v=j];
        }

        vis[v] = 1;

        for(int j = 1; j <= N; j++){
            if(vis[j] == 0 && dist[j] > mind + path[v][j])
                dist[j] = mind + path[v][j];
        }
    }
}
```

### Bellman-Ford算法
* Bellman-Ford每次迭代是否改变是相对于外层循环而言的
```C++
void init() {
	for (int i = 1; i < N; i++) {
		minDis[i] = Inf;
	}
	minDis[N] = 0;  // 假设N点为起点
}

bool relax(edge e, bool Double) {
	bool change = false;
	if (minDis[e.v] > minDis[e.u] + e.w) {
		minDis[e.v] = minDis[e.u] + e.w;
		change = true;
	}

	if (Double && minDis[e.u] > minDis[e.v] + e.w) {
		minDis[e.u] = minDis[e.v] + e.w;
		change = true;
	}

	return change;
}

bool BellmanFord() {
	init();
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < M + W; j++) {
			if(relax(edges[j], j < M))
			flag = true;
		}

		if (!flag) return true;
	}

	return false;
}
```

### Floyd算法
* 初始化时要设`dis[i][i] = 0`
```C++
void floyd(){
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
```

### 蛇形遍历数组
```C++
for(int i = 0; i < n * n - 1; i++){
	for(int j = i; j >= 0; j--){
		if(j < n && i - j < n){ //控制本次循环中元素数目(i-j, j)右上点，(j, i-j)左下点
			if(i % 2 != 0)
				num[i-j][j] = x++;
			else
				num[j][i-j] = x++;
		}
	}
}
```

### 对某一行的所有情况进行枚举（01）
```C++
void enumate(){
	for(int i = 1; i < 7; i++)
		press[1][i] = 0;

	while(guess() == false){
		int c = 1;
        press[1][c]++;
		while(press[1][c] > 1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}

	return;
}
```
**熄灯问题判断第(r+1, c)按钮是否需要按下：press[r+1][c]=(puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1]**


### 二分法
```C++
//  left为最开始元素, right是末尾元素的下一个数，x是要找的数
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;
        // 如果要替换为 upper_bound, 改为:if (A[m] <= v) x = m+1; else y = m;
    }
    return left;
}

/*
    最后left == right

    如果没有找到135577找6，返回7

    如果找有多少的x，可以用lower_bound查找一遍，upper_bound查找一遍，下标相减

    C++自带的lower_bound(a,a+n,x)返回数组中最后一个x的下一个数的地址

    upper_bound(a,a+n,x)返回数组中第一个x的地址

    如果a+n内没有找到x或x的下一个地址，返回a+n的地址

    lower_bound(a,a+n,x）-upper_bound(a,a+n,x)返回数组中x的个数
*/
```

### Kruskal
```C++
/*
    第一步：点、边、加入vector，把所有边按从小到大排序
    第二步：并查集部分 + 下面的code
*/

struct Edge{
    int u, v, cost;

    bool operator <(const EDGE & a) const{
        return cost > a.cost;
    }
};

int n, res, father[30];
priority_queue<Edge> q;

int findRoot(int x){
    int root = x;
    while(root != father[root])
        root = father[root];

    while(x != root){
        int tmp = father[x];
        father[x] = root;
        x = tmp;
    }

    return root;
}

void Union(int x, int y){
    int a = findRoot(x);
    int b = findRoot(y);
    father[a] = b;
}

void kluskal(){
    res = 0;
    while(!q.empty()){
        Edge e = q.top(); q.pop();
        if(findRoot(e.u) != findRoot(e.v)){
            Union(e.u, e.v);
            res += e.cost;
        }
    }
}
```

### Prim
```C++
const int MAX = 0x3f3f3f3f;

struct Node{
    int v, len;

    bool operator <(const Node & a) const{
        return len > a.len;
    }
};

priority_queue<Node> q;
int n, res, dis[35], vis[35];
vector<Node> G[35];

void init(){
    res = 0;

    while(!q.empty())
        q.pop();

    for(int i = 0; i < n; i++)
        G[i].clear();

    memset(vis, 0, sizeof(vis));
    memset(dis, MAX, sizeof(dis));
}

void prim(int s){
    Node n = {s, 0};
    q.push(n);
    while(!q.empty()){
        n = q.top(); q.pop();
        int v = n.v;
        if(vis[v] == 1)
            continue;

        res += n.len;
        vis[v] = 1;

        for(int i = 0; i < G[v].size(); i++){
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if(vis[v2] == 0 && dis[v2] > len){
                dis[v2] = len;
                Node tmp = {v2, len};
                q.push(tmp);
            }
        }
    }
}
```

### 拓扑排序
```C++
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector< vector<int> > edge;
map<int, bool> vis;
map<int, int> ru;
vector<int> res;

int v, a;

int finds(){
    int start = -1;
    for(int i = 1; i <= v; i++){
        if(ru[i] == 0 && !vis[i]){
            start = i;
            break;
        }
    }
    return start;
}

int main()
{
    cin >> v >> a;
    edge.resize(v+1);
    for(int i = 1; i <= v; i++){
        vis[i] = false;
        ru[i] = 0;
    }

    for(int i = 0; i < a; i++){
        int s, d;
        cin >> s >> d;
        edge[s].push_back(d);
        ru[d]++;
    }

    int start = finds();

    while(start != -1){
        res.push_back(start);
        vis[start] = true;
        for(int i = 0; i < edge[start].size(); i++){
            ru[edge[start][i]]--;
        }

        start = finds();
    }

    for(int i = 0; i < res.size() - 1; i++){
        cout << "v" << res[i] << " ";
    }
    cout << "v" << res[res.size() - 1] << endl;
    return 0;
}
```

### 根据前序和中序建立二叉树
```C++
struct Node{
    char val;
    Node * left;
    Node * right;

    Node(char c): val(c), left(NULL), right(NULL){};
};

string pre, mid;

Node* getTree(string & pre, string & mid){
    if(pre.size() == 0)
        return NULL;

    size_t pos = mid.find(pre[0]);
    string left = mid.substr(0, pos);
    string right = mid.substr(pos+1);
    string lpre = pre.substr(1, left.size());
    string rpre = pre.substr(1+left.size());

    Node *r = new Node(pre[0]);
    r->left = getTree(lpre, left);
    r->right = getTree(rpre, right);
    return r;
}
```