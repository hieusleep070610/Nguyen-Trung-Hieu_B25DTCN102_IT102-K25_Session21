#include <stdio.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {

    struct Car myCar = {"Toyota Camry", 2020, 850000.0};

    printf("Thong tin xe:\n");
    printf("Model: %s\n", myCar.model);
    printf("Nam san xuat: %d\n", myCar.year);
    printf("Gia: %.2f\n", myCar.price);

    return 0;
}

