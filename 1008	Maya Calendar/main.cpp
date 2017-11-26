#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char months[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",\
                       "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char days[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",\
                     "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main(){
    int n;
    cin>>n;
    cout<<n<<endl;
    while(n--){
        int day,month,year;
        char str_month[10];
        scanf("%d. %s %d",&day,str_month,&year);
        
        for(int i=0;i<19;i++){
            if(strcmp(str_month,months[i])==0){
                month = i;
                break;
            }
        }
        int sum_day = year*365 + month*20 + day;
        int re_year,re_month,re_day;
        re_year = sum_day/260;
        sum_day -= (sum_day/260)*260;
        re_month = sum_day%13;
        sum_day -= (sum_day/20)*20;
        printf("%d %s %d\n",re_month+1,days[sum_day],re_year);
    }
}

/* 
    分类:字符串
    仅仅是字符串的一些简单的操作,看好题就行了
*/