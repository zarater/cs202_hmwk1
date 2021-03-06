#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
const int SIZE = 100;
class info 
{
    public:
    info();
    ~info();
    char* initdata(char source[], const char todet[]);//initialize the data passed into arg and return it if it matches
    int display();
	char* n_day();

    protected:

    char* source;
    char* day;//will compare day int function
    char* e;//event title
    char* m;//movie title 
    char* l;//lecture title 
	char* escheduled_event; //event times
	char* mscheduled_event;//event times
	char* lscheduled_event;//event times
};


class node
{
    public:
    node();
    ~node();
    void setnext(node * newnext);// head -> next = temp;
    node*& getnext();//head = head -> next;
    int getdata();
 //   info*& sethead(info* newinfo);//returns data in which is the "head"
    info*& sethead();//returns data in which is the "head"

    protected:
    info *data;//head
    node *next;
};

class schedule
{
    public:
    schedule();//file_extract
    //schedule(const schedule &);
    ~schedule();
    int file_extract();
    int set(char a_day[],char a_e[],char a_m[], char a_l[],char a_escheduled_event[],char a_mscheduled_event[],char a_lscheduled_event[],int x);
    int into_cll(node* tosend);//wrapper converts to cll
    int push(node*);//is a linked list will be converted to cll in wrapper
    int into_aofLLL(node*);//turns into array of LLL
    int display();

    
    protected:
    node* head;
    node** calendar;//array of LLL
	info* allinfo;
    schedule *next;
    int cal_size;
    int r;
};
