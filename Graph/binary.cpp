#include <iostream>
#include <cstdio>
#include <vector>

#define maxn 10000
using namespace std;
//邻接矩阵
int z[maxn][maxn];//z[][]代表从i到j的边信息
//边表
vector<int> x[maxn],y[maxn];//边表，x数据代表从i出发的j条边终点为x[][]，y数据代表从i出发的j条边边权为y[][]
int add_edge(int p1,int p2,int data);//加边函数

int main(){

    int p1,p2,data;//p1,p2表示两点坐标，data代表所存数据
    cin>>p1>>p2>>data;
    int n,m;//n点数，m边数
    cin>>n>>m;

    //-----------------------------------邻接矩阵------------------------------------------//
    //邻接矩阵，空间复杂度为 O n^2，时间复杂度O 1 -> 数据切片直接获取
    //邻接矩阵无法处理重复的边问题，推荐在数据范围1e3内使用，没有重边/重边没有影响
    //有向图存储，只需要单边存储
    z[p1][p2] = data;
    //无向图存储，需要双向存储
    z[p1][p2] = data;
    z[p2][p1] = data;
    //两者存储方式过于消耗内存，可以采用边表
    //-----------------------------------------------------------------------------------//

    //-------------------------------------边表-------------------------------------------//
    //边表，只存用到的边，空间复杂度 O m，时间复杂度 O m -> 不知道存边的下表，需要全部将数据遍历才能搜索
    //边表可以用于处理重复的边，数据大于1e3，且重边对结果存在影响
    for(int i = 1;i <= m;i++){//该方法利用vector动态数组的特性，需要多少申请多少
        cin>>p1>>p2>>data;
        //有向
        add_edge(p1,p2,data);
        //无向
        add_edge(p1,p2,data);
        add_edge(p2,p1,data);
    }//---------------------------------------------------------------------------------//
}

//-----------------------加边----------------------//
int add_edge(int p1,int p2,int data){//边表，加边函数
    x[p1].push_back(p2);
    y[p1].push_back(data);
}//----------------------------------------------//