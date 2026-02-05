#include <stdio.h>
#include <pthread.h>

// Thread function to print first 10 prime numbers
void* print_primes(void* arg) {
    int count = 0, num = 2, i, flag;

    printf("First 10 Prime Numbers:\n");
    while (count < 10) {
        flag = 1;
        for (i = 2; i <= num/2; i++) {
            if (num % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    pthread_exit(NULL);
}

// Thread function to print first 10 Fibonacci numbers
void* print_fibonacci(void* arg) {
    int a = 0, b = 1, c, i;

    printf("First 10 Fibonacci Numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, print_primes, NULL);
    pthread_create(&t2, NULL, print_fibonacci, NULL);

    // Main thread waits for worker threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Main thread message
    printf("I am the main thread\n");

    return 0;
}