#include "libft.h" // Assurez-vous que ce fichier d'en-tête contient les prototypes des fonctions que vous utilisez.
#include <stdio.h>
char to_uppercase( unsigned int index, char c) 
{

    if (c >= 'a' && c <= 'z') {
	    index++;
        return c - 'a' + 'A'; // Convert lowercase to uppercase
    }
    return c;
}
int main(void) {
    char *original = "hello world";
    char *transformed;

    // Apply the ft_strmapi function with the to_uppercase function
    transformed = ft_strmapi(original, to_uppercase);

    if (transformed) {
        printf("Original string: %s\n", original);
        printf("Transformed string: %s\n", transformed);
        free(transformed); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
