#include <stdio.h>

void nhap (float a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Phan tu %d: ",i+1);
        scanf("%f",&a[i]);
    }
}

void xuat (float a[], int n)
{
    printf("Day so:");
    for (int i = 0; i < n; i++) printf(" %.2f",a[i]);
    printf("\n");
    getchar();
}

void swap (float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (float a[], int n)
{
    int i,j;
    for (i=0; i<n-1; i++)
        for (j=n-1; j>i; j--)
            if (a[j]<a[j-1])
                swap(&a[j],&a[j-1]);
}

int main(){
    float a[10];
    int n;
    printf("Nhap vao so luong: ");
    scanf("%d",&n);
    nhap(a,n);
    xuat(a,n);
    bubbleSort(a,n);
    printf("Sau khi sap xep\n");
    xuat(a,n);
}