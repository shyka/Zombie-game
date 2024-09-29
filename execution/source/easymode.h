#ifndef EASYMODE
#define EASYMODE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clearscreen.h"

//定義簡單模式所有的殭屍對應列表(zombie_spawn_tablet)
char str_EZ_array[4][4] = 
{{"100"}, 
 {"010"}, 
 {"001"}};

int easy_mode(void)
{
    srand(time(NULL)); // 隨機數種子，利用時間做為種子碼
    int num_EZ ,score = 0, heart = 3; // num對應每一行殭屍，score為分數，HEART為血量
    char line[4][4], gamerin[4], gamernum; //line對應各行殭屍，gamerin為使用者輸入質對應要攻擊的殭屍種類，gamernum為使用者輸入
    
    // 隨機生成三行殭屍(並儲存到指定變數中)
    for(int i = 0; i < 3; i++)
    {
        num_EZ = rand() % 3; // 使用Rand函數(亂數，不知道幾位)，並利用取餘數使數字介於我們想指定的範圍(0~2)
        sscanf(str_EZ_array[num_EZ], "%3s", line[i]); 
    }
    printf("\t%s\n", line[0]);
    printf("\t%s\n", line[1]);
    printf("\t%s\n      >>\n", line[2]);

    int key_all = 1, key = 1;// key_all為總遊戲控制循環，key_begin為使用者輸入的保險絲
    while (key_all == 1)
    {
        scanf(" %c", &gamernum);
        switch (gamernum)
        {
        case '1': // 對應打殭屍種類
            strcpy(gamerin, str_EZ_array[0]);
            clearScreen();
            break;
        case '2':
            strcpy(gamerin, str_EZ_array[1]);
            clearScreen();
            break;
        case '3':
            strcpy(gamerin, str_EZ_array[2]);
            clearScreen();
            break;
        case '0': // 跳脫遊戲
            key = 0;
            clearScreen();
            break;
        default: // 防呆機制
            printf("please enter again,you enter wrong code\n");
            continue; // 優化程式
        }

        if (key == 1) // key為遊戲結束控制字元
        {
            int cmp = strcmp(gamerin, line[2]); // 比較字串相同性
            if (cmp > 0) // str1 > str2
            {
                heart -= 1; // 對應錯誤會扣血
                printf("faulse, \t\t\tscore: %d", score);
                printf("  HP: %d\n\n", heart);
            }
            else if (cmp == 0) // str1 = str2
            {
                score += 1; // 成功則加分
                printf("success, \t\t\tscore: %d", score);
                printf("  HP: %d\n\n", heart);
            }
            else if (cmp < 0) // str1 < str2
            {
                heart -= 1;
                printf("faulse, \t\t\tscore: %d", score);
                printf("  HP: %d\n\n", heart);
            }
            // 下移程序
            for(int zcount_line = 2; zcount_line > 0; zcount_line--)
            {
                strcpy(line[zcount_line], line[zcount_line-1]); //將上一行數字傳給下一行
            }
            if (heart > 0) // 血量判斷
            {
                num_EZ = rand() % 3;
                sscanf(str_EZ_array[num_EZ], "%3s", line[0]); //重新生成line[0]
                printf("\t%s\n", line[0]);
                printf("\t%s\n", line[1]);
                printf("\t%s\n      >>\n", line[2]);
            }
            else // 輸，遊戲結束
            {
                printf("game is ended\n");
                printf("your score = %d\n", score);
                key_all = 0;
            }
        }
        else // 遊戲結束
        {
            printf("game is ended\n");
            printf("your score = %d\n", score);
            key_all = 0;
        }
    }
    return 0;
}

#endif