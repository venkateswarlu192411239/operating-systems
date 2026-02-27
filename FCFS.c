#include <stdio.h>

struct process {
    int id, burst;
};

void fcfs(struct process P[], int n) {
    int wait[n], tat[n];
    int total_wait = 0, total_tat = 0;

    wait[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        wait[i] = P[i - 1].burst + wait[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = P[i].burst + wait[i];
        total_wait += wait[i];
        total_tat += tat[i];

        printf("P%d: Wait = %d, Turnaround = %d\n",
               P[i].id, wait[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    struct process P[] = {{1, 5}, {2, 3}, {3, 8}};
    int n = 3;

    fcfs(P, n);

    return 0;
}