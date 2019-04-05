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
	string process_id;

	Process()
	{

        cout<<"Enter the process name\n";
        cin>>process_id;
        cout<<"Enter Arrival time\n";
        cin>>arrival_time;
        cout<<"Enter the burst time required";
        cin>>arrival_time;
	}
};

int main()
{

    Process process_list[4];

}

