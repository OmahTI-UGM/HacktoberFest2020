#include <iostream>
using namespace std;

struct Node{
	int num;
	struct Node* next;
	struct Node* prev;
};

bool isEmpty(struct Node* head){
	return head == NULL;
}

void insertLast(Node** head, int newNum){
	
	struct Node* newNode = new Node();
	newNode -> num = newNum;
	newNode -> next = NULL;
	
	struct Node* temp = *head;
	
	if(isEmpty(*head)){
		*head = newNode;
		newNode -> prev = NULL;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	} 
	
	temp->next = newNode;
	
	newNode->prev = temp;
}

void insertFirst(struct Node** head, int newNum){
   struct Node* newNode = new Node;
  
   newNode->num = newNum;
   newNode->prev = NULL;
   newNode->next = (*head);
  
   if (!isEmpty(*head)){
   		(*head)->prev = newNode;	
   }

   (*head) = newNode;
}

void showList(struct Node* node){
	if(!isEmpty(node)){
		struct Node* temp = node;
		while(temp->next != NULL){
			cout<<temp->num<<" ";
			temp = temp->next;
		}
		cout<<temp->num<<endl;
	} else {
		cout<<"linked list kosong"<<endl;
	}
}

void deleteLast(struct Node* head){
	struct Node* temp = head;
	
	if(!isEmpty(head)){
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		temp->next = NULL;	
	} else {
		cout<<"linked list kosong"<<endl;
	}
}

int main(){
	struct Node* head = NULL;
	
	insertFirst(&head,20);
	insertLast(&head,30);
	insertFirst(&head,40);
	showList(head);
	deleteLast(head);
	showList(head);
	
return 0;
}


