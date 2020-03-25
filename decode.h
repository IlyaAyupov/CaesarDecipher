
#ifndef CAESAR_DECODE_H
#define CAESAR_DECODE_H
#define EF {0.08167,0.01492,0.02782,0.04253,0.12702,0.02228,0.02015,0.06094,0.06966,0.00153,0.00772,0.04025,0.02406,0.06749,0.07707,0.01929,0.00095,0.05987,0.06327,0.09056,0.02758,0.00978,0.02360,0.00150,0.01974,0.00074}
#define WIDTH_SHIFT_TABLE 19
char encode(char , int );

double chi_sq(const int * ,int, int);

int encode_shift(char *);

int to_decode(int);

char * decode_text(char *);

void print_shift_chi_sq(char *);
#endif //CAESAR_DECODE_H
