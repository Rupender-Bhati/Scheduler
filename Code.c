#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<Windows.h>

int clock=0;
int clock_idle_time;
struct Process
{

    int current_burst_time;
    int time_waited;
	int arrival_time;
	int burst_time;
	int process_active;
	int process_finished;
	int used_time;

	char process_id[5];

};

void get_entries(struct Process *p)
{
    printf("Enter the process arrival time");
    scanf("%d",&p->arrival_time);
    printf("\nEnter the process burst time");
    scanf("%d",&p->burst_time);
    printf("\nEnter the process name");
    scanf("%s",&p->process_id);
    p->time_waited=0;
    p->process_active=0;
    p->current_burst_time=p->burst_time;
    p->process_active=0;
    p->process_finished=0;
    p->used_time=0;

}

void make_active(struct Process *p)
{
    p->process_active=1;
}
void make_inactive(struct Process *p)
{
    p->process_active=0;
}
void finish_process(struct Process *p)
{
    p->process_finished=1;

}
int check_process_finish(struct Process p)
{
    if(p.process_finished==1)
        return 1;
    else
        return 0;
}



int deduct_burst_time(struct Process *p,int x)
{
    int check=p->current_burst_time;
    if(check-x<=0)
    {
        finish_process(p);
         p->used_time+=p->current_burst_time;
        (p->current_burst_time)=0;
        return (check);

    }
    else
       {

       (p->current_burst_time)-=x;
        p->used_time+=x;
        return x;

       }


}


int main()
{
    struct Process process_list[4];

    //Initialising processes.
    for(int i=0;i<4;i++)
    {
        get_entries(&(process_list[i]));

    }
    printf("Process Name:  Time Added:  Burst Time:  Current Burst Time:\n");
    for(int i=0;i<4;i++)
    {
        printf("%s   %d    %d    %d   %d\n",process_list[i].process_id,process_list[i].arrival_time,process_list[i].burst_time,process_list[i].current_burst_time);
    }


    //first iteration

    for(int i=0;i<4;i++)
    {
        if(process_list[i].arrival_time>clock)
        {
            int diff= process_list[i].arrival_time-clock;
            clock+=diff;
            clock_idle_time+=diff;
        }
        else
        {

        }
        if(i==0)
        {
            process_list[i].time_waited=0;
            deduct_burst_time(&process_list[i],3);

            clock+=process_list[i].used_time;
        }
        else
        {

        deduct_burst_time(&process_list[i],3);
        process_list[i].time_waited=clock-process_list[i].arrival_time;
        clock+=process_list[i].used_time;

        }


    }
    Sleep(3000);

    system("cls");
    printf("Process Name:  Time Added:  Burst Time:  Current Burst Time:   Time Waited:    Time Consumed:  Status \n");
    for(int i=0;i<4;i++)
    {
        printf("%s               %d          %d                 %d                   %d                  %d               %d          \n",process_list[i].process_id,process_list[i].arrival_time,
               process_list[i].burst_time,process_list[i].current_burst_time,
               process_list[i].time_waited,process_list[i].used_time, process_list[i].process_finished);
    }

    clock=0;

    for(int i=0;i<4;i++)
    {
        clock+=process_list[i].used_time;
    }
    clock+=clock_idle_time;

    //Second iteration

    for(int i=0;i<4;i++)
        {
            if(process_list[i].process_finished==1)
                continue;

                process_list[i].time_waited=clock-process_list[i].used_time-process_list[i].arrival_time;
                clock+=deduct_burst_time(&process_list[i],6);
        }

    Sleep(6000);
    system("pause");
    system("cls");
    printf("Second Iteration \n");
    printf("Process Name:  Time Added:  Burst Time:  Current Burst Time:   Time Waited:    Time Consumed:  Status \n");
    for(int i=0;i<4;i++)
    {
        printf("%s               %d          %d                 %d                   %d                  %d               %d          \n",process_list[i].process_id,process_list[i].arrival_time,
               process_list[i].burst_time,process_list[i].current_burst_time,
               process_list[i].time_waited,process_list[i].used_time, process_list[i].process_finished);
    }

    struct Process temp;
    for(int i=0;i<3;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            if(process_list[i].current_burst_time>process_list[j].current_burst_time)
            {
                temp=process_list[i];
                process_list[i]=process_list[j];
                process_list[j]=temp;


            }
        }
    }

    system("pause");
    system("cls");
    printf("Second Iteration \n");
    printf("Process Name:  Time Added:  Burst Time:  Current Burst Time:   Time Waited:    Time Consumed:  Status \n");
    for(int i=0;i<4;i++)
    {
        printf("%s               %d          %d                 %d                   %d                  %d               %d          \n",process_list[i].process_id,process_list[i].arrival_time,
               process_list[i].burst_time,process_list[i].current_burst_time,
               process_list[i].time_waited,process_list[i].used_time, process_list[i].process_finished);
    }



}


