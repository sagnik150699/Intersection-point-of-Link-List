#include<stdio.h>
#include<stdlib.h>
typedef struct DCL{
	int data;
	DCL *next;
}node;

node *start1=NULL;
node *start2=NULL;
int limit=0;
int count1=0;
int count2=0;

node *createnode()
{
	node *n;
	n=(node*)malloc(sizeof(node));
	return n;
}


node* insert(node *h)
{
	if(limit>0)
	{
		printf("\n\t\t 2 lists are already merged.\n");
	}
	node *t=h,*temp;
	temp=createnode();
	printf("\n\t\tEnter the value:- ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(h==NULL)
	{
		h=temp;
		h->next=NULL;
	}
	else{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
	}
	return h;
}

void display(node *h)
{
	node *t=h;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
}


void merge()
{
	node *temp,*t1,*t2;
	t1=start1;
	t2=start2;
	//t2->next->next=t1->next->next->next;
	while(t2->next!=NULL)
	{
		t2=t2->next;
	}
	t2->next=t1->next->next->next;
}

void mergep()
{
	if(limit!=0)
		{	
			int c1=0,c2=0,pos=0,sub,flag=0;
		node *t1=start1;
		node *t2=start2;
		while(t1!=NULL)
		{
			c1++;
			t1=t1->next;
		}
		while(t2!=NULL)
		{
			c2++;
			t2=t2->next;
		}
		if(c1>c2)
		{
			sub=c1-c2;
			flag=1;
		}
		else{
			sub=c2-c1;
			flag=2;
		}
		if(flag==1){
			t1=start1;
			while(pos<sub)
			{
				pos++;
				t1=t1->next;
			}
					t2=start2;
		}
		else if(flag==2){
			t2=start2;
			while(pos<sub)
			{
				pos++;
				t2=t2->next;
			}
			t1=start1;
		}
		while(t1->next!=t2->next)
		{
			t1=t1->next;
			t2=t2->next;
		}
		printf("\n\t\tMerging point is %d for list-1\n",t1->data);
		printf("\n\t\tMerging point is %d for list-2\n",t2->data);
	}
	else
		printf("\n\t\tNo merging point present\n");
	
}

int main()
{
	printf("\n\t|*********************|Find the merging point|*********************|\n\t\t");
	printf("\n1:Insert first in list\n\n2:Insert in Second list\n\n3: Display first list\n\n4: Display first list\n\n5 Merge two linkelist\n\n6:Find merge point");
	while(1){
	int ch;
	printf("\n\n\t\tEnter your choice:- ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			start1=insert(start1);
			count1++;
			break;
		case 2:
			start2=insert(start2);
			count2++;
			break;
		case 3:
			printf("\n\t\tValue in first list\n\t\t");
			display(start1);
			break;
		case 4:
			printf("\n\t\tValue in second list\n\t\t");
			display(start2);
			break;
		case 5:
			if(count1>=4 && count2>=2)
			{
				if(limit==0)
				{
					merge();
					limit++;
					printf("\n\t\t Both lists has been merged sucessfully.\n\t\tNot find the merging point -_+\n");				
				}
				else
					printf("\n\t\t You have already mereged the lists");	
			}
			else
			{
				printf("\n\t\tPlease add atlest 4 nodes in first and 2 nodes in 2nd list");
			}
				
			break;
		case 6:
			mergep();
			printf("\n\n\t\t\t\t---Project by Saptarshi Sabui,Sagnik Bhattacharya, Sandipan Majumder, Debjani Chakraborty");
			return 0;
	}
}
	
}



