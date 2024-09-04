#include <stdio.h>
#include "src/utilities/console_utils.h"
#include "src/main_menu.h"

int main(){
    CON_CLEAR;
    printf("Welcome to the I Got Rooted (IGR)!\n");
    menu();
    printf("See ya next time!\n");
    return 0;
}