#include<stdio.h>
#include<stdlib.h>

struct node{
	float coef;
	int expo;
	struct node *link;
	};
	
struct node *create(struct node *);
struct node *insert_s(struct node *,float ,int);
struct node *insert(struct node *,float,int);
void display(struct node *);

void poly_add(struct node *,struct node *);
void poly_mul(struct node *,struct node *);

 void main()
{
	 int n,m;
	struct node *start1=NULL,*start2=NULL;
	
	printf("enter the first polynomial list\n");
	
	      start1=create(start1);
	      
	printf("enter the second polynomial list\n");
	
	       start2=create(start2);
	printf("polynomial display\n");
	   printf("first polynomial\n");
	     display(start1);
	     printf("second polynomial\n");
	        display(start2);
	        
	        
   printf("polynomial arithmatic\n");
   printf("\n");
    printf("polynomial addition\n");
       printf("\n");
        poly_add(start1,start2);
    printf("polynomial multiplication\n");
       printf("\n");	
	  poly_mul(start1,start2);
	   
}

   struct node *create(struct node *start)
   {
   	  int k,m,ex;
   	  float co;
   	  printf("how many nodes u want to create\n");
   	  scanf("%d",&k);
   	  
   	    for(m=0;m<k;m++)
   	     {
   	     	printf("enter the %d th coefficient\n",m+1);
   	     	scanf("%f",&co);
   	     	printf("enter the %dth exponent\n",m+1);
   	     	scanf("%d",&ex);
   	     	
   	     	start=insert_s(start,co,ex);
   	     	
   	     }
   	  
   	    return start;
   }
   
   
      struct node *insert_s(struct node *start,float co,int ex)
      {
      	struct node *ptr,*temp;
      	
      	temp=(struct node *)malloc(sizeof(struct node));
      	temp->coef=co;
      	temp->expo=ex;
      	
      	if(start==NULL||ex>start->expo)
      	  {
      	  	temp->link=start;
      	  	start=temp;
      	  }
      	  
      	  else
      	  {
      	  	ptr=start;
      	  	  
      	  	   while(ptr->link!=NULL&&ptr->link->expo>=ex)
      	  	        ptr=ptr->link;
      	  	        
      	  	        temp->link=ptr->link;
      	  	        ptr->link=temp;
      	  	        
      	  }
      	  return start;
      }
      
      
	       
			        
		         

	
  void display(struct node *start)
   {
   	 struct node *p;
   	 if(start==NULL)
   	 {
   	 	printf("the polynomial list is empty\n");
   	 	return;
   	 }
   	 p=start;
   	 while(p!=NULL)
   	 {
   	 	printf("%.1fx^%d",p->coef,p->expo);
   	 	p=p->link;
   	 	
   	 	  if(p!=NULL)
   	 	  printf("+");
   	 	  else
   	 	  printf("\n");
   	 	  
   	 }
   	 
   }
   
   struct node *insert(struct node *start,float co,int ex)
   {
   	
   	struct node *p,*temp;
   	temp=(struct node *)malloc(sizeof(struct node));
   	temp->coef=co;
   	temp->expo=ex;
   	
   	   if(start==NULL)
   	   {
   	   	temp->link=start;
   	   	start=temp;
   	   	
   	   }
   	   else
   	   {
   	   	p=start;
   	   	
   	   	    while(p->link!=NULL)
   	   	    p=p->link;
   	   	    temp->link=p->link;
   	   	    p->link=temp;
   	   }
   	   return start;
   }
   
   void poly_add(struct node *start1,struct node *start2)
   {
   	struct node *start3;
   	start3=NULL;
   	struct node *p1;
   	p1=start1;
   	struct node*p2;
   	p2=start2;
   	
   	while(p1!=NULL && p2!=NULL)
   	{
   	
   	   if(p1->expo>p2->expo)
   	   {
   	   	  start3=insert(start3,p1->coef,p1->expo);
   	   	  p1=p1->link;
   	   }
   	   
   	   if(p1->expo<p2->expo)
   	   {
   	   	start3=insert(start3,p2->coef,p2->expo);
   	   	p2=p2->link;
   	   }
   	   if(p1->expo==p2->expo)
   	   {
   	   	start3=insert(start3,p1->coef+p2->coef,p1->expo);
   	   	p1=p1->link;
   	   	p2=p2->link;
   	   }
   }
   	   while(p1!=NULL)
   	   {
   	   	start3=insert(start3,p1->coef,p1->expo);
   	   	p1=p1->link;
   	   }
   	   
   	   while(p2!=NULL)
   	   {
   	   	start3=insert(start3,p2->coef,p2->expo);
   	   	p2=p2->link;
   	   }
   
   display(start3);	
}

   void poly_mul(struct node *start1,struct node *start2)
   {
   	struct node *p1,*p2,*start3,*p3;
   	p1=start1;
   	p2=start2;
   	start3=NULL;
   	struct node *p_beg=p2;
   	while(p1!=NULL)
   	{
   		p2=p_beg;
   		while(p2!=NULL)
   		{
   			start3=insert(start3,p1->coef*p2->coef,p1->expo+p2->expo);
   			p2=p2->link;
   		}
   		p1=p1->link;
   	}
   	   
   	   display(start3);
   }

