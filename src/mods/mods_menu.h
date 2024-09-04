#ifndef MODS_MENU_H
#define MODS_MENU_H

#define DEFAULT_MODS_FOLDER "src/mods/default/"
#define DEFAULT_USERS_FOLDER "src/mods/users/"

#include <stdio.h>
#include <dirent.h>

inline int mods_menu(){
    DIR *directory;
    directory = opendir(DEFAULT_MODS_FOLDER);
    struct dirent *entry;

    if(directory == NULL){
        puts("Unable to open directory");
        return 1;
    }
    else{
        while( (entry = readdir(directory)) ){
            printf("File: %s\n", entry->d_name);
            //neeed to include entry->d_name        
        }
    }
    closedir(directory);
    
    return 0;
}

#endif