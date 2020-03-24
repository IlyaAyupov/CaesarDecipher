#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "frequency_table.h"
int offset(char c){
    if(c>='a'&&c<='z')return c-'a';
    if(c>='A'&&c<='Z')return c-'A';
    fprintf(stderr,"Error: %c is not a letter.\n",c);
}


int letter_count(char* str){
    int count=0;
    for(int i=0;i<strlen(str);i++)
        count+=(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z');
    return count;
}

int * create_freq_table(){
    int* mas= (int*)calloc(26, sizeof(int));
    for(int i =0;i<26;i++)mas[i]=0;
    return mas;
}


void add_letters(int * freq_table,char * str){
    for(int i=0;i<strlen(str);i++)
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))freq_table[offset(str[i])]++;

}

void print_freq_table(char * str){
    int * freq_table=create_freq_table();
    add_letters(freq_table,str);
    printf("Letters count: %d\nCharacters count: %ld\n",letter_count(str),strlen(str));
    printf("Frequency table\n");
    for(int i=0;i<WIDTH_FREQ_TABLE;i++)printf("-");
    printf("\n|%4s|%5s|\n","char","count");
    for(char c='a';c<='z';c++){
        for(int i=0;i<WIDTH_FREQ_TABLE;i++)printf("-");
        printf("\n");
        printf("|%4c|%5d|\n",c,freq_table[offset(c)]);
    }
    for(int i=0;i<WIDTH_FREQ_TABLE;i++)printf("-");
    printf("\n");
}