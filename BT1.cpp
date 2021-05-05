#include <stdio.h>
#define MaxLength 10
typedef struct{
float Elements[MaxLength];
int Last;
}List;
void Make_Null(List *L){
L->Last = 0;
}
void Insert_List(int P, float X, List *L){
int Q;
for(Q=L->Last;Q>P-1;Q--)
L->Elements[Q]=L->Elements[Q-1];
L->Elements[P-1]=X;
L->Last++;
}
void Nhap_List(List *L)
{
    int i,n;
    char c;
    float X;
    Make_Null(L);
    do{
    printf("Nhap vao so luong phan tu: ");
    scanf("%d",&n);
    }while(n>=MaxLength);
    for(i=1;i<=n;i++)
    {
    printf("Nhap phan tu thu %d: ",i);
    scanf("%f",&X);
    Insert_List (i,X,L);
    }
}
void Xuat_List(List *L)
{
    int i;
    printf("List = [");
    for (i=0;i<L->Last;i++) printf(" %.2f",L->Elements[i]);
    printf(" ]\n");
}
void Average(List *L)
{
    int i;
    float A=0;
    for (i=0;i<L->Last;i++) A=A+L->Elements[i];
    A=A/(L->Last);
    printf("\nGia tri trung binh cua: %.2f\n",A);
}
void Insert(List *L){
    int P,i;
    char c;
    float X;
    do{
    fflush(stdin);
    printf("Nhap phan tu moi vao: ");
    scanf("%f",&X);
    for(i=0;i<=L->Last;i++)
    if(X==L->Elements[i]){
    printf("So da ton tai!\n");
    i=L->Last+1;
    }
    }while(i!=L->Last+1);
    Insert_List(1,X,L);
    printf("Da them!\n");
}
void Delete_Point (List *L)
{
    int Q,P;
    printf("Nhap vi tri can xoa: ");
    scanf("%d",&P);
    for(Q=P-1;Q<L->Last-1;Q++) L->Elements[Q]=L->Elements[Q+1];
    L->Last--;
    printf("Da xoa!\n");
}
int main()
{
    int i;
    List *L, l;
    L = &l;
    Nhap_List(L);
    Xuat_List(L);
    Average(L);
    Delete_Point (L);
    Xuat_List(L);
    Insert(L);
    Xuat_List(L);
}