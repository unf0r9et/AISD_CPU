#include <stdio.h>

#define lastIndex 9
#define lastElement 4


typedef struct {
    int array[10];
    int index;
    _Bool isUsed;
    int input;
} User;

void CPU();

void TactFunction(int tact, int input, User *operation, int *downtime, int *tactCounter);

int PriorityDetermination(User array[]);

void ArrayTraversal(int tact, User array[]);

int main(void) {
    CPU(2, 2);
    return 0;
}


/*
 *---------------------------------FUNCTION-----------------------------------|
 */


void CPU(const int tact, const int input) {
    int downtime = 0;
    int tactCounter = 0;
    User operationArray[] = {
        {{3, 2, 3, 4, 5, 6, 9, 3, 2, 0}, 0, 0, 0},
        {{1, 2, 1, 8, 1, 6, 1, 4, 2, 3}, 0, 0, 0},
        {{3, 1, 6, 8, 7, 5, 9, 4, 2, 1}, 0, 0, 0},
        {{3, 2, 6, 3, 8, 9, 4, 7, 8, 9}, 0, 0, 0},
        {{9, 2, 1, 2, 3, 3, 1, 1, 2, 4}, 0, 0, 0}
    };


    while (operationArray[lastElement].array[lastIndex] != 0) {
        const int indexOperation = PriorityDetermination(operationArray);
        if (indexOperation == -1) break;
        ArrayTraversal(tact, operationArray);
        TactFunction(tact, input, &operationArray[indexOperation], &downtime, &tactCounter);
    }
}

void TactFunction(const int tact, const int input, User *operation, int *downtime, int *tactCounter) {
    for (int i = 1; i <= tact; i++) {
        operation->array[operation->index] -= 1;
        if (operation->array[operation->index] == 0) {
            operation->index += 1;
            operation->input = input;
            if (i < tact) {
                *downtime += tact - i;
                operation->input -= tact - i;
            }
            break;
        }
    }
    ++*tactCounter;
    operation->isUsed = 1;
}

int PriorityDetermination(User array[]) {
    for (int i = 0; i <= lastElement; i++) {
        if (!array[i].isUsed) {
            return i;
        }
    }
    return -1;
}

void ArrayTraversal(const int tact, User array[]) {
    for (int i = 0; i <= lastElement; i++) {
        array[i].input -= tact;
        array[i].isUsed = 0;
        if (array[i].input < 0) array[i].input = 0;
    }
}

void CPUOOO() {}

