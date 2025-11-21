#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
	int id;
	char name[50];
	float import;
	float selling;
	int stock;
}Product;

void printArray(Product *products, int length){
	int i;
	if(length <= 0){
		printf("Khong co san pham nao\n");
		return;
	}
	printf("-------Danh sach san pham-----------\n");
	for(i = 0 ; i < length ; i++){
		printf("|ID: %d | Ten san pham: %s | Gia nhap: %.2f | Gia ban %.2f | So luong: %d | \n", 
		products[i].id, products[i].name, products[i].import,products[i].selling, products[i].stock);
	}
	
} 

void enterInfor(Product *products, int *length, int *searchId){
	int i, n;
	printf("Moi ban nhap so luong san pham: ");
	scanf("%d", &n);
	getchar();
	for(i = 0 ; i < n ; i++){
		Product product;
		product.id = (*searchId)++;
		
		printf("Id thu: %d\n",i + 1 );
		printf("Ten san pham: ");
		fgets(product.name, sizeof(product.name), stdin);
		product.name[strcspn(product.name,"\n")] = '\0';
		
		printf("Gia nhap: ");
		scanf("%f", &product.import);
		while(getchar() != '\n');
		
		printf("Gia ban: ");
		scanf("%f", &product.selling);
		while(getchar() != '\n');
		
		product.stock = 0;
		
		products[*length+i] = product;
	}
	*length += n;
	printf("Nhap phan tu thanh cong\n");
}

void enterProduct(Product *products, int length, float *revenue){
	int i, id, quantity;
	printf("Nhap vao id ma ban muon nhap hang: ");
	scanf("%d", &id);
	
	for(i = 0 ; i < length ; i++){
		if(products[i].id == id){
			printf("So luong hang ban muon nhap: ");
			scanf("%d", &quantity);
			float totalMoney = products[i].import * quantity;
			if(*revenue - totalMoney < 0){
				printf("Khong du tien!\n");
				return;
			}else{
				products[i].stock += quantity;
				*revenue -= totalMoney;
				printf("Nhap hang thanh cong!\n");
				return;
			}
		}
	}
	printf("Khong tim thay phan tu co id la: %d\n", id);
}

void updateProduct(Product *products, int length){
	
	int i, id;
	printf("Nhap vao id ma ban muon cap nhat: ");
	scanf("%d", &id);
	
		for(i = 0 ; i < length ; i++){
			
			if(products[i].id == id){
			Product product;
			product.id = products[i].id;
		
			printf("Ten san pham cap nhat: ");
			fgets(product.name, sizeof(product.name), stdin);
			product.name[strcspn(product.name,"\n")] = '\0';
		
			printf("Gia nhap cap nhat: ");
			scanf("%f", &product.import);
			while(getchar() != '\n');
		
			printf("Gia ban cap nhat: ");
			scanf("%f", &product.selling);
			while(getchar() != '\n');
		
			product.stock = products[i].stock;
		
			products[i] = product;
			printf("Nhap phan tu moi thanh cong\n");
			return;
		}
	}
	printf("Khong tim thay id %d\n");
}

void sortPrice(Product *products, int length){
	printf("1. Sap xep theo gia tang dan\n");
	printf("2. Sap xep theo gia giam dan\n");
	
	int i, j, choice;
	printf("Lua chon cua ban ? ");
	scanf("%d", &choice);
	
	for (i = 0; i < length - 1; i++) {
	    for (j = 0; j < length - 1 - i; j++) {
	        if ((choice == 1 && products[j].selling > products[j+1].selling) ||
	            (choice == 2 && products[j].selling < products[j+1].selling)) {
	            Product tmp = products[j];
	            products[j] = products[j+1];
	            products[j+1] = tmp;
	        }
	    }
	}
		printf("Sap xep thanh cong\n");
	
}

void searchProduct(Product *products, int length){
	while(getchar() != '\n');
	char name[50];
	int i;
	
	printf("Nhap vao ten san pham ma ban muon tim: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
	
	for(i = 0; i < length ; i++){
		if(strcmp(products[i].name, name) == 0){
			printf("Da tim thay san pham\n");
			printf("|ID: %d | Ten san pham: %s | Gia nhap: %.2f | Gia ban %.2f | So luong: %d | \n", 
			products[i].id, products[i].name, products[i].import,products[i].selling, products[i].stock);
			return;
		}
	}
	printf("Khong tim thay san pham %s\n", name);
}

void sellingProduct(Product *products, int length, float *revenue) {
    int id, i, quantity;
    printf("Nhap id san pham muon ban: ");
    if (scanf("%d", &id) != 1) return;
    while (getchar() != '\n');

    for (i = 0; i < length; i++) {
        if (products[i].id == id) {
            printf("Nhap so luong san pham muon ban: ");
            if (scanf("%d", &quantity) != 1) return;
            while (getchar() != '\n');

            if (quantity <= 0) {
                printf("So luong khong hop le\n");
                return;
            }
            if (products[i].stock < quantity) {
                printf("San pham khong du\n");
                return;
            }
            products[i].stock -= quantity;
            *revenue += products[i].selling * quantity;
            printf("Ban thanh cong\n");
            if (products[i].stock == 0) {
                printf("San pham nay da het hang\n");
            }
            return;
        }
    }
    printf("Khong tim thay san pham nay\n");
}



int main(){
	int searchId = 1, length = 0, choice = 0;
	Product products[100];
	float revenue = 1000000;
	do{
		printf("---------------MENU---------------\n");
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n");
		printf("3. Nhap san pham\n");
		printf("4. Cap nhat thong tin san pham\n");
 		printf("5. Sap xep san pham theo gia (Tang | Giam)\n");
		printf("6. Tim kiem san pham\n");
		printf("7. Ban san pham\n");
		printf("8. Doanh thu hien tai\n");
		printf("9. Thoat\n");
		printf("Moi ban chon cac menu tren tu 1 - 9: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				enterInfor(products, &length, &searchId);
				break;
			case 2:
				printArray(products, length);
				break;
			case 3:
				enterProduct(products, length, &revenue);
				break;
			case 4:
				updateProduct(products, length);
				break;
			case 5:
				sortPrice(products, length);
				break;
			case 6:
				searchProduct(products, length);
				break;
			case 7:
				sellingProduct(products, length, &revenue);
				break;
			case 8:
				printf("Doanh thu hien tai la: %.2f\n", revenue);
				break;
			case 9:
				printf("Cam on ban da sua dung dich vu\n");
				break;
			default:
				printf("Vui long chon cac lua chon tu 1 - 9!!!!");
		}
	}while(choice != 9);
	
	return 0;
}
