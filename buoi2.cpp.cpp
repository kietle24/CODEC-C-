#include <stdio.h>
#include <unistd.h> // Th� vi?n s? d?ng h�m usleep

int main() {
    int i;
    
    for(i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("  ***    ***  \n");
            printf("  ***    ***  \n");
            printf("   ***  ***   \n");
            printf("    *****     \n");
            usleep(500000); // D?ng ch��ng tr?nh trong 0.5 gi�y
            system("clear"); // X�a m�n h?nh (ch? ho?t �?ng tr�n Unix/Linux)
        } else {
            printf("    ***  ***  \n");
            printf("   ***    *** \n");
            printf("  ***      ***\n");
            printf("   ***    *** \n");
            usleep(500000); // D?ng ch��ng tr?nh trong 0.5 gi�y
            system("clear"); // X�a m�n h?nh (ch? ho?t �?ng tr�n Unix/Linux)
        }
           printf("\n") ;

    }
 
    return 0;
}
