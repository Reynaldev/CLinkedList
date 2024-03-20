/*
===================
Basic linked list using C

Made by ReynDev
===================
*/

#include "main.h"

/*
The struct to create a linked list. 
You can call ll_init() or allocate it your own using malloc.
Don't forget to set the index to 0 for the first index, if you didn't use ll_init()
*/
struct Linked_List
{
    int index;

    void *data;

    struct Linked_List *next;
};

typedef struct Linked_List linked_list;

/*
Allocate Linked_List to memory. Also set index to 0.
*/
static linked_list * ll_init()
{
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    list->index = 0;

    return list;
}

/*
Add data to Linked_List. It can be any data type.

@params
@param linked_list* Current Linked_List to add data to.
@param void*        The data to be inserted into the Linked_List.
*/
static void ll_addData(linked_list *list, void *data)
{
    list->data = data;
}

/*
Add a new child to current Linked_List.

@param 
    linked_list* The Linked_List to add the child to.
*/
static void ll_addChild(linked_list *list)
{
    list->next = (linked_list*) malloc(sizeof(linked_list));
    list->next->index = list->index + 1;
}

/*
Get the next child of the current Linked_List.

@param
    linked_list*    The current linked_list to get the child from.

@return
    The child from the current Linked_List*. 
*/
static linked_list * ll_getChild(linked_list *list)
{
    if (list->next == NULL)
        return NULL;
    else
        return list->next;
}

/*
Get the data of the current Linked_List.
Returns any data type as assigned to the Linked_List.

@return 
    Any data type
*/
static void * ll_getData(linked_list *list)
{
    return list->data;
}

/*
Returns the current index of this Linked_List.

@param 
    linked_list* The current Linked_List to return the index from

@return 
    The index of the current linked_list
*/
static int ll_getIndex(linked_list *list)
{
    return list->index;
}

/*
Returns true if the Linked_List has next child.

@param 
    linked_list* The current Linked_List.

@return
    Boolean indicates whether child exist or not.
*/
static int ll_hasNext(linked_list *list)
{
    if (list->next == NULL)
        return FALSE;
    else
        return TRUE;
}

/*
Deallocate the child of the current Linked_List.
This function also set the child to NULL.

@param 
    linked_list* The current linked_list*

@return
    Boolean indicates whether operations success or not.
*/
static int ll_eraseChild(linked_list *list)
{
    free(list->next);
    list->next = NULL;

    if (list->next == NULL)
        return TRUE;
    else 
        return FALSE;
}