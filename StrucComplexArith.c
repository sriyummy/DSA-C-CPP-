#include <stdio.h>
#include <stdlib.h>

struct Operations
{
    float real;
    float img;
};

void addComplex (struct Operations c1, struct Operations c2, struct Operations *res)
{
    res->real = c1.real + c2.real;
    res->img = c1.img + c2.img;
}

void multiplyComplex (struct Operations *c1, struct Operations *c2, struct Operations *res)
{
    res->real = (c1->real * c2->real) - (c1->img * c2->img);
    res->img = (c1->real * c2->img) + (c1->img * c2->real);
}

int main() {
    struct Operations n1, n2, res;
    int ch;

    printf("Enter complex number 1 (real part followed by imaginary part): ");
    scanf("%f %f", &n1.real, &n1.img);

    printf("Enter complex number 1 (real part followed by imaginary part): ");
    scanf("%f %f", &n2.real, &n2.img);

    printf("MENU:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            addComplex(n1, n2, &res);
            printf("Sum: %.2f + %.2fi\n", res.real, res.img);
            break;
        case 2:
            multiplyComplex(&n1, &n2, &res);
            printf("Product: %.2f + %.2fi\n", res.real, res.img);
            break;
        default:
            printf("Wrong Input\n");
    }

    return 0;
}
