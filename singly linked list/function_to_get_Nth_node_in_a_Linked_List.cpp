#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
struct node *  returnNodeAtPos(struct node **s,int pos );

int main()
{   struct node * varnode;
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    varnode = returnNodeAtPos(&start,2);
    printf("data in the returned node is %d",varnode->data);
    return 0;
}
void insertStart(struct node ** s,int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = *s;
    *s = p;

}

void display(struct node **s){
    struct node *temp = *s;
    int i = 1;
    while (temp!=NULL){
        printf("Data in %d node is %d \n",i,temp->data);
        i++;
        temp = temp->next;
    }

}

struct node *  returnNodeAtPos(struct node **s,int pos ){
    struct node * temp = *s;
    if(pos == 1){
        return temp;
    }
    else{
        for (int i =1 ;i<pos;i++){
            temp = temp->next;
        }
    }
    return  temp;
}