// A simple C program to introduce
// a linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void insertLast(struct node **s,int data);
void insertAtPos(struct node **s,int data,int loopVar);
void display(struct node **s);
void deleteanodatpos(struct node **s,int pos );

int main()
{
    insertStart(&start,10);
    insertLast(&start,12);
    insertLast(&start,16);
    insertLast(&start,14);
    insertAtPos(&start,20,2);
    display(&start);
    deleteanodatpos(&start,5);
    printf("%s \n","After Deletion");
    display(&start);
    return 0;
}
void insertStart(struct node ** s,int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = *s;
    *s = p;
}

void insertLast(struct node **s, int data){
    struct node *p,*t;
    p=(struct node *)malloc(sizeof(struct node ));
    p->data = data;
    p->next =  NULL;
    if(*s == NULL){
        *s=p;
    }
    else{
        t=*s;
        while(t->next!=NULL){t=t->next;}
        t->next = p;
    }
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
void insertAtPos(struct node **s,int data,int loopVar){

    struct node *p,* temp;
    p=(struct node *)malloc(sizeof(struct node  ));
    temp = *s;
    p->data = data;
    if(loopVar>1)
    {
        for (int j = 1; j < loopVar-1 ; ++j) {
            temp=temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
    else{
        p->next = *s;
        *s = p;
    }
}
void deleteanodatpos(struct node **s,int pos ){
    struct node * temp1 = *s;
    if (pos ==1){
        temp1 = temp1->next;
        free(*s);
        *s = temp1;
    } else if (pos ==2){
        temp1 = temp1->next;
        (*s)->next =(*s)->next->next;
        free(temp1);
    }
    else if (pos>2){
        while(pos>2){
            temp1 = temp1->next;
            --pos;
        }
        struct node * temp2 = temp1->next;
        temp1->next = temp1->next->next;
        free(temp2);

    }
}