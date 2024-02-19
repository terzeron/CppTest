#include <stdio.h>
#include <setjmp.h>

jmp_buf main_routine_buf, coroutine_buf;

void coroutine() {
    printf("Coroutine start\n");
    if (setjmp(coroutine_buf) == 0) {
        longjmp(main_routine_buf, 1);
    }
    printf("Coroutine end\n");
}

int main() {
    printf("Main start\n");
    if (setjmp(main_routine_buf) == 0) {
        coroutine();
    } else {
        printf("Back in main\n");
        longjmp(coroutine_buf, 1);
    }
    printf("Main end\n");
    return 0;
}
