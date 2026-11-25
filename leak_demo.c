#include <stdio.h>
#include <stdlib.h>

/* Step 1: Function that allocates heap memory without freeing it */
void leak_memory(size_t count) {
    int *buffer = (int *)malloc(count * sizeof(int));
    if (buffer == NULL) {
        perror("malloc failed");
        return;
    }

    for (size_t i = 0; i < count; i++) {
        buffer[i] = (int)i;
    }

    /* Intentionally omitting free(buffer) to cause a memory leak */
}

int main(void) {
    /* Step 2: Call the function repeatedly to create leaks */
    for (int iteration = 0; iteration < 5; iteration++) {
        leak_memory(1024);
    }

    printf("Finished running intentional leak demo.\n");
    return 0;
}