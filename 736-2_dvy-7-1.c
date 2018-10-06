#include <stdio.h>
#include <stdlib.h>

int sort(int *mass, int size)
{
        int step = size, i;
        while(step > 1)
        {
            if (step > 1) step =step/ 1.247;
            for (i = 0; i + step < size; ++i)
            { if (mass[i + step] > mass[i])
                {
                    int tmp;
                    tmp = mass[i];
                    mass[i] = mass[i + step];
                    mass[i + step] = tmp;
                };
                   
            };
                   
        }
    return 1;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    int mass [n];
    for (i = 0; i<n; i++) scanf("%d", &mass[i]);
    sort(mass,n);

    for (i = 0; i<n; i++) printf("%d ", mass[i]);
    printf("\n");	
    return 1;
}
