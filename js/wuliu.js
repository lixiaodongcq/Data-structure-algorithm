/*




*/
#include<iostream>
using namespace std;
int n,g,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans[8];
int main()
{
    int n =1;
    int i,j,s=0;
    for(i=2017;i<=2017+n-1;i++)
      {
          if(i%4==0&&i%100!=0||(i%400==0))g=1;
          else g=0;
          for(j=1;j<=12;j++)
            {
                
                ans[(s+15)%7]++;
                if(g==1&&j==2)s=s+29;
                else s=s+a[j];
          }
      }
    for(i=0;i<=6;i++)cout<<ans[i]<<" ";
    return 0;
}