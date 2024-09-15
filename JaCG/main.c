#include <stdio.h>

#include "Player.h"

int main(){
    Player player;
    scanf("%255[^\n]", player.nickname);
    printf("%s\n", player.nickname);
    return 0;
}