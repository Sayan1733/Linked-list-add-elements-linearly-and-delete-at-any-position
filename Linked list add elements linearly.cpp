//Linked list
#include<iostream>
using namespace std;
class node{
	public:
		int data;			//Data Part
		node* next;			//Pointer part
		node(int val){		//inserting value using constructor
			data=val;
			next=NULL;
		}
};

void insertathead(node* &head,int val){
	node* n=new node(val);			//Assigning a memory and value or 
									//Assigning a data field[data->NUll]
	n->next=head;					//shifting head element to next 
	head=n;							//assign new value in head
}

void insertattail(node* &head,int val){
	node* n = new node(val);		//Assigning a data field[data->NUll]
	
	if(head==NULL){					//Checking if head is null or not
		head=n;
		return;
	}
	
	node* temp=head;			//new node name as temp and assign head
	while(temp->next!=NULL){	//iterate till NULL
		temp=temp->next;
	}
	temp->next=n;				//last node assign value
	
}

void display(node* head){
	node* temp=head;			//assign temp to head
	while(temp!=NULL){				//iterate to display data
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

bool search(node* head,int key){
	node* temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
void deletehead(node* &head){
	node* todelete=head;				//Access the data at head
	head=head->next;					//assign next to head
	delete todelete;					//then delete head
}
void deletion(node* &head,int val){
	node* temp=head;					//Assign head
	
	if(head==NULL){						//Checking if linkedlist is empty
		return;
	}
	if(head->next==NULL){				//if one elements in list
		deletehead(head);
		return;
	}
	
	while(temp->next->data!=val){		//iterate till data part of temp->next is not val
		temp=temp->next;
	}
	node* todelete=temp->next;			//store the pos to delete
	temp->next=temp->next->next;		//link the pos to its pos->next pos
	delete todelete;					//then delete the middle link
}
int main(){
	node* head=NULL;
	int n1,n2,i;
	cout<<"Enter 1 to add data in head or 2 to add data in tail"<<endl;
	cin>>i;
	if(i==1){
			do{
			cout<<"Type 0 to terminate the print"<<endl;
			cin>>n1;
			insertathead(head,n1);
		}while(n1!=0);
	}
	else if(i==2){
		do{
			cout<<"Type 0 to terminate the print"<<endl;
			cin>>n2;
			insertattail(head,n2);
		}while(n2!=0);
	}
	else{
		cout<<"You entered wrong choice"<<endl;
	}
	display(head);
	cout<<"\nAfter deletion:"<<endl;
	deletion(head,3);
	display(head);
	cout<<"\nAfter deletion at head:"<<endl;
	deletehead(head);
	display(head);
	int key;					//start of searching
	cout<<"\nEnter the data for searching:";
	cin>>key;
	if(search(head,key)){
		cout<<"\nTRUE"<<endl;
	}
	else{
		cout<<"\nFALSE"<<endl;
	}			
	return 0;
}
