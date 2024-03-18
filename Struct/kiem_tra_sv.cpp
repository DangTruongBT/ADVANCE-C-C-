#include <stdio.h>
#include <string.h>

struct SinhVien{
	char ma[10];
	char ten[150];
	bool gioitinh;
};

typedef SinhVien sv;


void Nhapslsv(int &n)
{
	do{
		printf("Nhap so luong sinh vien: ");
		scanf("%d", &n);
		if(n < 0 || n > 100)
		{
			printf("\nNhap lai n");
		}
	}while (n < 0 || n > 100);
}

void Nhap(sv a[], int n )
{
	for(int i = 1; i <= n; i++)
	{
		printf("\nNhap thong tin sinh vien thu %d:", i);
		printf("\nNhap ma sinh vien:");
		fflush(stdin);//xoa bo dem
        gets(a[i].ma);
		printf("\nNhap ten sinh vien:");
		fflush(stdin);
		gets(a[i].ten);
		printf("\nNhap gioi tinh:");
	    scanf("%d", &a[i].gioitinh);
		
	}
}
void Xuat(sv a[], int n)
{
	printf("\n------------THONG TIN SINH VIEN------\n");
	printf("MaSv \t  TenSV \t GioiTinh  \n");
	for(int i=1; i <= n; i++){
        printf("%s \t %s \t %d  \n",a[i].ma,a[i].ten,a[i].gioitinh);
    }
}
void timKiem(sv a[], int n){
//Nhập tên sinh viên cần tìm kiếm
    printf("\nNhap ten sinh vien can tim: ");
    char name[100];
    fflush(stdin);
    gets(name);
    printf("\nNhap ma sinh vien:");
    char maso[10];
	fflush(stdin);
	gets(maso);
     
    bool  check = false; //Biến để kiểm tra xem có sinh viên nào được tìm thấy hay không
 
   //Sử dụng  vòng for để lần lượt tìm qua tất cả sinh viên
    for(int i = 1; i <= n; i++){
        //So sánh xem sinh viên nào có tên khớp với tên nhập từ bàn phím
        if((stricmp(a[i].ten, name) == 0))
		{
			if (stricmp(a[i].ma, maso) == 0)
			{
			
            check = true;
            printf("\n%s %s %d", a[i].ten,a[i].ma,a[i].gioitinh);
        }
       }
   }
    		if(check == false)
			{
        	printf(" =>Khong tim thay sinh vien nao");
   			}

}
int main(){

 sv a[100];
 int n;
  Nhapslsv(n);
  Nhap(a,n);
  Xuat(a,n);
  timKiem(a,n);
 }