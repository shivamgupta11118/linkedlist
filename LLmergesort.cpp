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
     //  insertathead(head,data);
     head=new node(data);
     return;
   }

    node* tail=head;
    node* n=new node(data);
    while(tail->Next!=NULL){
      tail=tail->Next;
    }
    tail->Next=n;
}


       
     

  
void buildlist(node*& head){
    int data;
    cin>>data;
    while(data!=-1){
        insertattail(head,data);
        cin>>data;
    }
}
istream& operator>>(istream &is,node* &head){
    buildlist(head);
    return is;
}
ostream& operator<<(ostream &os,node* head){
    print(head);
    return os;
}
node* midpoint(node* head){
    if(head==NULL || head->Next==NULL){
        return head;
    }
    node* slow=head;
    node* fast=head->Next;
    while(fast!=NULL && fast->Next!=NULL){
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    return slow;
}

void print(node*head){
    node*temp=head;
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->Next;
    }
    cout<<endl;
}
node* merge (node* a,node* b){
    node* c;
    if(a==NULL ){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    if(a->data < b->data){
        c=a;
        c->Next=merge(a->Next,b);
    }
    else{
        c=b;
        c->Next=merge(a,b->Next);
    }
    return c;
}
node * mergesort(node * head){
    if(head==NULL || head->Next==NULL){
        return head;
    }
    node* mid=midpoint(head);
    node* a=head;
    node* b=mid->Next;
    mid->Next=NULL;
    a=  mergesort(a);
    b=mergesort(b);
    node* c=merge(a,b);
    return c;
}
int main() {
    node*head=NULL;


cin>>head;
cout<<head;
node *m=midpoint(head);
cout<<m->data<<endl;
node *me=merge(head,head1);
cout<<me;
head=mergesort(head);
cout<<head<<endl;
return 0;

}
