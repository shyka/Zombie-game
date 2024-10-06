#ifndef LEVEL_STAGE
#define LEVEL_STAGE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clearscreen.h"

//定義所有的殭屍對應列表(zombie_spawn_tablet)
char str_EZ_array[4][4]; //easy
char str_HD_array[11][6]; //hard
int p = 0, x;

char str_EZ_ST1[4][4] = 
{{"100"}, 
 {"010"}, 
 {"001"}};
 char str_EZ_ST2[4][4] = 
{{"1*0"}, 
 {"01*"}, 
 {"*01"}};
 char str_EZ_ST3[4][4] = 
{{"1#*"}, 
 {"*1#"}, 
 {"#*1"}};
 char str_EZ_ST4[4][4] = 
{{"164"}, 
 {"315"}, 
 {"871"}};
 char str_EZ_ST5[4][4] = 
{{"1$5"}, 
 {"91%"}, 
 {"@21"}};
 char str_EZ_ST6[4][4] = 
{{"1!l"}, 
 {"i1l"}, 
 {"!l1"}};
 char str_EZ_ST7[4][4] = 
{{"1+3"}, 
 {"-10"}, 
 {"2-1"}};
 char str_EZ_ST8[4][4] = 
{{"183"}, 
 {"l1!"}, 
 {"i]1"}};
 char str_EZ_ST9[4][4] = 
{{"1l#"}, 
 {")1$"}, 
 {"|71"}};
 char str_EZ_ST10[4][4] = 
{{"1OU"}, 
 {"A1E"}, 
 {"GA1"}};
 char str_EZ_ST11[4][4] = 
{{"1$5"}, 
 {"|1/"}, 
 {"lJ1"}};
 char str_EZ_ST12[4][4] = 
{{"1Il"}, 
 {"71:"}, 
 {":$1"}};
 char str_EZ_ST13[4][4] = 
{{"dIE"}, 
 {"DiE"}, 
 {"DIe"}}; // kill screen



char str_HD_ST1[11][6] = 
{{"10000"}, 
 {"01000"}, 
 {"00100"}, 
 {"00010"}, 
 {"00001"},
 {"?0000"},
 {"0?000"},
 {"00?00"},
 {"000?0"},
 {"0000?"}};
 char str_HD_ST2[11][6] = 
{{"10%00"}, 
 {"010%0"}, 
 {"001%0"}, 
 {"%0010"}, 
 {"%0001"},
 {"?0%00"},
 {"0?00%"},
 {"%0?00"},
 {"00%?0"},
 {"00%0?"}};
 char str_HD_ST3[11][6] = 
{{"10%0|"}, 
 {"01|%0"}, 
 {"|01%0"}, 
 {"%|010"}, 
 {"%0|01"},
 {"?|%00"},
 {"0?0%|"},
 {"%0?|0"},
 {"0|%?0"},
 {"|%00?"}};
 char str_HD_ST4[11][6] = 
{{"1~%+|"}, 
 {"~1|%+"}, 
 {"~|1%+"}, 
 {"%|~1+"}, 
 {"~+%|1"},
 {"?+~%|"},
 {"%?|~+"},
 {"%|?+~"},
 {"+|%?~"},
 {"|~%+?"}};
 char str_HD_ST5[11][6] = 
{{"1~i$l"}, 
 {"~1i%l"}, 
 {"+|1%$"}, 
 {"l|~1i"}, 
 {"i+l|1"},
 {"?l%|+"},
 {"%?|i$"},
 {"l|?%$"},
 {"i|%?~"},
 {"|~i+?"}};
 char str_HD_ST6[11][6] = 
{{"1~0$p"}, 
 {"917%l"}, 
 {":L1+j"}, 
 {"l2~1P"}, 
 {"$+l%1"},
 {"?+d7+"},
 {"9?|6$"},
 {"lI?%0"},
 {"iI:?6"},
 {"8~3+?"}};
 char str_HD_ST7[11][6] = 
{{"1+3=4"}, 
 {"+1=0!"}, 
 {"6-1=5"}, 
 {"0!=1!"}, 
 {"8/8=1"},
 {"?pple"},
 {"l?ist"},
 {"do?ge"},
 {"lea?!"},
 {"lyin?"}};
 char str_HD_ST8[11][6] = 
{{"12345"}, 
 {"21345"}, 
 {"23145"}, 
 {"23415"}, 
 {"23451"},
 {"?!@#$"},
 {"$?#@!"},
 {"$!?#@"},
 {"#!$?@"},
 {"#@!$?"}};
 char str_HD_ST9[11][6] = 
{{"1__l_"}, 
 {"_1__i"}, 
 {"__1_L"}, 
 {"I__1_"}, 
 {"i___1"},
 {"?MUWD"},
 {"H?JQA"},
 {"LK?OP"},
 {"TSV?K"},
 {"IAUX?"}};
 char str_HD_ST10[11][6] = 
{{"1[]|["}, 
 {"[1[|]"}, 
 {"|[1[["}, 
 {"][|1]"}, 
 {"|[|]1"},
 {"?EVER"},
 {"G?NNA"},
 {"GI?E~"},
 {"YOU?~"},
 {"UP~~?"}};
 char str_HD_ST11[11][6] = 
{{"[DIE]"}, 
 {"{DIE}"}, 
 {":DIE:"}, 
 {"!DIE!"}, 
 {"(DIE)"},
 {"|DIE|"},
 {"#DIE#"},
 {"$DIE$"},
 {"?DIE?"},
 {"/DIE/"}}; // kill screen


