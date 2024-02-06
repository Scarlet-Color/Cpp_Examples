#include <iostream>
#include <deque>
#include "cstdio"
using namespace std;

int n,k;
int a[10001],dp[10001];
int *head;
int *tail;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    *head,*tail = a[1];
    for(int i = 1;i <= n;i++){
        while(!*tail){
            *tail += 1;
            for(int i = *head; i <= *tail;i++){
                dp[i] = a[i];
            }
            ++*head;
            dp[*head] = a[*head];
            dp[*head - 1] = 0;
        }

    }
}