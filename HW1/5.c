//  Bài 5: Tính diện tích tam giác vuông
// Viết chương trình:
// Nhập vào 2 cạnh vuông a, b


// Tính diện tích tam giác vuông:


// S = 0.5 * a * b

#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b;
    printf("Nhap vao 2 canh vuong a, b: ");
    scanf("%f %f", &a,&b);
    printf("dien tich tam giac vuong la = %.2f", 0.5 *a *b);
    return 0;
}
