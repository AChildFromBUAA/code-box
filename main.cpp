//
//  main.cpp
//  code box
//
//  Created by kyz on 15/6/11.
//  Copyright (c) 2015年 BUAA.Software. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    printf("code box program\n");
    while(1)
    {
        int t;
        printf("1.encrypt\n2.decode\n3.exit\n");
        scanf("%d", &t);
        while(t != 1 && t != 2 && t != 3)
        {
            printf("Wrong!!!!\n");
            scanf("%d", &t);
        }
        
        if(t == 1)
        {
            printf("Please input:\t");
            char str[30];
            scanf(" %s", str);
            int len = strlen(str);
            
            srand((unsigned)time(0));
            int title = rand() % 8;
            
            char ans[31] = { static_cast<char>(title + 'a'), 0};
            printf("%c", ans[0]);
            for(int num = 0; num < len; num ++)
            {
                ans[num + 1] = (str[num] - 0) ^ title;
                printf("%c", ans[num + 1]);
            }
            printf("\n");
        }
        else if(t == 2)
        {
            printf("Please input:\t");
            char ans[31];
            scanf(" %s", ans);
            
            int len = strlen(ans);
            int title = ans[0] - 'a';
            char str[30];
            
            for(int num = 1; num < len; num ++)
            {
                str[num] = (ans[num] - 0) ^ title;
                printf("%c", str[num]);
            }
            printf("\n");
        }
        else if(t == 3)
        {
            exit(1);
        }
    }
    return 0;

}
