//
//  CLOCK.cpp
//  Algo
//
//  Created by KAUCE14 on 2. 12. 1..
//  Copyright © 2016년 Hsue. All rights reserved.
//

#include <stdio.h>

int clock[16];
int result = 987654321;
                   //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5
int SWITCH[10][16]={{3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,3,0,0,0,3,0,3,0,3,0,0,0,0},
                    {0,0,0,0,3,0,0,0,0,0,3,0,0,0,3,3},
                    {3,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,3,3,3,0,3,0,3,0,0,0},
                    {3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3},
                    {0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,3},
                    {0,0,0,0,3,3,0,3,0,0,0,0,0,0,3,3},
                    {0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,3,3,3,0,0,0,3,0,0,0,3,0,0}};

void Rotate(int CLOCK[],int sIdx, int cnt)
{
    // copy CLOCK value
    int tempClock[16];
    for(int i=0; i<16; i++)
        tempClock[i] = CLOCK[i];
    int tempCnt = cnt;

    for(int i=0; i<4; i++)
    {
        int TorF = 0;
        cnt = tempCnt+i;
        for(int j=0; j<16; j++)
        {
            CLOCK[j] = (tempClock[j]+(SWITCH[sIdx][j]*i))%12;
            if(CLOCK[j]!=0)
                TorF = 1;
        }
        
        if(TorF==0 && result>cnt)
            result = cnt;
        
        if(sIdx < 9)
            Rotate(CLOCK,sIdx+1,cnt);
    }

}

int main()
{
    int loop;
    scanf("%d",&loop);
    
    for(int i=0; i<loop; i++)
    {
        result = 987654321;
        
        for(int j=0; j<16; j++)
        {
            int temp;
            scanf("%d",&temp);
            clock[j]=temp%12;
        }
        
        Rotate(clock, 0, 0);
        
        if(result == 987654321)
            printf("-1\n");
        else
            printf("%d\n",result);
        
    }
    
    return 0;
}
