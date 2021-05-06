#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
char Elements;
Node *Next;
};


typedef Node* Position;
typedef struct{
Position Front, Rear;
}Queue;
typedef Position Stack;


int Empty_Stack(Stack S){
return (S->Next == NULL);
}

void MakeNull_Stack (Stack *S){
(*S)=(Node*)malloc(sizeof(Node));
(*S)->Next= NULL;
}


char Top_Stack(Stack *S){
if (Empty_Stack(*S)) return printf("Loi! Ngan xep rong!");
else return ((*S)->Next->Elements);
}

void EnQueue(char X, Queue *Q){
Q->Rear->Next=(Node*)malloc(sizeof(Node));
Q->Rear=Q->Rear->Next;
Q->Rear->Elements=X;
Q->Rear->Next=NULL;
}

void Pop_Stack(Stack *S){
if (!Empty_Stack(*S)){
Stack T = (*S)->Next;
(*S)->Next = T->Next;
free(T);
}}



void Push_Stack(char X, Stack *S){
Stack T;
T=(Node*)malloc(sizeof(Node));
T->Elements = X;
T->Next = (*S)->Next;
(*S)->Next = T;
}



void MakeNull_Queue(Queue *Q){
Position Header;
Header = (Node*)malloc(sizeof(Node));
Header->Next=NULL;
Q->Front=Header;
Q->Rear=Header;
}


int Empty_Queue(Queue Q){
    return (Q.Front == Q.Rear);}


void DeQueue(Queue *Q){
if (!Empty_Queue(*Q)){
Position T;
T=Q->Front;
Q->Front=Q->Front->Next;
free(T);
}}



void kiem_tra_ngoac(Queue *Q){
int i=0;
while(!Empty_Queue(*Q)){
if(Q->Front->Elements == '(') ++i;
if(Q->Front->Elements == ')'){
if(i==0){ --i;
break;}
else --i;}
DeQueue(Q);}
if(i==0) printf("Dung!\n");
else printf("Sai!\n");}


void nhap(Queue *Q){
int n,i;
char *str;
str = new char[10];
printf("Nhap chuoi dau ngoac tron: ");
scanf("%s",str);
n = strlen(str);
for(i=0;i<=n;i++) EnQueue(*(str+i),Q);
kiem_tra_ngoac(Q);}


void kiem_tra_chuoi(int n, Stack *S, Queue *Q){
int i=0;
if(n%2!=0) DeQueue(Q);
while(!Empty_Stack(*S)||!Empty_Queue(*Q)){
if(((*S)->Next->Elements)!=(Q->Front->Elements)){
i++;
break;}
else{
DeQueue(Q);Pop_Stack(S);}}
if(i==0) printf("Doi xung!\n");
else printf("Khong doi xung!\n");
}


void chuyen(int n, Stack *S, Queue *Q){
int i;
DeQueue(Q);
for (i=0;i<n/2;i++){
Push_Stack(Q->Front->Elements,S);
DeQueue(Q);}
kiem_tra_chuoi(n,S,Q);
}


void nhap2(Stack *S, Queue *Q){
int n,i;
char *str;
str = new char[10];
printf("Nhap chuoi: ");
scanf("%s",str);
n = strlen(str);
for(i=0;i<=n;i++) EnQueue(*(str+i),Q);
chuyen(n,S,Q);
}



int main (){
Queue *Q,q; Q=&q;
Stack *S,s; S=&s;
MakeNull_Stack(S);
MakeNull_Queue(Q);
nhap(Q);
nhap2(S,Q);
}