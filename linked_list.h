/*
===================
Basic linked list using C

Made by ReynDev

Note:
This header file comes with no guarantee.
You may modify, distribute, or share however you like.
===================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRUE    1
#define FALSE   0

/*
The struct to create a linked list. 
You can call ll_init() or allocate it your own using malloc.

Don't forget to set the index to 0 for the first index, if you didn't use ll_init()
*/
typedef struct Linked_List
{
    int index;

    void *data;

    struct Linked_List *next;
} linked_list;

/*
Allocate Linked_List to memory. Also set index to 0.
*/
linked_list * ll_init()
{
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    list->index = 0;
    list->data = NULL;
    list->next = NULL;

    return list;
}

/*
Add data to Linked_List. It can be any data type.

@params
@param linked_list* Current Linked_List to add data to.
@param void*        The data to be inserted into the Linked_List.
*/
void ll_addData(linked_list *list, void *data)
{
    list->data = data;
}

/*
Add a new child to current Linked_List.

@param 
    list*   The Linked_List to add the child to.
*/
void ll_addChild(linked_list *list)
{
    if (list->next == NULL)
    {
        list->next = ll_init();
        list->next->index = list->index + 1;
    }
    else
    {
        linked_list *nextList = list;
        while (nextList->next != NULL)
        {
            nextList = nextList->next;
        }

        nextList->next = ll_init();
        nextList->next->index = nextList->index + 1;
    }
}

/*
Get the next child of the current Linked_List.

@param
    list*   The current linked_list to get the child from.

@return
    The child from the current Linked_List* or NULL. 
*/
linked_list * ll_getChild(linked_list *list)
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
    Any data type or NULL if no data.
*/
void * ll_getData(linked_list *list)
{
    return list->data;
}

/*
Returns the current index of this Linked_List.

@param 
    list*   The current Linked_List to return the index from

@return 
    The index of the current linked_list
*/
int ll_getIndex(linked_list *list)
{
    return list->index;
}

/*
Returns true if the Linked_List has next child.

@param 
    list*   The current Linked_List.

@return
    Boolean indicates whether child exist or not.
*/
int ll_hasNext(linked_list *list)
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
    list*   The current linked_list*

@return
    Boolean indicates whether operations success or not.
*/
int ll_eraseChild(linked_list *list)
{
    free(list->next);
    list->next = NULL;

    if (list->next == NULL)
        return TRUE;
    else 
        return FALSE;
}

/*
This function will traverse all the child until there's no child left,
then dealocate and remove the last child.

@return
    Boolean whether child is successfully deleted or not.
*/
int ll_eraseLastChild(linked_list *list)
{
    linked_list *currList = list;
    linked_list *nextList = list;

    while (nextList->next != NULL)
    {
        currList = nextList;
        nextList = nextList->next;
    }

    free(nextList);
    currList->next = NULL;

    if (nextList == NULL)
        return TRUE;
    else 
        return FALSE;
}

/*
This function will find a linked_list based on the matched index

@params
    @param list*    The starting list to traverse from.
    @param index    The index to find the matching linked_list.

@return
    Returns the matching linked_list or NULL if no matching index is found.
*/
linked_list * ll_find(linked_list *list, int index)
{
    linked_list *currList = list;

    while (currList != NULL)
    {
        if (currList->index == index)
            break;

        if (currList->next != NULL)
            currList = currList->next;
        else 
        {
            currList = NULL;
            break;
        }
    }

    return currList;
}