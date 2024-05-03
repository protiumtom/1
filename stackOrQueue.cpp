#define NULL 0
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    char data;
    struct Stack *next;    
} Stack, *Lhead;

bool InitStack(Lhead &S){
    S=(Stack *)malloc(sizeof(Stack));
    if(S==NULL)
        return false;
    S->next = NULL;
    return true;
}

bool StackEmpty(Lhead S){
    if(S->next==NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Push(Lhead &S, char e){
    Stack *p=(Stack *)malloc(sizeof(Stack));
    if(p->next==NULL){
        return false;
    }
    p->next=S;
    p->data=e;
    S=p;
    char tt=S->data;
    return true;
}

bool Pop(Lhead &S, char &e){
    if(StackEmpty(S)){
        return false;
    }
    e=S->data;
    Stack *p=S->next;
    S->data=S->next->data;
    S->next=p->next;
    free(p);
    return true;
}



int main(){
    char ElemPop;
    Lhead S;
    InitStack(S);
    char a_Elem='a';
    char b_Elem='b';
    char c_Elem='c';
    Push(S,a_Elem);
    Pop(S,ElemPop);
    Push(S,b_Elem);
    Push(S,c_Elem);
    Pop(S,ElemPop);
    Pop(S,ElemPop);
    printf("The ElemPop is %c\n",ElemPop);
    return 0;
}