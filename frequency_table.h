//
// Created by ilya on 25.03.2020.
//

#ifndef CAESAR_FREQUENCY_TABLE_H
#define CAESAR_FREQUENCY_TABLE_H
#define WIDTH_FREQ_TABLE 12
int offset(char);

int letter_count(char*);

int * create_freq_table();

void add_letters(int *,char *);

void print_freq_table(char *);
#endif //CAESAR_FREQUENCY_TABLE_H
