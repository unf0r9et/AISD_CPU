#include <stdio.h>

typedef struct {
    int array[10];
    int index;
    _Bool isUse;
    int input;
} User;

void CPU();

void TactFunction(int tact, int input, User *operation, int *downtime);

int PriorityDetermination(User array[]);

int main(void) {
    CPU(2, 3);
    return 0;
}

void CPU(const int tact, const int input) {
    User operationArray[] = {
        {{3, 2, 3, 4, 5, 6, 9, 3, 2, 0}, 0, 0, 0},
        {{1, 2, 1, 8, 1, 6, 1, 4, 2, 3}, 0, 0, 0},
        {{3, 1, 6, 8, 7, 5, 9, 4, 2, 1}, 0, 0, 0},
        {{3, 2, 6, 3, 8, 9, 4, 7, 8, 9}, 0, 0, 0},
        {{9, 2, 1, 2, 3, 3, 1, 1, 2, 4}, 0, 0, 0}
    };

    int downtime = 0;;
    TactFunction(tact, input, &operationArray[PriorityDetermination(operationArray)], &downtime);

}

void TactFunction(const int tact, const int input, User *operation, int *downtime) {
    for (int i = 1; i <= tact; i++) {
        operation->array[operation->index] -= 1;
        if (operation->array[operation->index] == 0) {
            if (i < tact) {
                *downtime += tact - i;
            }
            operation->index += 1;
            operation->input = input;
            break;
        }
    }
    operation->isUse = 1;
}

int PriorityDetermination(User array[]) {
    return 0;
}
