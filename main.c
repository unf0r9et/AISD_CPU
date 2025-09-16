#include <stdio.h>

struct user {
    int array[10];
    int index;
    _Bool isUse;
    int input;
};

void CPU();

void TactFunction(int tact, int input, struct user *operation, int *downtime);

int PriorityDetermination(struct user array[]);

int main(void) {
    CPU(2, 3);
    return 0;
}


void CPU(const int tact, const int input) {
    struct user userNum1 = {{3, 2, 3, 4, 5, 6, 9, 3, 2}, 0, 0, 0};
    struct user userNum2 = {{1, 2, 1, 8, 1, 6, 1, 4, 2, 3}, 0, 0, 0};
    struct user userNum3 = {{3, 1, 6, 8, 7, 5, 9, 4, 2, 1}, 0, 0, 0};
    struct user userNum4 = {{3, 2, 6, 3, 8, 9, 4, 7, 8, 9}, 0, 0, 0};
    struct user userNum5 = {{9, 2, 1, 2, 3, 3, 1, 1, 2, 4}, 0, 0, 0};
    struct user userArray[] = {userNum1, userNum2, userNum3, userNum4, userNum5};
    int downtime = 0;;

    switch (PriorityDetermination(userArray)) {
        case 1:
            TactFunction(tact, input, &userNum1, &downtime);
            break;
        case 2:
            TactFunction(tact, input, &userNum2, &downtime);
            break;
        case 3:
            TactFunction(tact, input, &userNum3, &downtime);
            break;
        case 4:
            TactFunction(tact, input, &userNum4, &downtime);
            break;
        case 5:
            TactFunction(tact, input, &userNum5, &downtime);
            break;
        default:
            return;
    }
}

void TactFunction(const int tact, const int input, struct user *operation, int *downtime) {
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

int PriorityDetermination(struct user array[]) {
    return 0;
}
