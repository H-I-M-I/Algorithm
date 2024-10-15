#include <stdio.h>
#include <stdlib.h>

void knapsack(int n,float weight[],float profit[],float capacity)
{
    float x[10],tp=0;
    int i,j,u;
    u=capacity;
    for(i=0; i<n; i++)
    {
        if(weight[i]>u)
            break;
        else
        {
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
    if(i<n)
        x[i]=u/weight[i];

    tp=tp+(x[i]*profit[i]);

    printf("Maximum profit : %f",tp);
}

int main()
{
    float weight[20],profit[20],capacity;
    int num,i,j;
    float ratio[20],temp;

    printf("Enter number of objects : \n");
    scanf("%d",&num);
    printf("Enter number of weights : \n");
    for(i=0; i<num; i++)
    {
        scanf("%f",&weight[i]);
    }
    printf("Enter number of profit : \n");
    for(i=0; i<num; i++)
    {
        scanf("%f",&profit[i]);
    }

    printf("Enter number of capacity : \n");
    scanf("%f",&capacity);

    for(i=0; i<num; i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

            }
        }
    }
    knapsack(num,weight,profit,capacity);
    return 0;

}
