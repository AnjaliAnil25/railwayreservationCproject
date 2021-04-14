#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
#include<errno.h>
int enterchoice()
{
    int choice,i;
     gotoxy(28,1);
    textcolor(LIGHTMAGENTA);
printf("RAILWAY RESERVATION SYSTEM\n");
    textcolor(YELLOW);
       for(i=1;i<80;i++)
    printf("-");
    printf("\nSelect an option");
    printf("\n1-View Trains");
    printf("\n2-Book Ticket");
    printf("\n3-View Ticket");
    printf("\n4-Search Ticket Number");
    printf("\n5-View all Bookings");
    printf("\n6-View Trians Bookings");
    printf("\n7-Cancel Ticket");
    printf("\n8-Cancel Train");
    printf("\n9-Quit");
    printf("\n\nEnter Choice:");
    scanf("%d",&choice);
    return choice;
}
void add_trains()
{
    FILE*fp=fopen("e:\\textfile\\ alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]=
        {
{"123","BPL","GWA",2100,1500},

              {"546","BPL","DEL",3500,2240},

              {"345","HBJ","AGR",1560,1135},

              {"896","HBJ","MUM",4500,3360},

              };

        fp=fopen("e:\\textfile\\ alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
         fclose(fp);
    }
    else
    {
        fclose(fp);
    }
    }

void view_trains()
{
    int i;
    for(i=1;i<81;i++)
        printf("-");
        textcolor(LIGHTBLUE);
    printf("TRAIN NO\tFROM\t TO\t FIRSTAC FARE\t SECOND AC FARE\n");
    textcolor(YELLOW);
        for(i=1;i<80;i++)
        printf("-");
        FILE *fp=fopen("e:\\textfile\\ alltrains.dat","rb");
        Train tr;
        while(fread(&tr,sizeof(tr),1,fp)==1)
            {
                printf("\n%s\t\t%s\t%s\t  %d\t\t  %d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
        }
                  printf("\n\n\n\n");
             textcolor(WHITE);
             printf("Press any key to go back to the main screen");
             fclose(fp);

}

Passenger* get_passenger_details()
{
     clrscr();
     gotoxy(60,1);
     textcolor(LIGHTGREEN);
     printf("Press 0 to EXIT..");
     textcolor(YELLOW);
      static Passenger psn;
      gotoxy(1,1);
    printf("Enter Passenger Name:");
    fflush(stdin);
     textcolor(LIGHTCYAN);
     fgets(psn.p_name,20,stdin);
     char*pos;
     pos=strchr(psn.p_name,'\n');
     *pos='\0';
     if(strcmp(psn.p_name,"0")==0)
     {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("Reservation Cancelled !");
         getch();
         textcolor(LIGHTCYAN);
         clrscr();
         return NULL;
    }
    int valid;
     textcolor(YELLOW);
    printf("\nEnter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
         textcolor(LIGHTCYAN);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
        textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("Reservation Cancelled !");
         getch();
         textcolor(LIGHTCYAN);
         clrscr();
         return NULL;
        }
        if(psn.gender!='M' && psn.gender!='F')
        {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("ERROR ! Gender Should Be M or F (in uppercase) !..");
             valid=0;
             getch();
             gotoxy(19,3);
             printf(" \b");
             textcolor(LIGHTCYAN);
        }
    } while(valid==0);

            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,5);
             textcolor(YELLOW);
            printf("Enter Train no:");
            do
            {
                fflush(stdin);
                 textcolor(LIGHTCYAN);
                scanf("%s",&psn.train_no);
                if(strcmp(psn.train_no,"0")==0)
                {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled !");
                getch();
                textcolor(LIGHTCYAN);
                clrscr();
                return NULL;
            }
            valid=check_train_no(psn.train_no);         //functn call
            if(valid==0)
            {
                 textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("ERROR ! Invalid Train Number!..");
                getch();
                gotoxy(16,5);
                printf("\t\t\t");
                gotoxy(16,5);
                textcolor(LIGHTCYAN);

            }

    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
     textcolor(YELLOW);
    gotoxy(1,7);
    printf("Enter travelling class(First AC-F,Second AC-S):");
     do
    {
        valid=1;
        fflush(stdin);
         textcolor(LIGHTCYAN);
        scanf("%c",&psn.p_class);
        if(psn.gender=='0')
        {
        textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t");
         printf("Reservation Cancelled !");
         getch();
         textcolor(LIGHTCYAN);
         clrscr();
         return NULL;
        }
        if(psn.p_class!='F' && psn.p_class!='S')
        {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("ERROR ! Travelling class Should Be F or S (in uppercase) !..");
             valid=0;
             getch();
             gotoxy(48,7);
             printf(" \b");
             textcolor(LIGHTCYAN);
        }
    } while(valid==0);
gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
     textcolor(YELLOW);
    gotoxy(1,9);
    printf("Enter address:");
    fflush(stdin);
     textcolor(LIGHTCYAN);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
     if(strcmp(psn.address,"0")==0)
        {
        textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("Reservation Cancelled !");
         getch();
         textcolor(LIGHTCYAN);

         return NULL;
        }
        gotoxy(1,11);
 textcolor(YELLOW);
   printf("Enter Age:");
    do
    {
        valid=1;
        fflush(stdin);
         textcolor(LIGHTCYAN);
        scanf("%d",&psn.age);
         if(psn.age==0)
        {
        textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t");
         printf("Reservation Cancelled !");
         getch();
         textcolor(LIGHTCYAN);

         return NULL;
        }
        if(psn.age<0 || psn.age>=126)
        {
            textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("ERROR ! Age should be positive and valid..");
             valid=0;
             getch();
             gotoxy(11,11);
             printf("\t\t\t\t\t");
             gotoxy(11,11);
             textcolor(LIGHTCYAN);
        }
    }while(valid==0);
     gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
     textcolor(YELLOW);
    gotoxy(1,13);
    printf("Enter mobile number:");
    do
    {
                fflush(stdin);
                 textcolor(LIGHTCYAN);
                fgets(psn.mob_no,12,stdin);
                pos=strchr(psn.mob_no,'\n');
                if(pos!=NULL)
                    *pos='\0';
                if(strcmp(psn.mob_no,"0")==0)
                {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                printf("Reservation Cancelled !");
                getch();
                textcolor(LIGHTCYAN);

                return NULL;
            }
            valid= check_mob_no(psn.mob_no);        //functn call
            if(valid==0)
            {
                 textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("ERROR ! Invalid mobile Number!..");
                getch();
                gotoxy(21,13);
                printf("\t\t\t\t\t\t\t\t\t\t\t");
                gotoxy(21,13);
                textcolor(LIGHTCYAN);

            }
    }while(valid==0);

       return &psn;
    }


int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10 )
        return 0;
   while(*p_mob!='\0')
   {
       if(isdigit(*p_mob)==0)//if digit returns a non zero value otherwise return 0
        return 0;
       p_mob++;
   }
   return 1;

   }



