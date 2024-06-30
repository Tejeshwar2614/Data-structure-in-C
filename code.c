#include<stdio.h>
#include<stdlib.h>

// Next line is represented as @ 
int main()
{
    FILE *file;
    file = fopen("text.txt","r");
    if(file==NULL){
        printf("the file has no content so we cant print anything");
        return 0;
    }
    char ch;
    while((ch=fgetc(file))!=EOF){
        printf("%c",ch);
    }
    fclose(file);
    return 1;

}