#include <stdio.h>

void tangerines(const float price, float kg, float* cost);
void peaches(const float price, float kg, float* cost);
void grapes(const float price, float kg, float* cost);
void bag(float kg_t, float kg_p, float kg_g);
float summary(float cost_t, float cost_p, float cost_g, float kg_t, float kg_p, float kg_g, float sum_p);
void info();

int main() {
    float kg_t = 0, kg_p = 0, kg_g = 0, sum_p = 0;
    const float TANG_PRICE = 1.14, PEACHES_PRICE = 1.0, GRAPES_PRICE = 1.28;
    float cost_t = 0, cost_p = 0, cost_g = 0;

    printf("\nWelcome to the eFruit store!\n\n");
    while (1) {
        int choice;
        printf("\n1. Tangerines\n"
            "2. Peaches\n"
            "3. Grapes\n"
            "4. Basket\n"
            "5. Cost\n"
            "6. Contact Information\n"
            "7. Exit\n\n");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the number of kilograms: ");
            scanf_s("%f", &kg_t);
            if (kg_t > 0) {
                tangerines(TANG_PRICE, kg_t, &cost_t);
                break;
            }
            else if (kg_t < 0) {
                printf("\nInvalid input.\n");
                break;
            }
            else {
                printf("\nInvalid input.\n");
                return 0;
            }
        case 2:
            printf("\nEnter the number of kilograms: ");
            scanf_s("%f", &kg_p);
            if (kg_p > 0) {
                peaches(PEACHES_PRICE, kg_p, &cost_p);
                break;
            }
            else if (kg_p < 0) {
                printf("\nInvalid input.\n");
                break;
            }
            else {
                printf("\nInvalid input.\n");
                return 0;
            }
        case 3:
            printf("\nEnter the number of kilograms: ");
            scanf_s("%f", &kg_g);
            if (kg_g > 0) {
                grapes(GRAPES_PRICE, kg_g, &cost_g);
                break;
            }
            else if (kg_g < 0) {
                printf("\nInvalid input.\n");
                break;
            }
            else {
                printf("\nInvalid input.\n");
                return 0;
            }
        case 4:
            bag(kg_t, kg_p, kg_g);
            break;
        case 5:
            summary(cost_t, cost_p, cost_g, kg_t, kg_p, kg_g, sum_p);
            break;
        case 6:
            info();
            break;
        case 7:
            return 0;
        default:
            printf("\n\nInvalid input. Try again.\n\n");
        }
    }
}

void tangerines(const float price, float kg, float* cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void peaches(const float price, float kg, float* cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void grapes(const float price, float kg, float* cost) {
    if (kg < 0) *cost = 0;
    *cost = price * kg;
}
void bag(float kg_t, float kg_p, float kg_g) {
    if (kg_t < 0) kg_t = 0;
    if (kg_p < 0) kg_p = 0;
    if (kg_g < 0) kg_g = 0;

    printf("Tangerines: %0.01fkg\n", kg_t);
    printf("Peaches: %0.01fkg\n", kg_p);
    printf("Grapes: %0.01fkg\n\n", kg_g);
}
float summary(float cost_t, float cost_p, float cost_g, float kg_t, float kg_p, float kg_g, float sum_p) {
    sum_p = cost_t + cost_p + cost_g;
    printf("Order cost: %0.01f$\n", sum_p);

    if (sum_p == 0) {
        return 0;
    }
    if (sum_p >= 100) {
        sum_p *= 0.9;
        printf("\nOrder value over $ 100, you get a discount  10%!\nNow the cost of your order - %0.01"
            "f$!\n", sum_p);
    }

    float sum_kg = kg_t + kg_p + kg_g;
    if (sum_kg < 5) {
        sum_p += 1.0;
        printf("Product weight less than 5kg.\nCost of delivery - 1$.\n");
    }
    else if (sum_kg >= 5 && sum_kg < 20) {
        sum_p += 3.0;
        printf("Product weight more than 5kg .\nCost of delivery  - 3$\n");
    }
    else if (sum_kg >= 20) {
        sum_p += 10.0;
        printf("Product weight exceeds 20kg.\nCost of delivery  - 10$. And $ 2 for each kilogram.\n");
        while (sum_kg > 20) {
            sum_p += 2.0;
            --sum_kg;
        }
    }
    printf("\nThe cost of the order together with delivery - %0.01f$\n\n", sum_p);
}
void info() {
    printf("\nContact Information:\n Store - eFruit\n Phone number - +375(29)7684978\n");
}