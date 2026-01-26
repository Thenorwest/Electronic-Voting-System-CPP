#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<ctype.h>
#include<ctime>
#include<unistd.h>
using namespace std;
time_t current_time ;
void get_current_time()
{
     current_time = time(nullptr);        //total seconds from 1/1/1900 00:00:00
}
void print_current_time()
{
        // Get the current time
    get_current_time();        

    // Convert to a local time
    tm* local_time = localtime(&current_time);
   

    // Extract the components
    int c_seconds = local_time->tm_sec;
    int c_minutes = local_time->tm_min;
    int c_hours = local_time->tm_hour;
    int c_day = local_time->tm_mday;
    int c_month = local_time->tm_mon + 1; // Add 1 to convert from 0-based to 1-based
    int c_year = local_time->tm_year + 1900; // Add 1900 to get the actual year

    
    cout << "Current time: " << c_hours << ":" << c_minutes << ":" << c_seconds << endl;
    cout << "Current date: " << c_day << "/" << c_month << "/" << c_year << endl;
}

bool isConvertibleToInt(const std::string& str) {
    try {
        // Attempt to convert the string to an integer
        int num = std::stoi(str);

        // Conversion successful, the string can be converted to an integer
        return true;
    } catch (const std::exception& e) {
        // Conversion failed, the string cannot be converted to an integer
        return false;
    }
}

void capital(string& a)
{
    int i=0;
    while(a[i])
    {
        a[i]=char(toupper(a[i]));
        i++;
    }
}
string get_first_word(string a)
{
    size_t pos=a.find(" ");
    string temp;
    temp=a.substr(0,pos);
    return temp;
}
string get_second_word(string a)
{
    size_t pos1=a.find(" ");
    size_t pos2=a.find(" ",pos1+1);
    string temp;
    temp=a.substr(pos1+1,pos2-pos1-1);
    return temp;
}
string get_third_word(string a)
{
    size_t pos1=a.find(" ");
    size_t pos2=a.find(" ",pos1+1);
    size_t pos3=a.find(" ",pos2+1);
    string temp;
    temp=a.substr(pos2+1,pos3-pos2-1);
    return temp;
}

