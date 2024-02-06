#include <iostream>
#include "cstdio"
using namespace std;

int N[10][10];//主表格
int num;//num代表传入的数
int posx,posy;//pos代表该点位的坐标
int A[2][2],B[2][2];//AB的坐标

int main() {
    cin>>num;
   for(int i = 1;i <= num+1;i++){
       for(int j = 1;j <= num+1;j++){//双指针搜索
           cin>>posx>>posy>>N[posx][posy];
           if(posx == posy == N[posx][posy] == 0) break;//输入一行0时，退出循环
       }
   }

}