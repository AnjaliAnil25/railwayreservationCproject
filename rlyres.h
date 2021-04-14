#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];

};
typedef struct Train Train;
typedef struct Passenger Passenger;
int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
     int check_train_no(char *);//trainno as arg if train exist 1
     Passenger* get_passenger_details();//returns the add of passeng stuct variable/null
     int get_booked_ticket_count(char*,char);//ret no.of tickets booked in train in class
     int last_ticket_no();//ret ticktno of last booked ticket
     int check_mob_no(char*);
int *get_ticket_no(char *);
void view_ticket(int);
    int accept_ticket_no();
void view_all_bookings();
    char*accept_mob_no();   //it uses check_mob_no and get_ticket_no
    void view_all_tickets(char*,int*);
void view_booking(char *);
char*accept_train_no();
int check_train_no(char*);

int cancel_ticket(int);
int cancel_train(char*);


#endif // RLYRES_H_INCLUDED
