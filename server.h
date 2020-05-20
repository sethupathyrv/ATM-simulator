#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct something{
    char username[30];
    char gender[10];
    int age;
    char date[15];
    char actype[10];
    int acnum;
    int pin;
    int balance;
}user;
char enteredusername[30];
int enteredpin;
int checkinfoint=0;
int withdrawamt;
int depositamt;
int newpin;
int secretkey;
int denom[4]={100,100,100,100};
int dep[5]={0,0,0,0,0};
int wit[5]={0,0,0,0,0};
int depnum=0;
int witnum=0;
char deptime[5][30];
char wittime[5][30];
time_t currentTime;



void searchstruct(int i,int j,user *users)
{
    int a=0;
    char username[30];
    //printf("Enter the user name:");
    //fgets(username,30,stdin);
    int len=strlen(username);
    if(username[len-1]=='\n')
    {
        username[len-1]=0;
    }
    i=1;
    for(int a=1;a<=j;a++)
    {
        if(strcmp(username,users[a].username)==0)
            break;
        else
        {
            if(a==j)
            {
                printf("invalid entry.\n");
                return;
            }
        }
        i++;


    
    }

    printf("name:%s\n",users[i].username);
    printf("gender:%s\n",users[i].gender);
    printf("age:%d\n",users[i].age);
    printf("actype:%s\n",users[i].actype);
    printf("date:%s\n",users[i].date);
    printf("acnum:%d\n",users[i].acnum);
    printf("pin:%d\n",users[i].pin);
    printf("balance:%d\n\n\n",users[i].balance); 
    
}

void intro()
{
    printf("\t\t");
    for(int u=0;u<=165;u++)
    {
        printf("*");
    }
    printf("\n");
    printf(" \t\t ******     \t\t\t\t\t\t\t                                      \t\t\t\t\t\t\t       *****  \n");
    printf(" \t\t *******    \t\t\t\t\t\t\t          *     *******  **   **      \t\t\t\t\t\t\t     *******  \n");
    printf(" \t\t *********  \t\t\t\t\t\t\t         * *       *     * * * *      \t\t\t\t\t\t\t   *********  \n");
    printf(" \t\t ***********\t\t\t\t\t\t\t        *****      *     *  *  *      \t\t\t\t\t\t\t ***********  \n");
    printf(" \t\t *********  \t\t\t\t\t\t\t       *     *     *     *     *      \t\t\t\t\t\t\t   *********  \n");
    printf(" \t\t *******    \t\t\t\t\t\t\t      *       *    *     *     *      \t\t\t\t\t\t\t     *******  \n");  
    printf(" \t\t ******     \t\t\t\t\t\t\t                                      \t\t\t\t\t\t\t       *****  \n");       
    //printf("**********************************************************\n");
    
    printf("\t\t");
    for(int u=0;u<=165;u++)
    {
        printf("*");
    }
    printf("\n");
    printf("  \t\t\t\t\t\t\t\t\t             ////// BANK OF BERMUDA //////    \t\t\t\t\t\t\t\t\t         ");
    //printf("**********************************************************\n");
    printf("\t\t");
    for(int u=0;u<=165;u++)
    {
        printf("*");
    }
    printf("\n");
    
}   

void getinfo()
{
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the username:");
    scanf("%s",enteredusername);
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the PIN:");
    scanf("%d",&enteredpin);
    printf("\n\n");
}

int checkinfo(user *users)
{   
    int userIndex=-1;
    for(int i=0;i<24;i++)
    {
        if((strcmp(enteredusername,users[i].username)==0) && (enteredpin==users[i].pin))
        {
            userIndex= i;
            break;
        }
    }
    
    
    if(userIndex==-1)
            {
                printf("\t\t\t\t\t\t\t\t\t\t\tIncorrect credentials!.\n");
                return userIndex;
            }

   return userIndex;
}

/*void checkinfo(int i,int j,user *users)
{   
    i=1;
    for(int a=1;a<=j;a++)
    {
        if(strcmp(enteredusername,users[a].username)==0)
            break;
        else
        {
            if(a==j)
            {
                printf("invalid entry.");
                printf("TRANSACTION TERMINATED!!");
                return;
            }
        }
        i++;
    }
    printf("Value of i:%d\n",i);
    if(enteredpin==users[i].pin)
    {
        checkinfoint=1;
    }
    else
    {
        checkinfoint=0;
    }
}*/

int withdrawmoney(user u)
{
    int twoth=0;
    int twohun=0;
    int fivehun=0;
    int hun=0;
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the amount to be withdrawn(In multiples of 100):");
    scanf("%d",&withdrawamt);
    if(withdrawamt%100!=0)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tEntered amount was in wrong multiples\n");
        return u.balance;
    }
    printf("\t\t\t\t\t\t\t\t\t\t\tPrevious balance:%d\n",u.balance);
    if(withdrawamt<=u.balance && (withdrawamt%100==0))
    {
        
        wit[witnum]=withdrawamt;
        u.balance=u.balance - withdrawamt;
        twoth=withdrawamt/2000;
        withdrawamt=withdrawamt%2000;
        fivehun=withdrawamt/500;
        withdrawamt=withdrawamt%500;
        twohun=withdrawamt/200;
        withdrawamt=withdrawamt%200;
        hun=withdrawamt/100;
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 2000's:%d\n",twoth);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 500's:%d\n",fivehun);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 200's:%d\n",twohun);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 100's:%d\n\n",hun);

        printf("\t\t\t\t\t\t\t\t\t\t\tAvailable balance:%d\n",u.balance);
    
        time(&currentTime);
        strcpy(wittime[witnum],ctime(&currentTime));

        denom[0]-=twoth;
        denom[1]-=fivehun;
        denom[2]-=twohun;
        denom[3]-=hun;
        witnum+=1;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tInvalid entry\n");
        printf("\t\t\t\t\t\t\t\t\t\t\tThe withdraw amount exceeded balance ");
        return u.balance;
    }
    return u.balance;
}

