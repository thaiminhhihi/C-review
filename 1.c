// ## **Bài 1: Hoán đổi giá trị hai số nguyên**

// Viết một chương trình khai báo 2 biến số nguyên. Viết hàm thực hiện việc hoán đổi giá trị của hai biến này thông qua con trỏ. In kết quả trước và sau khi hoán đổi.

// ---
    #include <stdio.h>
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int main(int argc, char const *argv[])
    {
        int x = 5, y = 10;
        printf("Trước khi hoán đổi: x = %d, y = %d\n", x, y);
        swap(&x, &y);
        printf("Sau khi hoán đổi: x = %d, y = %d\n", x, y);
        return 0;
}
