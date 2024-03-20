#include "main.h"
#include "linked_list.h"

int main(int argc, char **argv)
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

    ll_eraseChild(my_list);

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
    
    return 0;
}
