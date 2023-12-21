#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void sigint_handler() {
    printf("\a");
    printf("Прозвучал сигнал SIGINT\n");
    count++;
}

void sigquit_handler() {
    printf("Прозвучал сигнал SIGQUIT %d раз(а)\n", count);
    exit(0);
}

int main() {

    while (1) {
    signal(SIGINT, &sigint_handler);
    signal(SIGQUIT, &sigquit_handler);

    }

    return 0;
}