#include <iostream>

using namespace std;

struct Activity
{
    char id[10];
    int start;
    int finish;
};

void activitySelection(Activity activities[], int n)
{
    int i, j;

    Activity temp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n-1 ; j++)
        {
            if (activities[j].finish > activities[j + 1].finish)   //Bubble sort
            {
                temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }

    cout << "Activities printed according to sorted order of their finishing time." << endl;
    cout << "Activity Start Finish" << endl;

    for (i = 1; i <= n; i++)
    {
        cout << activities[i].id << "       " << activities[i].start << "       " << activities[i].finish << endl;
    }

    cout << "Final Result" << endl;
    cout << "Activity  Start Finish" << endl;
    cout << activities[0].id << "       " << activities[0].start << "       " << activities[0].finish << endl;

    i = 1;

    for (j = 2; j <= n; j++)
    {
        if (activities[j].start >= activities[i].finish)
        {
            cout << activities[j].id << "       " << activities[j].start << "       " << activities[j].finish << endl;
            i = j;
        }
    }
}

int main(void)
{

    Activity activities[20];
      /*  {
            {"a1", 2, 3},
            {"a2", 1, 4},
            {"a3", 8, 10},
            {"a4", 6, 9},
            {"a5", 10, 15},
            {"a6", 5, 8},
        };*/

    int total_activity;
    cout << "Enter number of activity: ";
    cin >> total_activity;

    cout << "Enter starting and finishing time:" << endl;
    for (int i = 1; i <= total_activity; i++)
    {
        cin >> activities[i].id;
        cin >> activities[i].start;
        cin >> activities[i].finish;
    }

    activitySelection(activities, total_activity);

    return 0;
}