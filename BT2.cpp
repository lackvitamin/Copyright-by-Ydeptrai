#include <stdio.h>
#include <stdlib.h>
struct Node
{
float Elements;
Node *Next;
};
typedef struct Node* N;
void MakeNull(N *L){
(*L) = (Node*)malloc(sizeof(Node));
(*L)->Next=NULL;
}
void Chen_Cuoi(N P, float X){
N T;
T = (Node*)malloc(sizeof(Node));
T->Elements=X;
for(;P->Next!=NULL;P=P->Next);
T->Next=P->Next;
P->Next=T;
}
void Tao_List (N L){
int i,n;
float X;
printf("Nhap vao so luong: ");
scanf("%d",&n);
for(i=1;i<=n;i++){
printf("Nhap phan tu %d: ",i);
scanf("%f",&X);
Chen_Cuoi(L,X);
}
}
void Xuat_List(N L){
int i;
while (L->Next!=NULL){
printf(" %f",L->Next->Elements);
L=L->Next;
}}
void TrungBinh(N L)
{
int i=0;
float A=0;
while (L->Next!=NULL){
A += L->Next->Elements;
L = L->Next;
i++;
}A=A/i;
printf("Gia tri trung binh cua list: %.2f\n",A);
}
int Chen_For(float X, Node *L){
for(;L->Next!=NULL;L=L->Next) if(L->Next->Elements==X){
printf("So da ton tai!\n");
return 0;
}
return 1;
}
void Chen(N L){
N T;
int i=0;
T = (Node*)malloc(sizeof(Node));
float X;
do{
printf("Nhap phan tu moi: ");
scanf("%f",&X);
i = Chen_For(X,L);
}while(i!=1);
T->Elements=X;
T->Next=L->Next;
L->Next=T;
printf("Da them!\n");
}
void Xoa_List(N L){
int P,i;
N T;
printf("Nhap vi tri can xoa: ");
scanf("%d", &P);
for(i=1;i<P;i++){
if(L->Next->Next!=NULL) L=L->Next;
}
T=L->Next;
L->Next=T->Next;
free(T);
}
int main(){
    N L;
    MakeNull(&L);
    Tao_List (L);
    Xuat_List(L);
    TrungBinh(L);
    Xoa_List(L);
    Xuat_List(L);
    Chen(L);
    Xuat_List(L);
}