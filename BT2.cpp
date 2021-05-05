#include <stdio.h>
#include <stdlib.h>
struct Node
{
float Elements; //Chứa nội dung phần tử
Node *Next; //con trỏ chỉ đến phần tử kế tiếp cung co cung` kieu Node
};
typedef struct Node* N;
N MakeNull(){
    N H;
    H = (N)malloc(sizeof(Node));
    H->Next=NULL;
    return H;
}
void Insert_Last(N P, float X){
    N T;
    T = (N)malloc(sizeof(Node));
    T->Elements=X;
    for(;P->Next!=NULL;P=P->Next);
    T->Next=P->Next;
    P->Next=T;
}
void Create_List (N L){
    int i,n;
    char c;
    float X;
    do{
    printf("Nhap vao so luong: ");
    scanf("%d",&n);
    }while(n<=0);
    for(i=1;i<=n;i++){
    printf("Nhap phan tu %d: ",i);
    scanf("%f",&X);
    Insert_Last(L,X);
    }
}
void Output_List(N L){
    int i;
    printf("List = [");
    while (L->Next!=NULL){
    printf(" %.2f",L->Next->Elements);  //L->Next->Elements nằm phía sau của L->Elements
    L=L->Next;
    }
    printf(" ]\n");
}
void Average(N L)
{
    int i=0;
    float A=0;
    while (L->Next!=NULL){
    A += L->Next->Elements;
    L = L->Next;
    i++;
    }
    A=A/i;
    printf("Gia tri trung binh cua list: %.2f\n",A);
}
int Insert2(float X, Node *L){
    for(;L->Next!=NULL;L=L->Next) if(L->Next->Elements==X){
    printf("So da ton tai!\n");
    return 0;
    }
    return 1;
}
void Insert(N L){
    N T;
    int i=0;
    char c;
    T = (Node*)malloc(sizeof(Node));
    float X;
    do{
    printf("Nhap phan tu moi: ");
    scanf("%f",&X);
    i = Insert2(X,L);
    }while(i!=1);
    T->Elements=X;
    T->Next=L->Next;
    L->Next=T;
    printf("Da them!\n");
}
void Delete_Point(N L){
    int P,i;
    char c;
    N T;
    fflush(stdin);
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &P);
    for (i=1;i<P;i++){  //Số quá lớn thì xóa vị trí cuối cùng, neu muon nhap sai thi bao loi can them chuong trinh con
    if(L->Next->Next!=NULL) L=L->Next;
    }
    T=L->Next;
    L->Next=T->Next;
    free(T);
}
int main(){
    int i;
    N L = MakeNull();
    Create_List (L);
    Output_List(L);
    Average(L);
    Delete_Point(L);
    Output_List(L);
    Insert(L);
    Output_List(L);
    free(L);
}