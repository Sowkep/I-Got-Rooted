#ifndef MODS_MENU_H
#define MODS_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/cdefs.h>
#include <sys/stat.h>

#include "../utilities/paths.h"
#include "../utilities/console_utils.h"
#include "../utilities/map.h"
#include "default/OSINT.h"

#define DEFAULT_MODS_PATH "src/mods/default"
#define DEFAULT_USERS_PATH "src/mods/users"

static int mods_loader(){
    CON_CLEAR;

    DIR *directory;
    directory = opendir(DEFAULT_MODS_PATH);

    if(directory == NULL){
        perror("Unable to open directory");
        return 1;
    } else{
        FILE* includes;
        struct dirent *entry;

        #define filepath TMP_PATH "/includes.h"

        includes = fopen(filepath, "a");

        if(includes == NULL){
            perror("Unable to open tmp folder");
            puts("Making tmp folder");
            mkdir("tmp", S_IRWXU);
            puts("Success");
            mods_loader();
        } else{
            int el=0;
            char* mods[0];
            void* err;

            Map* funcs;

            while( (entry = readdir(directory)) != NULL){
                if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                    continue;
                fprintf(includes, "#include \"../%s/%s\"\n", DEFAULT_MODS_PATH, entry->d_name);
                
                fprintf(includes, "#define KEYS[%d] %s\n", el, entry->d_name);
                if(err == NULL){
                    perror("Unable to memory an array");
                    exit(1);
                }

                printf("%zu\n", strlen(entry->d_name));
                ++el;
            }
            fclose(includes);
            
            for(int i = 0; i < sizeof(mods)/sizeof(mods[0]); ++i){
                free(mods[i]);
            }
        }
    }
    closedir(directory);

    return 0;
}

#endif