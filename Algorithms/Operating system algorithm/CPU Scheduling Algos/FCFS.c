#include<stdio.h>
#include<string.h>
struct process{
    char process_id [10];
    int arrival_time;
    int burst_time;
    int wait_time;
    int turn_around_time;
};

int main(){
    // Temp variables for swapping
    int temp_at, temp_bt;
    char temp_id[10];
    int wait_time = 0;

    // Taking input for number of processes
    int number_of_processes;
    printf("Enter the number of processes:");
    scanf("%d",&number_of_processes);
    // Creating an array to store the processes;
    struct process process_queue[number_of_processes];
    for(int i = 0 ; i < number_of_processes ; i++){
        printf("PROCESS NUMBER:- %d\nEnter the process ID of:- ",i+1);
        scanf("%s", process_queue[i].process_id);
        printf("Enter the burst time:- ");
        scanf("%d", &process_queue[i].burst_time);
printf("Enter the arrival time:- ");
scanf("%d", &process_queue[i].arrival_time);

    }
    // for(int i = 0 ; i < number_of_processes ; i++){
    //     printf("ID:- %s\nAT:- %d\nBT:- %d\n",process_queue[i].process_id,process_queue[i].arrival_time,process_queue[i].burst_time);
    // }
    // Now we will sort the processes in the array based on their arrival time
    for(int i = 0 ; i < number_of_processes ; i++){
        for(int j = 0 ; j < number_of_processes - i - 1 ; j++){
            if(process_queue[j].arrival_time > process_queue[j+1].arrival_time){
                strcpy(temp_id , process_queue[j].process_id);
                temp_at = process_queue[j].arrival_time;
                temp_bt = process_queue[j].burst_time;
                strcpy(process_queue[j].process_id , process_queue[j+1].process_id);
                process_queue[j].arrival_time = process_queue[j+1].arrival_time;
                process_queue[j].burst_time = process_queue[j+1].burst_time;
                strcpy(process_queue[j+1].process_id , temp_id);
                process_queue[j+1].arrival_time = temp_at;
                process_queue[j+1].burst_time = temp_bt;
            }
        }
    }
    // Calculating the wait time
    for(int i = 0 ; i < number_of_processes ; i++){
        process_queue[i].wait_time = wait_time - process_queue[i].arrival_time;
        wait_time = wait_time + process_queue[i].burst_time;
    }
    // Calculating the turn around time
    for(int i = 0 ; i < number_of_processes ; i++){
        process_queue[i].turn_around_time = process_queue[i].burst_time + process_queue[i].wait_time;
    }
    // Printing the table
    printf("ID\tAT\tBT\tWT\tTAT\n");
    for(int i = 0 ; i < number_of_processes ; i++){
        printf("%s\t%d\t%d\t%d\t%d\n",process_queue[i].process_id,process_queue[i].arrival_time,process_queue[i].burst_time,process_queue[i].wait_time,process_queue[i].turn_around_time);
    }
    return 0;
}