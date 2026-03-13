#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], wt[n], tat[n];
    int queue[100], front = 0, rear = 0;
    int visited[n];

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d ID: ", i+1);
        scanf("%d", &pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        visited[i] = 0;
    }

    int current_time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    while (completed < n) {

        // Add arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (front == rear) {
            current_time++;
            continue;
        }

        int p = queue[front++];

        if (rt[p] > tq) {
            current_time += tq;
            rt[p] -= tq;

            // Add newly arrived processes
            for (int i = 0; i < n; i++) {
                if (at[i] <= current_time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }

            queue[rear++] = p; // put back in queue
        }
        else {
            current_time += rt[p];

            tat[p] = current_time - at[p];
            wt[p] = tat[p] - bt[p];

            avg_wt += wt[p];
            avg_tat += tat[p];

            rt[p] = 0;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    printf("\nUSN : 1BM24CS012");
    return 0;
}
