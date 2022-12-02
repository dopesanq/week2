#include<stdio.h>
void intersect(int no1, int no2,int A[1000], int B[1000], int It[1000], int *k)
{
    int i,j;
    for(i=0;i<no1;i++)
    {
        for(j=0;j<no2;j++)
        {
            if(A[i]==B[j])
            {
                It[*k]=A[i];
                *k+=1;
            }
        }
    }
}
void u(int no1, int no2, int A[1000], int B[1000],int It[1000], int u[1000], int *z, int x)
{
    int i,j,l=0;
    for(i=0;i<no1;i++)
    {
        for(j=0;j<no2;j++)
        {
            if(A[i]!=B[j])
            {
                l++;
            }
        }
        if(l==no2)
        {
            u[*z]=A[i];
            *z+=1;
        }
        l=0;
    }
    for(i=0;i<no2;i++)
    {
        for(j=0;j<no1;j++)
        {
            if(B[i]!=A[j])
            {
                l++;
            }
        }
        if(l==no1)
        {
            u[*z]=B[i];
            *z+=1;
        }
        l=0;
    }
    for(i=0;i<x;i++)
    {
        u[*z+i]=It[i];
    }
    *z+=i;
}
int main()
{
    int i,n1,n2,a[1000],b[1000],it[1000],un[1000],x=0,y=0,j;
    printf("Enter no1: ");
    scanf("%d",&n1);
    printf("Enter no1 members: ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter no2: ");
    scanf("%d",&n2);
    printf("Enter no2 members: ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    intersect(n1,n2,a,b,it,&x);
    int temp;
    for(i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if(it[i]>it[j])
            {
                temp=it[i];
                it[i]=it[j];
                it[j]=temp;
            }
        }
    }
    i=0;
    if(x)
    {
        while(i<x)
        {
            printf("%d ",it[i]);
            i++;
        }
        printf("\n");
    }
    else printf("Empty\n");
    u(n1,n2,a,b,it,un,&y,x);
    for(i=0;i<y;i++)
    {
        for(j=i+1;j<y;j++)
        {
            if(un[i]>un[j])
            {
                temp=un[i];
                un[i]=un[j];
                un[j]=temp;
            }
        }
    }
    i=0;
    while(i<y)
    {
        printf("%d ",un[i]);
        i++;
    }
    printf("\n");
    return 0;
}
//Enter no1: 5
//Enter no1 members: -12 -3 0 11 23
//Enter no2: 8
//Enter no2 members: -9 -3 8 11 12 14 20 23
