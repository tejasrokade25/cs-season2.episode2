/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node 
{
	public:
	Node *next;
	Node *prev;
	int data;
	Node()
	{
		next=NULL;
		prev=NULL;
	}
};

class dlinklist
{
	Node *head;
	Node *tail;
	public:
	dlinklist()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int value);
	void insertat(int pos,int value);
	void del();
	void delat(int pos);
	int count();
	void display();
};

void dlinklist::insert(int value)
{
	Node *current=new Node;
	current->data=value;
	if (head==NULL)
	{head=current;}
	else
	{current->prev=tail;
	 tail->next=current;}
	tail=current;
}

void dlinklist::insertat(int pos,int value)
{
	if( pos>this->count() )
	cout<<"Linklist doesnot have this many elements"<<endl;
	else
	{
	Node *temp=new Node;
	temp->data=value;
	if (pos==1)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;
	}
	else
	{	
		int i=1;
		Node *current=head;
		while(i<pos-1)
		{current=current->next;i++;}
		temp->prev=current;
		temp->next=current->next;
		current->next=temp;
		if(temp->next!=NULL)
		temp->next->prev=temp;
	}
	}
}

void dlinklist::del()
{
	Node *current=head;
	while(current->next!=tail)
	{current=current->next;}
	tail=current;
	current=current->next;
	tail->next=NULL;
	current->prev=NULL;
	delete current;
}

void dlinklist::delat(int pos)
{
	if( pos>this->count() )
	cout<<"Linklist Does not have that many elements"<<endl;
	else
	{
		Node *current=head;int i=1;
		while(i<pos)
		{current=current->next;i++;}
		
		if (current!=head)
		{current->prev->next=current->next;}
		
		if (current!=tail)
		{current->next->prev=current->prev;}
		
		current->next=NULL;
		current->prev=NULL;
		delete current;
		
	}
	
	
}

int dlinklist::count()
{
	Node *current=head;int i=0;
	while(current!=NULL)
	{
		i+=1;
		current=current->next;
	}
	return i;
}

void dlinklist::display()
{
	Node *current=head;
	while(current!=NULL)
	{
		cout<<current->data<<"->";
		current=current->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	dlinklist dl;
	dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);
	dl.display();
	dl.insertat(3,7);
	dl.display();
	dl.insertat(9,9);
	dl.del();
	dl.display();
	dl.delat(3);dl.display();	
	return 0;
}

