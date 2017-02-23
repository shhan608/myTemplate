//
// Created by shhan on 12/26/16.
//

#ifndef _SH_LIST_H
#define _SH_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sh_type.h"

typedef struct sh_linked_list {
	void *data;
	struct sh_linked_list *next;
} SH_ListData_t;

typedef struct {
	SH_ListData_t *head;
	SH_ListData_t *cur;
	SH_ListData_t *prev;
} SH_LinkedList_t;

SH_LinkedList_t *SH_LinkedListNew(void);
RETCODE SH_LinkedListAdd(SH_LinkedList_t *list, void *data);
void SH_LinkedListFree(SH_LinkedList_t *list, void(*free_data_callback)(void *));

#endif //_SH_LIST_H
