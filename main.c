#include <stdio.h>
#include <dirent.h>

#include "src/utilities/console_utils.h"
#include "src/main_menu.h"
#include "src/utilities/paths.h"

int main(){
    CON_CLEAR;
    printf("Welcome to the I Got Rooted (IGR)!\n");
    menu();
    printf("See ya next time!\n");
    
    //clear tmp
    DIR* directory;
    directory = opendir(TMP_PATH);
    if(directory == NULL){
        perror("Unable to open directory");
        exit(1);
    } else{
#       include <ftw.h>
#       include <unistd.h>
        int rem_val = remove("_tmp");
    }

    return 0;
}