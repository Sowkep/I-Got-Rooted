#ifndef MODS_MENU_H
#define MODS_MENU_H

#define DEFAULT_MODS_FOLDER "src/mods/default/"
#define DEFAULT_USERS_FOLDER "src/mods/users/"

#include <stdio.h>
#include <dirent.h>

int mods_menu(){
    DIR *directory;
    directory = opendir(DEFAULT_MODS_FOLDER);
    if(directory == NULL){
        puts("Unable to open directory");
        return 1;
    }
    else{
        puts("Opened");
        printf("%s\n", readdir(directory)->d_name);
    }
    closedir(directory);
    return 0;
}

#endif