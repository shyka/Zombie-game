#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char str1[4] = "100", str2[4] = "010", str3[4] = "001", line_1[4], line_2[4], line_3[4];
void clearScreen()
{

    system("cls");
}

int content(void)
{
    srand(time(NULL)); // 隨機數種子，利用時間做為種子碼
    int num1, num2, num3, score = 0, heart = 3;
    // num對應每一行殭屍，score為分數，HEART為血量
    char str1[4] = "100", str2[4] = "010", str3[4] = "001", line_1[4], line_2[4], line_3[4], gamerin[4], gamernum, mid[4];
    // str為枚舉殭屍種類，line對應各行殭屍，gamerin為使用者輸入質對應要攻擊的殭屍種類，gamernum為使用者輸入，mid為暫存值
    // 使用Rand函數(亂數，不知道幾位)，並利用取餘數使數字介於我們 想指定的範圍(1-3)
    num1 = rand() % 3 + 1;
    num2 = rand() % 3 + 1;
    num3 = rand() % 3 + 1;
    // 隨機生成三行殭屍(並儲存到指定變數中)
    // 第一行
    switch (num1)
    {
    case 1:
        sscanf(str1, "%s", line_1); // 讀取str1值，給line1
        break;
    case 2:
        sscanf(str2, "%s", line_1);
        break;
    case 3:
        sscanf(str3, "%s", line_1);
        break;
    }
    // 第二行
    switch (num2)
    {
    case 1:
        sscanf(str1, "%s", line_2);
        break;
    case 2:
        sscanf(str2, "%s", line_2);
        break;
    case 3:
        sscanf(str3, "%s", line_2);
        break;
    }
    // 第三行
    switch (num3)
    {
    case 1:
        sscanf(str1, "%s", line_3);
        break;
    case 2:
        sscanf(str2, "%s", line_3);
        break;
    case 3:
        sscanf(str3, "%s", line_3);
        break;
    }
    // 輸出遊戲基礎三隨機殭屍
    printf("%s\n", line_1);
    printf("%s\n", line_2);
    printf("%s\n", line_3);
    int key_all = 1, key = 1;
    // key_all為總遊戲控制循環，key_begin為使用者輸入的保險絲
    while (key_all == 1)
    {
        scanf(" %c", &gamernum);
        switch (gamernum)
        {
        case 'A':
        case 'a': // 對應打殭屍種類
            strcpy(gamerin, str1);
            clearScreen();
            break;
        case 'S':
        case 's':
            strcpy(gamerin, str2);
            clearScreen();
            break;
        case 'D':
        case 'd':
            strcpy(gamerin, str3);
            clearScreen();
            break;
        case 'F':
        case 'f': // 跳脫遊戲
            key = 0;
            clearScreen();
            break;
        default: // 防呆機制
            printf("please enter again,you enter wrong code\n");
            continue; // 優化程式
        }

        if (key == 1) // key為遊戲結束控制字元
        {
            int cmp = strcmp(gamerin, line_3); // 比較字串相同性
            if (cmp > 0)                       // str1 > str2
            {
                printf("faulse\n");
                heart -= 1; // 對應錯誤會扣血
            }
            else if (cmp == 0) // str1 = str2
            {
                score += 1; // 成功則加分
                printf("success, %-5d\n", score);
            }
            else if (cmp < 0) // str1 < str2
            {
                printf("faulse\n");
                heart -= 1;
            }
            // 下移程序
            strcpy(mid, line_2); // 將line2值賦予mid，strcpy
            strcpy(line_2, line_1);
            strcpy(line_3, mid);
            num3 = rand() % 3 + 1;
            if (heart > 0) // 血量判斷
            {

                switch (num3) // 打完後，將1，2行下移成為2，3行，並新增隨機第1行
                {
                case 1:
                    sscanf(str1, "%s", line_1);
                    break;
                case 2:
                    sscanf(str2, "%s", line_1);
                    break;
                case 3:
                    sscanf(str3, "%s", line_1);
                    break;
                }
                printf("%s\n", line_1);
                printf("%s\n", line_2);
                printf("%s\n", line_3);
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
int main(void)
{
    char begin = '1';
    int key = 1, key_type, key_end = 0, again = 0;
    while (key == 1)
    {

        printf("welcome to the game of shooting Zombies\n");
        printf("if you want to start the game, please enter 1, if not enter 0\n");
    here: // 優化程式
        scanf(" %c", &begin);
        clearScreen();
    there:
        switch (begin)
        {
        case '1':
            content();
            again = 1;
            key_end = 0;
            break;
        case '0':
            printf("thank you for playing\n");
            again = 0;
            key = 0;
            break;
        default:
            printf("please enter again, you enter wrong code\n");
            goto here;
            break;
        }

        while (again == 1)
        {
            printf("if you want to play again, please enter 1, if not enter 0\n");
            while (key_end == 0)
            {
            this:
                scanf("%d", &key_type);
                switch (key_type)
                {
                // 優化程式
                case 1:
                    key_end = 1;
                    key = 1;
                    begin = '1';
                    again = 0;
                    clearScreen();
                    printf("lets play again !!!\n");
                    goto there;
                    break;
                case 0:
                    key_end = 1;
                    key = 0;
                    again = 0;
                    clearScreen();
                    printf("thank you for playing\n");
                    break;
                default:
                    clearScreen();
                    printf("please enter again,you enter wrong code\n");
                    key_end = 0;
                    goto this;
                    break;
                }
            }
        }
    }
    return 0;
}
