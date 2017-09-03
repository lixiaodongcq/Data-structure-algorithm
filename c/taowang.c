#include <iostream>
using namespace std;
int dp[501];
struct E{
int w;
int v;
}list[50001];//这里开大一点
int max(int a,int b){
return a > b ? a : b;
}
int main(){
int n, v;
while(cin >> n >> v){
int cnt = 0;
for(int i = 1;i <= n;i++){
int m, w, s;//数量、体积、价值
cin >> m >> w >> s;
int c = 1;
while(m - c > 0){
m -= c;
list[++cnt].w = c*w;
list[cnt].v = c*s;
c *= 2;
}
list[++cnt].w = m*w;
list[cnt].v = m*s;
}
for (int i = 1; i <= v; i++)
dp[i] = 0;
for(int i = 1;i <=cnt;i++){
for(int j = v;j >= list[i].w;j--){
dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
}
}
cout << dp[v] << endl;
}
return 0;
}