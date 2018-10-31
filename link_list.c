#include <stdio.h>
#include <string.h>
#include "link_list.h"

#define	NR_STDS	5	

struct student {
	char				name[16];
	int					id;
	struct list_head	list;
};

typedef enum _Boolean { FALSE = 0, TRUE = 1 } LHBOOL; // list head boolean



struct list_head * find_node_by_id(struct list_head *next, struct list_head *std_head, int id)
{
	struct student *studentP; 

	list_for_each(next, std_head) 
	{
		studentP = (struct student *) list_entry(next, struct student, list);

		if (id == studentP->id)
		{
			return &studentP->list;
		}
	}
}

int del_node_by_id(struct list_head *next, struct list_head *std_head, int id)
{
	struct student *studentP; 

	list_for_each(next, std_head) 
	{
		studentP = (struct student *) list_entry(next, struct student, list);

		if (id == studentP->id)
		{
			printf("del addr[%04X]\r\n", &studentP->list);
			list_del(&studentP->list);
			return 0;
		}
	}

	return 1;
}

void dumplist(struct list_head *next, struct list_head *std_head)
{
	printf("======dump all elements of the list by invoking " "'list_for_each'=========\n");
	struct student		*studentP; 	// student pointer
	/* Traverse all elements of the list */
	list_for_each(next, std_head) 
	{
		studentP = (struct student *) list_entry(next, struct student, list);
		printf("[Adrian] name: %s, id: %d\n",
				studentP->name, studentP->id);
	}
}




int main()
{
	struct list_head	std_head, *next;
	struct student		sl[NR_STDS]; 		// student list
	struct student		*studentP; 	// student pointer
	int					idx;

	/* init std_head */
	INIT_LIST_HEAD(&std_head);

	/* Check whether the std_head is empty */
	if(list_empty(&std_head) == TRUE) {
		printf("\r\n\r\n[Adrian] std_head is NULL\n");
	}

	/* Add each element to student head (std_head) */
	for(idx=0;idx<sizeof(sl)/sizeof(struct student);idx++) 
	{
		sprintf(sl[idx].name, "Adrian Huang");
		sl[idx].id = idx + 1;
		list_add(&sl[idx].list, &std_head);
	}	

	dumplist(next, &std_head);


	struct list_head *node = find_node_by_id(next, &std_head, 3);
	printf("addr[%04X]\r\n", node);

	del_node_by_id(next, &std_head, 3);
	del_node_by_id(next, &std_head, 2);
	del_node_by_id(next, &std_head, 1);

	struct student	entry6, entry7; 		
	entry6.id = 6;
	entry7.id = 7;
	sprintf(entry6.name, "%s", "Nick_Huang 6");
	sprintf(entry7.name, "%s", "Nick_Huang 7");

	list_add(&entry6.list, &std_head);
	list_add_tail(&entry7.list, &std_head);

	dumplist(next, &std_head);

	return 0;
}