int depositmoney(user u)
{
    int twoth=0;
    int twohun=0;
    int fivehun=0;
    int hun=0;
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the amount to be deposited(In multiples of 100):");
    scanf("%d",&depositamt);
    if(depositamt%100!=0)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tAmount was not in multiples of 100!\n");
        return u.balance;
    }
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the count of 2000's:");
    scanf("%d",&twoth);
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the count of 500's:");
    scanf("%d",&fivehun);
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the count of 200's:");
    scanf("%d",&twohun);
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the count of 100's:");
    scanf("%d",&hun);
    if((twoth*2000 + fivehun*500 + twohun*200 + hun*100)==depositamt)
    {
        dep[depnum]=depositamt;
        
        printf("\n\t\t\t\t\t\t\t\t\t\t\tPrevious balance:%d\n\n",u.balance);
        u.balance=depositamt + u.balance;
        printf("\t\t\t\t\t\t\t\t\t\t\tAvailable balance:%d\n",u.balance);
        denom[0]+=twoth;
        denom[1]+=fivehun;
        denom[2]+=twohun;
        denom[3]+=hun;
        time(&currentTime);
        strcpy(deptime[depnum],ctime(&currentTime));
        depnum+=1;

        return u.balance;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tEntered number of denominations did not match the deposit amount entered!!\n");
        return u.balance;
    }
    

}

int changepin(user u)
{
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the new pin:");
    scanf("%d",&newpin);
    if(newpin>=1000 && newpin<=9999 && u.pin!=newpin)
    {
        u.pin=newpin;
        printf("\t\t\t\t\t\t\t\t\t\t\tPin changed successfully!\n");
        return u.pin;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tInvalid pin!\n");
        return u.pin;
    }
    
}

void balanceenquiry(user u)
    {
        int temp1=witnum;
        int temp2=depnum;
        printf("\t\t\t\t\t\t\t\t\t\t\tYour balance is Rs: %d\n",u.balance);
        printf("\n\t\t\t\t\t\t\t\t\t\t\tWithdrawals:\n");
        int count=0;
        for(witnum=0;witnum<5;witnum++)
        {
            
            if(wit[witnum]!=0)
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t%d.%d\t\t%s\n",witnum+1,wit[witnum],wittime[witnum]);
                count++;
            }
            
        }
        if(count==0)
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t-no widhdrawals-\n\n");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\tDeposits:\n");
        count=0;
        for(depnum=0;depnum<5;depnum++)
        {
            
            if(dep[depnum]!=0 && dep[depnum]%100==0)
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t%d.%d\t\t%s\n",depnum+1,dep[depnum],deptime[depnum]);
                
                count++;

            }
        
        }
        if(count==0)
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t-no deposits-\n\n");
        }

        witnum=temp1;
        depnum=temp2;
        return;
        
    }

/*void balanceenquiry(int i,user *users)
    {
        printf("user index IN balance enquiry :%d\n",i);
        printf("Your balance is Rs: %d",users[i].balance);
        return;
    }*/

void bankppl()
{
    int atmbalance=0;
    printf("\t\t\t\t\t\t\t\t\t\t\tEnter the SECRET KEY:");
    scanf("%d",&secretkey);
    if(secretkey!=1234)
        return;
    else
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 2000's:%d\n",denom[0]);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 500's:%d\n",denom[1]);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 200's:%d\n",denom[2]);
        printf("\t\t\t\t\t\t\t\t\t\t\tCount of 100's:%d\n",denom[3]);
        atmbalance=2000*denom[0] + 500*denom[1] + 200*denom[2] + 100*denom[3];
        printf("\t\t\t\t\t\t\t\t\t\t\tTotal amount in the ATM:%d\n\n",atmbalance);

    }
    
}

void acdetail(user u)
{
    printf("\t\t\t\t\t\t\t\t\t\t\tname:%s\n",u.username);
    printf("\t\t\t\t\t\t\t\t\t\t\tgender:%s\n",u.gender);
    printf("\t\t\t\t\t\t\t\t\t\t\tage:%d\n",u.age);
    printf("\t\t\t\t\t\t\t\t\t\t\tactype:%s\n",u.actype);
    printf("\t\t\t\t\t\t\t\t\t\t\tdate:%s\n",u.date);
    printf("\t\t\t\t\t\t\t\t\t\t\tacnum:%d\n",u.acnum);
    printf("\t\t\t\t\t\t\t\t\t\t\tpin:%d\n",u.pin);
    printf("\t\t\t\t\t\t\t\t\t\t\tbalance:%d\n\n",u.balance);       
}