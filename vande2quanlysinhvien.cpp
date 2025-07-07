#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

// a) �?nh ngh?a ki?u c?u tr�c SINHVIEN
typedef struct {
    char hoTen[50];
    char maSV[20];
    float tk;   // �i?m th�?ng k?
    float gk;   // �i?m gi?a k?
    float ck;   // �i?m cu?i k?
    float th;   // �i?m th?c h�nh
    float dtb;  // �i?m trung b?nh
} SINHVIEN;

float tinhDTB(SINHVIEN s) {
    return (((2 * s.tk + 3 * s.gk + 5 * s.ck) * 2 + s.th) / 3.0) / 10.0;
}

float nhapDiem(const char *tenDiem) {
    float diem;
    int result;
    do {
        printf("Nhap %s (0-10): ", tenDiem);
        result = scanf("%f", &diem);
        while(getchar() != '\n'); // X�a b? c�c k? t? d� th?a trong input
        if (result != 1) {
            printf("Nhap khong hop le. Vui long nhap lai!\n");
        }
        else if (diem < 0 || diem > 10) {
            printf("Diem khong hop le. Vui long nhap lai!\n");
        }
    } while (result != 1 || diem < 0 || diem > 10);
    return diem;
}

// Ki?m tra chu?i ch? ch?a ch? c�i v� kho?ng tr?ng
int laChu(const char *chuoi) {
    for (int i = 0; chuoi[i] != '\0'; i++) {
        if (!isalpha(chuoi[i]) && chuoi[i] != ' ')
            return 0;
    }
    return 1;
}

// H�m nh?p t�n v?i r�ng bu?c ch? bao g?m ch? c�i
void nhapTen(char *chuoi, int kichThuoc) {
    do {
        printf("Nhap ho ten : ");
        fgets(chuoi, kichThuoc, stdin);
        chuoi[strcspn(chuoi, "\n")] = '\0';
        if (strlen(chuoi) == 0 || !laChu(chuoi)) {
            printf("Ho ten khong hop le. Vui long nhap lai!\n");
        }
    } while (strlen(chuoi) == 0 || !laChu(chuoi));
}

// H�m nh?p MSSV (kh�ng c?n r�ng bu?c ch? ch?a s?)
void nhapMaSV(char *chuoi, int kichThuoc) {
    do {
        printf("Nhap ma sinh vien: ");
        fgets(chuoi, kichThuoc, stdin);
        chuoi[strcspn(chuoi, "\n")] = '\0';
        if (strlen(chuoi) == 0) {
            printf("Ma sinh vien khong duoc de trong. Vui long nhap lai!\n");
        }
    } while (strlen(chuoi) == 0);
}

int main() {
    SINHVIEN A[MAX];
    int n;

    // Nh?p s? l�?ng sinh vi�n v� ki?m tra h?p l? (t? 1 �?n MAX)
    printf("Nhap so luong sinh vien: ");
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("So luong khong hop le. Vui long nhap lai!\n");
        while (getchar() != '\n'); // X�a b? �?m �?u v�o
    }
    while(getchar() != '\n'); // X�a k? t? xu?ng d?ng c?n s�t l?i sau scanf

    // Nh?p th�ng tin cho t?ng sinh vi�n
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);

        nhapTen(A[i].hoTen, sizeof(A[i].hoTen));
        nhapMaSV(A[i].maSV, sizeof(A[i].maSV));

        A[i].tk = nhapDiem("diem TK");
        A[i].gk = nhapDiem("diem GK");
        A[i].ck = nhapDiem("diem CK");
        A[i].th = nhapDiem("diem TH");

        A[i].dtb = tinhDTB(A[i]);
    }

    // Hi?n th? danh s�ch sinh vi�n ph?i h?c l?i (DTB < 4.0)
    printf("\nDanh sach sinh vien phai hoc lai (DTB < 4.0):\n");
    printf("| %-4s | %-30s | %-15s | %-7s |\n", "STT", "HO TEN", "MA SINH VIEN", "DIEM TB");
    printf("---------------------------------------------------------------\n");

    int stt = 1;
    for (int i = 0; i < n; i++) {
        if (A[i].dtb < 4.0) {
            printf("| %-4d | %-30s | %-15s | %-7.2f |\n", stt, A[i].hoTen, A[i].maSV, A[i].dtb);
            stt++;
        }
    }
    if (stt == 1) {
        printf("Khong co sinh vien nao phai hoc lai.\n");
    }

    return 0;
}

