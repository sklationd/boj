#include <stdio.h>
#include <string.h>

long long int expa[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int color_to_index(char *color){
    if(!strcmp(color,"black")){
        return 0;
    } else if (!strcmp(color,"brown")){
        return 1;
    } else if(!strcmp(color,"red")){
        return 2;
    } else if(!strcmp(color,"orange")){
        return 3;
    } else if(!strcmp(color,"yellow")){
        return 4;
    } else if(!strcmp(color,"green")){
        return 5;
    } else if(!strcmp(color,"blue")){
        return 6;
    } else if(!strcmp(color,"violet")){
        return 7;
    } else if(!strcmp(color,"grey")){
        return 8;
    } else if(!strcmp(color,"white")){
        return 9;
    } else {
        return -1;
    }
}

int main(){
    char a1[10];
    char a2[10];
    char a3[10];
    int v1,v2,v3;

    scanf("%s",a1);
    scanf("%s",a2);
    scanf("%s",a3);

    v1 = color_to_index(a1);
    v2 = color_to_index(a2);
    v3 = color_to_index(a3);

    printf("%lld",(10*v1+v2)*expa[v3]);
}
