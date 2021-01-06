#include<stdio.h>
#include<string.h>
int checksum(int fl)
{
    char in[100]; //for input in binary format
    // int buf[25]; 
    int i,sum=0,n,temp;

    printf("Enter the string \n");
    scanf("%s",in);

    if(strlen(in)%2!=0) //n is number of rows to be added ( we divide by 2 as 2 hex = 8byte and that  can only come in a row)
            n=(strlen(in)+1)/2;
    else
            n=n=(strlen(in))/2;
    
    for(i=0;i<n;i++)
    {
        temp=in[i*2];   //to select 1st digit
        temp=(temp*256)+in[(i*2)+1];    // to increase the place value of 1st char by 8bits(start 8bits) then 2nd part of 8 bits can be done exactly
        sum=sum+temp;   // add each row binary numbers
    }

    if(fl==1)   //for decode
    {
        printf("Enter the checksum value \n");
        scanf ("%x", &temp);
        sum += temp; 
    }

    if(sum%65536!=0) //overflow condition(if last bit(17th bit) is set or not)
    {
        n = sum%65536;
        sum = (sum/65536) + n; //adding the 16th bit one(when overflow happens)
    }

    sum = 65535-sum; //taking compliment (we take compliment as FFFF(2^16 - 1) - sum)
    printf("%x\n",sum);
    return sum;
}

int main()
{
    int ch,sum;
    do
    {
        printf("1.Encode \n2.Decode \n3.Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1: sum=checksum(0);
                    printf("Checksum to append is:%x \n",sum);
                    break;
                    
            case 2: sum=checksum(1);
                    if(sum!=0)
                        printf("The data has been tampered with or invalid checksum\n");
                    else
                        printf("The checksum is valid \n");
                    break;

            case 3: break;
            default: printf("Invalid option, try again \n");
        }
    } while(ch!=3);
    return 0;
}
 
