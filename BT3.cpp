#define MaxLength 10
#include <stdio.h>
#include <string.h>
typedef struct{
char Elements[MaxLength];
int Front, Rear;
}Queue;
typedef struct{
char Elements[MaxLength];
int Top_idx;
}Stack;


void MakeNull_Stack(Stack *S){
S->Top_idx=MaxLength;
}


int Empty_Stack(Stack S){
return S.Top_idx==MaxLength;
}



void Pop(Stack *S){
S->Top_idx = S->Top_idx+1;
}


void Push_Stack(char X, Stack *S){
S->Top_idx=S->Top_idx-1;
S->Elements[S->Top_idx]=X;
}


void MakeNull_Queue(Queue *Q){
Q->Front=-1;
Q->Rear=-1;
}


int Empty_Queue(Queue Q){
return Q.Front==-1;
}


void DeQueue(Queue *Q){
if (!Empty_Queue(*Q)){
Q->Front=Q->Front+1;
if (Q->Front>Q->Rear) MakeNull_Queue(Q);
}else printf("Hang rong!");}


void EnQueue(char X, Queue *Q){
if (Empty_Queue(*Q)) Q->Front=0;
Q->Rear = (Q->Rear+1);
Q->Elements[Q->Rear]=X;
}


void kiem_tra_ngoac(Queue *Q){
int i=0;
while((Q->Front)<=(Q->Rear)){
if(Q->Elements[Q->Front] == '(') i++;
if(Q->Elements[Q->Front] == ')')
{
if(i==0){
i--;
break;
}
else i--;
}
Q->Front++;
}
if(i==0) printf("Dung!\n");
else printf("Sai!\n");}
void nhap(Queue *Q){
int n,i=0;
char str[MaxLength];
do{
i = 0;
printf("Nhap chuoi dau ngoac: ");
scanf("%s",str);
n = strlen(str);
}while(i!=0);
for(i=0;i<n;i++) EnQueue(str[i],Q);
kiem_tra_ngoac(Q);
}


void kiem_tra_chuoi(int n, Stack *S, Queue *Q){
int i=0;
if(n%2!=0)
DeQueue(Q);
while(!Empty_Stack(*S)&&!Empty_Queue(*Q)){
if(S->Elements[S->Top_idx]!=Q->Elements[Q->Front]){
i++;
break;
}
else{
DeQueue(Q);
Pop(S);
}}
if(i==0) printf("Doi xung\n");
else printf("Khong doi xung\n");
}


void chuyen(int n, Stack *S, Queue *Q){
int i;
for (i=0;i<n/2;i++){
Push_Stack(Q->Elements[Q->Front],S);
DeQueue(Q);
}
kiem_tra_chuoi(n,S,Q);
}


void nhap2(Stack *S, Queue *Q)
{
int n,i;
char str[MaxLength];
do{
i=0;
printf("Nhap chuoi: ");
scanf("%s",str);
fflush(stdin);
n = strlen(str);
if (n > MaxLength){
i=1;
printf("Chuoi qua dai! Vui long nhap lai..\n\n");}
}while(i!=0);
for(i=0;i<n;i++) EnQueue(str[i],Q);
chuyen(n,S,Q);
}



int main ()
{
int i;
Queue *Q,q;Q=&q;
Stack *S,s;S=&s;
MakeNull_Stack(S);
MakeNull_Queue(Q);
nhap(Q);
nhap2(S,Q);
}