#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "utilities/console_utils.h"
#include "mods/mods_loader.h"

static const char* options[] = {"mods", "setting up", "exit"};
static int user_input;

static void menu(){
    printf("Select an option:\n");
    for(int i = 0; i < sizeof(options) / sizeof(options[0]); ++i)
        printf("%d)%s\n", i, options[i]);
    scanf("%d", &user_input);

    switch(user_input){
        case 0:
            mods_loader();
        break;
        case 1:
        break;
        case 2:
            CON_CLEAR;
            exit(0);
        break;
        default:
            CON_CLEAR;
            exit(1);
        break;
    }
}

#endif 