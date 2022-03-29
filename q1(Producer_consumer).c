#include <stdio.h>
#include <stdlib.h>

int lock = 1;

int full = 0;

int empty = 8, y = 0;

void producer()
{
    --lock;

    ++full;

    --empty;

    y++;
    printf("\nProducer produces"
           " item %d",
           y);

    ++lock;
}

void consumer()
{

    --lock;
 

    --full;
 
    ++empty;
    printf("\nConsumer consumes "
           "item %d",
           y);
    y--;
 
    ++lock;
}

int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
 
       #pragma omp critical
 
    for (i = 1; i > 0; i++) {
 
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n) {
        case 1:
            if ((lock == 1)
                && (empty != 0)) {
                producer();
            }

            else {
                printf("Buffer is full!");
            }
            break;
 
        case 2:

            if ((lock == 1)
                && (full != 0)) {
                consumer();
            }

            else {
                printf("Buffer is empty!");
            }
            break;
 
        
        case 3:
            exit(0);
            break;
        }
    }
}
