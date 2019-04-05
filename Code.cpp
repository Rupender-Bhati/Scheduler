#include<iostream>
#include<string>
using namespace std;

class Process
{
public:
    int current_burst_time;
    int time_waited;
	int arrival_time;
	int burst_time;
	bool process_active;

	string process_id;

	Process()
	{

        cout<<"Enter the process name\n";
        cin>>process_id;
        cout<<"Enter Arrival time\n";
        cin>>arrival_time;
        cout<<"Enter the burst time required";
        cin>>arrival_time;
        current_burst_time=burst_time;
        time_waited=0;
	}
	int deduct_burstime(int x)
	{
	    int check=current_burst_time;

	    if(check-x<=0)

	    {
	        current_burst_time=0;
	        return (x-current_burst_time);
	    }
	    else

            {current_burst_time=current_burst_time-x;
                return 0;
            }


	}
	void addtowait()
	{
	    if(process_active==false)
        {
            time_waited++;
        }
	}

	void make_active()
	{
	    process_active=true;
	}
	void make_inactive()
	{
        process_active=false;
	}



};

int main()
{

    Process process_list[4];

}

