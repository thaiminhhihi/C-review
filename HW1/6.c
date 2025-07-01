//  Bài 6 (Dùng if nâng cao): Xếp loại học lực
// Viết chương trình:
// Nhập vào điểm trung bình (float)


// Xếp loại theo điều kiện:


// >= 8.5   → Gioi  
// >= 6.5   → Kha  
// >= 5.0   → Trung binh  
// < 5.0    → Yeu
#include <stdio.h>
int main(int argc, char const *argv[])
{
    float diemTB;
    scanf("%f", &diemTB);
    if (diemTB >= 8.5)
    {
        printf("Gioi\n");
        return 0;
    }else if (diemTB >= 6.5)
    {
        printf("Kha\n");
        return 0;
    }else if (diemTB >= 5.0)
    {
        printf("Trung binh\n");
        return 0;
    }else {
        printf("Yeu\n");
        return 0;
    }
    
    
    
    
    
    return 0;
}
