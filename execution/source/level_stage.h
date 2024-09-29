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
int p = 0;

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


void LV_stage_change(int mode, int level)
{
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
        }
        break;
    }
}

#endif