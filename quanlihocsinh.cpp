#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct tagHOCSINH {
    int Mhs;
    char Hoten[35];
    int ngay, thang, nam;
    float Toan;
    float Van;
    float TK;
}HOCSINH, *PHOCSINH;
 
typedef struct tagNODE {
    HOCSINH Data;
    tagNODE* Next;
}NODE, *PNODE;
 
typedef struct tagLIST {
    NODE* Dau;
    NODE* Cuoi;
}LISTHS, *PLIST;
NODE* KhoitaoNode()
{
    NODE* x = (NODE*)malloc(sizeof(NODE));
    if(x == NULL)
    {
        printf("\n Bo nho khong du ");
        return 0;
    }
    x->Next = NULL;
    return x;
}
 
void KhoitaoList(LISTHS* x)
{
    x->Dau = NULL;
    x->Cuoi=NULL;
}
void Nhap (NODE* x)
{
    char tg[25];
    int a, d, m, y;
    float t, c;
    printf("\nNhap ma Hoc sinh: ");
    scanf("%d", &a);
    x->Data.Mhs = a;
    fflush(stdin);
    printf("Nhap ten Hoc sinh: ");
    gets(tg);
    strcpy(x->Data.Hoten,tg);
    fflush(stdin);
    do
    {
        printf("Nhap Ngay Sinh: ");
        scanf("%d", &d);
        fflush(stdin);
    }while(d > 31 || d < 1);
    x->Data.ngay = d;
    do
    {
        printf("Nhap Thang Sinh: ");
        scanf("%d", &m);
        fflush(stdin);
    }while(m > 12 || m < 1);
    x->Data.thang = m;
    do
    {
        printf("Nhap Nam Sinh: ");
        scanf("%d", &y);
        fflush(stdin);
    }while(y > 9999 || y < 1000);
    x->Data.nam = y;
    fflush(stdin);
    do
    {
        printf("Nhap Diem Toan: ");
        scanf("%f", &c);
    }while(c < 0 || c > 10);
    x->Data.Toan = c;
    fflush(stdin);
    do
    {
        printf("Nhap Diem Van: ");
        scanf("%f", &t);
    }while(c < 0 || c > 10);
    x->Data.Van = t;
    x->Data.TK = (x->Data.Toan + x->Data.Van)/2;
    fflush(stdin);
    x->Next = NULL;
}
void InHS(NODE* p)
{
    printf("\nMa Hoc sinh: %d   ",p->Data.Mhs);
    printf("\tTen Hoc sinh: %s  ",p->Data.Hoten);
    printf("\nNgay/ Thang/ Nam sinh: %5d/%5d/%5d   ", p->Data.ngay, p->Data.thang, p->Data.nam);
    printf("\nDiem Toan: %.2f   ", p->Data.Toan);
    printf("\tDiem Van: %.2f   ", p->Data.Van);
    printf("\tDiem tong ket: %.2f\n\n\n", p->Data.TK);
}
void InDanhSach(LISTHS x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        InHS(p);
        p = p->Next;
    }
}
void ThemCuoi(LISTHS* x, NODE* t)
{
    if(x->Dau == NULL)
    {
        x->Dau = t;
    }
   else
   {
       x->Cuoi->Next = t;
   }
   x->Cuoi = t;
}
int NhapHS(LISTHS* x)
{
    NODE* a = KhoitaoNode();
    Nhap(a);
    ThemCuoi(x,a);
    return 0;
}
void TimKiem(LISTHS x , int n)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.Mhs == n)
        {
            InHS(p);
        }else   printf("\n Khong co hoc sinh dat tieu chuan can tim\n");
        p = p->Next;
    }
}
int XoaHS(LISTHS *x , int n)
{
    NODE *p = x->Dau,*q;
    q=NULL;
    while (p!=NULL)
    {
        if (p->Data.Mhs==n)
            break;
        q=p;
        p=p->Next;
    }
    if (p==NULL)
        return 0; //không  tim thay
    if (q!=NULL)
    {
        x->Cuoi=q;
        q->Next=p->Next;
        delete p;
    }
    else
    {
        x->Dau=p->Next;
        if(x->Dau==NULL)
            x->Cuoi=NULL;
    }
    return 1;
}
void giaiphong(LISTHS *x)
{
    NODE *p = x->Dau;
    NODE *a;
   while( p->Next != NULL)
    {
        a = p;
        p = p->Next;
        free(a);
    }
}
void inHSGioi(LISTHS x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.TK >= 8)
        {
            InHS(p);
        } else printf("\n Khong co hoc sinh dat tieu chuan can tim\n");
        p = p->Next;
    }
}
void inHSKha(LISTHS x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.TK < 8 && p->Data.TK >= 7)
        {
            InHS(p);
        }else printf("\n Khong co hoc sinh dat tieu chuan can tim\n");
        p = p->Next;
    }
}
void inHSThilai(LISTHS x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.Toan < 5 || p->Data.Van < 5)
        {
            InHS(p);
        } else printf("\n Khong co hoc sinh dat tieu chuan can tim\n");
        p = p->Next;
    }
}
void HSHocLai(LISTHS x)
{
    NODE *p;
    int n = 0;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.Toan < 5 && p->Data.Van < 5)
        {
            n++;
        }
        p = p->Next;
    }
    printf("\n So Cac hoc sinh Phai Hoc Lai : %d\n", n);
}
void inHS10(LISTHS x)
{
    NODE *p;
    p = x.Dau;
    while(p != NULL)
    {
        if(p->Data.thang == 10)
        {
            printf("\n Cac hoc sinh sinh vao thang 10 :");
            InHS(p);
        }else printf("\n Khong co hoc sinh dat tieu chuan can tim\n");
        p = p->Next;
    }
}
int Menu()
{
    int a;
    int Ma;
    LISTHS x;
    KhoitaoList(&x);
    do
    {
        printf("\nCHUONG TRINH QUAN LY HOC SINH C/C++");
        printf("\n*************************MENU**************************");
        printf("\n 1 ** Nhap danh sach hoc sinh                        **");
        printf("\n 2 ** Liet ke danh sach hoc sinh                     **");
        printf("\n 3 ** Tim kiem hoc sinh theo ma Hang                 **");
        printf("\n 4 ** Liet ke danh sach hoc sinh dat loai gioi       **");
        printf("\n 5 ** Liet ke danh sach hoc sinh dat loai Kha        **");
        printf("\n 6 ** Liet ke danh sach hoc sinh Phai thi lai        **");
        printf("\n 7 ** Tong So hoc sinh Phai Hoc lai                  **");
        printf("\n 8 ** Liet ke cac hoc sinh sinh vao thang 10:        **");
        printf("\n 9 ** Xoa hoc sinh theo Ma hoc sinh                  **");
        printf("\n 0 ** Thoat                                          **");
        printf("\nnhap tuy chon: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                {
                    int n;
                    printf("\nNhap so luong hoc sinh : ");
                    scanf("%d",&n);
                    for(int i = 1; i <= n ;i++)
                    {
                        printf("\nNhap Don vi hoc sinh thu: %d \n",i);
                        NhapHS(&x);
                    }
                    break;
                }
            case 2:
                {
                    InDanhSach(x);
                    break;
                }
            case 3:
                {
                    fflush(stdin);
                    printf("\nNhap Ma hoc sinh can tim:");
                    scanf("%d",&Ma);
                    TimKiem(x ,Ma);
                    break;
                }  
            case 4:
                {
                    inHSGioi(x);
                    break;
                }
            case 5:
                {
                    inHSKha(x);
                    break;
                }
            case 6:
                {
                    inHSThilai(x);
                    break;
                }
            case 7:
                {
                    HSHocLai(x);
                    break;
                }
            case 8:
                {
                    inHS10(x);
                    break;
                }
            case 9:
                {
                    fflush(stdin);
                    printf("\nNhap Ma hoc sinh Xoa:");
                    scanf("%d",&Ma);
                    fflush(stdin);
                    XoaHS(&x ,Ma);
                    break;
                }
            case 0:
                {
                    break;
                }
            default: printf("\nBan chon sai vui long chon lai!");
        }
    }while(a != 0);
    giaiphong(&x);
    return 1;
}
int main()
{
    Menu();
    return 0;
}

