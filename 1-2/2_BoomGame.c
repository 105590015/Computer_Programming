#include <stdio.h>
main()
{
    int people[100]={0},n,m,k,i,j,die=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        people[i]=i+1;
    while(k!=0)
    {
        die=(die+m-1)%n;
        printf("%d ",people[die]);
        for(j=die;j<n;j++)
            people[j]=people[j+1];
        n--;
        k--;
        /*printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,die=%d,n=%d,k=%d\n",people[0],people[1],people[2],people[3],people[4],people[5],people[6],people[7],people[8],die,n,k);*/
    }
    if(people[die]!=0)
        printf("%d",people[die]);
    else
        printf("%d",people[0]);
}
