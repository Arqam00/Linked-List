#include<iostream>
#include<iomanip>
using namespace std;

// Node structure for a linked list
struct node {
	int data;
	node* link;
};
// Function to insert a node at the beginning of the linked list
void insert_beginning(node*& head, int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->link = head->link;
	head = newNode;
}

// Function to insert a node at a specified position in the linked list
bool insert_at(node* head, int pos) {
	int x;



	if (pos == 1) {
		cout << "\nPlease use \"Update Head option\" for this purpose.\n\n";
		return false;
	}
	cout << "Enter the number: ";
	cin >> x;
	node* temp = head;
	node* newNode = new node;
	newNode->data = x;
	newNode->link = NULL;


	pos--;
	while (pos != 1) {
		temp = temp->link;
		pos--;
	}
	newNode->link = temp->link;
	temp->link = newNode;

	return true;
}

// Function to insert a node at the end of the linked list
void insert_end(node* head, int x) {
	node* newNode = new node;
	newNode->data = x;
	if (head->link == NULL) {
		newNode->link = NULL;
		head->link = newNode;
	}
	else {
		while (head->link != NULL) {
			head = head->link;
		}
		head->link = newNode;
		newNode->link = NULL;
	}
}

// Function to delete the last node in the linked list
void del_end(node*& head) {
	if (head == NULL) {
		return;
	}
	if (head->link == NULL) {
		delete head;
	}
	node* sec_last = head;
	while (sec_last->link->link != NULL) {
		sec_last = sec_last->link;
	}
	delete(sec_last->link);
	sec_last->link = NULL;
}

// Function to delete the first node in the linked list
void del_head(node*& head) { //& is used so that the list itself also changes
	if (head == NULL)
		return;

	head = head->link;
}

// Function to delete a node at a specified position in the linked list
void del_at(node*& head, int pos) {
	node* prev = head;
	node* curr = head;
	if (head == NULL) {
		cout << "List is already empty";
		return;
	}

	if (pos == 1) {
		head = curr->link;
		curr->link = NULL;
		curr = NULL;
	}

	node* temp = head;
	for (int i = 1; i < pos - 1; ++i) {
		if (temp->link != NULL)
			temp = temp->link;
	}
	if (temp->link == NULL) {
		cout << "Invalid position for deletion." << endl;
	}

	node* val = temp->link;
	temp->link = val->link;
	delete (val);
}

// Function to delete a node with a specific data value in the linked list
void del_data(node*& head, int val) {
	if (head == NULL)
		return;
	if (head->data == val) {
		node* temp = head;
		head = head->link;
		delete temp;
		return;
	}
	node* num = head;
	while (num->link != NULL && num->link->data != val) {
		num = num->link;
	}
	if (num->link == NULL) {
		cout << "Value not found in the list." << endl;
		return;
	}
	node* temp = num->link;
	num->link = temp->link;
	delete temp;
}
bool swap(node* head,int pos1, int pos2);
bool update_node(node* head, int num, int pos);
// Function to search for a node with a specific data value in the linked list
node* search(node* head, int find) {
	int count = 1;
	if (head == NULL) {
		return NULL;
	}
	if (head->data == find) {
		cout << "The number " << find << " is found at positon #0" << count << " of the list.\n\n";
		return head;
	}
	if (head->link == NULL && head->data != find) {
		cout << "The number " << find << " is not found in the list.\n\n";
	}
	while (head->data != find && head->link != NULL) {
		count++;
		head = head->link;
	}
	cout << "The number " << find << " is found at positon #0" << count << " of the list.\n\n";
	return head;
}

// Function to sort the linked list in ascending order
void sort(node* head) {
	if (head->link == NULL || head == NULL) {
		return;
	}

	node* nextNode = NULL;
	while (head->link != NULL) {
		nextNode = head->link;
		while (nextNode != NULL) {
			if (head->data > nextNode->data) {
				int temp = head->data;
				head->data = nextNode->data;
				nextNode->data = temp;
			}
			nextNode = nextNode->link;
		}
		head = head->link;
	}
}

