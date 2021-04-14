#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"



int main()
{
   int  choice,book,ticket_no,result;
   char *ptrain_no,*pmob_no;
   int*pticket_no;
   Passenger*p;
   add_trains();

   while(1)
   {
       choice=enterchoice();
       if(choice==9)
       {
           exit(0);
       }
       switch(choice)
       {
           case 1:
               clrscr();
               view_trains();
               getch();
                clrscr();

               break;
              case 2:
            p=get_passenger_details();
            clrscr();
            if(p!=NULL)
            {
              ticket_no=book_ticket(*p);
              if(ticket_no==-1)
              {
                  textcolor(LIGHTRED);
                printf("Booking Failed !");
             }
             else{
                 textcolor(LIGHTGREEN);
                printf("Ticket Successfully booked \n Your ticket no is %d ",ticket_no);
             }
             textcolor(WHITE);
             printf("\n\n\nPress any key to go back to the main screen");
             getch();
             clrscr();
          }

            break;
           case 3:
               clrscr();
               ticket_no=accept_ticket_no();
               if(ticket_no!=0)
               {
                   view_ticket(ticket_no);
                   textcolor(LIGHTGREEN);
                   printf("\nPress any key to go back to the main screen..");
                   getch();
                   clrscr();
                   break;

               }

           case 4:
             //get_ticket_no();
                clrscr();
                pmob_no=accept_mob_no();
                if(pmob_no!=NULL)
                {
                    pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
                }
                clrscr();

                 break;
           case 5:
                clrscr();
            view_all_bookings();
            clrscr();

                    break;
           case 6:
          clrscr();
          ptrain_no=accept_train_no();
          if(ptrain_no!=NULL)
          {
              view_booking(ptrain_no);
          }
          clrscr();


            break;
           case 7:
            //cancel_ticket();
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                   printf("Sorry! No tickets booked against ticket no %d",ticket_no);

                }
                else if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("Ticket no %d successfully cancelled",ticket_no);

                }
                   textcolor(WHITE);
                   printf("\n\nPress any key to go back to the main screen..");
                   getch();
                   clrscr();
                   break;

            }

           case 8:
            //cancel_train();
            clrscr();
             ptrain_no=accept_train_no();
               if(ptrain_no!=NULL)
                {
                    result=cancel_train(ptrain_no);
                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                       printf("Sorry! No bookings  against this Train No %s avialable",ptrain_no);

                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Bookings against Train no %s successfully cancelled",ptrain_no);

                    }
                 textcolor(WHITE);
                   printf("\n\nPress any key to go back to the main screen..");
                   getch();
                   clrscr();
                   break;
          }

            default:
                textcolor(LIGHTRED);
                printf("Wrong choice !Try Again\n");
                getch();
                clrscr();
       }

       }
 clrscr();
        return 0;

   }

