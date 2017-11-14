#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }
    if(c=='A'||c=='B'||c=='C'){
        return 2;
    }
    if(c=='D'||c=='E'||c=='F'){
        return 3;
    }
    if(c=='G'||c=='H'||c=='I'){
        return 4;
    }
    if(c=='J'||c=='K'||c=='L'){
        return 5;
    }
    if(c=='M'||c=='N'||c=='O'){
        return 6;
    }
    if(c=='P'||c=='R'||c=='S'){
        return 7;
    }
    if(c=='T'||c=='U'||c=='V'){
        return 8;
    }
    if(c=='W'||c=='X'||c=='Y'){
        return 9;
    }
}

void print(int m){

    int pow = 1000000;
    int i=0;
    for(i=0;i<7;i++){
        if(i==3){
            printf("-");
        }
        printf("%d",m/pow);
        m = m % pow;
        pow = pow / 10;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char number[100];
    int numberInt[100];
    char visit[9999999];
    memset(visit,0,sizeof(int)*9999999);
    for(i=0;i<n;i++){
        scanf("%s",number);
        //´¦Àí-
        int j;
        int cnt=0;
        int tmp = 0;
        int pow = 1000000;
        for(j=0;j<strlen(number);j++){
            if(number[j]!='-'){
                numberInt[cnt] = find(number[j]);
                tmp+=numberInt[cnt]*pow;
                cnt++;
                pow = pow/10;
            }
        }
        if(visit[tmp]==0){
            visit[tmp] == 1;
        }
        else{
            visit[tmp]++;
        }
    }
    for(i=0;i<=9999999;i++){
        if(visit[i]!=0){
            print(i);
            printf(" %d\n",visit[i]);
        }
    }
    return 0;
}
