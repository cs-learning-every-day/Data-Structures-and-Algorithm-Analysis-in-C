#include "list.h"
#include "fatal.h"
#include <stdlib.h>

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L) {
    if (L != NULL)
        DeleteList(L);

    L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of memory!");
    L->Next = NULL;
    return L;
}

/**
 *  Return true if L is empty 
 */
int IsEmpty(List L) {
    return L->Next == NULL;
}

/**
 * Return true if P is the last position in list L
 * Parameter L is unused in this implementation
 */
int IsLast(Position P, List L) {
    return P->Next == NULL;
}

/**
 * Return Position of X in L; NULL if not found
 */
Position Find(ElementType X, List L) {
    Position P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/**
 * Delete first occurrence of X from a list
 * Assume use of a header one
 */
void Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/**
 * If X is not found, the Next field of returned Position is NULL
 * Assumes a header
 */
Position FindPrevious(ElementType X, List L) {
    Position P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

/**
 * Insert (after legal position P)
 * Header implementation assumed
 * Parameter L is unused in this implementation
 */
void Insert(ElementType X, List L, Position P) {
    Position TmpCell = (Position) malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!!!");
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;
    
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}