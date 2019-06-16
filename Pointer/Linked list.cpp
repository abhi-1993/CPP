#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
 int data;
 node *next;
};
struct node * head;
void print()
{
 int count = 0;
 node *temp;
 temp = head;
 cout<<"List is :";
 while(temp != NULL)
 {
	cout<<" "<<temp->data;
	temp = temp->next;
	//count++;
	//cout<<count;
 }
 cout<<endl;
}

void insert(int a)
{
 node *temp = new node();
 temp->data = a;
 temp->next = head;
 head = temp;
}

void insertafter(int a)
{
 if(head != NULL)
 {
  node *temp = new node();
  temp->data = a;
  temp->next = head->next;
  head->next = temp;
 }
 else
 {
  insert(a);
 }
}

void insertatpos()
{
 int pos, b, count = 0;
 cout<<"Enter the position where you want to enter the data"<<endl;
 cin>>pos;
 node *s = head;
 while(s != NULL)
 {
 	s = s->next;
 	count++;
 	//cout<<" "<<count;
 }
 if(pos > 0 && pos <= count)
 {
 cout<<"Enter the number";
 cin>>b;
 node *temp = new node();
 temp->data = b;
 temp->next = NULL;
 if(pos == 1)
 	{
 		insert(b);
 	}
 node *temp1 = head;
 
 for(int i = 1; i < pos -1 ; i++ )
 	{
 		temp1 = temp1->next;        //getting address of the position of the node by the previous nodes next pointer.
 	}
 temp->next = temp1->next;         //saving the location of next node in new node's next.
 temp1->next = temp;  			   //pointing to the new node by previous node's next pointer.
}
else
{
 cout<<"Out of bound"<<endl;
}
} 

void insertatend()
{
	int a;
	node* temp = new node;
	cout<<"Enter the number : "<<endl;
	cin>>a;
	temp->data = a;
	temp->next = NULL;
	if(head == NULL)
	{
		temp->next = head;
		head = temp;
	}
	node* s = head;
	while( s -> next != NULL )
	{	
		s = s->next;
		//print();
	}
	//temp->next = s -> next;
	s -> next = temp;
	cout<<"Element inserted at last"<<endl;
	print();
}

void delatend()
{
	int count = 0;
	node* temp = new node;
	temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
		//cout<<"temp->data"<<temp->data<<endl;
		count++;
	}
	delete(temp->next);
	temp->next = NULL;
	
}

void delatpos()
{
	int pos, i, counter = 0;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    node *s, *ptr;
    s = head;
    if (pos == 1)
    {
        head = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        //cout<<counnt
        if (pos > 0 && pos <= counter)
        {
            s = head;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}
int main()
{
 int a,b,c,c/hoice,pos;
 head = NULL;
 char z;
 do
 {
 	cout<<" Menu "<<endl;
 	cout<<"1.Insert at Beginning"<<endl;
 	cout<<"2.Insert after Beginning"<<endl;
 	cout<<"3.Insert at Position"<<endl;
 	cout<<"4.Insert at end"<<endl;
 	cout<<"5.Delete at end"<<endl;
	cout<<"6.Delete at Position"<<endl;
	cout<<"Enter Option"<<endl;
 	cin>>choice;
 	switch(choice)
 	{
	case 1:
 	{
	    cout<<"Enter the number of element to be inserted in the list"<<endl;
 		cin>>a;
 		for(int i = 0;i<a;i++)
 	{
		cout<<"Enter the number"<<endl;
		cin>>b;
		insert(b);
    	print();
 	}
 	}
 	break;
 	case 2:
 	{
 		cout<<"Enter the number to insert : ";
		cin>>c;
		insertafter(c);
		print();	
	}
	break;
	case 3:
	{
		insertatpos();
		print();
	}
	break;
	case 4:
	{
		insertatend();
		print();
	}
	break;
	case 5:
	{
		delatend();
		print();
	}
	break;
	case 6:
	{
		delatpos();
		print();
	}
	break;
	default :
		cout<<"Wrong Choice"<<endl;
	}
	cout<<"Press Y to Continue or anyting to exit";
	cin>>z;
		
 }while(z == 'Y' || z == 'y');
 
 return 0;
}