void LV_stage_change(int mode, int level)
{
    srand(time(NULL));
    switch(mode)
    {
    case 1:
        switch (level)
        {
        case 1:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST1[p]);
            }
            break;
        case 2:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST2[p]);
            }
            break;
        case 3:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST3[p]);
            }
            break;
        case 4:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST4[p]);
            }
            break;
        case 5:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST5[p]);
            }
            break;
        case 6:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST6[p]);
            }
            break;
        case 7:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST7[p]);
            }
            break;
        case 8:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST8[p]);
            }
            break;
        case 9:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST9[p]);
            }
            break;
        case 10:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST10[p]);
            }
            break;
        case 12:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST11[p]);
            }
            break;
        case 14:
            for(p = 0; p < 3; p++)
            {
                strcpy(str_EZ_array[p], str_EZ_ST12[p]);
            }
            break;
        case 16:
            strcpy(str_EZ_array[0], str_EZ_ST9[0]);
            strcpy(str_EZ_array[1], str_EZ_ST4[1]);
            strcpy(str_EZ_array[2], str_EZ_ST7[2]);
            break;
        case 18:
            strcpy(str_EZ_array[0], str_EZ_ST2[0]);
            strcpy(str_EZ_array[1], str_EZ_ST11[1]);
            strcpy(str_EZ_array[2], str_EZ_ST8[2]);
            break;
        case 20:
            strcpy(str_EZ_array[0], str_EZ_ST5[0]);
            strcpy(str_EZ_array[1], str_EZ_ST10[1]);
            strcpy(str_EZ_array[2], str_EZ_ST6[2]);
            break;
        case 21:
            for(p = 0; p < 3; p++)
            {
                x = rand() % 3;
                strcpy(str_EZ_array[x], str_EZ_ST13[x]);
            }
            break;
        }
        break;   
    case 2:
        switch (level)
        {
        case 1:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST1[p]);
            }
            break;
        case 2:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST2[p]);
            }
            break;
        case 3:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST3[p]);
            }
            break;
        case 4:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST4[p]);
            }
            break;
        case 5:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST5[p]);
            }
            break;
        case 6:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST6[p]);
            }
            break;
        case 7:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST7[p]);
            }
            break;
        case 10:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST8[p]);
            }
            break;
        case 15:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST9[p]);
            }
            break;
        case 20:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST10[p]);
            }
            break;
        case 21:
            for(p = 0; p < 10; p++)
            {
                strcpy(str_HD_array[p], str_HD_ST11[p]);
            }
            break;
        }
        break;
    }
}

#endif
