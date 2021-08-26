#include<bits/stdc++.h>
using namespace std;


struct node
{
  int roll;
	node *next;
};
node *root=NULL;

void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
	}
	else
	{
		node *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		node *newnode = new node(); //create a new node
		newnode->roll=roll;
		newnode->next=NULL;
		current_node->next=newnode; //link the last node with new node
	}
}

void append_after(int roll1,int roll2)
{
	node *current_node=root;
	while(current_node->roll!=roll1) //Searching node
	{
		current_node=current_node->next;
	}
	if(current_node->next==NULL)
    {
        node *newnode = new node(); //create a new node
		newnode->roll=roll2;
		newnode->next=NULL;
		current_node->next=newnode;
    }
    else
    {
        node *newnode = new node(); //create a new node
		newnode->roll=roll2;
		newnode->next=current_node->next;
		current_node->next=newnode;
    }
}

void delete_node(int roll)
{
	node *current_node=root;
	node *previous_node=NULL;
	while(current_node->roll!=roll) //Searching node
	{
		previous_node=current_node; //Save the previous node
		current_node=current_node->next;
	}
	if(current_node==root) //Delete root
	{
		node *temp=root; //save root in temporary variable
		root=root->next; //move root forward
		delete(temp); //free memory
	}
	else //delete non-root node
	{
		previous_node->next=current_node->next; //previous node points the current node's next node
		delete(current_node); //free current node
	}
}

void print()
{
    node *current_node=root;
    while(current_node!=NULL) //loop until you reach null
    {
        printf("%d\n",current_node->roll);
        current_node=current_node->next;
    }
}

int main(){

    append(1);
	append(2);
	append(6);
	append_after(2,8);
	print();
    return 0;
}



