#include<iostream>


using namespace std;

class Player{
    private:
        string name;
        int real;
        int pos;

    public:
        Player()
        {

        }
        Player(string name)
        {
            this->name = name;
            this->real=1;
            this->pos=0;
        }
        Player(string name, int real)
        {
            this->name = name;
            this->real=real;
            this->pos=0;
        }
        string GetPlayerName()
        {
            return this->name;
        }
        int IsReal()
        {
            return this->real;
        }

        void SetPos(int pos)
        {
            this->pos=pos;
        }

        int GetPos()
        {
            return this->pos;
        }
};



class Board{
    private:
        int playground;
        Player player1;
        Player player2;
        unordered_map<int, int> snake;
        unordered_map<int,int> ladder;
        int turn;
    public:
         
        Board(Player player1,Player player2)
        {
            this->player1=player1;
            this->player2=player2;
            this->snake = GetSnakes();
            this->ladder = GetLadder();
            this->playground = 100;
            this->turn = 0;

        }
        unordered_map<int,int> GetSnakes()
        {
            unordered_map<int, int> snake;
            snake[10]=2;
            snake[20]=8;
            snake[40]=15;
            snake[80]=68;
            snake[98]=37;
            return snake;

        }
        unordered_map<int,int> GetLadder()
        {
            unordered_map<int, int> ladder;
            ladder[11]=95;
            ladder[7]=16;
            ladder[55]=70;
            ladder[34]=68;
            ladder[88]=92;
            return ladder;
        }
        int RollDice()
        {
            return (rand()%6)+1;
        }

        void printheader()
        {
            cout<<player1.GetPlayerName() <<" and "<< player2.GetPlayerName() << "are Playing" <<endl;
            cout<<player1.GetPlayerName() <<" at "<< player1.GetPos() << endl;
            cout<<player2.GetPlayerName() <<" at "<< player2.GetPos() << endl;
        }
        void play()
        {
            while(player1.GetPos()!=100 || player2.GetPos()!=100)
            {

                printheader();
                if(turn)
                {
                    int x= RollDice();
                    cout<<player2.GetPlayerName() <<"'s Dice roll value is "<< x<<endl;
                    if(player2.GetPos()!=0)
                    {
                        int y=x+player2.GetPos();
                        if(y<=100)
                        {
                            player2.SetPos(y);
                            if(snake.find(y)!=snake.end())
                            {
                                player2.SetPos(snake[y]);
                            }
                            if(ladder.find(y)!=ladder.end())
                            {
                                player2.SetPos(ladder[y]);
                            }
                        }
                    }
                    else if(x==1)
                    {
                        player2.SetPos(1);
                    }
                    turn = 0;
                }
                else
                {
                    int x= RollDice();
                    cout<<player1.GetPlayerName() <<"'s Dice roll value is "<< x <<endl;
                    if(player1.GetPos()!=0)
                    {
                        int y=x+player1.GetPos();
                        if(y<=100)
                        {
                            player1.SetPos(y);
                            if(snake.find(y)!=snake.end())
                            {
                                player1.SetPos(snake[y]);
                            }
                            if(ladder.find(y)!=ladder.end())
                            {
                                player1.SetPos(ladder[y]);
                            }
                        }
                    }
                    else if(x==1)
                    {
                        player1.SetPos(1);
                    }
                    turn = 1;
                }
//                sleep_for(2000);
                //   Sleep(2000);

            }
            if(player1.GetPos()==100)
            {
                cout<<player1.GetPlayerName()<<" is the Winner.\n";
            }
            else{
                cout<<player2.GetPlayerName()<<" is the Winner.\n";
            }
            cout<<"Congratulations\n";
        }    
};
int main()
{
    int c=5;
    int option;
    do {
        cout<<"You are about to Play Snake and Ladders\n";
        cout<<"Press 1 to play with computer.\n";
        cout<<"Press 2 to play with partner.\n";
        cin>>option;
        c--;
    }
    while(c && option!=1 && option!=2);
    if(option == 1)
    {
        string name;
        cout<<"Please enter your name\n";
        cin>>name;
        Player player1(name);
        Player player2("Computer", 0);
        Board board(player1, player2);
        board.play();
    }
    else
    {
        string name1, name2;
        cout<<"Please enter first player name\n";
        cin>>name1;
        cout<<"Please enter second player name\n";
        cin>>name2;
        Player player1(name1);
        Player player2(name2);
        Board board(player1, player2);
        board.play();
    }
    
}