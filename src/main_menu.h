#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "utilities/console_utils.h"
#include "mods/mods_menu.h"

static const char* options[] = {"mods", "setting up", "exit"};
static int user_input;

inline void menu(){
    printf("Select an option:\n");
    for(int i = 0; i < sizeof(options) / sizeof(options[0]); i++){
        printf("%d)%s\n", i, options[i]);
    }
    scanf("%d", &user_input);
    if(user_input == 0){
        mods_menu();
    }
}

#endif