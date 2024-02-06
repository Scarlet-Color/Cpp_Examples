#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define maxn 10000
using namespace std;
vector<int> x[maxn],y[maxn];
queue<int> Q;
int col[maxn];//col[]代表每个点的颜色，0代表否，1代表左侧，2代表右侧
//染色问题
bool bfs(int start);
int add_edge(int p1,int p2,int data);

int main(){
    int p1,p2,n,m,data;
    cin>>p1>>p2>>n>>m>>data;
    for(int i = 1;i <= m;i++){
        cin>>p1>>p2>>data;
        add_edge(p1,p2,data);//二分图的本质为无向图
        add_edge(p2,p1,data);
    }
    for(int i = 1;i <= m;i++){//无法确保bfs(1)能遍历整张图，需要判断整张图没有染色的点
        if(!col[i]){
            if(bfs(i)) cout<<"Y"<<endl;
            cout<<"N"<<endl;
        }
    }
    return 0;
}

//--------------------------------二分图的判断---------------------------------------//
bool bfs(int start){//从点start，判断是否存在冲突，冲突返回false
    col[start] = 1;//设初值为1
    Q.push(start);//队列加入初始点
    while(Q.size()){
        int p1 = Q.front();//引入p1指针指向Q队列的前端
        Q.pop();//推出队列前端;
        for(int i = 0;i <= x[p1].size();i++){
            int p2 = x[p1][i];//该边为从p1 -> p2的边 |||
            if(col[p2] = 0)/*p2没有被染色*/ col[p2] = 3-col[p1];
            if(col[p1] = col[p2]) return false;//如果两个点的颜色相同，则返回该图不是二分图
        }
    }
}//-------------------------------------------------------------------------------//

int add_edge(int p1,int p2,int data){//边表，加边函数
    x[p1].push_back(p2);
    y[p1].push_back(data);
}