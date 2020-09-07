/*
    Sine Function for an input x between (0, 1)
    Domingo Gallardo Saavedra
    August 9, 2020
*/

// Includes
#include <stdio.h>
#include <math.h>

// Main function
int main(void)
{
    double value; // User input
    double sine_calc; // Result
    
    // While loop until the user enter a range between (0, 1)
    do
    {
        printf("Enter a value between (0, 1): ");
        scanf("%lf", &value);
    } while (value <= 0.0 || value >= 1.0); // Condition

    sine_calc = sin(value); // Sine with Math library
    printf("The sine of %lf is %lf\n\n", value, sine_calc); // Print result

    return 0; // Return 0 for success
}