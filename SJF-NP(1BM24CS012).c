#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int finished[n];

    int current_time = 0, completed = 0;

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        finished[i] = 0;
    }

    while(completed < n) {
        int min_bt = INT_MAX;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && finished[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                index = i;
            }
        }

        if(index == -1) {
            current_time++;
        }
        else {
            ct[index] = current_time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            current_time = ct[index];
            finished[index] = 1;
            completed++;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
