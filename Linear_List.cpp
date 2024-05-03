#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;

void InitList(SeqList &L){
    L.data=(int *)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize=InitSize;
}

void IncreaseSize(SeqList &L,int len){
    int *p=L.data;
    L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0; i<L.length; i++){
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

bool LisrInsert(SeqList &L, int i, int e){
    if (i<1||i>L.length+1){
        return false;
    }
    if(L.length>=L.MaxSize){
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L,int i,int &e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

void PrintList(SeqList L){
    for(int i=0;i<L.length;i++){
        printf("SeqList[%d]=%d\n",i+1,L.data[i]);
    }
    printf("work");
}

int main(){
    SeqList L;
    InitList(L);
    L.data[0]=1;
    L.data[1]=2;
    L.length=2;
    printf("length is %d\n",L.length);
    //printf("SeqList[%d]=%d\n",1,L.data[0]);
    LisrInsert(L,2,5);
    printf("length is %d\n",L.length);
    //printf("SeqList[%d]=%d\n",1,L.data[0]);
    PrintList(L);
    int e=-1;
    if (ListDelete(L,2,e)){
        printf("已删除第2个元素,删除元素值为=%d\n",e);
    }else{
        printf("位序2不合法,删除失败\n");
    }
    printf("length is %d\n",L.length);
    PrintList(L);
    return 0;
}