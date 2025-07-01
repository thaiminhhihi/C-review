// 🔸 Bài 7 (Dùng switch case): Máy tính đơn giản
// Viết chương trình:
// Nhập 2 số nguyên a, b và 1 ký hiệu phép toán +, -, *, /


// Dùng switch để thực hiện phép toán tương ứng và in kết quả


// Kiểm tra nếu như có chia cho 0 (sai)
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b;
    char pheptoan;
    scanf("%d %d %c", &a, &b, &pheptoan);
    switch(pheptoan) {
        case '+':
            printf("Tong a + b = %d\n", a + b);
            break;
            case '-':
            printf("Hieu a-b= %d\n", a-b);
            break;
            case '*':
            printf("Tich a*b= %d\n", a*b);
            break;
            case '/':
            if (b == 0) {
                printf("Loi: Chia cho 0\n");
            } else {
                printf("Thuong a/b= %d\n", a/b);
            }
            break;  
    }
    return 0;
}
