#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define maxn 10000
using namespace std;
vector<int> x[maxn],y[maxn];//x数据代表从i出发的j条边终点为x[][]，y数据代表从i出发的j条边边权为y[][]
int in[maxn];//in[]代表i点的入度为多少
int res[maxn];//拓扑排序结果
int cnt;//当前拓扑排序的点数

int add_edge(int p1,int p2,int data);
int dp();
//DAG，路径最长是多少
//对于DAG 有向无环图，可以采用拓扑排序使得可以从i=1，i++遍历
//将入度为0的点放到最前面，然后删去该店，形成新的入度为0的点，放到先前点后，循环
//拓扑排序：每次找到入度为0的点，然后将其删掉，形成新的入度为0的点
//对于DAG，常用dp处理，对于dp，常用DAG处理
int main(){

    int p1,p2,data;//p1,p2表示两点坐标，data代表所存数据
    cin>>p1>>p2>>data;
    int n,m;//n点数，m边数
    cin>>n>>m;

    for(int i = 1;i <=n;i++){
        if(in[i] == 0){//如果入度为0，记录
            cnt++;
            res[cnt] = i;
        }
    }

    //---------------------拓扑排序,B3644-------------------------------//
    for(int i = 1;i <= n;i++) {//将拓扑排序第i个点从拓扑排序中删掉
        int p1 = res[i];
        for (int j = 1; j <= x[p1].size(); j++) {//遍历从p1发出的所有边
            int p2 = x[p1][j];//p1到p2的边
            in[p2]--;//将入度减小，变成-1
            if (in[p2] == 0) {//如果p2的入度为0，则继续循环
                cnt++;
                res[cnt] = p2;
            }
        }
    }
    //------------------------------------------------------------------//

}

int dp(){//先枚举情况，再枚举状态
    for(int i = 1;i <= n;i++){//用自己的值求别人的值
        int p1 = res[i];//f[p1]已经求出，用其去更新其他状态
    }
    for(int j = 0;j <= 0;j <= x[p1].size();i++){//引出p1发出的所有边
        int p2 = x[p1][j];//p1 -> p2的边
        int d = y[p1][j];//该边权值（长度）为d
        f[p2] = max(f[p2],f[p1]+d);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,f[i]);
    }
    cout<<ans<<endl;
}

int add_edge(int p1,int p2,int data){
    x[p1].push_back(p2);
    y[p1].push_back(data);
    in[p2]++;
}