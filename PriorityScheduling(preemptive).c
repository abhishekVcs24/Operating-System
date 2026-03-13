#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n];

    float avg_wt = 0, avg_tat = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority (lower number = higher priority): ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i]; // Remaining time
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n) {

        int highest_priority = 9999;
        int selected_process = -1;

        // Select highest priority process
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) {
                if (pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected_process = i;
                }
            }
        }

        if (selected_process == -1) {
            current_time++;
        }
        else {
            rt[selected_process]--;
            current_time++;

            if (rt[selected_process] == 0) {
                ct[selected_process] = current_time;

                tat[selected_process] = ct[selected_process] - at[selected_process];
                wt[selected_process] = tat[selected_process] - bt[selected_process];

                avg_wt += wt[selected_process];
                avg_tat += tat[selected_process];

                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    printf("\nUSN : 1BM24CS012");
    return 0;
}
