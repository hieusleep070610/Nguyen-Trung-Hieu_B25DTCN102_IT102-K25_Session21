#include <stdio.h>
#include <string.h>

struct Thuvien{
	char maSach[20];
	char tenSach[10];
	char tacGia[20];
	float giaTien[40];
	char theLoai[20];
};
int main(){
	int maxSach = 100;
	Thuvien danhSach[100];
	int soLuong = 0 ;
	int choice;
	do{
		printf("================MENU===============\n");
		printf("1.Nhap so luong va thong tin sach \n");
		printf("2.Hien thi thong tin sach\n");
		printf("3.Them sach vao vi tri \n");
		printf("4.Xoa sach theo ma sach\n");
		printf("5.Cap nhat thong tin sach theo ma sach \n");
		printf("6.Sap xep theo gia(tang/giam) \n");
		printf("7.Tim kiem sach theo ten sach \n");
		printf("8.Thoat \n");
		printf("lua chon cua ban :");
		scanf("%d",choice);
		getchar();
		switch(choice){
			case 1:{
				int n;
				printf("Nhap so luong sach :");
				scanf("%d", &n);
				getchar();
				for(int i = 0; i < n && soLuong < maxSach;i++){
					printf("Sach %d:\n", soLuong +1 );
					printf("Ma sach :");gets(danhSach[soLuong].maSach);
					printf("Ten sach :"); gets(danhSach[soLuong].tenSach);
					printf("Tac gia :");gets(danhSach[soLuong].tacGia);
					printf("Gia tien: "); scanf("%f", &danhSach[soLuong].giaTien); getchar();
					printf("The loai:");gets(danhSach[soLuong].theLoai);
					soLuong++;
				}
				break;
			}
			case 2:{
				 for (int i = 0; i < soLuong; i++) {
                    printf("%d. %s | %s | %s | %.2f | %s\n", i + 1,
                           danhSach[i].maSach, danhSach[i].tenSach,
                           danhSach[i].tacGia, danhSach[i].giaTien,
                           danhSach[i].theLoai);
            }
				break;
			}
			case 3:{
				int pos;
                printf("Nhap vi tri can chen (0-%d): ", soLuong);
                scanf("%d", &pos); getchar();
                if (pos < 0 || pos > soLuong || soLuong >= maxSach) {
                    printf("Vi tri khong hop le hoac danh sach day!\n");
                } else {
                    for (int i = soLuong; i > pos; i--) {
                        danhSach[i] = danhSach[i - 1];
                    }
                    printf("Nhap thong tin sach moi:\n");
                    printf("Ma sach: "); gets(danhSach[pos].maSach);
                    printf("Ten sach: "); gets(danhSach[pos].tenSach);
                    printf("Tac gia: "); gets(danhSach[pos].tacGia);
                    printf("Gia tien: "); scanf("%f", &danhSach[pos].giaTien); getchar();
                    printf("The loai: "); gets(danhSach[pos].theLoai);
                    soLuong++;
                }
				
				break;
			}
			case 4:{
				 char ma[20];
                printf("Nhap ma sach can xoa: ");
                gets(ma);
                int found = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maSach, ma) == 0) {
                        for (int j = i; j < soLuong - 1; j++) {
                            danhSach[j] = danhSach[j + 1];
                        }
                        soLuong--;
                        found = 1;
                        printf("Da xoa sach.\n");
                        break;
                }
            }
             if (!found) printf("Khong tim thay sach!\n");
                break;
			}
			case 5:{
				char ma[20];
                printf("Nhap ma sach can cap nhat: ");
                gets(ma);
                int found = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maSach, ma) == 0) {
                        printf("Ten moi: "); gets(danhSach[i].tenSach);
                        printf("Tac gia moi: "); gets(danhSach[i].tacGia);
                        printf("Gia moi: "); scanf("%f", &danhSach[i].giaTien); getchar();
                        printf("The loai moi: "); gets(danhSach[i].theLoai);
                        found = 1;
                        printf("Da cap nhat.\n");
                        break;
                    }
                }
                if (!found) printf("Khong tim thay sach!\n");
				break;
			}
			case 6:{
				 int tang;
                printf("Sap xep theo gia (1: tang, 0: giam): ");
                scanf("%d", &tang); getchar();
                for (int i = 0; i < soLuong - 1; i++) {
                    for (int j = i + 1; j < soLuong; j++) {
                        if ((tang && danhSach[i].giaTien > danhSach[j].giaTien) ||
                            (!tang && danhSach[i].giaTien < danhSach[j].giaTien)) {
                            Thuvien temp = danhSach[i];
                            danhSach[i] = danhSach[j];
                            danhSach[j] = temp;
                        }
                    }
                }
                printf("Da sap xep.\n");
				break;
			}
			case 7:{
				 char ten[100];
                printf("Nhap ten sach can tim: ");
                gets(ten);
                int found = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strstr(danhSach[i].tenSach, ten)) {
                        printf("%d. %s | %s | %s | %.2f | %s\n", i + 1,
                               danhSach[i].maSach, danhSach[i].tenSach,
                               danhSach[i].tacGia, danhSach[i].giaTien,
                               danhSach[i].theLoai);
                        found = 1;
                    }
                }
                if (!found) printf("Khong tim thay sach!\n");
				break;
			}
			case 8:{
				 printf("Tam biet!\n");
				 
				break;
				default:
                printf("Lua chon khong hop le!\n");
			}
		}
	}while(choice !=0);
	
	return 0;
}