// Function to reverse the linked list
void reverse(node*& head) { //& used as calls the list by ref
	node* prev = NULL, * next = NULL;

	while (head != NULL) {
		next = head->link;
		head->link = prev; //changes the direction of pointer/node
		prev = head;
		head = next;
	}
	head = prev; //set the now first value as head
}


// Function to determine the size of the linked list
int size_determine(node* head) {
	int size = 1;
	node* temp = head;
	while (temp->link != NULL) {
		size += 1;
		temp = temp->link;
	}
	return size;
}

// Function to traverse and print the linked list
void traverse(node* head) {
	cout << "\nYour list is:\n\n";
	while (head->link != NULL) {
		cout << "|" << head->data << "|" << "  ";
		head = head->link;
	}
	cout << "|" << head->data << "|" << "  ";
	return;
}

void traverse_temp(node* head) {
	cout << "\n\n";
	while (head->link != NULL) {
		cout << "|" << head->data << "|" << "  ";
		head = head->link;
	}
	cout << "|" << head->data << "|" << "  ";
	return;
}

void update_node(node* head, int num) {

	search(head, num);



}

int main() {

	node* head = new node; /*inintializing node*/
	head->link = NULL;
	bool fin = false;
	int n, e, m, pos,pos1,pos2;
	int press; /*initializing further variables*/
	cout << setw(85) << right << "---------------------------------------------------------\n";
	cout << setw(85) << right << "\"Welcome respected user to the list management system!!!\"\n";
	cout << setw(86) << right << "---------------------------------------------------------\n\n";
	cout << "To proceed further, please tell us how many numbers you would like in your list: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			cout << "enter number #01: ";
			cin >> e;
			insert_beginning(head, e);
		}
		else {
			cout << "enter number #0" << i << ": ";
			cin >> e;
			insert_end(head, e);
		}
	}


	cout << setw(85) << right << "--------------------------------------------------------" << endl;
	cout << setw(79) << right << "|     PRESS ON ANY OF THE BELOW OPTIONS TO PROCEED " << setw(7) << right << "|" << endl;
	cout << setw(86) << right << "|--------------------------------------------------------|" << endl;
	cout << setw(29) << "|" << "1. Print Your List" << setw(39) << right << "|" << endl;
	cout << setw(29) << "|" << "2. Insert A Number in the List" << setw(27) << right << "|" << endl;
	cout << setw(29) << "|" << "3. Update a Node" << setw(41) << right << "|" << endl;
	cout << setw(29) << "|" << "4. Delete the Head Node" << setw(34) << right << "|" << endl;
	cout << setw(29) << "|" << "5. Delete A Particular Node" << setw(30) << right << "|" << endl;
	cout << setw(29) << "|" << "6. Search A Number In The List" << setw(27) << right << "|" << endl;
	cout << setw(29) << "|" << "7. Reverse The List" << setw(38) << right << "|" << endl;
	cout << setw(29) << "|" << "8. Sort The List" << setw(41) << right << "|" << endl;
	cout << setw(29) << "|" << "9. Check The Size Of The List" << setw(28) << right << "|" << endl;
	cout << setw(29) << "|" << "11. Exit The Program" << setw(37) << right << "|" << endl;
	cout << setw(85) << right << "--------------------------------------------------------" << endl;

	cout << "PLease enter your choice here: ";
	cin >> press;

	do {
		switch (press) {

		case 1: {
			traverse(head);

			break;
		}

		case 2: {
			cout << "\n\nPlease tell at which position you want to add your number: ";
			cin >> pos;

			if (pos > n or pos <= 0) {
				cout << "\nThis position doesn't exist in the list.\n\n";
				break;
			}

			if (insert_at(head, pos)) {
				cout << "Your updated list is: ";
				traverse_temp(head);
			}
			break;
		}

		case 3:{
			cout << "\n Position 1 from which you want to swap: ";
			cin	>> pos1;
			cout <<	"\n Position 2 from which you want to swap: ";
			cin >> pos2;
			if (pos > n or pos <= 0) {
				cout << "\nThis position doesn't exist in the list.\n\n";
				break;
			}

			if (swap(head,pos1,pos2)) {
				cout << "Your updated list is: ";
				traverse_temp(head);
			}				
			break;
							
		}
				//		case '4':{
				//			
				//			
				//			break;
				//			
				//		}
				//		case '5':{
				//			
				//			
				//			break;
				//			
				//		}
		case 6: {
			cout << "enter which number to find: ";
			cin >> m;
			search(head, m);

			break;

		}
				//		case '7':{
				//			
				//			
				//			break;
				//			
				//		}
				//		case '8':{
				//			
				//			
				//			break;
				//			
				//		}
				//		case '9':{
				//			
				//			
				//			break;
				//			
				//		}
				//		case '10':{
				//			
				//			
				//			break;
				//			
				//		}	

		default: {

			if (press == 11) {
				cout << "\n\nBye,Have a Good Day!!!\n";
				fin = true;
				break;
			}
//			else if(press>'11' or press<='0'){
//				cout<<"Invalid option\n";
//				break;
//			}
			break;
		}
		}
		cout << "\nPLease enter your choice here: ";
		cin >> press;
	} while (press != 11 && fin != true);




	// Uncomment and test other functions as needed

