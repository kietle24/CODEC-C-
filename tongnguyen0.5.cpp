#include <stdio.h>

int main() {
    int n;


    printf("Nhap n: ");
    scanf("%d", &n);

    printf("C�c so thoa m�n dieu kien l�:\n");
 
    for (int i = 1; i <= n; i++) {
      
        if (i % 2 != 0 && i % 3 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
