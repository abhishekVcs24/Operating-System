#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    // Input process details
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // Remaining Time initially equals Burst Time
    }

    while(completed < n) {
        int min_rt = INT_MAX;
        int index = -1;

        // Find process with minimum remaining time
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                index = i;
            }
        }

        // If no process is ready
        if(index == -1) {
            time++;
        }
        else {
            // Execute process for 1 unit time
            rt[index]--;
            time++;

            // If process finishes
            if(rt[index] == 0) {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
    }

    // Display results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
