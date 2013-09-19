#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int maxSum(int* a, int n)    
{    
    int sum=0;     int b=0; 
	int i=0;
    //其实要处理全是负数的情况，很简单，如稍后下面第3点所见，直接把这句改成："int sum=a[0]"即可     
    //也可以不改，当全是负数的情况，直接返回0，也不见得不行。     
    for(i=0; i<n; i++)    
    {    
        if(b<0)           //...     
            b=a[i];    
        else    
            b+=a[i];    
        if(sum<b)    
            sum=b;    
    }    
    return sum;    
}    
int MaxsunLoop(int *a,int n)
{
	int temp[20]={0};
	int i=0,j=0,k=0,sum;
	sum=maxSum(a,n);
    for(i=0;i<n;i++)
	{
		temp[k++]=a[i];
		for(j=i+1;j!=i;j=(++j)%n)
			temp[k++]=a[j%n];
	//	printf("%d  %d  %d\n",temp[0],temp[1],k);
         k=0;
		if(sum<maxSum(temp,n))
			sum=maxSum(temp,n);
	}
	return sum;
}
int MaxsumMat(int n, int m, int d[][20])
{
	int i=0,k=0,j=0;
	int temp[20],t;
	int s=0,sum=0;
	for(k=0;k<n;k++)
	{ 
	   for(j=k;j<n;j++)
	   {
		   for(i=0;i<m;i++)
		   {
			   for(t=k;t<=j;t++)
			   {temp[i]+=d[t][i];}
		   }
           if(maxSum(temp,m)>sum)
			   sum=maxSum(temp,m);
		   // printf("%d  %d  %d %d %d  %d\n",sum,k,j,temp[0],temp[1],d[2][0]);
		   for(s=0;s<m;s++)
			   temp[s]=0;
	   }
   }
return sum;
}
int MaxsumMatloop(int n,int m,int d[][20],int flag)
{
	
	int i=0,k=0,j=0;
	int temp[20]={0},t=0;
	int s=0,sum=0;
	if(flag==1)
	{
		for(k=0;k<n;k++)
		{ 
		for(j=k;j<n;j++)
		{
			for(i=0;i<m;i++)
			{
				for(t=k;t<=j;t++)
				{temp[i]+=d[t][i];}
			}
			if(MaxsunLoop(temp,m)>sum)
				sum=MaxsunLoop(temp,m);
			// printf("%d  %d  %d %d %d  %d\n",sum,k,j,temp[0],temp[1],d[2][0]);
			for(s=0;s<m;s++)
				temp[s]=0;
		}
	}
	}
	if(flag==2)
	{
		for(k=0;k<n;k++)
		{
			for(j=(k+1)%n;j!=k;j=(++j)%n)
			{
				for(i=0;i<m;i++)
				{
					for(t=k;t!=j;t=(++t)%n)
					{temp[i]+=d[t][i]; }
				
				}
				for(i=0;i<m;i++)
				temp[i]+=d[j][i];

				if(MaxsunLoop(temp,m)>sum)
					sum=MaxsunLoop(temp,m);
				 //printf("%d  %d  %d %d %d  %d\n",sum,k,j,temp[0],temp[1],d[2][0]);
				for(s=0;s<m;s++)
					temp[s]=0;
			}
		}

	}
return sum;


}
int main(int argc, char* argv[])
{
	FILE *in;

    int i=0,j=0,k=0,z=0,t=0,temp[200]={0};
	int n,m,d[200][200],sum=0,s=0;
    int test[10]={1,2,3,-1,2,3,1};
	char path[50];
	
	j=strlen(argv[0]);
	for(;j>=0;j--)
	{
		if((int)argv[0][j]==92)
			break;
	}
	for(i=0;i<=j;i++)
		path[i]=argv[0][i];
	path[i]='\0';
	
	strcat(path,argv[argc-1]);
//	printf("%s\n",path);
	in=fopen(path,"r");
	fscanf(in,"%d",&n);
	fscanf(in,"%d",&m);
    if(argc>4)
	{printf("too many arguments");exit(0);}
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(in,"%d",&d[i][j]);
		}
	}
  //if(strcmp(argv[1],"-h"))
 // {
     sum=maxSum(d[0],m);
  //}

   printf("%d\n",sum);

	for(;;);	
}
