#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int clock=0;
struct Process
{

    int current_burst_time;
    int time_waited;
	int arrival_time;
	int burst_time;
	int process_active;
	int process_finished;

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
    p->process_active=false;
    p->current_burst_time=p->burst_time;
    p->process_active=0;
    p->process_finished=0;

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
        (p->current_burst_time)=0;
        return(x-check);
    }
    else
        (p->current_burst_time)-=x;
        return 0;


}


int main()
{
    struct Process process_list[4];

    //Initialising processes.
    for(int i=0;i<4;i++)
    {
        get_entries(&(process_list[i]));

    }


}


