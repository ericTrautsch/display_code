#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the image file
    FILE *fp = fopen("img.bmp", "rb");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Get the size of the image file
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("%ld bytes",size);
    //printf("%u",sizeof(unsigned char));
    
    fclose(fp);
    
    // NEED TO FREE IN DEALLOCATE STEP
    //free(image_data);

    return 0;
}
//In this code, we're opening the image file "img.bmp" in binary mode using the fopen() function. We then get the size of the file using the fseek() and ftell() functions.

//Next, we allocate memory for the image data using the malloc() function, and we read the image data from the file into memory using the fread() function.

//After we've loaded the image data into memory, we convert the memory address to a string using the sprintf() function, and we allocate memory for an environment variable called MEM_LOC using the malloc() function. We then set the value of the MEM_LOC environment variable to the memory address string using the setenv() function, and we free the memory allocated for the environment variable using the free() function.

//Finally, we close the file using the fclose() function and we free the memory allocated for the image data using the free() function.

//Note that the sprintf()


