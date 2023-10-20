#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data; 
	struct Node* next; // Node* boyle yaparak pointer yaptim adreslerin icine girmek icin '->' kullanmam gerekecek 
}node;

void write_linkedlist(node* n){
	node* temp =  n ; // node refer to struct Node unutma ve burada baslangic node onemli oldugu icin burada kopyasini olusturup veriyorum 
	while (temp!=NULL){
		printf("%d\n", temp->data );
		temp=temp->next;
	}
	printf("-----------------------------------------\n");
}

struct Node* create_linkedlist(int data){
	node* n=(node*)malloc(sizeof(node));
	n->data = data; 
	n->next = NULL;
	return n; 
}
 void add_node_end_of_linkedlist(struct Node** linkedlist , int data ){
 	node*temp= *linkedlist;
 	
 	if(*linkedlist==NULL){ // eger benim ilk node'um null ise direk yeni node olustur dedim sona eklemis oluyoruz cunku ilk node null 
 		*linkedlist=create_linkedlist(data);
	}
	else
	{
	 	while(temp->next!=NULL){// eger ilk node null degilse bir sonraki node kontrol et null ise yeni node oluturup birlestir 
	 		temp=temp->next;
		 }
		 temp->next=create_linkedlist(data); 
	}
	  
 }


int main() {
	node* root=create_linkedlist(5);
    add_node_end_of_linkedlist(&root,6);
    write_linkedlist(root);
    
    node* root2=NULL;
    add_node_end_of_linkedlist(&root2,10);
    write_linkedlist(root2);

	
	return 0;
 }
