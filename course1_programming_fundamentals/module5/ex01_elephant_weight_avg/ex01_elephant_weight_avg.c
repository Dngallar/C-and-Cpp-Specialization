/*
    Program to compute the average weight for a population of
    elephant seals read into an array

    Domingo Gallardo Saavedra
    April 4, 2025
*/

// Includes
#include <stdio.h> /* Standard I/O library */
#include <ctype.h> /* For use isalpha() and isdigit() functions */
#include <math.h>  /* For use pow() function*/

// Prototypes
int convert_int_array_to_int(int*, int); /* Function used to transform int array into int */

// Main function
int main(void) {
    int c;                  // Used for value of character
    int num_elp = 0;        // Used to count the number of elephant weights
    int aux_count = 0;      // Used to count the digits until space
    int digits[10] = {0};   // Used for store the digits found
    int sum_weights = 0;    // Int used to the sum of the elephant weights

    FILE *fp; // Pointer to the file
    fp = fopen("elephant_seal_data.txt", "r"); // To open the file

    // Read until end of file
    while ((c = fgetc(fp)) != EOF) {
        // Check if the current char is a digit
        if (isdigit(c)) {
            digits[aux_count] = (int) c - 48; // Poblate digits as int less ASCI offset
            aux_count++; // Increment number of digits until space
        }
        // Space found
        else if (aux_count != 0) {
            int len_array = aux_count; // To store the length of the array
            sum_weights = sum_weights + convert_int_array_to_int(digits, len_array); // To sum to the actual total
            num_elp++; // Sum 1 to number of elephant weights
            aux_count = 0; // Reset number of digits
        }
    }

    // Output print
    printf("\nThe average weight is: %.3f Kg\n\n", (float)sum_weights / num_elp);

    fclose(fp); // To close the file
    return 0; // Return 0 for success
}

/* Function used to transform int array into int */
int convert_int_array_to_int(int *int_array, int len_array) {
    int converted = 0; // Used to sum the respective decimal place

    // Loop to get the power of 10 for the n digits and sum it
    for(int i = len_array; i > 0; i--) {
        converted = converted + (int) (int_array[len_array - i] * pow(10.0, (double) (i-1)));
    }

    return converted; // Return the int array as integer
}
