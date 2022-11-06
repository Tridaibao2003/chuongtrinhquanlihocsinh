

#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
 
struct Hocsinh {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB = 0;
    char hocluc[10] = "-";
};
 
typedef Hocsinh HS;
 
void printLine(int n);
void nhapThongTinHS(HS &hs, int id);
void nhapHS(HS a[], int id, int n);
void capNhatThongTinHS(HS &HS);
void capNhatHS(HS a[], int id, int n);
int xoaTheoID(HS a[], int id, int n);
void timKiemTheoTen(HS a[], char ten[], int n);
void tinhDTB(HS &hs);
void xeploai(HS &hs);
int idLonNhat(HS a[], int n);
void sapxepTheoDTB(HS a[], int n);
void sapXepTheoTen(HS a[], int n);
void showStudent(HS a[], int n);
int docFile(HS a[], char fileName[]);
void ghiFile(HS a[], int n, char fileName[]);
void pressAnyKey();
 
int main() {
    int key;
    char fileName[] = "hocsinh.txt";
    HS arrayHS[MAX];
    int soluongHS = 0;
    int idCount = 0;
     
    // nhap danh sach hoc sinh tu file
    soluongHS = docFile(arrayHS, fileName);
    idCount = idLonNhat (arrayHS, soluongHS);
 
    while(true) {
        cout << "CHUONG TRINH QUAN LY HOC SINH C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them hoc sinh.                               **\n";
        cout << "**  2. Cap nhat thong tin hoc sinh boi ID.          **\n";
        cout << "**  3. Xoa hoc sinh boi ID.                         **\n";
        cout << "**  4. Tim kiem hoc sinh theo ten.                  **\n";
        cout << "**  5. Sap xep hoc sinh theo diem trung binh (GPA). **\n";
        cout << "**  6. Sap xep hoc sinh theo ten.                   **\n";
        cout << "**  7. Hien thi danh sach hoc sinh.                 **\n";
        cout << "**  8. Ghi danh sach hoc sinh vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them hoc sinh.";
                idCount++;
                nhapHS(arrayHS, idCount, soluongHS);
                printf("\nThem hoc sinh thanh cong!");
                soluongHS++;
                pressAnyKey();
                break;
            case 2:
                if(soluongHS > 0) {
                    int id;
                    cout << "\n2. Cap nhat thong tin hoc sinh. ";
                    cout << "\n Nhap ID: "; cin >> id;
                    capNhatHS(arrayHS, id, soluongHS);
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongHS > 0) {
                    int id;
                    cout << "\n3. Xoa hoc sinh.";
                    cout << "\n Nhap ID: "; cin >> id;
                    if (xoaTheoID(arrayHS, id, soluongHS) == 1) {
                        printf("\nhoc sinh co id = %d da bi xoa.", &id);
                        soluongHS--;
                    }
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongHS > 0) {
                    cout << "\n4. Tim kiem hoc sinh theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arrayHS, strTen, soluongHS);
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongHS > 0) {
                    cout << "\n5. Sap xep hoc sinh theo diem trung binh (GPA).";
                    sapxepTheoDTB(arrayHS, soluongHS);
                    showStudent(arrayHS, soluongHS);
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongHS > 0) {
                    cout << "\n6. Sap xep hoc sinh theo ten.";
                    sapXepTheoTen(arrayHS, soluongHS);
                    showStudent(arrayHS, soluongHS);
                } else {
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if(soluongHS > 0){
                    cout << "\n7. Hien thi danh sach hoc sinh.";
                    showStudent(arrayHS, soluongHS);
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                pressAnyKey();
                break;
            case 8:
                if(soluongHS > 0){
                    cout << "\n8. Ghi danh sach hoc sinh vao file.";
                    ghiFile(arrayHS, soluongHS, fileName);
                }else{
                    cout << "\nSanh sach hoc sinh trong!";
                }
                printf("\nGhi danh sach hoc sinh vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
  
void tinhDTB(HS &hs) {
    hs.diemTB = (hs.diemToan + hs.diemLy + hs.diemHoa) / 3;    
}
 
void xeploai(HS &hs) {
    if(hs.diemTB >= 8) strcpy(hs.hocluc, "Gioi");
    else if(hs.diemTB >= 6.5) strcpy(hs.hocluc, "Kha");
    else if(hs.diemTB >= 5) strcpy(hs.hocluc, "Trung binh");
    else strcpy(hs.hocluc, "Yeu");
}
  
void nhapThongTinHS(HS &hs, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(hs.ten);
    cout << " Nhap gioi tinh: "; gets(hs.gioiTinh);
    cout << " Nhap tuoi: "; cin >> hs.tuoi;
    cout << " Nhap diem Toan: "; cin >> hs.diemToan;
    cout << " Nhap diem Ly: "; cin >> hs.diemLy;
    cout << " Nhap diem Hoa: "; cin >> hs.diemHoa;
    hs.id = id;
    tinhDTB(hs);
    xeploai(hs);
}
 
void nhapHS(HS a[], int id, int n) {
    printLine(40);
    printf("\n Nhap hoc sinh thu %d:", n + 1);
    nhapThongTinHS(a[n], id);
    printLine(40);
}
 
void capNhatThongTinHS(HS &hs) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(hs.ten);
    cout << " Nhap gioi tinh: "; gets(hs.gioiTinh);
    cout << " Nhap tuoi: "; cin >> hs.tuoi;
    cout << " Nhap diem Toan: "; cin >> hs.diemToan;
    cout << " Nhap diem Ly: "; cin >> hs.diemLy;
    cout << " Nhap diem Hoa: "; cin >> hs.diemHoa;
    tinhDTB(hs);
    xeploai(hs);
}
 
void capNhatHS(HS a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin hoc sinh co ID = " << id;
            capNhatThongTinHS(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n hoc sinh co ID = %d khong ton tai.", id);
    }
}
 
int xoaTheoID(HS a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa HS co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n hoc sinh co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}
 
void timKiemTheoTen(HS a[], char ten[], int n) {
    HS arrayFound[MAX];
    char tenHS[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenHS, a[i].ten);
        if(strstr(strupr(tenHS), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}
 
void showStudent(HS a[], int n) {
    printLine(100);
    cout <<"\n\STT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        // in hoc sinh thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocluc);
    }
    printLine(100);
}
  
void sapxepTheoDTB(HS a[], int n) {
    //Sap xep theo DTB tang dan
    HS tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
void sapXepTheoTen(HS a[], int n) {
    //Sap xep hoc sinh theo ten theo thu tu tang dan
   HS tmp;
    char tenHS1[30];
    char tenHS2[30];
    for(int i = 0;i < n; i++) {
        strcpy(tenHS1, a[i].ten);
        for(int j = i+1; j < n; j++) {
            strcpy(tenHS2, a[j].ten);
            if(strcmp(strupr(tenHS1), strupr(tenHS2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
int idLonNhat (HS a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
 
int docFile(HS a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin hoc sinh
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].ten, 
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa, 
            &a[i].diemTB, &a[i].hocluc) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong hoc sinh co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong hoc sinh duoc doc tu file
    return i;
}
 
void ghiFile(HS a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].ten,a[i].gioiTinh, 
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocluc);
    }
    fclose (fp);
}
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
