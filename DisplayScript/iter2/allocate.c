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

    // Allocate memory for the image data
    //unsigned char *image_data = (unsigned char*)malloc((size * sizeof(unsigned char)));
    unsigned char *image_data = (unsigned char*)malloc((3275658));


    // Check if the memory allocation was successful
    if (image_data == NULL) {
        printf("Error: Unable to allocate memory for image\n");
        fclose(fp);
        return 1;
    }

    // Read the image data from the file into memory
    fread(image_data, sizeof(unsigned char), size, fp);

    // Set the memory location into an environment variable
    char *mem_loc_str = (char*)malloc(64 * sizeof(char)); // allocate memory for the environment variable
    sprintf(mem_loc_str, "%x", &image_data); // convert the memory address to a string
    //setenv("TTEST", mem_loc_str, 1); // set the environment variable
    printf(mem_loc_str);
    free(mem_loc_str); // free the memory allocated for the environment variable

    // Close the file and free the memory when you're done using it
    fclose(fp);
    



    




    // NEED TO FREE IN DEALLOCATE STEP
    free(image_data);

    return 0;
}
//In this code, we're opening the image file "img.bmp" in binary mode using the fopen() function. We then get the size of the file using the fseek() and ftell() functions.

//Next, we allocate memory for the image data using the malloc() function, and we read the image data from the file into memory using the fread() function.

//After we've loaded the image data into memory, we convert the memory address to a string using the sprintf() function, and we allocate memory for an environment variable called MEM_LOC using the malloc() function. We then set the value of the MEM_LOC environment variable to the memory address string using the setenv() function, and we free the memory allocated for the environment variable using the free() function.

//Finally, we close the file using the fclose() function and we free the memory allocated for the image data using the free() function.

//Note that the sprintf()


