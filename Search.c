#include <stdio.h>

void nhap(float a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Nhap so thu %d: ",i+1);
		scanf("%f",&a[i]);
	}
}
void xuat(float a[], int n){
    printf("Day so: ");
    for(int i = 0; i < n; i++) printf(" %.2f",a[i]);
    printf("\n");
}
// Linear Search
int LinearSearch(float a[], float x, int n){
    for(int i = 0; i < n; i++) if(a[i] == x) return i+1;
    return -1;
}
// Binary Search
int BinarySearch(float a[], float x, int l, int r){
    int j = 0;
    if(r >= l)
    {
        int mid = l+(r-l)/2; // Chia de tri
        if(a[mid]==x) return mid;
        if(a[mid]>x) return BinarySearch(a,x,l,mid-1);
        return BinarySearch(a,x,mid+1,r);
    }
    return -1;
}
int main()
{   int n, p;
    float a[20], x;
    printf("Nhap so luong: ");
    scanf("%d",&n);
    nhap(a,n);
    xuat(a,n);
    printf("Nhap so can tim: ");
    scanf("%f",&x);
    printf("LINEAR SEARCH\n");
    p = LinearSearch(a, x, n);
    if(p == -1) printf("Khong co so can tim\n");
    else printf("Vi tri %d\n",p);
    printf("BINARY SEARCH\n");
    p = BinarySearch(a, x, 0, n-1);
    if(p == -1) printf("Khong co so can tim\n");
    else printf("Vi tri %d\n",p+1);
}
