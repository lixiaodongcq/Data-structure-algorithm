/*
  定义一个month的数组，表示每个月份的天数。在程序中对闰年进行单独处理。
  定义一个result的数组，表示星期一到星期天17号落在每个星期的个数。
  根据提示 2017年1月17日是星期二，可以对应调整数组的位置。
*/
#include<iostream>
using namespace std;

int main()
{
    int isLeap,month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},result[7];
    int n =1;
    int i,j,sum=0;
    for(i=2017;i<=2017+n-1;i++)
      {
          if(i%4==0&&i%100!=0||(i%400==0))
            isLeap=1;
          else isLeap=0;
          for(j=1;j<=12;j++)
            {
                
                result[(sum+15)%7]++;
                if(g==1&&j==2)
                  sum=sum+29;
                else sum=sum+month[j];
          }
      }
    for(i=0;i<=6;i++)cout<<result[i]<<" ";
    return 0;
}








function fn(strID,regionArry){
    var arr = strID.split("");
    var address = arr.slice(0,6).join("");
    var birth = arr.slice(6,14);
    var seq = arr.slice(14,17).join("");
    if (arr.length !== 18) {
        return false;
    }
    if((regionArry.indexOf(address) != -1) && checkDate(birth) && seq != "000" && checkCode(arr)){
        if (parseInt(seq.slice(-1))%2 == 0) {
            return "Female";
        }else{
            return "Male"
        }
    }else{
        return false;
    }
}
function checkDate(arr){
    var year = parseInt(arr.slice(0,4).join(""));
    var month = parseInt(arr.slice(4,6).join(""));
    var date = parseInt(arr.slice(6).join(""));
    if (isNaN(year) || isNaN(month) || isNaN(date)) {
        return false;
    }
    if(year<1900 || year > 2011){
        return false;
    }
    if (month > 31) {
        return false;
    }
    if ((month==4 || month==6 || month==9 || month==11) && (date > 30)) {
        return false;
    }
    if (month == 2) {
        if (date > 29) {
            return false;
        }
        if (((year%4 == 0 && year%100 != 0)||(year%400 == 0)) && date > 28) {
            return false;
        }
    }
    return true;
}




function checkCode(arr){
    var code = arr[arr.length-1];
    if (code == "X") {
        code = 10;
    } else {
        code = parseInt(code);
    }
    if (isNaN(code)) {
        return false;
    }
    var res  = 0;
    for (let index = 0; index < arr.length-1; index++) {
        var element = arr[index];
        res += element * Math.pow(2,(17-index));
    }
    if ((code+res)%11 == 1) {
        return true;
    }else{
        return false;
    }
}


int checkCode(char arr[]){
  char code = arr[arr.length-1]
}



