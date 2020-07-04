/*
*作者：fish
*日期：2020年 05月 21日 星期四 20:53:42 CST
*功能：
*附加说明：
*记录  ：
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct node
{
		int number;
		struct node *next;
}
node;

//void deleteNode(struct ListNode* node) {
	    
//}
int main (void)
{
//		int NumsSize = get_int("NumsSize: ");
//		int Nums[NumsSize];
//		for(int i= 0;i<NumsSize;i++)
//		{
//				int a = get_int("Nums: ");
//				Nums[i]=a;
//		}
//		for(int i= 0;i<NumsSize;i++)
//		{
//				printf(" %d ",Nums[i]); 
//		} 
//		printf("\n");

//		struct	node *head, *p1,*p2;
//		int i;
//		head =0;
//		for(i=1;i<=5;i++)
//		{
//				p1 = ( struct node *)malloc(sizeof(struct node));
//				(*p1).data = i;
//		        printf("(*p1).data= %d p1 = %p \n",(*p1).data,p1); 
//		}
//		p2 = ( struct node *)malloc(sizeof(struct node));
//		(*p2).data = 2;
//
//		p1->next = p2;
//		printf("(*p1).data= %d p1 = %p \n",(*p1).data,p1); 
//		p2->next = NULL;
//		head = p1;
//		printf("(*p1).data= %d head = %p \n",(*p1).data,head); 

        // Memory for numbers
		node * numbers =NULL;
		//Prompt for number
        while(true)
		{
		   // Prompt for number
		   int number = get_int("number: ");
		   //check for EOF
           if(number == INT_MAX)
			{
				break;
			}
			//Allocate space for number
			node *n = malloc(sizeof(node));
			if(!n)
			{
				return 1;
			}
			// add number to list
			n->number=number;
			n->next =NULL;
			if(numbers)
			{
				for(node *ptr = numbers; ptr != NULL; ptr = ptr->next)
				{
					if(!ptr->next)
					{
						ptr->next =n;
						break;
					}
				}

			}
			else
			{
                  numbers =n;
			}
		}
		return 0;
}
