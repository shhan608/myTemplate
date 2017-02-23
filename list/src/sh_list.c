//
// Created by shhan on 12/26/16.
//

#include "sh_list.h"

SH_LinkedList_t *SH_LinkedListNew(void) {
	SH_LinkedList_t *l = NULL;

	l = (SH_LinkedList_t *)malloc(sizeof(SH_LinkedList_t));

	if (l) {
		memset(l, 0, sizeof(*l));
	}

	return l;
}

RETCODE SH_LinkedListAdd(SH_LinkedList_t *list, void *data) {
	if (list) {
		if (list->head == NULL) {
			// Head
			list->head = (SH_ListData_t *)malloc(sizeof(SH_ListData_t));
			list->head->next = NULL;

			list->head->data = data;

			list->cur = list->head;
			list->prev = list->head;
		} else {
			SH_ListData_t *p;
			// Tail

			//list->cur = list->head;
			while(list->cur->next) {
				list->cur = list->cur->next;
			}

			p = (SH_ListData_t *)malloc(sizeof(SH_ListData_t));
			p->data = data;
			p->next = NULL;

			list->cur->next = p;
			list->prev = list->cur;
			list->cur = list->cur->next;
		}
		return SH_SUCCESS;
	}
	return SH_FAIL;
}

void SH_LinkedListFree(SH_LinkedList_t *list, void(*free_data_callback)(void *)) {
	SH_ListData_t *temp = NULL;
	SH_ListData_t *head = list->head;

	while(head) {
		if (head->data) {
			free_data_callback(head->data);
			temp = head->next;
			free(head);
			head = temp;
		}
	}

	free(list);
}

/*
SH_LinkedList* SH_NewList() {
	SH_LinkedList *l = (SH_LinkedList *)malloc(sizeof(SH_LinkedList));
	memset(l, 0, sizeof(*l));
	return l;
}

SH_LinkedList* SH_AddList(SH_LinkedList *l, void *data, int len) {
	SH_LinkedList *p = NULL;

	if (data && len > 0) {
		if (l->data) free(l->data);
		
		l->data = malloc(len);
		if (l->data) {
			memcpy(l->data, data, len);

			p = (SH_LinkedList *)malloc(sizeof(SH_LinkedList));
			memset(p, 0, sizeof(SH_LinkedList));

			l->next = p;
			l = l->next;

		}
	}

	return p;
}

void SH_RemoveAllList(SH_LinkedList *head, void (*free_data_callback)(void *)) {
	while (head->data) {
		SH_LinkedList *temp;

		free_data_callback(head->data);

		temp = head->next;
		free(head);
		head = temp;
	}
	if (head) free(head);
}*/
