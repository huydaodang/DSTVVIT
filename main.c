#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ID;
    int MSSV;
    char hoTen[100];
    int Group_id;
}thanhvien;
void Nhap(thanhvien *tv)
{
    printf("Nhap thong tin thanh vien\n");
    gets(tv->hoTen);
    printf("Nhap MSSV:\n");
    scanf("%d",&tv->MSSV);
    fflush(stdin);
    printf("Nhap ID:\n");
    scanf("%d",&tv->ID);
    fflush(stdin);
    printf("Nhap Group_id:\n");
    scanf("%d",&tv->Group_id);
    fflush(stdin);
}
void In(thanhvien *tv)
{
    printf("Ten thanh vien %s\n",tv->hoTen);
    printf("ID: %d\n",tv->ID);
    printf("Ma so sinh vien:%d\n",tv->MSSV);
    printf("Group_id:%d\n",tv->Group_id);
}
int Tim(thanhvien *tv,char hoten[],int size)
{
    int dem=0;
    while(strcmp(tv->hoTen,hoten)!=0)
    {
        tv=(tv+1);
        dem++;
    }
    return dem;
}
void deltv(thanhvien *tv,int dem,int *size)
{
    int i;
    thanhvien *p;
    tv=tv+dem;
    while(dem<(*size-1))
    {
        p=tv+1;
        strcpy(tv->hoTen,p->hoTen);
        tv->ID=p->ID;
        tv->MSSV=p->MSSV;
        tv->Group_id=p->Group_id;
        tv=tv+1;
        dem++;
    }
    tv=tv-(*size-1);
    *size=*size-1;
}
void Suatv(thanhvien *tv,int dem,int size)
{
    tv=tv+dem;
    printf("Nhap thong tin thanh vien\n");
    gets(tv->hoTen);
    printf("Nhap MSSV:\n");
    scanf("%d",&tv->MSSV);
    fflush(stdin);
    printf("Nhap ID:\n");
    scanf("%d",&tv->ID);
    fflush(stdin);
    printf("Nhap Group_id:\n");
    scanf("%d",&tv->Group_id);
    fflush(stdin);
}
void Themtv(thanhvien *tv,int *size)
{
    Nhap(&tv[*size]);
    *size=*size+1;
}


void main()
{
   thanhvien tv1[200];
   int i,j,k,h,m,size,dem=0;
   char hoten[30],hoten1[30];
   printf("Nhap vao so thanh vien:\n");
   scanf("%d",&size);
   fflush(stdin);
   for(i=0;i<size;i++)
   {
       Nhap(&tv1[i]);
   }
   for(j=0;j<size;j++)
   {
       In(&tv1[j]);
   }
   printf("Nhap vao ten nguoi can xoa:\n");
   gets(hoten);
   dem=Tim(&tv1,hoten,size);
   printf("%d\n",dem);
   deltv(&tv1,dem,&size);
   for(k=0;k<size;k++)
   {
        In(&tv1[k]);
   };
   printf("Nhap vao ten thanh vien can sua thong tin:\n");
   gets(hoten1);
   Tim(&tv1,hoten1,size);
   Suatv(&tv1,dem,size);
    for(h=0;h<size;h++)
   {
        In(&tv1[h]);
   };
   printf("Them thanh vien:\n");
    Themtv(&tv1,&size);
    for(m=0;m<size;m++)
    {
        In(&tv1[m]);
    }
}