//	cout<<"PLease enter the location which is to be deleted: ";
//	cin>>m;

	// del_end(head);
//	 del_head(head);
//	 del_at(head, m);
	// del_data(head, m);
	// cout << endl << "The size is: " << size_determine(head);
	// cout << endl << search(head, m);
	// sort(head);
//	reverse(head);
}
//bool swap(node* head,int pos1, int pos2){
//	node* temp1=head;
//	node* temp2=head;
//	if(pos1 == pos2){
//		cout << "\n Both positions can't be the same \n";
//		return false;
//	}
//	if(pos1 == 1){
//		temp1=head;
//	}
//	else{
//		for (int i = 1; i < pos1; ++i) {
//		if (temp1->link != NULL){
//			temp1 = temp1->link;}
//	}
//	}
//	if(pos2 == 1){
//		temp2=head;
//	}
//	else{
//	for (int i = 1; i < pos2; ++i) {
//		if (temp2->link != NULL){
//			temp2 = temp2->link;}
//	}}
//	int temp;
//	temp=temp1->data;
//	temp1->data=temp2->data;
//	temp2->data=temp;
//	return true;
//	
//}
bool swap(node* head, int pos1, int pos2) {
    // Use the search function to find the nodes at the specified positions
    node* node1 = search(head, pos1);
    node* node2 = search(head, pos2);

    // Check if both nodes were found
    if (node1 != NULL && node2 != NULL) {
        // Swap the data of the nodes
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;

        cout << "Nodes swapped successfully at positions #" << pos1 << " and #" << pos2 << ".\n\n";
        return true;
    } else {
        cout << "Unable to swap. One or both positions are invalid.\n\n";
        return false;
    }
}

//bool update_node(node* head, int num, int pos){
//	search(head,num)
//}



//bool insert_at(node* head, int pos) {
//	int x;
//
//
//
//	if (pos == 1) {
//		cout << "\nPlease use \"Update Head option\" for this purpose.\n\n";
//		return false;
//	}
//	cout << "Enter the number: ";
//	cin >> x;
//	node* temp = head;
//	node* newNode = new node;
//	newNode->data = x;
//	newNode->link = NULL;
//
//
//	pos--;
//	while (pos != 1) {
//		temp = temp->link;
//		pos--;
//	}
//	newNode->link = temp->link;
//	temp->link = newNode;
//
//	return true;
//}
