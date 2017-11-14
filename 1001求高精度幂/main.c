/*
问题很多，根据测试用例一步步调才做对
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

void add(char* re,int *reLen,char* tmp,int tmpLen){
    int i;
    int jinwie = 0;
    for(i=0;i<(*reLen)||(i<tmpLen);i++){
        int a1,a2,a3;
        a1 = re[i];
        a2 = tmp[i];
        if(i>=*reLen){
            a1 = '0';
        }
        if(i>=tmpLen){
            a2 = '0';
        }
        int num = a1 - '0' + a2 - '0' + jinwie;
        re[i] = num%10+'0';
        jinwie = num/10;
        //printf("ok");
    }
    if(jinwie!=0){
        re[i++] = jinwie+'0';
    }
    *reLen = i;

}

char * compute(char *lastre,int *lastreLen,char* in,int inLen){
    char *re = (char*)malloc(sizeof(char)*N);
    char *tmp = (char*)malloc(sizeof(char)*N);
    memset(re,'0',sizeof(char)*N);
    int reLen = 0;
    int i,j;
    int jinwei = 0;
    for(i=0;i<inLen;i++){
        jinwei = 0;
        for(j=0;j<(*lastreLen);j++){
            int num = (in[i]-'0')*(lastre[j]-'0')+jinwei;
            tmp[j]=num%10+'0';
            jinwei = num/10;
        }
        if(jinwei!=0){
            tmp[j++] = jinwei+'0';
        }
        int tmpj;
        for(tmpj=j-1;tmpj>=0;tmpj--){
            tmp[tmpj+i] = tmp[tmpj];
        }
        for(tmpj=0;tmpj<i;tmpj++){
            tmp[tmpj] = '0';
        }
        //printf("%s %s\n",re,tmp);

        add(re,&reLen,tmp,j+i);
    }
    *lastreLen = reLen;
    return re;
}
int find(char* re,int pos){
    int i;
    for(i=pos;i>=0;i--){
        if(re[i]!='0'){
            return 1;
        }
    }
    return 0;
}
int main()
{
    char in[N];
    char re[N];
    int n;
    int firstCase = 1;
    while(scanf("%s%d",in,&n)!=EOF){
        int i,j;
        if(in[0]=='.'){
            for(i=strlen(in)-1;i>=0;i--){
                in[i+1] = in[i];
            }
            in[0] = '0';
        }


        int cntDot = 0;
        while(cntDot<strlen(in)&&in[cntDot]!='.'){
            cntDot++;
        }
        cntDot = strlen(in)-1-cntDot;
        if(cntDot<0){
            cntDot=0;
        }
        i=0;
        j=0;
        for(i=strlen(in)-1;i>=0;i--){
            if(in[i]!='.'){
                re[j++] = in[i];
            }
        }
        for(i=0;i<j;i++){
            in[i] = re[i];
        }
        int reLen = j;
        //printf("%s %d %s %d\n",re ,reLen,in,j);
        for(i=0;i<n-1;i++){
            memcpy(re,compute(re,&reLen,in,j),sizeof(char)*N);
            //printf("%s\n",re);
        }
        cntDot=cntDot*n;
        cntDot = cntDot-1;
        int startPrint = 0;
        //printf("%s\n",re);
        for(reLen=reLen-1;reLen>=0;reLen--){
            if(re[reLen]!='0'||reLen==cntDot){
                startPrint = 1;
            }
            if(reLen==cntDot&&find(re,reLen)==1){
                printf("%c",'.');
            }
            //printf("startPrint:%d\n",startPrint);
            if(startPrint == 1 ){
                if(re[reLen] == '0'){
                    if(find(re,reLen)==0&&cntDot>=reLen){
                        break;
                    }
                    printf("%c",re[reLen]);
                }
                else{
                    printf("%c",re[reLen]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
