#include<stdio.h>

int main()
{
    int b[10],p[10],nb,np,i,j,w;

    printf("Enter number of blocks: ");
    scanf("%d",&nb);

    printf("Enter block sizes:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    printf("Enter process sizes:\n");
    for(i=0;i<np;i++)
        scanf("%d",&p[i]);

    for(i=0;i<np;i++)
    {
        w=-1;
        for(j=0;j<nb;j++)
        {
            if(b[j]>=p[i])
                if(w==-1 || b[j]>b[w])
                    w=j;
        }

        if(w!=-1)
        {
            printf("Process %d allocated to block %d\n",i+1,w+1);
            b[w]-=p[i];
        }
        else
            printf("Process %d not allocated\n",i+1);
    }
}