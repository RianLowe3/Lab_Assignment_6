#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        return -1; // Base case: element not found
    }

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value) {
        return mid; // Element found at mid index
    } else if (numbers[mid] > value) {
        return search(numbers, low, mid - 1, value); // Search left half
    } else {
        return search(numbers, mid + 1, high, value); // Search right half
    }
}

int main(void) {
    int i, numInputs;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        average = 0;
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        // Print the elements of the array
        printf("Array: ");
        for (i = 0; i < countOfNums; i++) {
            printf("%d ", numArray[i]);
        }
        printf("\n");

        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
