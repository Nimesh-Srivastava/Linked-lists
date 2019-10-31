#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<process.h>

using namespace std;

struct node
{
	int info;
	node *next;
}*start, *newptr, *save, *ptr, *rear;

node *create_new_node(int);
void insert_beg(node*);
void display(node*);
void insert_end(node*);
void delnode();

int main()
{
	start = rear = NULL;
	int inf, n;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		cout << "\n\n\tEnter data for the new node : ";
		cin >> inf;
		cout << "\n\n\tCreating new node............\n\n\n\n";
		system("pause");
		newptr = create_new_node(inf);
		if (newptr != NULL)
		{
			system("cls");
			cout << "\n\n\tNew node created successfully..........\n\n\n\n\n";
			system("pause");
		}
		else
		{
			system("cls");
			cout << "\n\n\tCannot create new node. Aborting........\n\n\n\n\n";
			system("pause");
			exit(1);
		}
		system("cls");
		cout << "\n\n\tSelect option :";
		cout << "\n\t1)Insert at beginning\t\t2)Insert at end";
		cout << "\n\n\tNumber : ";
		cin >> n;
		if (n == 1)
		{
			cout << "\n\n\tNow inserting this node in the beginning of the list.......\n\n\n\n\n\n\n";
			system("pause");
			insert_beg(newptr);
		}
		else if (n == 2)
		{
			cout << "\n\n\tNow inserting this node at the end of the list.......\n\n\n\n\n\n\n";
			system("pause");
			insert_end(newptr);
		}
		else
		{
			cout << "\n\n\tAborting..........\n\n\n\n\n\n\n\n\n";
			system("pause");
			exit(1);
		}
		system("cls");
		cout << "\n\n\tNow the list is : \n";
		display(start);
		cout << "\n\n\tPress y to enter new node, n to exit : ";
		cin >> ch;
	}
	cout << "\n\tPress y to delete element : ";
	cin >> ch;
	while(ch=='y'||ch=='Y')
	{
		delnode();
		display(start);
		cout << "\n\n\tWant to delete more(y/n) : ";
		cin >> ch;
	}
	return 0;
}

node*create_new_node(int n)
{
	ptr = new node;
	ptr->info = n;
	ptr->next = NULL;
	return ptr;
}

void insert_beg(node*np)
{
	if (start == NULL)
	{
		start = np;
	}
	else
	{
		save = start;
		start = np;
		np->next = save;
	}
}

void display(node*np)
{
	cout << "\t";
	while (np != NULL)
	{
		cout << np->info << " -> ";
		np = np->next;
	}
	cout << " END\n";
}

void insert_end(node*np)
{
	if (start == NULL)
	{
		start = rear = np;
	}
	else
	{
		rear->next = np;
		rear = np;
	}
}

void delnode()
{
	if (start == NULL)
	{
		cout << "\n\tUnderflow!!!\n";
	}
	else
	{
		ptr = start;
		start = start->next;
		delete ptr;
	}
}