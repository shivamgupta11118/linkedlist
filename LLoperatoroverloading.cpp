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


cin>>head;
cout<<head;
return 0;

}
