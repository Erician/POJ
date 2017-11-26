#include<iostream>

using namespace std;

int main()
{
    int goods[6];
    while (true)
    {
        for(int i = 0;i < 6;i++)
        {
            cin>>goods[i];
        }
        if (goods[0] == 0 && goods[1] == 0 && goods[2] == 0 && \
            goods[3] == 0 && goods[4] == 0 && goods[5] == 0)
        {
            return 0;
        }
        int packet_number = 0;
        packet_number+=goods[5];
        packet_number+=goods[4];
        goods[4] -= goods[5]*11;
        packet_number+=goods[3];
        for(int i=0;i<goods[3];i++)
        {
            int cnt = 5;
            while (cnt--)
            {
                if(goods[1]>0)
                {
                    goods[1]--;
                }
                else
                {
                    goods[0]-=4;
                }
            }
        }
        packet_number += (goods[2]%4==0)?(goods[2]/4):((goods[2]/4)+1);
        if(goods[2]%4!=0)
        {
            int left = 4-goods[2]%4;
            if(left == 1)
            {
                if(goods[1]>0)
                {
                    goods[1]--;
                    goods[0]-=5;
                }
                else
                {
                    goods[0]-=9;
                }
            }
            else
            {
                if(goods[1]>=(left+1))
                {
                    goods[1]-=(left+1);
                    goods[0]-=
                }
                goods[1]-=(5-left);
            }


        }

}