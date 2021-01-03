#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main()
{
    int orate,drop=0,cap,x,count=0;
    int inp[10]={0};    //arr to store packets cmmg at each second
    int i=0;    // seconds(time) counter
    int nsec;

    printf(" \n enter bucket size : ");
    scanf("%d",&cap);
    printf("\n enter output rate :");
    scanf("%d",&orate);
    
    int ch;
    do
    {
        printf("\n enter number of packets coming at second %d : ",i+1);
        scanf("%d",&inp[i]);
        i++;
        printf("\n enter 1 to contiue or 0 to quit..........");
        scanf("%d",&ch);
    }while(ch);

    nsec=i; // total seconds storage
    printf("\n second \t recieved \t sent \t dropped \t remained \n");

    // COUNT has the data being carried forwARD TO NEXT ITERtion(second)
    for(i=0; count || i<nsec ;i++)  //check for all seconds till max 
    {
        printf("%d",i+1);
        printf(" \t %d\t ",inp[i]);
        printf(" \t %d\t ",MIN((inp[i]+count),orate));  //since maximum we can send is output rate

        if( (x=inp[i]+count-orate)>0 )  //if value to be send is more than ouput rate!
        {                               // x is the leftover value even after data is send equal to output rate
            if(x>cap)  // if val is more than bucket size( DROP CONDITION!)
            {
                count = cap;
                drop = x-cap;
            }
            else
            {
                count=x;
                drop=0;
            }
        }
        else
        {
            drop=0;
            count=0;
        }

        printf(" \t %d \t %d \n",drop,count);
    }
    return 0;
}

