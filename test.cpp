#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isAnagram(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) {
        return 0;
    }

    int count[256] = {0};

    for (int i = 0; s1[i] != '\0'; i++) {
        count[(unsigned char)s1[i]]++;
    }

    for (int i = 0; s2[i] != '\0'; i++) {
        count[(unsigned char)s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Nh?p chu?i th? nh?t: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // X�a k? t? xu?ng d?ng n?u c�

    printf("Nh?p chu?i th? hai: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // X�a k? t? xu?ng d?ng n?u c�

    if (isAnagram(str1, str2)) {
        printf("Hai chu?i l� anagram!\n");
    } else {
        printf("Hai chu?i KH�NG ph?i l� anagram!\n");
    }

    return 0;
}

