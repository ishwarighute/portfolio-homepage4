#include <stdio.h>
#include <stdlib.h>

/* Step 5: Allocate memory and properly free it */
void allocate_and_free(size_t count) {
    int *buffer = (int *)malloc(count * sizeof(int));
    if (buffer == NULL) {
        perror("malloc failed");
        return;
    }

    for (size_t i = 0; i < count; i++) {
        buffer[i] = (int)i;
    }

    free(buffer);
    buffer = NULL;
}

int main(void) {
    for (int iteration = 0; iteration < 5; iteration++) {
        allocate_and_free(1024);
    }

    printf("Finished running clean memory demo.\n");
    return 0;
}