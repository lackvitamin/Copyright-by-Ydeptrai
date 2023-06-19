#include <stdio.h>

void nhap(float a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Phan tu %d: ",i+1);
        scanf("%f",&a[i]);
    }
}

void xuat(float a[], int n)
{
    printf("Day so:");
    for (int i = 0; i < n; i++) printf(" %.2f",a[i]);
    printf("\n");
}

void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(float a[], int n, int i)
{
    int max = i; // Khoi tao root
    int l = 2*i + 1; // left
    int r = 2*i + 2; // right
    if (l < n && a[l] > a[max])
        max = l;
    if (r < n && a[max] > a[max])
        max = r;
    if (max != i)
    {
        swap(&a[i],&a[max]);
        heapify(a, n, max);
    }
}
void HeapSort(float a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    float a[10];
    int n;
    printf("Nhap so luong n: ");
    scanf("%d",&n);
    nhap(a,n); // Trung so trong day phat sinh loi ??
    xuat(a,n);
    HeapSort(a,n);
    printf("Sau khi sap xep\n");
    xuat(a,n);
}