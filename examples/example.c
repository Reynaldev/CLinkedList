/*
===================
Example usage of linked_list.h

Another usage: Just copy the header (e.g. linked_list.h) to your own project.
===================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRUE    1
#define FALSE   0

#include "../linked_list.h"

void printHelp()
{
    printf(
        "This is an example of Linked List in C\n\n"
        "Another usage: Just copy the header (e.g. linked_list.h) to your own project.\n"
        "Arguments:\n\t"
        "1\tFirst example\n\t"
        "2\tSecond example\n"
    );
}

void example1()
{
    linked_list *my_list = ll_init();
    ll_addData(my_list, (int*) 5);

    ll_addChild(my_list);

    printf(
        "My list\n"
        "Data: %d\n"
        "Index: %d\n"
        "Has next node? %d\n", 
        ll_getData(my_list),
        ll_getIndex(my_list),
        ll_hasNext(my_list)
    );

    linked_list *my_child = ll_getChild(my_list);
    ll_addData(my_child, (int*) 10);

    // ll_eraseChild(my_list);

    if (ll_hasNext(my_list) == TRUE)
    {
        printf(
            "My child\n"
            "Data: %d\n"
            "Index: %d\n"
            "Has next node? %d\n", 
            ll_getData(my_child),
            ll_getIndex(my_child),
            ll_hasNext(my_child)
        );
    }
    else
        printf("No child exists\n");

    free(my_list);
}

void example2()
{
    linked_list *list = ll_init();
    linked_list *nextList = NULL;

    int isRunning = TRUE;
    while (isRunning == TRUE)
    {
        printf("Linked List example in C\n\n");
        printf(
            "|\tIndex\t|\tData\t|\tHas next?\t|\n"
            "=====================================================\n"
        );

        nextList = list;

        while (nextList != NULL)
        {
            int data = 0;
            if (ll_getData(nextList) != NULL)
                data = *(int *)ll_getData(nextList);

            printf(
                "|\t%d\t|\t%d\t|\t%d\t|\n",
                ll_getIndex(nextList),
                data,
                ll_hasNext(nextList)
            );

            if (ll_hasNext(nextList) == TRUE)
                nextList = ll_getChild(nextList);
            else break;
        }

        int *input = (int *) malloc(sizeof(int));
        printf(
            "Commands:\n"
            "0 - Exit\n"
            "1 - Add data\n"
            "2 - Add child\n"
            "3 - Erase all child\n"
            "4 - Erase last child\n"
            "5 - Find\n"
            "Input: "
        );

        scanf("%d", input);

        switch (*input)
        {
        case 0: isRunning = FALSE; break;
        case 1:
            printf("Input data: ");
            scanf("%d", input);

            ll_addData(nextList, input);
            break;
        case 2:
            ll_addChild(list);
            break;
        case 3:
            ll_eraseChild(list);
            break;
        case 4:
            ll_eraseLastChild(list);
            break;
        case 5:
            printf("Insert index: ");
            scanf("%d", input);

            linked_list *foundList = ll_find(list, *(int *)input);
            if (foundList != NULL)
            {
                int data = 0;

                if (ll_getData(foundList) != NULL)
                    data = *(int *)ll_getData(foundList);

                printf(
                    "\n|\tIndex\t|\tData\t|\tHas next?\t|\n"
                    "=====================================================\n"
                    "|\t%d\t|\t%d\t|\t%d\t|\n",
                    ll_getIndex(foundList),
                    data,
                    ll_hasNext(foundList)
                );

                foundList = NULL;
            }
            else
                printf("List not found.\n");
            
            break;
        }

        input = NULL;
    }

    free(nextList);
    free(list);
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printHelp();
        return 1;   
    }

    char arg = **(argv + 1);

    switch (arg)
    {
    case 49:    // 1
        example1();
        break;
    case 50:    // 2
        example2();
        break;
    }
    
    return 0;
}
