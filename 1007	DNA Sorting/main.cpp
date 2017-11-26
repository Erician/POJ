#include <iostream>
#include <cstring>
using namespace std;

void insert_sort(char *mystr,int &number){
    number = 0;
    char str[strlen(mystr)+1];
    strcpy(str,mystr);
    for(int i=1;i<strlen(str);i++){
        int pos = i;
        for(int j = i-1;j>=0;j--){
            if(str[pos]<str[j]){
                number++;
                char tmp = str[j];
                str[j] = str[pos];
                str[pos] = tmp;
                pos = j;
            }
        }
    }
}
int find_least(int *numbers,int n){
    int least = 10000000;
    int pos = -1;
    for(int i=0;i<n;i++){
        if(numbers[i]<least){
            least = numbers[i];
            pos = i;
        }
    }
    if(pos == -1){
        numbers[0] = 10000000;
        return 0;
    }
    else{
        numbers[pos] = 10000000;
        return pos;
    }
}


int main(){
    int n,m;
    cin>>m>>n;
    char str[n][m+1];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    int numbers[n];
    for(int i=0;i<n;i++){
        insert_sort(str[i],numbers[i]);
    }
    for(int i=0;i<n;i++){
        int pos = find_least(numbers,n);
        cout<<str[pos]<<endl;
    }
    return 0;
}

/*
    归类:排序
    
    这个问题比较简单,逆序对的数量等于插入排序所要移动的元素对的数量
    所以,只要写出插入排序,问题也就解决了
*/