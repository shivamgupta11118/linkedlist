#include <iostream>
using namespace std;
class node{
public:
int data;
node* Next;
node(int d){
    data=d;
    Next=NULL;
}
};
 void insertathead(node*&head,int data){
node* n=new node(data);
n->Next=head;
head=n;
}
void insertattail(node*&head,int data){
   if(head==NULL){
       insertathead(head,data);
   }

    node* tail=head;
    node* n=new node(data);
    while(tail->Next!=NULL){
      tail=tail->Next;
    }
    tail->Next=n;
}
int lenght(node* head){
    int len=0;
    while(head!=NULL){
        head=head->Next;
        len++;
    }
    return len;
}
void insert(node*&head,int data,int pos){
    if(head==NULL || pos==0){
        insertathead(head,data);
    }
    else if(pos>lenght(head)){
        insertattail(head,data);
    }
    else{
        int jump=0;
        node* temp=head;
        while(jump<=pos-1){
            temp=temp->Next;
            jump++;
        }
        node* n=new node(data);
        n->Next=temp->Next;
        temp->Next=n;
    }
}

void deleteathead(node*&head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    head=head->Next;
    delete temp;
    return;
}
void deleteattail(node*& head){
    node* temp=head;
    node* prev=NULL;
    while(temp->Next!=NULL){
        prev=temp;
        temp=temp->Next;
    }
    delete temp;
    prev->Next=NULL;
    return;
}
void del(node*& head, int pos){
    if(pos==1){
        deleteathead(head);
    }
    else if(head==NULL){
        return;
    }
    else{
        int jump=0;
        node *temp=head;
        node* prev=NULL;
        node* next=NULL;
        while(jump<pos-1){
            prev=temp;
            temp=temp->Next;
            next=temp->Next;
            jump++;
        }
        prev->Next=next;
        delete temp;
        return;
        
    }
}
void print(node*head){
    node*temp=head;
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->Next;
    }
    cout<<endl;
}

int main() {
    node*head=NULL;
    insertathead(head,3);
     insertathead(head,10);
      insertathead(head,20);
       insertathead(head,30);
insertathead(head,4);
insertathead(head,5);

insert(head,69,1);

insertattail(head,89);


deleteathead(head);
print(head);
deleteattail(head);
print(head);
del(head,3);
print(head);
return 0;

}
