#include<iostream>
using namespace std;

// Node structure for a linked list
struct node {
	int data;
	node* link;
};
// Function to insert a node at the beginning of the linked list
void insert_beginning(node* &head, int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->link = head->link;
	head = newNode;
}

// Function to insert a node at a specified position in the linked list
void insert_at(node* head, int x, int pos) {
	node* temp = head;
	node* newNode = new node;
	newNode->data = x;
	newNode->link = NULL;
	if(pos == 1){
		newNode->link=head;
		head=newNode;
	}
	pos--;
	while (pos != 1) {
		temp = temp->link;
		pos--;
	}
	newNode->link = temp->link;
	temp->link = newNode;
}

// Function to insert a node at the end of the linked list
void insert_end(node* head, int x) {
	node* newNode = new node;
	newNode->data = x;
	if (head->link == NULL) {
		newNode->link = NULL;
		head->link = newNode;
	} else {
		while (head->link != NULL) {
			head = head->link;
		}
		head->link = newNode;
		newNode->link = NULL;
	}
}

// Function to delete the last node in the linked list
void del_end(node* head) {
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
void del_head(node* &head) { //& is used so that the list itself also changes
	if (head == NULL)
		return;

	node* temp = head;
	head = head->link;
	delete (temp);
}

// Function to delete a node at a specified position in the linked list
void del_at(node*& head, int pos){ 
	if (head == NULL)
		return;

	if (pos == 1 ){
		node* temp = head;
		head = head->link;
		delete temp;
		return;
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

// Function to search for a node with a specific data value in the linked list
node* search(node* head, int find) {
	if (head == NULL) {
		return NULL;
	}
	if (head->data == find) {
		return head;
	}
	while (head->data != find && head != NULL) {
		head = head->link;
	}
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
void reverse(node*&head) { //& used as calls the list by ref
	node *prev = NULL, *next = NULL;

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
	cout << "\n\nThe output is : \n\n";
	while (head->link != NULL) {
		cout << head->data << "  ";
		head = head->link;
	}
	cout << head->data;
}

int main() {
	int n, b, e, m;
	cout << "how many numbers you need to enter: ";
	cin >> n;
	node* head = new node;
	head->link = NULL;
	cout << "enter number #1: ";
	cin >> b;
	insert_beginning(head, b);

	for (int i = 1; i <= n; i++) {
		if (i == 1)
			head->data = b;
		else {
			cout << "enter number #" << i << ": ";
			cin >> e;
			insert_end(head, e);
		}
	}

	traverse(head);
//	cout<<"\nat which position you need to insert a number? : ";
//	int pos;
//	cin>>pos;
	cout<<endl<<"enter the location to delete";
	cin>>m;
	// Uncomment and test other functions as needed
	// insert_at(head, m, pos);
	//del_end(head);
	//del_head(head);
	//del_at(head, m);
	// del_data(head, m);
	// cout << endl << "The size is: " << size_determine(head);
	// cout << endl << search(head, m);
	// sort(head);
	//reverse(head);
	traverse(head);

	return 0;
}

