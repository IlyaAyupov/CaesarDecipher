#include "frequency_table.h"
#include "decode.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char encode(char c, int shift){
    if(c>='a'&&c<='z')return 'a'+(c-'a'+shift)%26;
    if(c>='A'&&c<='Z')return 'A'+(c-'A'+shift)%26;
    return c;
}


double chi_sq(const int * text_freq,int shift, int n){
    double sum=0;
    double ENGLISH_FREQ[]=EF;
    for(char i='a';i<='z';i++){
            sum+=((n*ENGLISH_FREQ[offset(i)]-text_freq[offset(encode(i,shift))])*(n*ENGLISH_FREQ[offset(i)]-text_freq[offset(encode(i,shift))]))/ENGLISH_FREQ[offset(i)];

    }
    return sum/(n*n);
}


int encode_shift(char * str){
    int min_shift=0;
    double min_value=100;
    int * freq_table=create_freq_table();
    add_letters(freq_table,str);
    int n=letter_count(str);
    for(int i=0;i<26;i++){
        double sq=chi_sq(freq_table,i,n);
        if(sq<min_value){
            min_value=sq;
            min_shift=i;
        }
    }
    if(min_value>=0.5){
        fprintf(stderr,"Error: SKO too big.\n");
        min_shift=0;
    }
    return min_shift;
}


void print_shift_chi_sq(char * str){
    int * freq_table=create_freq_table();
    add_letters(freq_table,str);
    int n=letter_count(str);
    printf("Shift SKO table\n");
    for(int i=0;i<WIDTH_SHIFT_TABLE;i++)printf("-");
    printf("\n|%6s|%10s|\n","shift","SKO");
    for(int i=0;i<26;i++){
        double sq=chi_sq(freq_table,i,n);
        for(int i=0;i<WIDTH_SHIFT_TABLE;i++)printf("-");
        printf("\n");
        printf("|%6d|%10lf|\n",i,sq);

    }
    for(int i=0;i<WIDTH_SHIFT_TABLE;i++)printf("-");
    printf("\n");
}


int to_decode(int shift){
    return (26-shift)%26;
}

char * decode_text(char * str){
    int shift=to_decode(encode_shift(str));
    char * out=(char*)calloc(strlen(str)+1, sizeof(char));
    for(int i=0;i<strlen(str);i++){
        out[i]=encode(str[i],shift);
    }
    out[strlen(str)]=0;
    return out;
}