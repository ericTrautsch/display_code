#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned char *output;
    output = argv[1];
    
    printf("The value of 'output' is: %s\n", output);

    // free memory
    free(output);

    return 0;
}