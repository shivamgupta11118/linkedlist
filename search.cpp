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
void search(node* head,int key){
    int flag=0;
    while(head!=NULL){
        if(head->data==key){
            flag=1;
        }
        head=head->Next;
    }
    if(flag==1){
        cout<<"present"<<endl;
    }
    else
    cout<<"not present"<<endl;
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
insertathead(head,4);
insertathead(head,5);
print(head);
print(head);
insert(head,69,1);
print(head);
insertattail(head,89);
print(head);
search(head,4);
search(head,99);
return 0;

}
