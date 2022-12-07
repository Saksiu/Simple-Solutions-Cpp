#include <iostream>

//Written by: Maks Spisjak s25303

template <typename T>	//simple linked list element
struct Node {
    T data;
    Node* next;
};

//function initializing and inserting a new element and the end of the list
template <typename T>
void insert(Node<T>** head,T item){

	Node<T>* newNode=new Node<T>;
	newNode->data=item;
	newNode->next=NULL;
	Node<T>* ptr;
	
	if(*head==NULL)	{*head=newNode;}
	else{
		ptr=*head;
		while(ptr->next!=NULL)	{ptr=ptr->next;}
		ptr->next=newNode;
	}
}

//function creating a linked list from an array of any type, returning its' head
template <typename T>
Node<T>* arrayToList(const T arr[], size_t size){
	Node<T> *head=NULL;
	for(size_t i=0;i<size;i++)	{insert(&head,arr[i]);}
	return head;
}
//simple function to see the state of the list
template <typename T>
void showList(Node<T>* head){
	if(head){
		std::cout<<"\n";
		while(head!=NULL){
			std::cout<<head->data<<" ";
			head=head->next;
		}
		std::cout<<"\n\n";
	}
	else{
		std::cout<<"\nempty list!";
	}
}

//function removing specified elements based on a given boolean lambda function
//and "stiching" back their links
template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p){

	Node<T>*headHolder=head;
	Node<T>*checker;
	Node<T>*prevPtr;
	bool check=false;

	if(p(headHolder->data)){
		std::cout<<"DEL "<<headHolder->data<<"; ";
		check=true;
	}

	while(head->next!=NULL){

		if(p(head->next->data)){

			checker=head;
			while(checker->next!=NULL&&p(checker->next->data)){
				checker=checker->next;
				std::cout<<"DEL "<<checker->data<<"; ";
			}
			head->next=checker->next;
		}
		else{
			head=head->next;
		}
	}
	//reset to actual head and look if first element is also true to the predicate
	if(check)
		head=headHolder->next;
	else
		head=headHolder;
}
//function to delete whole list;
template <typename T>
void deleteList(Node<T>*& head){
	Node<T>* prevPtr;
	while(head){
		prevPtr=head->next;
		std::cout<<"DEL "<<head->data<<"; ";
		free(head);
		head=prevPtr;
	}
}

int main() {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = sizeof(arr) / sizeof(arr[0]);

	Node<int>* head = arrayToList(arr,size);
	showList(head);
	
    removeBad(head, [](int n) {return n%2 != 0;});
    showList(head);

    removeBad(head, [](int n) {return n < 5;});
    showList(head);

    removeBad(head, [](int n) {return n > 9;});
    showList(head);

    deleteList(head);
    showList(head);

	return 0;
}