int check_train_no(char*trainno)
{
    Train tr;
    FILE*fp=fopen("e:\\textfile\\ alltrains.dat","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;

}
int get_booked_ticket_count(char*train_no,char tc)
{
    FILE *fp=fopen("e:\\textfile\\ allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count =0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
            ++count;
    }
    fclose(fp);
    return count;

}
int last_ticket_no()
{
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}
int book_ticket(Passenger p)
{
    int  ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
   {
       textcolor(LIGHTRED);
        printf("All seats in train no %s in class %c are full ",p.train_no,p.p_class);
    return -1;
   }
   int ticket_no=last_ticket_no()+1;
   p.ticketno=ticket_no;
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","ab");
    if(fp==NULL)
      {
          textcolor(LIGHTRED);
          printf("Sorry ! File cannot be opened");
          return -1;
      }
      fwrite(&p,sizeof(p),1,fp);
      fclose(fp);
      return ticket_no;

}
int accept_ticket_no()
{
    printf("Enter ticket no:");
    int valid;
    int ticket_no;
    do
        {

       valid=1;
    scanf("%d",&ticket_no);
    if(ticket_no==0)
    {
        textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                printf("Cancelling Input....!");
                getch();
                textcolor(LIGHTCYAN);
                clrscr();

                return 0;
    }
    if(ticket_no<0)
    {
        textcolor(LIGHTRED);
         gotoxy(1,25);
        printf("Error Ticket number should be positive!");
        getch();
        valid=0;
       gotoxy(24,1);
         printf("\t\t\t\t\t\t");
          gotoxy(24,1);
           textcolor(LIGHTCYAN);

    }
}while(valid==0);
return ticket_no;
}
void view_ticket(int ticket_no)
{
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","rb");
     if(fp==NULL)
     {
         textcolor(LIGHTRED);
         printf("\nNo bookings done yet");
         return ;
     }
     Passenger pr;
     int found=0;
     while(fread(&pr,sizeof(pr),1,fp)==1)
     {
         if(ticket_no==pr.ticketno)
         {
             textcolor(LIGHTCYAN);
             printf("\nName:%s\nGender:%c\nTrain No.:%s\nClass:%c\nAddress:%s\nAge:%d\nMobile No:%s\nTicket No:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
                printf("\n\n");
                found=1;
                break;
         }

     }
      if(!found)    //found==0
      {
           textcolor(LIGHTRED);
                printf("\nNo details of ticket no %d found!",ticket_no);

      }
      fclose(fp);

}

char*accept_mob_no()
{
    static char mob_no[11];
    char*pos;
    int valid;
    printf("Enter Mobile Number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
             textcolor(LIGHTRED);
                         gotoxy(1,25);
                         printf("\t\t\t\t\t\t\t");
                         gotoxy(1,25);
                         printf("Cancelling Input....!");
                         getch();
                          textcolor(LIGHTCYAN);
                          clrscr();
                         return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("ERROR ! Invalid mobile Number!..");
                getch();
                gotoxy(21,1);
                printf("\t\t\t\t\t\t\t\t\t");
                gotoxy(21,1);
                textcolor(LIGHTCYAN);
        }
    }while(valid==0);
    clrscr();
    return mob_no;
}
int *get_ticket_no(char*p_mob_no)
{
    int count=0;
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","rb");
    if(fp==NULL)
        return NULL;
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
    }
        if(!count)//count==0
        {
            fclose(fp);
            return NULL;
        }
        int*p=(int*)malloc((count+1)*sizeof(int));
        rewind(fp);
        int i=0;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
            if(strcmp(pr.mob_no,p_mob_no)==0)
            {
                *(p+i)=pr.ticketno;
                i++;
            }
        }
        *(p+i)=-1;
        fclose(fp);
        return p;
}

