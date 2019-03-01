#include <iostream>

struct frac
{
    int nume, denom;
    frac * nex;
};

int main()
{
    int num = 2;
    frac * head = new frac;
    frac * tail = new frac;
    head->nume = 0;head->denom = 1;head->nex = tail;
    tail->nume = 1;tail->denom = 1;tail->nex = head;
    int n;
    scanf("%d", &n);
    int add = 0;
    if (n != 1) add = 1;
    frac * now = head;
    while (add)
    {
        add = 0;
        now = head;
        int numm = num;
        for (int tim = 1;tim < numm;tim++)
        {
            if ((now->denom+(now->nex)->denom)<=n)
                {
                    add = 1;
                    num++;
                    frac* nexx = now->nex;
                    now ->nex = new frac;
                    (now ->nex)->nume = now->nume + nexx ->nume;
                    (now ->nex)->denom = now->denom + nexx ->denom;
                    (now ->nex)->nex = nexx;
                    now = nexx;
                }
            else now = now->nex;
        }
    }


    now = head;
    for (int i = 1;i <= num;i++)
    {
        printf("%d/%d\n", now->nume, now->denom);
        now = now->nex;
    }
    return 0;
}