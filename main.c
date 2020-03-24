#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decode.h"
#include "frequency_table.h"

int main(int argc, char *argv[]) {
    char * str="Aol thpu mvyt vm mvvk wyvkbjapvu pu zbjo zvjplaplz pz aol khpsf jvssljapvu vm dpsk wshuaz huk aol obuapun vm dpsk hupthsz. Obualy-nhaolylyz tvcl hyvbuk jvuzahuasf pu zlhyjo vm mvvk.";
    print_freq_table(str);
    print_shift_chi_sq(str);
    printf("Decoded string: %s",decode_text(str));
    return 0;
}
