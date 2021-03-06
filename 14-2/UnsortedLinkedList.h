#pragma once

#include "Common.h"
#include "Node.h"

typedef struct _UnsortedLinkedList UnsortedLinkedList;

UnsortedLinkedList *UnsortedLinkedList_new();

void UnsortedLinkedList_delete(UnsortedLinkedList *_this);

Boolean UnsortedLinkedList_isEmpty(UnsortedLinkedList *_this);

Boolean UnsortedLinkedList_isFull(UnsortedLinkedList *_this);

Boolean UnsortedLinkedList_add(UnsortedLinkedList *_this, Element anElement);

Element UnsortedLinkedList_min(UnsortedLinkedList *_this);

Element UnsortedLinkedList_removeMax(UnsortedLinkedList *_this);

Boolean UnsortedLinkedList_search(UnsortedLinkedList* _this, Element anElement);

Element UnsortedLinkedList_remove(UnsortedLinkedList* _this, Element anElement);
