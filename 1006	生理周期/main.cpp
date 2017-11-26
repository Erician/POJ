#include <iostream>
#include <cstdio>

#define P 23
#define E 28
#define I 33

using namespace std;
int main()
{
    int p,e,i,d;
    int cnt = 0;
    while(true)
    {
        if (cnt != 0)
        {
            printf("\n");
        }
        cnt++;
        cin>>p>>e>>i>>d;
        if(p == -1 && e == -1 && i == -1 && d == -1)
        {
            return 0;
        }
        p = p % P;
        e = e % E;
        i = i % I;
        int currentDay = p;
        while (currentDay <= d)
        {
            currentDay += P;
        }
        while(!((currentDay-e)%E == 0 && (currentDay-i)%I == 0))
        {
            currentDay += P;
        }

        printf("Case %d: the next triple peak occurs in %d days.",cnt,currentDay-d);


    }
}