void view_all_tickets(char*pmob_no,int*pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nSorry ! No tickets booked against mob no. %s ",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return ;
    }
        printf("Following are the Tickets Booked for Mobile No %s",pmob_no);
    int i;
    textcolor(LIGHTCYAN);
     printf("\n\nTICKET NO\n");
    printf("-----------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
                printf("\n%d",*(pticket_no+i));
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
                textcolor(YELLOW);
                getch();
                free(pticket_no);

}




char* accept_train_no()
{
    static  char train_no[10];
    int valid=1;
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to Exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
             textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelled !");
                getch();
                textcolor(LIGHTCYAN);
                clrscr();
                return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
                 textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("ERROR ! Invalid Train Number!..");
                getch();
                gotoxy(20,1);
                printf("\t\t\t\t\t");
                gotoxy(20,1);
                textcolor(YELLOW);
        }
    }while(valid==0);
    clrscr();

     return train_no;

}
void view_all_bookings()
{
    clrscr();
   int count=0;
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","rb");
    if(fp==NULL)
         {
             textcolor(LIGHTRED);
        printf("\nSorry ! No bookings available now");
         }
    Passenger pr;
    textcolor(LIGHTGREEN);
    printf("Following are the bookings:");
    gotoxy(1,2);
for(int i=1;i<80;i++)
     printf("-");
       while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            textcolor(LIGHTCYAN);
                printf("\nName:%s\nGender:%c\nTrain No.:%s\nClass:%c\nAddress:%s\nAge:%d\nMobile No:%s\nTicket No:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
                printf("\n\n");

}
 textcolor(WHITE);
 printf("\n\nPress any key to go back to the main screen..");
    getch();
    clrscr();

       fclose(fp);
}
void view_booking(char*train_no)
{
    int found=0;
    FILE*fp=fopen("e:\\textfile\\ allbookings.dat","rb");
     if(fp==NULL)
     {
         textcolor(LIGHTRED);
         printf("\nSorry! File cannot be opened");
         return;
     }
     Passenger pr;
     textcolor(LIGHTBLUE);
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(int i=1;i<80;i++)
    {
        printf("-");
    }
    int row =3;
    gotoxy(1,3);
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {

        if(strcmp(pr.train_no,train_no)==0)
        {
            textcolor(YELLOW);
            printf("%d\t\t %c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s",pr.gender,pr.age,pr.mob_no);
            row++;
            getch();
            found=1;

        }
    }
    if(!found)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo details of bookings in train no %s found",train_no);
    }
    textcolor(WHITE);
    printf("\n\nPress any key to continue!");
    textcolor(YELLOW);
    fclose(fp);
    getch();

}
int cancel_train(char*train_no)
{
    clrscr();
     int result;
    extern int errno;
     int found=0;
    FILE*fp1=fopen("e:\\textfile\\ allbookings.dat","rb");
     if(fp1==NULL)
     {
         textcolor(LIGHTRED);
         printf("\nSorry! File cannot be opened");
         return -1;
     }
     FILE*fp2=fopen("e:\\textfile\\ temp.dat","wb");
    Passenger pr;
      while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("e:\\textfile\\ temp.dat");
    }
    else
    {
        result=remove("e:\\textfile\\ allbookings.dat");
        if(result!=0)
         {
             printf("Error code:%d",errno);
             printf("\nReason %s",strerror(errno));
             return 2;
         }
        result=rename("e:\\textfile\\ temp.dat","e:\\textfile\\ allbookings.dat");
          }
    return found;

}


int cancel_ticket(int ticket_no)
{
    clrscr();
    int result;
    extern int errno;
    FILE*fp1=fopen("e:\\textfile\\ allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Bookings Done Yet!");
        return -1;
    }
    FILE*fp2=fopen("e:\\textfile\\ temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("e:\\textfile\\ temp.dat");
    }
    else
    {
        result=remove("e:\\textfile\\ allbookings.dat");
        if(result!=0)
         {
             printf("Error code:%d",errno);
             printf("\nReason %s",strerror(errno));
             return 2;
         }
        result=rename("e:\\textfile\\ temp.dat","e:\\textfile\\ allbookings.dat");
            }
    return found;

}







