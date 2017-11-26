#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI (atan(1.0)*4)

int main()
{
    int N;
    float x,y;
    cin>>N;
    int cnt = 0;
    while(cnt++<N)
    {
        cin>>x>>y;
        float n = PI*(x*x+y*y)/100;
        printf("Property %d: This property will begin eroding in year %d.\n",cnt,int(ceil(n)));
    }
    printf("END OF OUTPUT.");
}