#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include "decode.h"
#include "frequency_table.h"
#include "cmdline.h"
#define IN_FILE 0b1
#define OUT_FILE 0b10
#define SUPRESS_DECODE 0b100
#define DECODE_SHIFT 0b1000
#define ENCODE_SHIFT 0b10000
#define FREQUENCY 0b100000
#define SKO 0b1000000



int main(int argc, char *argv[]) {
    int flags=0;
    char* out_file;
    char* in_file;
    struct gengetopt_args_info args_info;
    cmdline_parser(argc, argv, &args_info);
    if(args_info.file_given){
        in_file=args_info.file_arg;
        flags|=IN_FILE;
    }
    if(args_info.out_given){
            out_file=args_info.out_arg;
            flags|=OUT_FILE;
        }
    flags|=SUPRESS_DECODE*args_info.supress_given;
    flags|=DECODE_SHIFT*args_info.decode_shift_given;
    flags|=ENCODE_SHIFT*args_info.encode_shift_given;
    flags|=FREQUENCY*args_info.frequency_given;
    flags|=SKO*args_info.sko_given;
    char str[2000]={0};
    if(flags&IN_FILE){
        FILE * infile=fopen(in_file,"r");
        if(infile==NULL){
            fprintf(stderr,"File %s doesn't exist.\n",in_file);
            exit(1);
        }
        for(int i=0;i<2000&&!feof(infile);i++){
            str[i]=fgetc(infile);
        }
        str[strlen(str)-1]=0;
    }
    char * decoded_str=decode_text(str);
    if(flags&DECODE_SHIFT)printf("Decode shift: %d\n",to_decode(encode_shift(str)));
    if(flags&ENCODE_SHIFT)printf("Encode shift: %d\n",encode_shift(str));
    if(flags&FREQUENCY)print_freq_table(str);
    if(flags&SKO)print_shift_chi_sq(str);
    if(!(flags&SUPRESS_DECODE||flags&OUT_FILE)){
        printf("Decoded string: %s\n",decoded_str);
    }
    if(flags&OUT_FILE){
        FILE * outfile=fopen(out_file,"w");
        if(out_file==NULL){
            fprintf(stderr,"Can't create output file.\n");
            exit(1);
        }
        fprintf(outfile,"%s",decoded_str);
    }
    return 0;
}
