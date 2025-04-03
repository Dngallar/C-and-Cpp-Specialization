/*
    Sine and Cosine Table between (0, 1)

    Domingo Gallardo Saavedra
    April 4, 2025
*/

// Includes
#include <stdio.h>
#include <math.h> /* has  sin() and cos() */

// Main function
int main(void) {
    double interval; // Variable to manage the interval between input value
    int i; // Variable to manage each interval of the sine-cosine table

    printf(" Input |  Sine  | Cosine\n"); // Header of the table

    // For loop to fill the table
    int num_of_input = 15; // To set the number of values to calculate
    for (i = 0; i <= num_of_input; i++) {
        interval = i / (double) num_of_input; // To create a interval between (0, 1)
        // print format: input_value | sine(input_value) | cosine(input_value)
        // with only 4 decimal places
        printf("%.4lf | %.4lf | %.4lf \n", interval, sin(interval), cos(interval));
    }

    return 0; // Return 0 for success
}