bool check_file(string sn)
{
    string line;
    fstream file;
    file.open("signs.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        line=get_first_word(line);
        if(sn==line)
        {
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}

class Person
{
    int age;
    string cnic;
    string province;
    string name;
    string f_name;
    public:
    Person(int a=0,string c="",string p="",string n="",string fn="")
    {
        if(a<0)
        {
            age=0;
        }
        else
        age=a;
        cnic=c;
        province=p;
        name=n;
        f_name=fn;
    }

    //getters

    int getage()
    {
        return age;
    }
    string getcnic()
    {
        return cnic;
    }
    string getprovince()
    {
        return province;
    }
    string getname()
    {
        return name;
    }
    string getf_name()
    {
        return f_name;
    }

    //setters

    void setage(int a)
    {
        if(age<0)
        {
            age=0;
        }
        age=a;
    }
    void setcnic(string c)
    {
        cnic=c;
    }
    void setprovince(string p)
    {
        province=p;
    }
    void setname(string n)
    {
        name=n;
    }
    void setf_name(string n)
    {
        f_name=n;
    }
};
class Voter
{
    Person details;
    int seat_mna;
    int seat_mpa;
    string vote_mna;
    string vote_mpa;
    string phone;
    public:
    Voter():details()
    {
        seat_mna=0;
        seat_mpa=0;
        vote_mna="";
        vote_mpa="";
        phone="123";
    }
    //setters

    void setage(int a)
    {
        details.setage(a);
    }
    void setcnic(string c)
    {
        details.setcnic(c);
    }
    void setprovince(string p)
    {
        details.setprovince(p);
    }
    void setname(string n)
    {
        details.setname(n);
    }
    void setfname(string f)
    {
        details.setf_name(f);
    }
    void set_seats(int mna,int mpa)
    {
        seat_mna=mna;
        seat_mpa=mpa;
    }
    void set_votes(string mna,string mpa)
    {
        vote_mna=mna;
        vote_mpa=mpa;
    }
    void setphone(string ph)
    {
        phone=ph;
    }

    //getters

    int getage()
    {
        return details.getage();
    }
    string getcnic()
    {
       return details.getcnic();
    }
    string getprovince()
    {
        return details.getprovince();
    }
    string getname()
    {
        return details.getname();
    }
    string getfname()
    {
        return details.getf_name();
    }
    int get_mna_seat()
    {
        return seat_mna;
    }
    int get_mpa_seat()
    {
        return seat_mpa;
    }
    string get_mna_vote()
    {
        return vote_mna;
    }
    string get_mpa_vote()
    {
        return vote_mpa;
    }
    string getphone()
    {
        return phone;
    }

    //other methods

    bool check_age(int a)
    {
        if(a<18)
        {
            return 0;
        }
        else
        return 1;
    }
    bool vote_checking(string cnic)         //used to check whether this user has vote already or not
    {
        string temp;
        fstream check;
        check.open("v_cnic.txt",ios::in);
        while(check.eof()==0)
        {
            getline(check,temp);
            if(cnic==temp)
            {
                check.close();
                return 1;
            }
        }
        check.close();
        return 0;
    }
    void update_in_file()
    {
        fstream file;
        file.open("v_details.txt",ios::app);            //updating voter details file
        file<<"\n\nCNIC: "<<details.getcnic()<<endl;
        file<<"***MNA Seat: "<<seat_mna<<endl;
        file<<"MNA Vote: "<<vote_mna<<endl;
        file<<"Province: "<<details.getprovince();
        file<<"***MPA Seat: "<<seat_mpa<<endl;
        file<<"MPA Vote: "<<vote_mpa<<endl;
        file<<"Name: "<<details.getprovince()<<endl;
        file<<"Father's Name: "<<details.getf_name()<<endl;
        file<<"Age: "<<details.getage()<<endl;
        file<<"Phone: "<<phone<<endl;
        file.close();
        
        fstream c_file;         //updating voter cnic file
        c_file.open("v_cnic.txt",ios::app);
        c_file<<details.getcnic()<<endl;
        c_file.close();
    }
    void increment_vote_mna()
    {
        string data,data_temp;
        fstream file1,temp;
        file1.open("mna.txt",ios::in | ios::out);
        temp.open("temp.txt",ios::in | ios::out);
        while(file1.eof()==0)
        {
            getline(file1,data);
            temp<<data<<endl;
        }
            file1.close();
            temp.close();
            file1.open("mna.txt",ios::in | ios::out);
            temp.open("temp.txt",ios::in | ios::out );
            while (temp.eof()==0)
            {
                getline(temp,data);
                    file1<<data<<endl; 
                    data_temp=get_first_word(data);        //extracting first word
                    
                    if(data_temp=="**Seat")
                    {
                        int number;      //for integer getting for comparison
                        data_temp=get_second_word(data);
                        number=stoi(get_third_word(data));         //this is actually seat number
                        
                        if(number==seat_mna)
                        {
                            while(data_temp!="**Seat" && temp.eof()==0)
                            {
                                
                                getline(temp,data);
                                file1<<data<<endl;
                                data_temp=data.substr((data.find(" "))+1);     //words after first word

                                
                                if(data_temp==vote_mna)
                                {
                                    for(int i=1;i<=6;i++)       //other details of candidate
                                    {
                                        getline(temp,data);
                                        file1<<data<<endl;
                                    }
                                    getline(temp,data);
                                    data_temp=get_first_word(data);
                                    number=stoi(get_second_word(data));     //votes
                                    ++number;                              //add one vote
                                    file1<<data_temp<<" "<<number<<endl;
                                    while (temp.eof()==0)
                                    {
                                        getline(temp,data);
                                        file1<<data<<endl;
                                    }
                                    file1.close();
                                    temp.close();
                                    return;
                                }
                                else
                                {
                                    data_temp=get_first_word(data);
                                    continue;
                                }
                            }
                            while (temp.eof()==0)
                            {
                                getline(temp,data);
                                file1<<data<<endl;
                            }
                                file1.close();
                                temp.close();
                                return;
                            
                        }
                        else
                        {
                            
                            continue;   //if seat no not matcha
                        }
                        
                    }
                    else
                    {
                                 
                        continue;       //if seat word not match
                    }
            }
            
    }
    void increment_vote_mpa()
    {
        string data,data_temp;
        fstream file1,temp;
        file1.open("mpa.txt",ios::in | ios::out);
        temp.open("temp.txt",ios::in | ios::out);
        while(file1.eof()==0)
        {
            getline(file1,data);
            temp<<data<<endl;
        }
            file1.close();
            temp.close();
            file1.open("mpa.txt",ios::in | ios::out);
            temp.open("temp.txt",ios::in | ios::out );
            while(temp.eof()==0)
            {
                    getline(temp,data);
                    file1<<data<<endl;
                    data_temp=get_first_word(data);
                    if(data_temp=="***Province:")
                    {
                        
                        data_temp=get_second_word(data);     //getting second word after province
                        if(data_temp==details.getprovince())
                        {
                            
                            while(temp.eof()==0)
                            {
                                getline(temp,data);
                                file1<<data<<endl; 
                                data_temp=get_first_word(data);        //extracting first word
                    
                                if(data_temp=="**Seat")
                                {
                                    int number;      //for integer getting for comparison
                                    data_temp=get_second_word(data);
                                    number=stoi(get_third_word(data));         //this is actually seat number
                        
                                    if(number==seat_mpa)
                                    {
                                        while(data_temp!="**Seat" && temp.eof()==0)
                                        {
                                
                                            getline(temp,data);
                                            file1<<data<<endl;
                                            data_temp=data.substr((data.find(" "))+1);     //words after first word

                                
                                            if(data_temp==vote_mpa)
                                            {
                                                for(int i=1;i<=6;i++)       //other details of candidate
                                                {
                                                    getline(temp,data);
                                                    file1<<data<<endl;
                                                }
                                                getline(temp,data);
                                                data_temp=get_first_word(data);
                                                number=stoi(get_second_word(data));     //votes
                                                ++number;                              //add one vote
                                                file1<<data_temp<<" "<<number<<endl;
                                                while (temp.eof()==0)
                                                {
                                                        getline(temp,data);
                                                        file1<<data<<endl;
                                                }
                                                file1.close();
                                                temp.close();
                                                return;
                                            }
                                            else
                                            {
                                                data_temp=get_first_word(data);
                                                continue;
                                            }
                                        }
                                        while (temp.eof()==0)
                                        {
                                            getline(temp,data);
                                            file1<<data<<endl;
                                        }
                                            file1.close();
                                            temp.close();
                                            return;
                            
                                    }
                                    else
                                    {
                            
                                        continue;   //if seat no not match
                                    }
                        
                                }
                                else
                                {
                                 
                                    continue;       //if seat word not match
                                }
                            }       
                        }
                    }
            
            
            }

    }
};
class Time
{
    int seconds;
    int minutes;
    int hours;
    public:
    Time()
    {
        seconds=0;
        minutes=0;
        hours=1;
    }

    //setters

    void setseconds(int s)
    {
        if(s>60 || s<0)
        {
            seconds=0;
        }
        else
        seconds=s;
    }
    void setminutes(int m)
    {
        if(m>60 || m<0)
        {
            minutes=0;
        }
        else
        minutes=m;
    }
    void sethours(int h)
    {
        if(h>23 || h<0)
        {
            hours=0;
        }
        else
        hours=h;
    }

    //getters

    int getseconds()
    {
        return seconds;
    }
    int getminutes()
    {
        return minutes;
    }
    int gethours()
    {
        return hours;
    }

    //other methods
};
class Date
{
    int day;
    int month;
    int year;
    Time time;
    public:
    Date():time()
    {
        day=1;
        month=1;
        year=1990;
    }
    
    //setters

    void setseconds(int s)
    {
        time.setseconds(s);
    }
    void setminutes(int m)
    {
        time.setminutes(m);
    }
    void sethours(int h)
    {
        time.sethours(h);
    }
    void setday(int d)
    {
        if(d<1 || d>31)
        day=1;
        else
        day=d;
    }
    void setmonth(int m)
    {
        if(m<1 || m>12)
        month=1;
        else
        month=m;
    }
    void setyear(int y)
    {
        year=y;
    }

    //getters

    int getseconds()
    {
       return time.getseconds();
    }
    int getminutes()
    {
        return time.getminutes();
    }
    int gethours()
    {
       return time.gethours();
    }
    int getday()
    {
        return day;
    }
    int getmonth()
    {
        return month;
    }
    int getyear()
    {
        return year;
    }

    //other methods
    

    bool start_time_checking(const int& y,const int& m,const int &d,const int& hr,const int& min,const int& sec)
    {

        if(y>year || y==year)
        {
            if(m>=month ||(m<month && y>year))
            {
                if(d>=day || (d<day && (m>month || y>year)))
                {
                    if(hr>=time.gethours())
                    {
                        if(min>=time.getminutes() ||(min<time.getminutes() && hr>time.gethours()))
                        {
                            if(sec>=time.getseconds() || (sec<time.getseconds() && (min>time.getminutes() || hr>time.gethours())))
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;       
            }
        }
        else
        {
            return 0;       //wrong date because start is greater than end time
        }
    }

    bool end_time_checking(const int& y,const int& m,const int &d,const int& hr,const int& min,const int& sec)
    {
        // Get the current time
        get_current_time();         

        // Convert to a local time
        tm* local_time = localtime(&current_time);      //tm is a structure
        
        // Extract the components
        int c_seconds = local_time->tm_sec;
        int c_minutes = local_time->tm_min;
        int c_hours = local_time->tm_hour;
        int c_day = local_time->tm_mday;
        int c_month = local_time->tm_mon + 1; // Add 1 to convert from 0-based to 1-based
        int c_year = local_time->tm_year + 1900; // Add 1900 to get the actual year

        if(y>c_year || y==c_year)
        {
            if(m>=c_month ||(m<c_month && y>c_year))
            {
                if(d>=c_day || (d<c_day && (m>c_month || y>c_year)))
                {
                    if(hr>=c_hours)
                    {
                        if(min>=c_minutes ||(min<c_minutes && hr>c_hours))
                        {
                            if(sec>=c_seconds || (sec<c_seconds && (min>c_minutes || hr>c_hours)))
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;       //because month is in Past
            }
        }
        else
        {
            return 0;       //wrong date because date is in Past
        }
    }

    bool check()
    {
        // Get the current time
        get_current_time();         

        // Convert to a local time
        tm* local_time = localtime(&current_time);      //tm is a structure
        
        // Extract the components
        int c_seconds = local_time->tm_sec;
        int c_minutes = local_time->tm_min;
        int c_hours = local_time->tm_hour;
        int c_day = local_time->tm_mday;
        int c_month = local_time->tm_mon + 1; // Add 1 to convert from 0-based to 1-based
        int c_year = local_time->tm_year + 1900; // Add 1900 to get the actual year

        if(year>c_year || year==c_year)
        {
            if(month>=c_month ||(month<c_month && year>c_year))
            {
                if(day>=c_day || (day<c_day && (month>c_month || year>c_year)))
                {
                    if(time.gethours()>=c_hours)
                    {
                        if(time.getminutes()>=c_minutes ||(time.getminutes()<c_minutes && time.gethours()>c_hours))
                        {
                            if(time.getseconds()>=c_seconds || (time.getseconds()<c_seconds && (time.getminutes()>c_minutes || time.gethours()>c_hours)))
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;       //because month is in Past
            }
        }
        else
        {
            return 0;       //wrong date because date is in Past
        }
    }

    void print_Time()
    {
        cout << "Time: " << time.gethours() << ":" << time.getminutes() << ":" << time.getseconds() << endl;
        cout << "Date: " << day << "/" << month << "/" << year << endl; 
    }
};
class Candidate
{
    Person details;
    string type;
    string party;
    string sign;
    int count;
    string address;
    string phone;
    int seat;
    public:
    Candidate(int a=1,string c="",string p="",string n="",string t="",string f="",string pt="",string s="",int ct=0,string add="",string pn="123",int st=1):details(a,c,p,n,f)
    {
        type=t;
        party=pt;
        sign=s;
        if(ct<0)
        {
            count=0;
        }
        else
        count=ct;
        address=add;
        phone=pn;
        seat=st;
    }

    //setters

    void setage(int a)
    {
        details.setage(a);
    }
    void setcnic(string c)
    {
        details.setcnic(c);
    }
    void setprovince(string p)
    {
        details.setprovince(p);
    }
    void setname(string n)
    {
        details.setname(n);
    }
    void settype(string t)
    {
        type=t;
    }
    void setfname(string f)
    {
        details.setf_name(f);
    }
    void setparty(string p)
    {
        party=p;
    }
    void setsign(string s)
    {
        sign=s;
    }
    void setcount(int c)
    {
        if(c<0)
        {
            count=0;
        }
        else
        count=c;
    }
    void setaddress(string a)
    {
        address=a;
    }
    void setphone(string p)
    {
        phone=p;
    }
    void setseat(int s)
    {
        seat=s;
    }

    //getters

    int getage()
    {
        return details.getage();
    }
    string getcnic()
    {
       return details.getcnic();
    }
    string getprovince()
    {
        return details.getprovince();
    }
    string getname()
    {
        return details.getname();
    }
    string gettype()
    {
        return type;;
    }
    string getfname()
    {
        return details.getf_name();
    }
    string getparty()
    {
        return party;
    }
    string getsign()
    {
        return sign;
    }
    int getcount()
    {
        return count;
    }
    string getaddress()
    {
        return address;
    }
    string getphone()
    {
        return phone;
    }
    int getseat()
    {
        return seat;
    }

    // other methods

    void update_file()
    {
        string data;
        string data_temp;
        fstream temp,file1;
        
        if(check_seat_in_file())        //if it is 1 then we will rewrite file with new entry
        {
            
            if(type=="MNA")
            {
                file1.open("mna.txt",ios::in | ios::out);
                temp.open("temp.txt",ios::in | ios::out);
                while(file1.eof()==0)
                {
                    getline(file1,data);
                    temp<<data<<endl;
                }
                file1.close();
                temp.close();
                file1.open("mna.txt",ios::in | ios::out);
                temp.open("temp.txt",ios::in | ios::out );  
                while(temp.eof()==0)
                {
                    getline(temp,data);
                    file1<<data<<endl; 
                    data_temp=get_first_word(data);        //extracting first word
                    
                    if(data_temp=="**Seat")
                    {
                        int number;      //for integer getting for comparison
                        
                        number=stoi(get_third_word(data));         //this is actually seat number
                        
                        if(number==seat)
                        {
                            file1<<endl;
                            file1<<"Party: "<<party<<endl;
                            file1<<"Sign: "<<sign<<endl;
                            file1<<"Name: "<<details.getname()<<endl;
                            file1<<"Father's Name: "<<details.getf_name()<<endl;
                            file1<<"Cnic: "<<details.getcnic()<<endl;
                            file1<<"Age: "<<details.getage()<<endl;
                            file1<<"Phone No: "<<phone<<endl;
                            file1<<"Address: "<<address<<endl;
                            file1<<"Votes: "<<0<<endl;
                            while(temp.eof()==0)
                            {
                                getline(temp,data);
                                file1<<data<<endl;
                            }
                            file1.close();
                            temp.close();
                            return;
                        }
                        else
                        {
                            
                            continue;   //if seat no not match
                        }
                        
                    }
                    else
                    {
                                 
                        continue;       //if seat word not match
                    }
                    
                }
            }
            else
            {
                file1.open("mpa.txt",ios::in | ios::out);
                temp.open("temp.txt",ios::in | ios::out);
                while(file1.eof()==0)
                {
                    getline(file1,data);
                    temp<<data<<endl;
                }
                file1.close();
                temp.close();
                file1.open("mpa.txt",ios::in | ios::out);
                temp.open("temp.txt",ios::in | ios::out );     

                while(temp.eof()==0)
                {
                    getline(temp,data);
                    file1<<data<<endl;
                    data_temp=get_first_word(data);
                    if(data_temp=="***Province:")
                    {
                        
                        data_temp=get_second_word(data);     //getting second word after province
                        if(data_temp==details.getprovince())
                        {
                            
                            while(temp.eof()==0)
                            {
                                
                                getline(temp,data);
                                data_temp=get_first_word(data);
                                if(data_temp=="***Province:" || temp.eof()==1)
                                {
                                        
                                        file1<<"**Seat No: "<<seat<<" *****"<<endl<<endl;
                                        file1<<"Party: "<<party<<endl;
                                        file1<<"Sign: "<<sign<<endl;
                                        file1<<"Name: "<<details.getname()<<endl;
                                        file1<<"Father's Name: "<<details.getf_name()<<endl;
                                        file1<<"Cnic: "<<details.getcnic()<<endl;
                                        file1<<"Age: "<<details.getage()<<endl;
                                        file1<<"Phone No: "<<phone<<endl;
                                        file1<<"Address: "<<address<<endl;
                                        file1<<"Votes: "<<0<<endl;
                                        file1<<endl;
                                        
                                        Add_Seat(seat,details.getprovince(),type);

                                        while(temp.eof()==0)
                                        {
                                            file1<<data<<endl;
                                            getline(temp,data);
                                            if(temp.eof()==1)
                                            {
                                                file1<<data<<endl;
                                            }
                                        }
                                        file1.close();
                                        temp.close();
                                        return;
                                }
                                file1<<data<<endl;
                                
                                
                                if(data_temp=="**Seat")
                                {
                                    int number;
                                    
                                    number=stoi(get_third_word(data));        //this is actually seat number
                                    
                                    if(number==seat)
                                    {
                                        file1<<endl;
                                        file1<<"Party: "<<party<<endl;
                                        file1<<"Sign: "<<sign<<endl;
                                        file1<<"Name: "<<details.getname()<<endl;
                                        file1<<"Father's Name: "<<details.getf_name()<<endl;
                                        file1<<"Cnic: "<<details.getcnic()<<endl;
                                        file1<<"Age: "<<details.getage()<<endl;
                                        file1<<"Phone No: "<<phone<<endl;
                                        file1<<"Address: "<<address<<endl;
                                        file1<<"Votes: "<<0<<endl<<endl;
                                        while(temp.eof()==0)
                                        {
                                            getline(temp,data);
                                            file1<<data<<endl;
                                        }
                                        file1.close();
                                        temp.close();
                                        return;
                                    }
                                    
                                }
                               
                                
                            }
                        }
                        else
                        {
                            
                            continue;
                        }
                        
                        
                    }
                    else
                    continue;       //when Province: word not found
                }
            }
            
        }
        else        //if above function return zero then we will just append file
        {
            fstream file;
                        if(type=="MNA")
                        {
                            file.open("mna.txt",ios::app);
                            
                            file<<"\n**Seat No: "<<seat<<" *****"<<endl<<endl;
                            file<<"Party: "<<party<<endl;
                            file<<"Sign: "<<sign<<endl;
                            file<<"Name: "<<details.getname()<<endl;
                            file<<"Father's Name: "<<details.getf_name()<<endl;
                            file<<"Cnic: "<<details.getcnic()<<endl;
                            file<<"Age: "<<details.getage()<<endl;
                            file<<"Phone No: "<<phone<<endl;
                            file<<"Address: "<<address<<endl;
                            file<<"Votes: "<<0<<endl;
                            file.close();

                            Add_Seat(seat,details.getprovince(),type);
                        }
                        else
                        {
                            file.open("mpa.txt",ios::app);
                            
                            file<<"***Province: "<<details.getprovince()<<" **********"<<endl<<endl;
                            file<<"**Seat No: "<<seat<<" *****"<<endl<<endl;
                            file<<"Party: "<<party<<endl;
                            file<<"Sign: "<<sign<<endl;
                            file<<"Name: "<<details.getname()<<endl;
                            file<<"Father's Name: "<<details.getf_name()<<endl;
                            file<<"Cnic: "<<details.getcnic()<<endl;
                            file<<"Age: "<<details.getage()<<endl;
                            file<<"Phone No: "<<phone<<endl;
                            file<<"Address: "<<address<<endl;
                            file<<"Votes: "<<0<<endl;
                            file.close();

                            Add_Seat(seat,details.getprovince(),type);
                        }
        }
    }

    void Add_Seat(int s,string prov,string t)
{
    fstream file;
    if(t=="MNA")
    {
        file.open("MNA_SEATS/seats.txt",ios::app);
        file<<s<<endl;
        file.close();
    }
    else if(prov=="BALOCHISTAN")
    {
        file.open("MPA_SEATS/balochistan.txt",ios::app);
        file<<s<<endl;
        file.close();
    }
    else if(prov=="PUNJAB")
    {
        file.open("MPA_SEATS/punjab.txt",ios::app);
        file<<s<<endl;
        file.close();
    }
    else if(prov=="SINDH")
    {
        file.open("MPA_SEATS/sindh.txt",ios::app);
        file<<s<<endl;
        file.close();
    }
    else if(prov=="KPK")
    {
        file.open("MPA_SEATS/kpk.txt",ios::app);
        file<<s<<endl;
        file.close();
    }
}
    
    
    bool check_seat_in_file()       //checking whether given seat no is already available in file or not
    {
        string temp;
        int s_temp;
        ifstream file;
        if(type=="MNA")
        {
            file.open("mna.txt");
            while(file.eof()==0)
            {
                file>>temp;
                if(temp=="**Seat")
                {
                    file>>temp;             //avoid No: string
                    file>>s_temp;
                    if(s_temp==seat)
                    {
                        file.close();
                        return 1;
                    }   
                    else
                    {
                        continue;
                    }
                }
            }
            file.close();
            return 0;
        }
        else
        {
            file.open("mpa.txt");
            while(file.eof()==0)
            {
                file>>temp;
                if(temp=="***Province:")
                {
                    file>>temp;
                    if(temp==details.getprovince())
                    {
                        
                        
                        file.close();
                        return 1;           //if province found still we need to modify file in between so that's why returning 1
                    }
                    
                }
                
                
            }
            file.close();
            return 0;       //seat not available
        }
    }


};
class Election
{
    Candidate c_entry;      //Political Candidate Entry
    Voter v_entry;          //Voter Entry
    Date start_time,end_time;            //Voting Time
    public:
    Election():c_entry(),v_entry(),start_time(),end_time()         //no parameterized constructors needed
    {

    }
    void Register_Candidate()
    {
        int ag;
        string c;
        string prov;
        string nm;
        string tp;
        string f_nm;
        string pty;
        string sn;
        int ct;
        string add;
        string ph;
        int st;
        cout<<"\n\n\t\t\t****** Please Type Correctly and Carefully ******\n\n";
        cout<<"\nEnter age of candidate:  ";
        cin>>ag;
        if(ag<25)               //because for MNA and MPA you must be 25+ years old
        {
            cout<<"\n\n\t\t\t****** You are not eligible your age is less than 25 ******\n\n";
            return;
        }
        else
        {
            cout<<"Enter Province of him\\her in voting:  ";
            cin>>prov;
            capital(prov);
            cout<<"Enter Seat No:   ";
            cin>>st;
            cout<<"Enter Type of Candidate (MNA or MPA):  ";
            cin>>tp;
            capital(tp);
            if(check_seat(prov,st,tp)==0)
            {
                cout<<"\n\n\t\t\t****** Invalid seat please try again ******\n\n";
            }
            else
            {
                cout<<"\nEnter sign of candidate:  ";
                cin>>sn;
                capital(sn);
                
                if(check_sign(prov,st,tp,sn)==1)
                {
                    cout<<"\n\n\t\t\t****** Sign Already Available in this Seat please try again ******\n\n";
                }
                else
                {
                    getchar();
                    cout<<"Enter Party Name:  ";
                    getline(cin,pty);
                    capital(pty);
                    cout<<"Enter Name: ";
                    getline(cin,nm);
                    capital(nm);
                    cout<<"Enter Father Name: ";
                    getline(cin,f_nm);
                    capital(f_nm);
                    cout<<"Enter Cnic: ";
                    getline(cin,c);
                    cout<<"Enter Address:  ";
                    getline(cin,add);
                    capital(add);
                    cout<<"Enter Phone Number:  ";
                    getline(cin,ph);

                    //passing to data members

                    c_entry.setage(ag);
                    c_entry.setcnic(c);
                    c_entry.setprovince(prov);
                    c_entry.setname(nm);
                    c_entry.setfname(f_nm);
                    c_entry.settype(tp);
                    c_entry.setparty(pty);
                    c_entry.setsign(sn);
                    c_entry.setseat(st);
                    c_entry.setaddress(add);
                    c_entry.setphone(ph);

                    //saving sign in one file

                    if(!check_file(sn))
                    {
                        fstream file;
                        file.open("signs.txt",ios::app);
                        file<<sn<<" "<<0<<endl;
                        file.close();
                    }

                    //now puting in file

                    c_entry.update_file();
                    cout<<"\n\n\t\t\t****** Candidate is Registered ******\n\n"; 
                    
                }
            }
        }
    }

void get_results(string& sign,int seat, string type,string province)
    {
        //we are getting result through 1 variables which are passed by reference
          //  we get return through sign variable
        
        int m2=0,m3=0;
        int votes=0;          // here votes is used as maximum
        string p,p2=" ",p3=" ";
        sign=" ";        // and sign is used as sign with most votes
        string line,temp;
        fstream display;
        if(type=="MNA")
        {
            display.open("mna.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="**Seat")
                {
                    int temp1;
                    temp=get_second_word(line);     //to avoid below loop condition
                    temp1=stoi(get_third_word(line));
                    if(temp1==seat)
                    {
                        
                        while(temp!="**Seat" && display.eof()==0)
                        {
                            if(temp=="Sign:")
                            {
                            
                                p=get_second_word(line);
                            }
                            if(temp=="Votes:")
                            {
                                
                                temp1=stoi(get_second_word(line));
                                if(temp1>votes)
                                {
                                    m3=m2;
                                    p3=p2;

                                    m2=votes;
                                    p2=sign;

                                    votes=temp1;
                                    sign=p;
                                }
                                
                            }
                            
                            getline(display,line);
                            temp=get_first_word(line);
                        }
                        
                        display.close();
                        return;
                        
                    }
                }
            }
            display.close();
            
        }
        else
        {
            display.open("mpa.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="***Province:")
                {
                    temp=get_second_word(line);
                    if(temp==province)
                    {
                        while(temp!="***Province:" && display.eof()==0)
                        {
                            getline(display,line);
                            temp=get_first_word(line);
                            if(temp=="**Seat")
                            {
                                int temp1;
                                temp=get_second_word(line);     //to avoid below loop condition
                                temp1=stoi(get_third_word(line));
                                if(temp1==seat)
                                {
                                    
                                    while(temp!="**Seat" && display.eof()==0)
                                    {
                                        
                                        if(temp=="Sign:")
                                        {
                                        
                                            p=get_second_word(line);
                                        }
                                        if(temp=="Votes:")
                                        {
                                            
                                            temp1=stoi(get_second_word(line));
                                            if(temp1>votes)
                                            {
                                                m3=m2;
                                                p3=p2;

                                                m2=votes;
                                                p2=sign;

                                                votes=temp1;
                                                sign=p;
                                            }
                                        }
                            
                                        getline(display,line);
                                        temp=get_first_word(line);
                                    }
                                    
                                
                                    display.close();
                                    return;
                                }
                            }
                        }
                    }

                }
            }
            display.close();
        }
    }



void Declare_results()
{
    string line;
    string sign="";
    int seat;
    fstream file;
    file.open("MNA_SEATS/seats.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        
        if(isConvertibleToInt(line))
        {
            seat=stoi(get_first_word(line));
            
            get_results(sign,seat,"MNA"," ");
            
            increment_total(sign);
            
        }
        
    }
    
    file.close();
    
    file.open("MPA_SEATS/kpk.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        if(isConvertibleToInt(line))
        {
            seat=stoi(get_first_word(line));
            get_results(sign,seat,"MPA","KPK");
            increment_total(sign);
        }
        
    }
    
    file.close();
    file.open("MPA_SEATS/balochistan.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        if(isConvertibleToInt(line))
        {
            seat=stoi(get_first_word(line));
            get_results(sign,seat,"MPA","BALOCHISTAN");
            increment_total(sign);
        }
        
    }
    file.close();
    
    file.open("MPA_SEATS/punjab.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        if(isConvertibleToInt(line))
        {
            seat=stoi(get_first_word(line));
            get_results(sign,seat,"MPA","PUNJAB");
            increment_total(sign);
        }
        
    }
    file.close();
    
    file.open("MPA_SEATS/sindh.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        if(isConvertibleToInt(line))
        {
            seat=stoi(get_first_word(line));
            get_results(sign,seat,"MPA","SINDH");
            increment_total(sign);
        }
        
    }
    file.close();
    
    for(int i=5;i>=1;i--)
    {
        system("cls");
        sleep(1);
        cout<<"\n\n\t\t"<<i;
        sleep(1);
    }
    sleep(1);
    system("cls");
    int number;

    sign=getWinner(number);
    cout<<"\n\n\n\t\t\t*************** HAPPY GOVERNMENT TO "<<sign<<" who have won "<<number<<" seats *************\n\n\n"<<endl;
    Display_signs();
    
}

string getWinner(int& votes)
{   //one value is returning through input which is pass by pass by reference
    string line;
    int max=0,temp;
    string m_sign=" ";
    fstream file;
    file.open("signs.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        if(isConvertibleToInt(line))
        {
            temp=stoi(get_second_word(line));
        if(temp>max)
        {
            max=temp;
            m_sign=get_first_word(line);
        }
        }
        
        
    }
    file.close();
    votes=max;
    return m_sign;
}
void Display_signs()
{
    string line;
    int seats;
    fstream file;
    file.open("signs.txt",ios::in);
    while(file.eof()==0)
    {
        getline(file,line);
        line=get_first_word(line);
        if(isConvertibleToInt(line))
        {
             seats=stoi(get_second_word(line));
            cout<<"\n\n********Sign: "<<line<<"\nSeats Won: "<<seats<<endl<<endl;
        }
       
    }
    file.close();
}

void increment_total(string sign)
{
    
    string line,word;
    int n1;
    fstream file,temp;
    file.open("signs.txt",ios::in | ios::out);
    temp.open("temp.txt",ios::in | ios::out);
    while(file.eof()==0)
    {
        
        getline(file,line);
        temp<<line<<endl;
    }
    
    
    file.close();
    temp.close();
    
    file.open("signs.txt",ios::in | ios::out);
    temp.open("temp.txt",ios::in | ios::out);
    while(temp.eof()==0)
    {
        getline(temp,line);
        word=get_first_word(line);
        
        if(word==sign)
        {
            if(isConvertibleToInt(line))
            {
                n1=stoi(get_second_word(line));
                ++n1;
            
                file<<word<<" "<<n1<<endl;
            }
            
        }
        else
        {
           
            file<<line<<endl;
        }
    }
}
    
    void show_results()         //displaying top 3
    {
        string province,type;
        int seat;
        cout<<"\nEnter Seat No: ";
        cin>>seat;
        getchar();
        
        cout<<"Enter Province: ";
        getline(cin,province);
        capital(province);
        cout<<"Enter Type: ";
        getline(cin,type);
        capital(type);
            
        
        int m1=0,m2=0,m3=0;
        string p,p1="",p2="",p3="";
        string line,temp;
        fstream display;
        if(type=="MNA")
        {
            display.open("mna.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="**Seat")
                {
                    int temp1;
                    temp=get_second_word(line);     //to avoid below loop condition
                    temp1=stoi(get_third_word(line));
                    if(temp1==seat)
                    {
                        
                        while(temp!="**Seat" && display.eof()==0)
                        {
                            if(temp=="Sign:")
                            {
                            cout<<"\n\n*****"<<line<<endl;
                                p=get_second_word(line);
                            }
                            if(temp=="Votes:")
                            {
                                cout<<line<<endl;
                                temp1=stoi(get_second_word(line));
                                if(temp1>m1)
                                {
                                    m3=m2;
                                    p3=p2;

                                    m2=m1;
                                    p2=p1;

                                    m1=temp1;
                                    p1=p;
                                }
                                else if(temp1>m2)
                                {
                                    m3=m2;
                                    p3=p2;

                                    m2=temp1;
                                    p2=p;
                                }
                                else if(temp1>m3)
                                {
                                    m3=temp1;
                                    p3=p;
                                }
                            }
                            
                            getline(display,line);
                            temp=get_first_word(line);
                        }
                        sleep(8);
                        cout<<"\n\n******** Top 3\n\n";
                        cout<<"1) "<<p1<<endl;
                        cout<<"Votes: "<<m1<<endl<<endl<<endl;
                        cout<<"2) "<<p2<<endl;
                        cout<<"Votes: "<<m2<<endl<<endl<<endl;
                        cout<<"3) "<<p3<<endl;
                        cout<<"Votes: "<<m3<<endl<<endl<<endl;
                        display.close();
                        return;
                        
                    }
                }
            }
            display.close();
            
        }
        else
        {
            display.open("mpa.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="***Province:")
                {
                    temp=get_second_word(line);
                    if(temp==province)
                    {
                        while(temp!="***Province:" && display.eof()==0)
                        {
                            getline(display,line);
                            temp=get_first_word(line);
                            if(temp=="**Seat")
                            {
                                int temp1;
                                temp=get_second_word(line);     //to avoid below loop condition
                                temp1=stoi(get_third_word(line));
                                if(temp1==seat)
                                {
                                    
                                    while(temp!="**Seat" && display.eof()==0)
                                    {
                                        
                                        if(temp=="Sign:")
                                        {
                                        cout<<"\n\n*****"<<line<<endl;
                                            p=get_second_word(line);
                                        }
                                        if(temp=="Votes:")
                                        {
                                            cout<<line<<endl;
                                            temp1=stoi(get_second_word(line));
                                            if(temp1>m1)
                                            {
                                                m3=m2;
                                                p3=p2;

                                                m2=m1;
                                                p2=p1;

                                                m1=temp1;
                                                p1=p;
                                            }
                                            else if(temp1>m2)
                                            {
                                                m3=m2;
                                                p3=p2;

                                                m2=temp1;
                                                p2=p;
                                            }
                                            else if(temp1>m3)
                                            {
                                                m3=temp1;
                                                p3=p;
                                            }
                                        }
                            
                                        getline(display,line);
                                        temp=get_first_word(line);
                                    }
                                    sleep(8);
                                    cout<<"\n\n******** Top 3\n\n";
                                    cout<<"1) "<<p1<<endl;
                                    cout<<"Votes: "<<m1<<endl<<endl<<endl;
                                    cout<<"2) "<<p2<<endl;
                                    cout<<"Votes: "<<m2<<endl<<endl<<endl;
                                    cout<<"3) "<<p3<<endl;
                                    cout<<"Votes: "<<m3<<endl<<endl<<endl;
                                
                                    display.close();
                                    return;
                                }
                            }
                        }
                    }

                }
            }
            display.close();
        }
    }

    void voting()
    {
        //setting time
        set_time();

        //now start voting

        while(1)
        {
            system("cls");
            if(!start_time.check())
            {  
                cout<<"Vote Starting: ";
                sleep(5);
                cout<<"Please Wait: ";
                sleep(5);
                for(int i=3;i>=1;i--)
                {
                    system("cls");
                    sleep(1);
                    cout<<"\n\n\t\t"<<i;
                    sleep(1);
                }
                sleep(1);
                system("cls");

                while(end_time.check())
                {
                    int age, s_mna, s_mpa;
                    string name,f_name,cnic,province,phone,mna_v,mpa_v;
                    system("cls");
                    cout<<"\nEnter Age: ";
                    cin>>age;
                    getchar();
                    if(v_entry.check_age(age))
                    {
                        cout<<"\nEnter Cnic: ";
                        getline(cin,cnic);
                        if(v_entry.vote_checking(cnic))
                        {
                            cout<<"\n\n\t\t\t****** You have Already voted ******\n\n";
                        }
                        else
                        {
                            cout<<"\nEnter Province: ";
                            getline(cin,province);
                            capital(province);
                            cout<<"\nEnter Name: ";
                            getline(cin,name);
                            capital(name);
                            cout<<"\nEnter Father's Name: ";
                            getline(cin,f_name);
                            capital(f_name);
                            while(1)
                            {
                                cout<<"\nEnter your Seat No for MNA seat vote: ";
                                cin>>s_mna;
                                getchar();
                                if(check_seat(province,s_mna,"MNA"))            //checking seat is correct or not
                                {
                                    Display_Candidates(s_mna,province,"MNA");
                                    cout<<"\n\nEnter Sign for vote: ";
                                    getline(cin,mna_v);
                                    capital(mna_v);

                                    if(!check_sign(province,s_mna,"MNA",mna_v))
                                    {
                                            cout<<"\n\n\t\t\t****** Sign not available in the MNA Seat No: "<<s_mna<<" please  try again ******\n\n";
                                                continue;
                                    }
                                    system("cls");
                                    cout<<"\nEnter your Seat No for MPA seat vote: ";
                                    cin>>s_mpa;
                                    getchar();
                                    if(check_seat(province,s_mpa,"MPA"))
                                    {
                                        
                                            Display_Candidates(s_mpa,province,"MPA");
                                            cout<<"\n\nEnter Sign for vote: ";
                                            getline(cin,mpa_v);
                                            capital(mpa_v);
                                            if(!check_sign(province,s_mpa,"MPA",mpa_v))
                                            {
                                                cout<<"\n\n\t\t\t****** Sign not available please in MPA the seat No: "<<s_mpa<<" try again ******\n\n";
                                                
                                            }
                                            
                                        
                                        if(!end_time.check())       //when time is not finished
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            system("cls");

                                            //setting value to class
                                            v_entry.setage(age);
                                            v_entry.setcnic(cnic);
                                            v_entry.setprovince(province);
                                            v_entry.setname(name);
                                            v_entry.setfname(f_name);
                                            v_entry.set_seats(s_mna,s_mpa);
                                            v_entry.set_votes(mna_v,mpa_v);


                                            v_entry.update_in_file();       //update values in files

                                            v_entry.increment_vote_mna();       //add vote to mna

                                            v_entry.increment_vote_mpa();       //add vote to mpa

                                            cout<<"\n\n\t\t\t****** You have successfully Voted to MNA: "<<mna_v<<" and MPA: "<<mpa_v<<" ******\n\n";
                                            sleep(10);
                                            break;                                                                           
                                        }
                                        
                                        
                                    }
                                    else
                                    {
                                        cout<<"\n\n\t\t\t****** Incorrect Seat Try Again ******\n\n";
                                    }
                                }
                                else
                                {
                                        cout<<"\n\n\t\t\t****** Incorrect Seat Try Again ******\n\n";
                                }
                            }
                        }
                    }
                    else
                    {
                        cout<<"\n\n\t\t\t****** You are not eligible your age is less than  18 ******\n\n";
                        sleep(3);
                        continue;
                    }
                }
                cout<<"\n\n******";
                print_current_time();
                cout<<"\n\n******Voting Ending Time********"<<endl;
                end_time.print_Time();
                cout<<"\n\n******VOTING TIME IS FINISHED";
                sleep(6);
                break;
            }
            else
            {
                cout<<"\n\n******";
                print_current_time();
                cout<<"\n\n******Voting Starting Time********"<<endl;
                start_time.print_Time();
                cout<<"\n\n******Please Wait********"<<endl;
                sleep(1);
                continue;
            }
        }
    }
    void set_time()
    {
        int y,m,d,hr,min,sec;

        //Entering Starting Time
        
            cout<<"\nEnter Starting Time and Date:\n";
            cout<<"\nEnter Day: ";
            cin>>d;
            cout<<"\nEnter Month: ";
            cin>>m;
            cout<<"\nEnter Year: ";
            cin>>y;
            cout<<"\nEnter Hour: ";
            cin>>hr;
            cout<<"\nEnter Minute: ";
            cin>>min;
            cout<<"\nEnter Second: ";
            cin>>sec;
            
        

        //passing to variable

        start_time.setday(d);
        start_time.setmonth(m);
        start_time.setyear(y);
        start_time.sethours(hr);
        start_time.setminutes(min);
        start_time.setseconds(sec);

        //Entering Ending Time

        while(1)
        {
            cout<<"\nEnter Ending Time and Date:\n";
            cout<<"\nEnter Day: ";
            cin>>d;
            cout<<"\nEnter Month: ";
            cin>>m;
            cout<<"\nEnter Year: ";
            cin>>y;
            cout<<"\nEnter Hour: ";
            cin>>hr;
            cout<<"\nEnter Minute: ";
            cin>>min;
            cout<<"\nEnter Second: ";
            cin>>sec;
            
            if(start_time.start_time_checking(y,m,d,hr,min,sec)==1)
            {
                if(end_time.end_time_checking(y,m,d,hr,min,sec)==1)
                {
                    break;
                }
                else
                {
                    
                    cout<<"\n\n\t\t\t*****The time is already over Please Insert Time correctly******\n\n"<<endl;
                    cout<<"Current Time is\n";
                    print_current_time();
                    continue;
                }
            }
            else
            {
                
                cout<<"\n\n\t\t\t*****The time is before start time Please Insert Time correctly******\n\n"<<endl;
                cout<<"Starting Time is\n";
                start_time.print_Time();
                continue;
            }
            
        }
        

        //passing to variable

        end_time.setday(d);
        end_time.setmonth(m);
        end_time.setyear(y);
        end_time.sethours(hr);
        end_time.setminutes(min);
        end_time.setseconds(sec);
    }

    void Display_Candidates(int st,string prov,string tp)
    {
        string line,temp;
        fstream display;
        if(tp=="MNA")
        {
            display.open("mna.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="**Seat")
                {
                    int temp1;
                    temp=get_second_word(line);     //to avoid below loop condition
                    temp1=stoi(get_third_word(line));
                    if(temp1==st)
                    {
                        cout<<"\n\n****** MNA Candidates  ********\n\n";
                        while(temp!="**Seat" && display.eof()==0)
                        {
                            
                            cout<<line<<endl;
                            getline(display,line);
                            temp=get_first_word(line);
                        }
                        display.close();
                        return;
                        
                    }
                }
            }
            display.close();
            
        }
        else
        {
            display.open("mpa.txt",ios::in);
            while(display.eof()==0)
            {
                getline(display,line);
                temp=get_first_word(line);
                if(temp=="***Province:")
                {
                    temp=get_second_word(line);
                    if(temp==prov)
                    {
                        while(temp!="***Province:" && display.eof()==0)
                        {
                            getline(display,line);
                            temp=get_first_word(line);
                            if(temp=="**Seat")
                            {
                                int temp1;
                                temp=get_second_word(line);     //to avoid below loop condition
                                temp1=stoi(get_third_word(line));
                                if(temp1==st)
                                {
                                    cout<<"\n\n****** MPA Candidates  ********\n\n";
                                    while(temp!="**Seat" && display.eof()==0)
                                    {
                                        
                                        cout<<line<<endl;
                                        getline(display,line);
                                        temp=get_first_word(line);
                                    }
                                    display.close();
                                    return;
                                }
                            }
                        }
                    }

                }
            }
            display.close();
        }
    }

    bool check_sign(string p,int s,string t,string sn)          // for checking sign if it is already available on specific seat or not, 1 will show available and 0 for not available
{
        
        string temp,temp_s;
        fstream file;
        if(t=="MNA")
        {
            file.open("mna.txt",ios::in);
            while(file.eof()==0)
            {
                getline(file,temp);
                temp_s=get_first_word(temp);
                if(temp_s=="**Seat")
                {
                    int temp1;
                    temp_s=get_second_word(temp);       //just to run below loop
                    temp1=stoi(get_third_word(temp));             //taking number of seat for checking exact seat


                    if(temp1==s)
                    {
                        while(temp_s!="**Seat" && file.eof()==0)         //continue untill next seat arrives
                        {
                            getline(file,temp);         
                            
                            temp_s=get_first_word(temp);
                            if(temp_s=="Sign:");
                            {
                                temp_s=temp.substr((temp.find(" "))+1);     //words after first word
                                
                                if(temp_s==sn)
                                {
                                    file.close();
                                    return 1;
                                }
                                
                            } 
                        }
                        file.close();
                        return 0;           //if sign not that found in that seat
                        

                    }
                    else
                    {
                        continue;           //if seat not matches
                    }
                }
                else
                {
                    continue;       //if word is not seat
                }
            }
            file.close();
            return 0;       //because file became finished and sign not found
        }
        else
        {
           file.open("mpa.txt",ios::in);
            while(file.eof()==0)
            {
                getline(file,temp);
                temp_s=get_first_word(temp);
                if(temp_s=="***Province:")
                {
                    temp_s=get_second_word(temp);
                    
                    
                    if(temp_s==p)
                    {
                        
                        while(temp_s!="***Province:" && file.eof()==0)
                        {
                            getline(file,temp);
                            temp_s=get_first_word(temp);
                            
                            if(temp_s=="**Seat")
                            {
                                int temp1;
                                temp_s=get_second_word(temp);       //just to run below loop
                                temp1=stoi(get_third_word(temp));        //because we  will be comparing int
                                
                                if(temp1==s)
                                {
                                    while(temp_s!="**Seat" && file.eof()==0)         //continue untill next seat arrives
                                    {
                                        getline(file,temp);         
                            
                                        temp_s=get_first_word(temp);
                                        
                                        if(temp_s=="Sign:");
                                        {
                                            temp_s=temp.substr((temp.find(" "))+1);     //words after first word

                                            
                                            if(temp_s==sn)
                                            {
                                                file.close();
                                                return 1;
                                            }
                                
                                        }
                                    }
                                    file.close();
                                    return 0;           //if sign not that found in that seat
                                }   
                                else
                                {           
                                    continue;       //if not specific seat
                                }
                            }
                            else
                            {
                                
                                continue;   //if not seat word
                            }
                            
                        }
                        file.close();
                        return 0;           //if sign in not found in a whole province
                    }
                   
                }
                
                
            } 
            file.close();
            return 0;       //whole file finished but not found
        }
    }

   bool check_seat(string p,int s,string t)        //for checking seat if it is accurate or not with type and province, 1 will show accurate and 0 will show incorrect seat
    {
        if(t=="MNA")        //first checking mna seat no number
        {
            if(s>=1 && s<=336)
            {
                return 1;
            }
            else 
            return 0;
        }
        else if(t=="MPA")       //then checking of mpa seat no
        {
            if(p=="KPK")
            {
                if(s>=1 && s<=145)
                {
                    return 1;
                }
                else 
                return 0;
            }
            else if(p=="PUNJAB")
            {
                if(s>=1 && s<=371)
                {
                    return 1;
                }
                else
                return 0;
            }
            else if(p=="SINDH")
            {
                if(s>=1 && s<=168)
                {
                    return 1;
                }
                else
                return 0;
            }
            else if(p=="BALOCHISTAN")
            {
                if(s>=1 && s<=65)
                {
                    return 1;
                }
                else
                return 0;
            }
            else
            return 0;
        }
        else
        return 0;
    }
 
};
class Administrator
{
    int id;
    int pass;
    public:
    Administrator()
    {
        fstream file;
        file.open("system.txt",ios::in);
        file>>id;
        file>>pass;
        file.close();
    }
    int getid()
    {
        return id;
    }
    int getpass()
    {
        return pass;
    }
    void change_id_pass()           //password changing of owner
    {
        int i,p;
        cout<<"Enter old id: ";
        cin>>i;
        cout<<"Enter old pass: ";
        cin>>p;
        if(i==id&&p==pass)
        {
            cout<<"\nEnter New Id: ";
            cin>>id;
            cout<<"Enter New Pass: ";
            cin>>pass;
            change_in_file();       //changing in file in order to use again when program restart
        }
        else
        {
            cout<<"\nIncorrect id and Pass\nTry Again!\n";
        }
    }
    void change_in_file()
    {
        fstream file;
        file.open("system.txt",ios::out);
        file<<id<<endl<<pass;
        file.close();
    }
};
int main()
{
    Administrator admin;
    Election election;
    int i,p;
    int option;

    //Password Entering Loop
    do 
    {
    cout<<"Enter Id: ";
    cin>>i;
    if(i==0)        //by default value to terminate program 
    {
        break;
    }
    if(i!=admin.getid())
    {
        cout<<"Incorrect Id, Please Try Again"<<endl;
        continue;
    }
    cout<<"Enter Pass: ";
    cin>>p;

    //if password matches then proceed
    if(p==admin.getpass())      //checking with owner pass in order to use the program
    {  

              //loop for owner for menu driven 
      
                do
                {
                    //Menu driven for owner
                    cout<<"\n\n\n1)Start Voting\n2)Register Politician\n3)Check Specific Result/filter\n4)Declare Result\n5)Change Password\nEnter Option: ";
                    cin>>option;
                    if(option==1)
                    {
                        election.voting();
                    }
                    else if(option==2)
                    {
                        election.Register_Candidate();
                    }
                    else if(option==3)
                    {
                        election.show_results();
                    }
                    else if(option==4)
                    {
                        election.Declare_results();
                    }
                    else if(option==5)
                    {
                        admin.change_id_pass();
                    }
                    else if(option==0)
                    {
                        system("cls");
                        break;
                    }
                    else
                    {
                        cout<<"\nInvalid Option\nEnter Again!\n";
                    }
                        } 
                        while (1);
                
                
        
    }
    else            //if user type id and pass incorrect
    {
        cout<<"\nIncorrect Pass\nPlease Try Again!\n";
        continue;
    }
    }
    while(1);
}