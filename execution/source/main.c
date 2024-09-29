#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clearscreen.h"
#include "easymode.h"
#include "hardmode.h"

//遊玩主程式
int main(void) 
{
    char begin = '1', key_type = '1'; //為輸入型字元，用來判斷遊玩的執行與否
    int key = 1, key_end = 0, again = 0;
    while (key == 1) //開頭歡迎遊玩介面
    {

        printf("welcome to the game of shooting Zombies\n");
    there:
        printf("if you want to start the game, please enter 1 to play easy mode, enter 2 to play hard mode, if not enter 0\n");
    here: // 優化程式
        scanf(" %c", &begin);
        clearScreen();
        switch (begin)
        {
        case '1': //確定遊玩
            easy_mode();
            again = 1;
            key_end = 0;
            break;
        case '2': //確定遊玩
            hard_mode();
            again = 1;
            key_end = 0;
            break;
        case '0': //退出
            printf("thank you for playing\n");
            again = 0;
            key = 0;
            break;
        default: //防呆設定
            printf("please enter again, you enter wrong code\n");
            goto here;
            break;
        }

        while (again == 1) //第一次結束遊玩後，再次詢問是否要重新遊玩
        {
            printf("if you want to play again, please enter 1, if not enter 0\n");
            while (key_end == 0)
            {
                scanf(" %c", &key_type);
                switch (key_type)
                {
                // 優化程式
                case '1': //確認遊玩
                    key_end = 1;
                    key = 1;
                    begin = '1';
                    again = 0;
                    clearScreen();
                    printf("lets play again !!!\n");
                    goto there; //再次執行遊玩程式
                    break;
                case '0': //退出
                    key_end = 1;
                    key = 0;
                    again = 0;
                    clearScreen();
                    printf("thank you for playing\n");
                    break;
                default: //防呆設定
                    clearScreen();
                    printf("please enter again,you enter wrong code\n");
                    key_end = 0;
                    break;
                }
            }
        }
    }
    return 0;
}
