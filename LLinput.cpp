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
//     insertathead(head,3);
//      insertathead(head,10);
//       insertathead(head,20);
//        insertathead(head,30);
// insertathead(head,4);
// insertathead(head,5);
// print(head);
// print(head);
// insert(head,69,1);
// print(head);
// insertattail(head,89);
buildlist(head);
print(head);

//del(head,3);
//print(head);
return 0;

}
