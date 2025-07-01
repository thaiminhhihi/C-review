// 🔸 Bài 1: Tính tổng, hiệu, tích, thương của 2 số
// Viết chương trình:
// Nhập vào 2 số nguyên a, b
// In ra tổng, hiệu, tích, thương (nếu b != 0)



#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d", &a,&b);
    if (b!=0)
    {
        printf("Tong a+ b = %d\n", a+b);
        printf("Hieu a-b= %d\n", a-b);
        printf("tich a*b =%d\n", a*b);
        printf("thuong a/b = %d",a/b);
    }
    

    
}