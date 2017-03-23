#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
	int number;
	Node* next;
};

void sort(Node* head)
{
	Node* temp1 = head;
	while (temp1 != NULL)
	{
		Node* temp2 = temp1;
		while (temp2 != NULL)
		{

			if (temp1->number > temp2->number)
			{
				int price;
				price = temp1->number;
				temp1->number = temp2->number;
				temp2->number = price;
			}

			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void show(Node* head)
{
	if (head == NULL)
	{
		cout << "There are nothing to be displayed yet\n";
	}
	sort(head);
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->number << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void delEl(Node*& head, int value)
{
	if (head == NULL)
	{
		cout << "List is empty\n";
	}
	else
	{

		Node* curr = head;
		Node* temp = NULL;

		while (curr != NULL)
		{
			if (curr->number == value)
			{
				break;
			}
			else
			{
				temp = curr;
				curr = curr->next;
			}
		}

		if (curr == NULL)
		{
			cout << "Number " << value << " is not in the list\n";
		}
		else
		{
			if (curr == head)
			{
				head = head->next;
				delete curr;
			}
			else
			{
				temp->next = curr->next;
				delete curr;
			}
			cout << "Number " << value << " was deleted\n";
			cout << endl;
		}
	}
}

void search(Node* head, int value)
{
	if (head == NULL)
	{
		cout << "There are no items in the list\n";
	}
	else
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->number == value)
			{
				cout << "Number is found: " << value << endl;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		if (temp == NULL) cout << "Number " << value << " is not found in the list\n";
	}
}

void del(Node* head)
{
	while (head != NULL)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	srand(time(NULL));
	Node* head = NULL;

	int choice;
	int number;
	cout << "~~~~~~~~~~~~~ Linked List ~~~~~~~~~~~~~\n\n";
	cout << "1. Generate random numbers\n";
	cout << "2. Show list\n";
	cout << "3. Delete number\n";
	cout << "4. Search number\n";
	cout << "5. Exit\n";
	cout << endl;
	while (true)
	{
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1: 
			cout << "Enter the number: ";
			cin >> number;
			for (int i = 0; i < number; i++)
			{
				Node* bleah = new Node;
				bleah->number = rand();
				bleah->next = NULL;

				if (head == NULL)
				{
					head = bleah;
				}
				else
				{
					Node* temp = head;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = bleah;
				}
			}
			break;
		case 2: show(head);
			break;
		case 3: cout << "Enter number which you want to delete: ";
			cin >> number;
			delEl(head, number);
			break;
		case 4: cout << "Enter searching number: ";
			cin >> number;
			search(head, number);
			break;
		case 5: return 0;
		}
		cout << endl;
		cout << "~~~~~~~~~~~~~ Linked List ~~~~~~~~~~~~~\n\n";
		cout << "1. Generate random numbers\n";
		cout << "2. Show list\n";
		cout << "3. Delete number\n";
		cout << "4. Search number\n";
		cout << "5. Exit\n";
		cout << endl;
	}

	del(head);

	return 0;
}
