#include "schedule.h"



node :: node(): next(NULL), source(NULL), day(NULL), e(NULL), m(NULL), l(NULL), escheduled_event(NULL), mscheduled_event(NULL), lscheduled_event(NULL)
{}

node :: ~node()
{
	if(next)
		delete next;

		if(day)
	delete  day;
if(e)
	delete e;
if(m)
	delete m;
if(l)
	delete l;
if(escheduled_event)
	delete escheduled_event;
if(mscheduled_event)
	delete mscheduled_event;
if(lscheduled_event)
	delete lscheduled_event;
}

char* node:: n_day()
{
	char b_day[] = "somestuff";
	day = new char[strlen(b_day)];
		strcpy(day,b_day);
		cout << day << endl;
		return day;
}
char* node :: initdata(char source[], const char todet[])
{
	if(strcmp(todet, "day")==0)
	{
		if(day){delete day;}//day is null and if day will check if stuff exitsts
		day = new char[strlen(source)];
		strcpy(day, source);
		return day;
	}
	if(strcmp(todet, "e")==0)
	{
		if (e){delete e;}
		e = new char[strlen(source)];
		strcpy(e, source);
		return e;
	}
	if(strcmp(todet, "m")==0)
	{
		if (m){delete m;}
		m = new char[strlen(source)];
		strcpy(m, source);
		return m;
	}
	if(strcmp(todet, "l")==0)
	{
		if (l){delete l;}
		l = new char[strlen(source)];
		strcpy(l, source);
		return l;
	}
	if(strcmp(todet, "esched")==0)
	{
		if (escheduled_event){delete escheduled_event;}
		escheduled_event = new char[strlen(source)];
		strcpy(escheduled_event, source);
		return escheduled_event;
	}
	if(strcmp(todet, "msched")==0)
	{
		if (mscheduled_event){delete mscheduled_event;}
		mscheduled_event = new char[strlen(source)];
		strcpy(mscheduled_event, source);
		return mscheduled_event;
	}
	if(strcmp(todet, "lsched")==0)
	{
		if (lscheduled_event){delete lscheduled_event;}
		lscheduled_event = new char[strlen(source)];
		strcpy(lscheduled_event, source);
		return lscheduled_event;
	}
	return NULL;
}

int node :: display()
{
	cout << day << endl;
	cout << e << endl;
	cout << m << endl;
	cout << l << endl;
	cout << escheduled_event << endl;
	cout << mscheduled_event << endl;
	cout << lscheduled_event << endl;
	return 1;
}


void node :: setnext(node * newnext)
{
	next = newnext; 
}

node *& node :: getnext()
{
	return next;
}

int node :: getdata()
{
	display();
	return 1;
}


schedule :: schedule(): r(0), head(NULL), next(NULL),cal_size(6)
{
	calendar = new node *[cal_size];

    for(int i = 0; i<cal_size; ++i)
	{
		calendar[i] = NULL;
	}

	//calendar = NULL;

    file_extract();
}


schedule :: ~schedule()
{
	if(head) delete head;
	if(next) delete next;
        for(int n = 0; n<cal_size; ++n)
		{
        delete calendar[n];
		}
		//delete calendar;
}

    /*
    //TODO
	copy constructor
	schedule :: schedule(const schedule &){}
    */
int  schedule :: file_extract()
{
	char a_day[100];
	char a_e[100];
	char a_m[100];
	char a_l[100];
	char a_escheduled_event[100];
	char a_mscheduled_event[100];
	char a_lscheduled_event[100];

	int x = 0;

	ifstream file_in;
	file_in.open("schedule.txt");

	if(!file_in) {
		cout << "error" <<endl;
	}

	while(!file_in.eof())
	{

		file_in.get(a_day, 100, '{'); file_in.ignore();
		file_in.get(a_e, 100, ':'); file_in.ignore();
		file_in.get(a_escheduled_event, 100, ':'); file_in.ignore();
		file_in.get(a_m, 100, ':'); file_in.ignore();
		file_in.get(a_mscheduled_event, 100, ':'); file_in.ignore();
		file_in.get(a_l, 100, ':'); file_in.ignore();
		file_in.get(a_lscheduled_event, 100, '\n'); file_in.ignore();
		file_in.get();
		/*
		cout << a_day << endl;
		cout << a_e << endl;
		cout << a_escheduled_event << endl;
		cout << a_m << endl;
		cout << a_mscheduled_event << endl;
		cout << a_l << endl;
		cout << a_lscheduled_event << endl;
		*/
	set(a_day, a_e, a_m, a_l, a_escheduled_event, a_mscheduled_event, a_lscheduled_event,x);
    
	}
	file_in.close();
return 1;
}
int schedule :: set(char a_day[],char a_e[],char a_m[], char a_l[],char a_escheduled_event[],char a_mscheduled_event[],char a_lscheduled_event[],int x)
{
	node *temp = new node;
	temp -> initdata(a_day, "day");
	temp -> initdata(a_e, "e");
	temp -> initdata(a_m, "m");
	temp -> initdata(a_l, "l");
	temp -> initdata(a_escheduled_event,"esched");
	temp -> initdata(a_mscheduled_event, "msched");
	temp -> initdata(a_lscheduled_event, "lsched");
	into_aofLLL(temp);
    into_cll(temp);
		++x;
        r=x;
 return x;
}
int schedule :: into_cll(node* tosend)
{
	push(tosend);
	return 1;
}

int schedule :: push(node* filled_node)
{
	node* temp = filled_node;
	
	if(!head)
	{
		head = temp;
		head -> setnext(NULL); // head -> next = NULL;
		return 1;
	}
	temp -> setnext(NULL); //temp -> next = NULL;
	head -> setnext(temp); //head -> next = temp;
	head = temp;
	head = head -> getnext();//head = head -> next;
    return 1;
}
int schedule :: into_aofLLL(node * filled_node)
{
	//int r will be allocated when x iterates in set function i = 0 - 6
	node * temp = filled_node;
	if(calendar[r] == NULL)
	{
		calendar[r] = new node;
		calendar[r]= temp;
		return 1;
	}
 return 1;
}

int schedule :: display()
{
	cout << "day" << endl;
	//head ->getdata();
	
	return 1;
}

