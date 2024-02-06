#include <iostream>
#include <cstdio>
using namespace std;

int volume,val[1001],weight[1001],k,n,f[1001];
void cycle(int h);
void dp(int n,int k);

void cycle(int h){
    for(int i = 1; i <= h; i++){//循环输入价值，重要度
        cin>>val[i]>>weight[i];
    }
}

void dp(int n,int k){
    for(int i = 1;i <= n;i++){
        for(int j = k;j >= 0;j--){
            if(j >= weight[i]){
                f[j] = max(f[j],f[j-weight[i]]+val[i]);//状态转移，要么不取，要么取，容量减少一个，价值增加
            }
        }
    }
    cout<<f[k]<<endl;
}

int main(){
    cin>>n>>k;
    cycle(k);
    dp(n,k);
    return 0;
}