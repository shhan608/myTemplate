//
// Created by shhan on 12/26/16.
//

#include <stdio.h>
#include <malloc.h>

#include "sh_list.h"

#ifdef __linux__

struct mallinfo before, after;

void BeforeTest() {

    before = mallinfo();
    printf("before uordblks = %d\n", before.uordblks);
}

void AfterTest() {

    after = mallinfo();
    printf("after uordblks = %d\n", after.uordblks);
    printf("final = %d\n", after.uordblks - before.uordblks - 1040);
}
#endif

void free_int(void *data) {
	int *p = data;
	free(p);
}

int main() {

    //BeforeTest();

	int i = 1;

	SH_LinkedList *int_list, *head, *temp;
	
	int_list = SH_NewList();
	head = int_list;

	/*if ((int_list = SH_AddList(int_list, &i, sizeof(i))) == NULL) {
		return 0;
	}

	i++;

	if ((int_list = SH_AddList(int_list, &i, sizeof(i))) == NULL) {
		return 0;
	}

	i++;

	if ((int_list = SH_AddList(int_list, &i, sizeof(i))) == NULL) {
		return 0;
	}
	i++;

	if ((int_list = SH_AddList(int_list, &i, sizeof(i))) == NULL) {
		return 0;
	}*/

	temp = head;
	while (temp->data) {
		printf("%d\n", *(int *)temp->data);
		temp = temp->next;
	}
	
	SH_RemoveAllList(head, free_int);

	printf("");

   // AfterTest();

}