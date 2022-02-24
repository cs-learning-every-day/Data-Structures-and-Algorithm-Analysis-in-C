#include <stdio.h>
#include "list.h"
#include <assert.h>

void PrintList(List L) {
    Position P = First(L);
    while (P != NULL) {
        printf("%d ", Retrieve(P));
        P = Advance(P);
    }
    printf("\n");
}

// gcc -o test_list test_list.c list.c
int main() {
    List L;
    Position P;

    L = MakeEmpty(NULL);
    P = Header(L);
    assert(IsEmpty(L));

    for (int i = 0; i < 10; i++) {
        Insert(i, L, P);
        P = Advance(P);
    }

    Delete(2, L);
    
    assert(Find(2, L) == NULL);
    assert(Find(9, L) != NULL);

    assert(!IsEmpty(L));

    PrintList(L);
    DeleteList(L);

    return 0;
}