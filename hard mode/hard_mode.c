#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char str_array[16][6] = {{"10000"}, 
                         {"01000"}, 
                         {"00100"}, 
                         {"00010"}, 
                         {"00001"}, 
                         {"11000"}, 
                         {"10100"}, 
                         {"10010"}, 
                         {"10001"}, 
                         {"01100"}, 
                         {"01010"}, 
                         {"01001"}, 
                         {"00110"}, 
                         {"00101"}, 
                         {"00011"}}; //定義所有的殭屍對應列表(zombie_spawn_tablet)

int main(void)
{
    srand(time(NULL)); // 隨機數種子，利用時間做為種子碼
    int num_15 , score = 0, heart = 3;
    // num對應每一行殭屍，score為分數，HEART為血量
    char line[5][6], gamerin[6], gamernum, mid[6];
    // line對應各行殭屍，gamerin為使用者輸入質對應要攻擊的殭屍種類，gamernum為使用者輸入，mid為暫存值
    // 使用Rand函數(亂數，不知道幾位)，並利用取餘數使數字介於我們 想指定的範圍(1-15)
    for(int i=1; i<=4; i++)
    {
        num_15 = rand() % 15;
        sscanf(str_array[num_15], "%5s", line[i-1]);
    }
    
    // 輸出遊戲基礎三隨機殭屍
    printf("%s\n", line[0]);
    printf("%s\n", line[1]);
    printf("%s\n", line[2]);
}