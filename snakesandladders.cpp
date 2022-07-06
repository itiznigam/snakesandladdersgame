#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
class snl{
    public:
    int score,random,lastposition;
    string playername;
    static int playercount;
    snl(){}
    void registername()
    {
        cout<<setfill('=')<<setw(80)<<"Enter Player "<<playercount<<" Name:"<<setw(78)<<"="<<endl;
        cin>>playername;
        playercount++;
    }
    void snllocation(int &score)
    {
        switch(score)
        {
            case 1:
            score=38;
            break;
            case 4:
            score=14;
            break;
            case 8:
            score=30;
            break;
            case 21:
            score=42;
            break;
            case 28:
            score=77;
            break;
            case 50:
            score=67;
            break;
            case 71:
            score=92;
            break;
            case 80:
            score=99;
            break;
            case 32:
            score=10;
            break;
            case 36:
            score=6;
            break;
            case 48:
            score=26;
            break;
            case 62:
            score=18;
            break;
            case 88:
            score=24;
            break;
            case 95:
            score=56;
            break;
            case 97:
            score=78;
            break;
        }
    }
    string playgame(snl &player2)
    {
        srand(time(0));
        score=0,player2.score=0;
        cin.get();
        while(true)
        {
            cout<<setfill('*')<<setw(172)<<endl;
            cout<<playername<<" its your turn to roll the dice"<<endl;
            cout<<"Press ENTER to Roll The Dice"<<endl;
            cin.get();
            random=rand();
            random=(random%6)+1;
            score+=random;

         
            cout<<"You got a "<<random<<" on the dice"<<endl<<endl;
            if(score>=100)
            return playername;
            lastposition=score;
            snllocation(score);
            cout<<setfill(' ')<<setw(80)<<"Current position: "<<playername<<" "<<score<<endl;
            cout<<setw(80)<<"Current position: "<<player2.playername<<" "<<player2.score<<endl;
            if(lastposition>score)   
            {
                cout<<"You encountered a snake!!!"<<endl;
                cout<<"Your position now is "<<score<<endl;
                cout<<setfill('*')<<setw(170)<<endl<<endl;
            }
            else if(lastposition<score)
            {
                cout<<"You got a ladder."<<endl<<endl;
                cout<<"Your position now is "<<score<<endl;
                cout<<setfill('*')<<setw(170)<<endl<<endl;
            }
            else 
            {
                cout<<"your position is "<<score<<endl<<endl;
                cout<<setfill('*')<<setw(170)<<endl<<endl;
            }
            
            cout<<player2.playername<<" its your turn to roll the dice"<<endl;
            cout<<"Press ENTER to Roll The Dice"<<endl;
            cin.get();
            random=rand();
            random=(random%6)+1;
            player2.score+=random;
            cout<<"You got a "<<random<<" on the dice"<<endl<<endl;
            if(player2.score>=100)
            return player2.playername;
            lastposition=player2.score;
            snllocation(player2.score);
            cout<<setfill(' ')<<setw(80)<<"Current position: "<<player2.playername<<" "<<player2.score<<endl;
            cout<<setw(80)<<"Current position: "<<playername<<" "<<score<<endl;
            if(lastposition>player2.score)   
            {
                cout<<"You encountered a snake"<<endl<<endl;
                cout<<"Your position now is "<<score<<endl<<endl<<endl;
            }
            else if(lastposition<player2.score)
            {
                cout<<"You got a ladder"<<endl<<endl;
                cout<<"Your position now is "<<player2.score<<endl<<endl<<endl;
            }
            else
            {cout<<"Your position is "<<player2.score<<endl<<endl<<endl;}
            
        }
    }
};
int snl::playercount=1;
int main()
{
    system("Color 0E");
    string winner;
    system("cls");
    snl player1,player2;
    player1.registername();
    cout<<endl<<endl;
    player2.registername();
    system("cls");
    winner=player1.playgame(player2);
    cout<<winner<<" wins the game!!!";
}