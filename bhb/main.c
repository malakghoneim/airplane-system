#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int usercount=0;
int flightcount=0;

typedef struct
{
    int passport;
    char name[100] ;
    int flight;
    int seat;
}user;
user u[50];

typedef struct
{
    int flight;
    char departure[20] ;
    char destination[20];
    int ticket;
}flight;
flight fl[50];

void load()
{
    FILE *f1;
    FILE *f2;
    f1=fopen("user_info.txt","r");
    if(f1==NULL)
        printf("cannot find file\n");
    while(!feof(f1))
    {
      fscanf(f1,"%d,",&u[usercount].passport);
      fscanf(f1,"%[^,],",u[usercount].name);
      fscanf(f1,"%d,",&u[usercount].flight);
      fscanf(f1,"%d\n",&u[usercount].seat);
      usercount++;

    }
    fclose(f1);
    f2=fopen("flight_info.txt","r");
    if(f2==NULL)
        printf("cannot find file\n");
    while(!feof(f2))
    {
        fscanf(f2,"%d,",&fl[flightcount].flight);
        fscanf(f2,"%[^,],",fl[flightcount].departure);
        fscanf(f2,"%[^,],",fl[flightcount].destination);
        fscanf(f2,"%d\n",&fl[flightcount].ticket);
        flightcount++;
    }
    fclose(f2);

}

void adduser()
{
    FILE *f1;
    f1=fopen("user_info.txt","a");
    user us;
    printf("--ADD USER--\n\n");
    printf("Passport number:\n");
    scanf("%d",&us.passport);
    printf("Name:\n");
    scanf("%s",us.name);
    printf("Flight number:\n");
    scanf("%d",&us.flight);
    printf("Seat number:\n");
    scanf("%d",&us.seat);
    u[usercount]=us;
    usercount++;
    fprintf(f1,"%d,%s,%d,%d\n",u[usercount-1].passport,u[usercount-1].name,u[usercount-1].flight,u[usercount-1].seat);
    fclose(f1);

}

void addflight()
{

    FILE *f2;
    f2=fopen("flight_info.txt","a");

    printf("--ADD NEW FLIGHT--\n\n");
    printf("Flight number:\n");
    scanf("%d",&fl[flightcount].flight);
    printf("Departure:\n");
    scanf("%s",fl[flightcount].departure);
    printf("Destination:\n");
    scanf("%s",fl[flightcount].destination);
    printf("Ticket price:\n");
    scanf("%d",&fl[flightcount].ticket);
    flightcount++;
        fprintf(f2,"%d,%s,%s,%d\n",fl[flightcount-1].flight,fl[flightcount-1].departure,fl[flightcount-1].destination,fl[flightcount-1].ticket);
    fclose(f2);
}

void displayflights()
{
    printf("--DISPLAY FLIGHTS--\n\n");
    int i;
    printf("Flight number\tDeparture\tDestination\tTicket price\n");
    for(i=0;i<flightcount;i++)
    {
        printf("%-17d%-17s%-17s%-17d\n",fl[i].flight,fl[i].departure,fl[i].destination,fl[i].ticket);
    }
}

void displayusers()
{
    int i;
    printf("--DISPLAY USERS INFO--\n\n");
    printf("Passport number\t    Name\t       Flight number\t Seat number\n");
    for(i=0;i<usercount;i++)
        printf("%-19d%-21s%-19d%-19d\n",u[i].passport,u[i].name,u[i].flight,u[i].seat);

}

void print_users_sorted()
{
    user temp;
    int i,j,k;
    for(i=0;i<usercount-1;i++)
    {
        for(j=0;j<usercount-1-i;j++)
        {
            if(strcasecmp(u[j].name,u[j+1].name)>0)
            {
                temp = u[j];
                u[j]=u[j+1];
                u[j+1]=temp;
            }
        }
    }
    printf("--DISPLAY USERS INFO SORTED BY NAME--\n\n");
     printf("Passport number\t    Name\t       Flight number\t Seat number\n");
    for(k=0;k<usercount;k++)
    printf("%-19d%-21s%-19d%-19d\n",u[k].passport,u[k].name,u[k].flight,u[k].seat);

}

void print_flights_sorted()
{
    flight temp;
    int i,j,k;
    for(i=0;i<flightcount;i++)
    {
        for(k=0;k<flightcount-i-1;k++)
        {
            if(fl[k].flight>fl[k+1].flight)
        {
            temp=fl[k];
            fl[k]=fl[k+1];
            fl[k+1]=temp;
        }
        }
    }
    printf("--DISPLAY FLIGHTS' INFO SORTED BY FLIGHT NUMBER\n\n");
     printf("Flight number\tDeparture\tDestination\tTicket price\n");
    for(j=0;j<flightcount;j++)
    {
        printf("%-17d%-17s%-17s%-17d\n",fl[j].flight,fl[j].departure,fl[j].destination,fl[j].ticket);
    }

}

void searchflight()
{
    int x,i;
    printf("--SEARCH FOR A FLIGHT--\n\n");
    printf("Enter flight number\n");
    scanf("%d",&x);
    for(i=0;i<flightcount;i++)
    {
        if(x==fl[i].flight)
        {
            printf("--Flight details you searched for--\n");
            printf("Flight number\tDeparture\tDestination\tTicket price\n");
            printf("%-17d%-17s%-17s%-17d\n",fl[i].flight,fl[i].departure,fl[i].destination,fl[i].ticket);


        }
    }
}

void sumandaverage()
{
    int i,sum=0;
    float av;
    printf("--SUM AND AVERAGES OF TICKET PRICES--\n\n");
    for(i=0;i<flightcount;i++)
        sum=sum+ fl[i].ticket;
    printf("sum=%d\n",sum);
    av=sum*1.0/flightcount;
    printf("Average=%f",av);
}



int main()
{
    int c;
    load();

    printf("Malak Abdelhamid Abobakr Ghoneim 19200476\n");
    printf("  ---AIRLINE RESERVATION SYSTEM DATABASE---  \n\n");
    printf("Choose your option\n");
    printf("1-Add user\n");
    printf("2-Add flight\n");
    printf("3-Display flights\n");
    printf("4-Display users\n");
    printf("5-Sort users' info by name\n");
    printf("6-Sort flights by flight number\n");
    printf("7-Search for a flight using flight number\n");
    printf("8-Display sum and average of all tickets' price\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        adduser();
        break;
    case 2:
        addflight();
        break;
    case 3:
        displayflights();
        break;
    case 4:
        displayusers();
        break;
    case 5:
        print_users_sorted();
        break;
    case 6:
        print_flights_sorted();
        break;
    case 7:
        searchflight();
        break;
    case 8:
        sumandaverage();
        break;
    default:
        printf("No option with this number please try again\n");

    }

    return 0;
}
