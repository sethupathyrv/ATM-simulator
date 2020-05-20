#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"server.h"
time_t currentTime;
void searchstruct(int i ,int j,user users[j]);
int j = 1;

int main()
{
    FILE *myfile;
    myfile=fopen("atm.csv","r");
    if((myfile=fopen("atm.csv","r"))==NULL)
    {
        printf("Can't open file.\n");
        exit(1);
    }
    rewind(myfile);
    char myline[200]; 
    fgets(myline,200,myfile);
    char* delimiter = ",";
    int i = 0  ;
     
    for(char c=getc(myfile); c != EOF;c=getc(myfile))
    {
        if(c=='\n')
        {
            j++;
        }
    }
    
    user users[j+1];
    rewind(myfile);


    while(fgets(myline,200, (FILE*)myfile)!=NULL)
    {
    strcpy(users[i].username,strtok(myline,delimiter));   
    strcpy(users[i].gender,strtok(NULL, delimiter));
    users[i].age = atoi(strtok(NULL, delimiter));
    strcpy(users[i].date,strtok(NULL, delimiter));
    strcpy(users[i].actype,strtok(NULL, delimiter));
    users[i].acnum = atoi(strtok(NULL, delimiter));
    users[i].pin = atoi(strtok(NULL, delimiter));
    users[i].balance = atoi(strtok(NULL, delimiter));
    i++;
    }

    fclose(myfile); 

    //searchstruct(i,j,users);
    intro();
    getinfo();
    int userIndex= checkinfo(users);

    if(userIndex>=0)
    {
        int choosetask=99;
        while(choosetask!=7)
        {
                printf("\t\t");
                for(int u=0;u<=165;u++)
                {
                    printf("*");
                }
                printf("\n");
            //printf("\n**********************************************************\n");
            printf("\n\t\t\t\t\t\t\t\tChoose the corresponding number for the task you want to perform\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t1.Withdraw Money\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t2.Deposit money\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t3.Change password\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t4.Balance enquiry\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t5.ATM details\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t6.Account details\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t7.Exit\n\n");
            printf("\t\t");
                for(int u=0;u<=165;u++)
                {
                    printf("*");
                }
                printf("\n");
            //printf("**********************************************************\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\tEnter the option:");
            scanf("%d",&choosetask);

            if(choosetask==1)
            {
                users[userIndex].balance=withdrawmoney(users[userIndex]);
                
            }
            else if(choosetask==2)
            {
                users[userIndex].balance=depositmoney(users[userIndex]);
                
            }
            else if(choosetask==3)
            {
                users[userIndex].pin=changepin(users[userIndex]);
            }
            else if(choosetask==4)
            {
                balanceenquiry(users[userIndex]);
            }
            else if(choosetask==5)
            {
                bankppl();
            }
            else if(choosetask==6)
            {
                acdetail(users[userIndex]);
            }
            else if (choosetask==7)
            {
                return 0;
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t\t\tINVALID ENTRY\n");
                printf("\t\t\t\t\t\t\t\t\t\t\tTransaction cancelled!!");
                return 0;
            }
        }
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tTransaction terminated!");
        return 0;
    }
    return 0;
    



}