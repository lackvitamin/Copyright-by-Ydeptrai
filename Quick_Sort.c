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
    getchar();
}
void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int findPivot(float a[], int i, int j)
{
    int k;
    for (k = i+1; (k<=j) && a[k]==a[i]; k++);   // Selects largest pivot in the firsts Elenment
    if (k>j) return -1; // Khong co Pivot
    else if (a[k]>a[i]) return k;
    else return i;
}
int partition(float a[], int i, int j, float pivot)
{
    int l = i;
    int r = j;
    while (l<r)
    {
        while(a[l]<pivot) l++;
        while(a[r]>=pivot) r--;
        if(l<r) swap(&a[l],&a[r]);
    }
    return l;
}
void QuickSort(float a[] ,int i, int j)
{
    int pivot_ind = findPivot(a,i,j);
    if (pivot_ind != -1)
    {
        float pivot = a[pivot_ind];
        int k = partition(a,i,j,pivot);
        QuickSort(a,i,k-1);
        QuickSort(a,k,j);
    }
}
int main(){
    float a[10];
    int n;
    printf("Nhap so luong n: ");
    scanf("%d",&n);
    nhap(a,n);
    xuat(a,n);
    QuickSort(a,0,n-1);
    printf("Sau khi sap xep\n");
    xuat(a,n);
}