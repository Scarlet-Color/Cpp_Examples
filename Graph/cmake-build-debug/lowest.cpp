#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define maxn 10000
using namespace std;


bool bfs(int start);
int add_edge(int p1,int p2,int data);

int add_edge(int p1,int p2,int data){
    x[p1].push_back(p2);
    y[p1].push_back(data);
}


//------------------------------多源最短路径-------------------------------//
class mutipler(){

vector<int> x[maxn],y[maxn];
queue<int> Q;
int dis[maxn][maxn];//表示从i到j的最短路径
int f[maxn][maxn][maxn];//从j走到k中间经过的点编号小于等于i的最短路径的长度 -> f[i每个点的编号最大轴][j起点][k终点]
//dis[i][j] = f[n][i][j] -> 对于起点是i，j的两个点，距离不超过n，任意走，可以走出最短路径
//对于f(x)的状态转移，需要分i与0的关系，如果i<0,f[i][j][k] = f[i-1][j][k],如果i=0,f[i][j][k] = f[i-1][j][i]+f[i-1][i][k]
//i<0时，不经过i，则是j k为两端，如果i=0，经过i点，则j i为第一次两端，i k为第二次两端
//最短路的三角不等式 -> 同三角形三边关系 dis[i][j] <= dis[i][k] + dis[k][j]

//最短路分为 单源最短路径 -> 只有一个起点
//         多源最短路径 -> 有多个起点 -> 求dis[i][j] 任意两点之间的最短路径 -> 弗洛伊德(Floyd) O n^3
//Floyd推荐使用邻接矩阵
//int f[maxn][maxn][maxn];代表从j走到k中间的编号<=i时候最短路径长度
//时间O n^3 空间 O n^3 最大100左右
//B3647

    memset(f,0x3f,sizeof(f));//将f数组初始化成无穷大
    for(int i = 1;i <= n;i++){
        f[0][i][i] = 0;//自身设为0
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(x[i][j] != 0) f[0][i][j] = x[i][j];
        }
    }
    //--------------------------------Floyd-----------------------------------//
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;j <= n;j++){
                f[i][j][k] = min(f[i-1][j][k],f[i-1][j][i] + f[i-1][i][k]);
            }
        }
    }
    //--------------------------------------------------------------------------//
    //对其优化，利用滚动数组，对于i在接下来过程中影响不大，可以删去，使Floyd成为空间 -> O(n^2) -> 100左右
}
//----------------------------------------------------------------------------------------//

//-----------------------------------单源最短路---------------------------------------------//
class single(){
    //-------------------------------dijkstra---------------------------------------------//
    int dijkstra(int start){
        int dis[maxn];
        //需要保证所有边的边权不是负边权
        //dijkstra初始化 -> 令初值为0，其他为正无穷
        //利用上一个状态更新下一个状态，枚举从初点出发的所有边的权，得到其他的点的最短路
        //再将初始值推出，因为所有边权 => 0，找到最短路径的点（最小边权），更新由它发出的所有边
        //循环
        //该思路类似于贪心，每次找dis[i]最小的值，由该值寻找最短路径
        //dis[i]代表起点st到i点的最短路径为多少
        bool done[maxn];//done表示是否被去过，false没有，true有

        memset(dis,0x3f,sizeof(dis));
        dis[start] = 0;
        for(int i = 1;i <= n;i++){//第一轮要取一个点，需要取没有被取过的点的dis[i]最小，因此取Start点
            //while(done[heap.top().second]) heap.pop(); -> 增加判断 2.
            for(int j = 1;j <= n;j++){//O n^2
                if(done[maxn] == false && p1==0||dis[j]<dis[p1]) p1 = j;//该步骤找dis[i]最小的点
            }
            //可以利用小根堆优化 -> 小根堆：根节点最小
            //priority_queue<pair<int,int>> heap; -> first代表距离dis[]，second代表编号
            //for(int i = 1;i <= n;i++){
            //    heap.push(make_pair(-dis[i],i)); -> pair先比较first -> C++默认大根堆，那么先将dis[]设为负数
            //for(int i = 1;i <= n;i++){
            //int p1 = heap.top().second; -> 拿出当前编号
            //heap.pop(); -> 直接推出当前值，模拟扔掉的过程
            //done[p1] = true; -> 更新done的状态
            //}
            done[p1] = true;
            for (int l = 0; l < x[p1]; ++l) {//枚举所有点的所有边 O m
                int p2 = x[p1][j];
                int d = y[p1][j];//由p1->p2，长度为d的边
                if(dis[p1] + d < dis[p2]) dis[p2] = dis[p1] + d;//更新p2的最短路径
                //heap.push(make_pair(-dist[p2],p2)); -> 无法判断该值是否用过 1. |||
            }
        }
    }//该算法时间复杂度为O n^2+m
    //该算法优化时间复杂度为O (n+m)log(n+m)
    //P3371,P4779
    //-------------------------------------------------------------------------------//

    //-------------------------------------------------------------------------------//
}