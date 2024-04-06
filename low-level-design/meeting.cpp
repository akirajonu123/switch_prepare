#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class history {
    public:
    int room_id;
    string start_time;
    string end_time;

    history(int room_id,string start_time,string end_time)
    {
        this->room_id = room_id;
        this->start_time = start_time;
        this->end_time = end_time;
    }
};
class User{
    private:
    int user_id;
    string name;
    queue<history> History;
    int max_limit;
    public:
    User(){}
    User(string name, int user_id)
    {
        this->max_limit = 20;
        this->name= name;
        this->user_id = user_id;
    }
    string getName()
    {
        return this->name;
    }
    void setHistory(history m)
    {
        cout<<getName()<<"goat"<<endl;
        if(this->max_limit>0)
        {
            History.push(m);
            this->max_limit--;
        }
        else
        {
            History.pop();
            History.push(m);
        }        
    }
    void printHistory()
    {
        cout<<"hola"<<History.size()<<endl;
        cout<<getName()<<"goat"<<endl;
        int n = 20-this->max_limit;
        while(n--)
        {
            history q =History.front();
            cout<<getName()<<" "<<q.room_id<<" "<<q.start_time<<" "<<q.end_time<<endl;
            History.pop();
            History.push(q);
        }      
    }
};

class MeetingRoom
{
    public:
    int room_id;

    bool operator<(const MeetingRoom& m) const
    {
        return this->room_id<m.room_id;
    }
    MeetingRoom()
    {

    }
    MeetingRoom(int i)
    {
        room_id = i;
    }
};
class Meeting{
    public:
    vector<User> attendee;
    MeetingRoom mRoom;
    User user_id;
    string start_time;
    string end_time;
    Meeting(){}
    Meeting(string start_time,string end_time,User user_id,vector<User> attendees,MeetingRoom mRoom)
    {
        this->start_time = start_time;
        this->end_time = end_time;
        this->user_id = user_id;
        for(auto x: attendees)
        {
            this->attendee.push_back(x);
        }
        this->mRoom = mRoom;

    }
};

class Calender{
    public:
    map<MeetingRoom,vector<Meeting> > meet;
    string curr_time;
    map<MeetingRoom,vector<Meeting> > & getMeet()
    {
        return this->meet;
    }
};


class Scheduler
{
    public:
    Scheduler(){}
    int numberOfRooms;
    Calender* c;
    Scheduler(int n)
    {
        numberOfRooms = n;
        c = new Calender();
        //map<MeetingRoom,vector<Meeting> > meets = c->getMeet();
        cout<<c->getMeet().size()<<endl;
        vector<Meeting> v;
        for(int i=1;i<=n;i++)
        {
            MeetingRoom meetingRoom(i);
            c->getMeet().insert(make_pair(meetingRoom,v));
        }
        cout<<c->getMeet().size()<<endl;
        cout<<"constructor scheduler\n";
    }

    MeetingRoom bookMeetingRoom(User &user,vector<User> id,string start_time,string end_time)
    {
        
        //map<MeetingRoom,vector<Meeting> > meets = c->getMeet();
        cout<<c->getMeet().size()<<endl;
        for(auto m:c->getMeet())
        {
            int flag=0;
            for(auto x:m.second)
            {
                if(x.start_time>=end_time ||  x.end_time<=start_time)
                {
                    
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                
                Meeting obj(start_time,end_time,user,id,m.first);
                c->getMeet()[m.first].push_back(obj);
                sendNoti(user,"hello, Please find meet details ",obj);
                cout<<"Booking Confirmed\n";
                history obj1(m.first.room_id,start_time,end_time);
                user.setHistory(obj1);
                return m.first;
            }
        }
        cout<<"No booking\n";
        //return nullptr;
    }   
    void sendNoti(User user,string message,Meeting meeting)
    {
        cout<<user.getName()<<" is organising a meeting.\n";
        for(auto x: meeting.attendee)
        {
            cout<<"Hi! " << x.getName()<<", you are invite to meeting at room " <<meeting.mRoom.room_id <<" from "<<meeting.start_time<<" to "<<meeting.end_time<<endl;
        }
    }

};


int main()
{
    cout<<"Good Luck!"<<endl;
    // string date;
    // int n;
    // cout<<"Enter number of meeting rooms available";
    // cin>>n;
    Scheduler* p = new Scheduler(2);
    // string start_time;
    // string end_time;
    // int capacity;
    // cout<<"Enter the date,time and capacity you want to ";
    // cin>>date>>start_time>>end_time>>capacity;
    User a1("r",0);
    User a2("s",1);
    User a3("t",2);
    User a4("j",3);
    User a5("z",4);
    vector<User> attendee;
    attendee.push_back(a2);
    attendee.push_back(a3);
    attendee.push_back(a4);
    attendee.push_back(a5);
    p->bookMeetingRoom(a1,attendee,"12:30", "18:30");
    p->bookMeetingRoom(a2,attendee,"13:30", "16:30");
    p->bookMeetingRoom(a3,attendee,"10:30", "11:30");
    p->bookMeetingRoom(a4,attendee,"10:30", "11:30");
    p->bookMeetingRoom(a5,attendee,"14:30", "18:30");
    a1.printHistory();
    a2.printHistory();
    a3.printHistory();
    a4.printHistory();
    a5.printHistory();
}