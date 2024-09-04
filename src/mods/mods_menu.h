#ifndef MODS_MENU_H
#define MODS_MENU_H

#define DEFAULT_MODS_FOLDER "default/"
#define DEFAULT_USERS_FOLDER "users/"

#include <stdio.h>
#include <dirent.h>

int mods_menu(){
    DIR *directory;
    directory = opendir(".");
    if(directory == NULL){
        puts("unable to open directory");
        return 1;
    }
    else{
        puts("opened");
        printf("%s\n", readdir(directory)->d_name);
    }
    closedir(directory);
    return 0;
}

#endif