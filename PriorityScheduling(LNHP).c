#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n];
    bool completed[n];

    for(int i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        completed[i] = false;
    }

    int current_time = 0;
    int completed_count = 0;
    float total_wt = 0, total_tat = 0;

    while(completed_count < n) {

        int highest_priority = 9999;
        int selected_process = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == false) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected_process = i;
                }
            }
        }

        if(selected_process == -1) {
            current_time++;
        }
        else {
            int start_time = current_time;

            ct[selected_process] = start_time + bt[selected_process];

            tat[selected_process] = ct[selected_process] - at[selected_process];

            wt[selected_process] = tat[selected_process] - bt[selected_process];

            current_time = ct[selected_process];

            completed[selected_process] = true;
            completed_count++;

            total_wt += wt[selected_process];
            total_tat += tat[selected_process];
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    printf("\nUSN : 1BM24CS012");
    return 0;
}














