#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 100000

typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;

static int Max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

void ZeroPolynomial(Polynomial Poly)
{
    for (int i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2,
                   Polynomial PolySum)
{
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
    for (int i = PolySum->HighPower; i >= 0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2,
                    Polynomial PolyProd)
{
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    for (int i = 0; i <= Poly1->HighPower; i++)
        for (int j = 0; j <= Poly2->HighPower; j++)
            PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
}

void PrintPoly(const Polynomial Q)
{
    for (int i = Q->HighPower; i > 0; i--)
        printf("%dx^%d + ", Q->CoeffArray[i], i);
    printf("%d\n", Q->CoeffArray[0]);
}

int main()
{
    Polynomial p, q, res;
    p = malloc(sizeof(*p));
    q = malloc(sizeof(*q));
    res = malloc(sizeof(*res));
    
    q->HighPower = p->HighPower = 2;
    q->CoeffArray[2] = p->CoeffArray[1] = 2;
    q->CoeffArray[1] = p->CoeffArray[2] = 3;

    PrintPoly(p);
    PrintPoly(q);

    AddPolynomial(p, q, res);
    PrintPoly(res);

    MultPolynomial(p, q, res);
    PrintPoly(res);

    free(p), free(q);
    return 0;
}