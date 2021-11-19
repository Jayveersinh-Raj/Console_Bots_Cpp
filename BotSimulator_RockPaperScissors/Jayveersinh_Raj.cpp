// Lecture 13 - Type casting
#include <iostream>
#include <tuple>
#include <thread>
#include <chrono>
#include <memory>
#include <vector>
#include <ostream>
#include <ctime>
#include <cstdlib>
/*
 *
 *
Implementing Task Requirement Number 5
*
*
*/


using namespace std;
using namespace std::chrono_literals;

const int TIMEOUT = 400; // maximum number of milliseconds that a player is allowed to take




//ITEM 3.k: Template
//Our End game Handler function
template<typename T>
T endgame(){
    cin.get();
    system("cls");
    system("exit");
}



//Flags or Player0,Player1,Mountains, Flags, and empty places
int checkValue(char c){
    if(islower(c)&&c!='f'){
        return 0;
    }
    else if(c=='S'||c=='R'||c=='P'){
        return 1;
    }
    else if(c==' '){
        return 2;
    }
    else if(c=='M'){
        return 3;
    }
    else if(c=='F'){
        return 4;
    }
    else if(c=='f'){
        return 5;
    }
    else if(c=='L'){
        return 6;
    }
}




//ITEM 3.k : Vector STL
//Our World map where everything would be displayed
vector<vector<char>> map;



//ITEM 3.f: Call to contant member function
//ITEM 3.b: Class with more than one constructor and a destructor
class name{
    const string name_my(string s){
        s="Raj";
        return s;
    };
public:
    name(string s){
        name_my(s);
    }
    name(){
        cout<<"Chess like bot game";
    }
    ~name();
};

//ITEM 3.e: Virtual function
class units{
    int x;
    virtual void assign(int a){
        x=a;
    };
};

//ITEM 3.e: Pure virtual function
class idle{
    virtual void J(string s)=0;
};

class vertical: units{
    void assign(int a) override{
        a=3;
    }
};


//ITEM 3.h: Explicit Specialization
template<class units=int> class A{
public:
    A();
};;
template<> A<float>::A(){};






//Evaluate illegal move
void illegal(string s){
    cout<<"Player" << s << "lose due to a illegal move"<<endl;
    endgame<void>();
}



class World {
public:
   static int calls; //ITEM 3.d: Static typing
   World(){};
    // Conatiners with smart pointers for player0, mountains M and Player1
    vector<shared_ptr<char>> player0(){
        vector<shared_ptr<char>> v;
        v.push_back(make_shared<char>('s'));
        v.push_back(make_shared<char>('p'));
        v.push_back(make_shared<char>('r'));
        v.push_back(make_shared<char>('f'));
        return v;
    }
    void M(){
        vector<shared_ptr<char>> v;
        v.push_back(make_shared<char>('M'));
    }
    void player1(){
        vector<shared_ptr<char>>v;
        v.push_back(make_shared<char>('S'));
        v.push_back(make_shared<char>('P'));
        v.push_back(make_shared<char>('R'));
    }
};




class Position{
public:
    std::tuple<int, int> pos;

    // TODO Implement the operator == and other operators if necessary
    //Implemented

    //ITEM 3.c: Operator Overload
    bool operator==(Position &p) {
        if (pos == p.pos) {
            return true;
        }
    }
        tuple<int,int> operator+(Position &p){
          get<0>(pos)+=get<0>(p.pos);
          get<1>(pos)+=get<1>(p.pos);
          return make_tuple(get<0>(pos),get<1>(pos));
        }/*
        tuple<int ,int> operator=(Position &p){
        get<0>(pos)=get<0>(p.pos);
        get<1>(pos)=get<1>(p.pos);
            return make_tuple(get<0>(pos),get<1>(p.pos));
        }*/
        bool operator>(Position &p){
        if(get<0>(pos)>get<0>(p.pos)){
            return true;
        }
    }
};



class Action {
    Position from;// current row, column of the unit to be moved
    Position to; // position to where the unit must be moved
public:
    Action Action0()=delete;//ITEM 3.g: A non copyable object

    //This is the manner of acting while encountering other characters,moutain or winning
    void act(int i, int j , int k, int l){

        //For little paper p
        if(map[i][j]=='p'&&map[k][l]=='R'){
            map[k][l]='p';
            map[i][j]=' ';
        }
        if(map[i][j]=='p'&&map[k][l]=='S'){
            map[i][j]=' ';
            map[k][l]='S';
        }
        if(map[i][j]=='p'&&map[k][l]=='P'){
            map[i][j]='p';
            map[k][l]='P';
        }

        //For little scissors 's'
        if(map[i][j]=='s'&&map[k][l]=='P'){
            map[k][l]='s';
            map[i][j]=' ';
        }
        if(map[i][j]=='s'&&map[k][l]=='R'){
            map[i][j]=' ';
            map[k][l]='R';
        }
        if(map[i][j]=='s'&&map[k][l]=='S'){
            map[i][j]='s';
            map[k][l]='S';
        }

        //For little Rock r
        if(map[i][j]=='r'&&map[k][l]=='P'){
            map[k][l]='P';
            map[i][j]=' ';
        }
        if(map[i][j]=='r'&&map[k][l]=='R'){
            map[i][j]='r';
            map[k][l]='R';
        }
        if(map[i][j]=='r'&&map[k][l]=='S') {
            map[i][j] = ' ';
            map[k][l] = 'r';
        }

        //for capital scissor S
        if(map[i][j]=='S'&&map[k][l]=='p'){
            map[k][l]='S';
            map[i][j]=' ';
        }
        if(map[i][j]=='S'&&map[k][l]=='r'){
            map[i][j]=' ';
            map[k][l]='r';
        }
        if(map[i][j]=='S'&&map[k][l]=='s') {
            map[i][j] = 'S';
            map[k][l] = 's';
        }

        //For Capital Rock R
        if(map[i][j]=='R'&&map[k][l]=='p'){
            map[k][l]='p';
            map[i][j]=' ';
        }
        if(map[i][j]=='R'&&map[k][l]=='r'){
            map[i][j]='R';
            map[k][l]='r';
        }
        if(map[i][j]=='R'&&map[k][l]=='s') {
            map[i][j] = ' ';
            map[k][l] = 'R';
        }
        //For capital Paper P
        if(map[i][j]=='P'&&map[k][l]=='p'){
            map[k][l]='p';
            map[i][j]='P';
        }
        if(map[i][j]=='P'&&map[k][l]=='r'){
            map[i][j]=' ';
            map[k][l]='P';
        }
        if(map[i][j]=='P'&&map[k][l]=='s') {
            map[i][j] = ' ';
            map[k][l] = 's';
        }
        else if(checkValue(map[i][j])==0&&map[k][l]=='M'){
            cout<<"game end Player 1 win, Player 0 crashed into mountain"<<endl;
            endgame<void>();
            return;
        }
        else if(checkValue(map[i][j])==1&&map[k][l]=='M'){
            cout<<"game end Player 0 win, Player 1 crashed into mountain"<<endl;
            endgame<void>();
            return;
        }
        else if(checkValue(map[i][j])==0&&map[k][l]=='F'){
            cout<<"Player 0 wins by capturing the flag"<<endl;
            endgame<void>();
            return;
        }
        else if(checkValue(map[i][j])==1&&map[k][l]=='f'){
            cout<<"Player 1 wins by capturing the flag"<<endl;
            endgame<void>();
            return;
        }
        else{
            swap(map[i][j],map[k][l]);
        }
    }
};








//Player0 is our random bot operating randomly
//ITEM 3.c: Random smart Player bot

Action actionPlayerZero(const World world) {
    // TODO Implement some basic strategy and remove the lines below
    Action a;
    int from0=0;
    int from1=0;
    int t0=0;
    int t1=0;

    srand(time(0));
    bool isTrue=false;
    while(!isTrue) {
        from0 = (rand() % 15);
        from1 = (rand() % 15);
        if (checkValue(map[from0][from1] == 0)) {
            int possibility = rand() % 4;
            if (possibility == 0 && from0 != 0) {
                t0 = from0;
                t1 = from0 - 1;
                if (checkValue(map[t0][t1] == 0)) {
                    string s = "Player0";
                    isTrue = true;
                    illegal(s);
                }
            }
            if (possibility == 1 && from0 >= 0 && from0 < 14) {
                t0 = from0;
                t1 = from0 + 1;
                if (checkValue(map[t0][t1] == 0)) {
                    string s = "Player0";
                    isTrue = true;
                    illegal(s);
                }
            }
            if (possibility == 2 && from0 != 0) {
                t0 = from0 - 1;
                t1 = from0;
                if (checkValue(map[t0][t1] == 0)) {
                    string s = "Player0";
                    isTrue = true;
                    illegal(s);
                }
            }
            if (possibility == 3 && from0 >= 0 && from0 < 14) {
                t0 = from0 + 1;
                t1 = from0;
                if (checkValue(map[t0][t1] == 0)) {
                    string s = "Player0";
                    isTrue = true;
                    illegal(s);
                }
            }
        } else {
            if (from0 == 0 && from1 <= 14 && checkValue(map[from0][from1 + 1] != 0) && map[from0][from1 + 1] != 'f') {
                t0 = from0;
                t1 = from1 + 1;

                if (map[from0][from1] == 's'){
                    int ran=rand()%8;
                    if(ran==0) {
                        if (from0 < 12 && from1 < 14) {
                            t0 = from0 + 2;
                            t1 = from1 + 1;
                        } else if (from0 < 12 && from1 == 14) {
                            t0 = from0 + 2;
                            t1 = from1 - 1;
                        }
                    }

                        if(ran==1){
                            if(from1<13&&from0<14){
                                t0=from0+1;
                                t1=from1+2;
                            }
                            else if(from1>=13&&from0<14){
                                t0=from0-1;
                                t1=from1-2;
                            }
                            }
                        if(ran==2){
                            if(from1<14&&from0<13){
                                t0=from0+2;
                                t1=from1+1;
                            }
                            else if(from1>12&&from0<=2){
                                t0=from0-1;
                                t1=from1-2;
                            }
                            if(ran==3){
                                if(from1<13&&from0<14){
                                    t0=from0+1;
                                    t1=from1+2;
                                }
                                else if(from1>12&&from0<14){
                                    t0=from0-1;
                                    t1=from1-2;
                                }
                            }

                    }
                }

                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                    }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }

                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }
                }
                isTrue = true;
            }

            if (from0 == 0 && from1 > 0 && checkValue(map[from0][from1 - 1] != 0) && map[from0][from1 - 1] != 'f') {
                t0 = from0;
                t1 = from1 - 1;

                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                    }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }

                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }

                    isTrue = true;
                }
            }
            if (from0 == 0 && from1 <= 14 && checkValue(map[from0 + 1][from1] != 0) && map[from0 + 1][from1] != 'f') {
                t0 = from0 + 1;
                t1 = from1;

                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                    }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }


                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }

                    isTrue = true;
                }
            } else if (from0 <= 14 && from1 == 0 && checkValue(map[from0][from1 + 1] != 0) &&
                       map[from0][from1 + 1] != 'f') {
                t0 = from0;
                t1 = from1 + 1;

                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                    }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }


                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }

                    isTrue = true;
                }

            } else if (from0 < 14 && from1 == 0 && checkValue(map[from0 + 1][from1] != 0) &&
                       map[from0][from1 + 1] != 'f') {
                t0 = from0 + 1;
                t1 = from1;

                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                    }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }


                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }

                    isTrue = true;
                }

            } else if (from0 > 0 && from1 == 0 && checkValue(map[from0 - 1][from0] != 0) &&
                       map[from0 - 1][from1] != 'f') {
                t0 = from1 - 1;
                t1 = from1;
                if (map[from0][from1] == 'r'){
                    int r=rand()%2;
                    if(r==0&&from1<13) {
                        t1 = from1 + 2;
                    }
                    if(r==0&&from1>13){
                        t1=from1-2;
                    }
                    if(r==1&&from0<13){
                        t1 = from0 + 2;
                        }
                    if(r==1&&from0>2){
                        t1 = from0 - 2;
                    }
                }
                if (map[from0][from1] == 'p') {
                    int rd = rand() % 4;
                    {
                        if (rd == 0 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        }

                        if (rd == 1 && from0 != 0) {
                            t0 = from0 - 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                    }
                    if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 + 1;
                        t1 = from1 + 1;
                    }
                    if (rd == 3 && from0 != 14) {
                        t0 = from0 + 1;
                        t1 = from1 - 1;
                        if (checkValue(map[t0][t1]) == 0) {
                            illegal("Player 0");
                            endgame<void>();
                        }
                    } else {
                        t0 = from0 - 1;
                        t1 = from1 + 1;
                    }

                    isTrue = true;
                }
            }
            if (from0 > 0 && from0 <= 14 && from1 > 0 && from1 <= 14) {
                if (checkValue(map[from0][from1]) == 0 && checkValue(map[from0 - 1][from1]) != 0 &&
                    map[from0 - 1][from1] != 'f') {
                    t0 = from0 - 1;
                    t1 = from1;

                    if (map[from0][from1] == 'r'){
                        int r=rand()%2;
                        if(r==0&&from1<13) {
                            t1 = from1 + 2;
                        }
                        if(r==0&&from1>13){
                            t1=from1-2;
                        }
                        if(r==1&&from0<13){
                            t1 = from0 + 2;
                        }
                        if(r==1&&from0>2){
                            t1 = from0 - 2;
                        }
                    }

                    if (map[from0][from1] == 'p') {
                        int rd = rand() % 4;
                        {
                            if (rd == 0 && from0 != 14) {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            }

                            if (rd == 1 && from0 != 0) {
                                t0 = from0 - 1;
                                t1 = from1 - 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            } else {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                            }
                        }
                        if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                        if (rd == 3 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                        }

                        isTrue = true;
                    }
                }
                if (checkValue(map[from0][from1]) == 0 && checkValue(map[from0 + 1][from1]) != 0 &&
                    map[from0 + 1][from1] != 'f') {
                    t0 = from0 + 1;
                    t1 = from1;

                    if (map[from0][from1] == 'r'){
                        int r=rand()%2;
                        if(r==0&&from1<13) {
                            t1 = from1 + 2;
                        }
                        if(r==0&&from1>13){
                            t1=from1-2;
                        }
                        if(r==1&&from0<13){
                            t1 = from0 + 2;
                        }
                        if(r==1&&from0>2){
                            t1 = from0 - 2;
                        }
                    }


                    if (map[from0][from1] == 'p') {
                        int rd = rand() % 4;
                        {
                            if (rd == 0 && from0 != 14) {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            }

                            if (rd == 1 && from0 != 0) {
                                t0 = from0 - 1;
                                t1 = from1 - 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            } else {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                            }
                        }
                        if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                        if (rd == 3 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                        }

                        isTrue = true;
                    }
                }
                if (checkValue(map[from0][from1]) == 0 && checkValue(map[from0][from1 - 1]) != 0 &&
                    map[from0][from1 - 1] != 'f') {
                    t0 = from0;
                    t1 = from1 - 1;
                    isTrue = true;
                }
                if (checkValue(map[from0][from1]) == 0 && checkValue(map[from0][from1 + 1]) != 0 &&
                    map[from0][from1 + 1] != 'f') {
                    t0 = from0;
                    t1 = from1 + 1;

                    if (map[from0][from1] == 'r'){
                        int r=rand()%2;
                        if(r==0&&from1<13) {
                            t1 = from1 + 2;
                        }
                        if(r==0&&from1>13){
                            t1=from1-2;
                        }
                        if(r==1&&from0<13){
                            t1 = from0 + 2;
                        }
                        if(r==1&&from0>2){
                            t1 = from0 - 2;
                        }
                    }


                    if (map[from0][from1] == 'p') {
                        int rd = rand() % 4;
                        {
                            if (rd == 0 && from0 != 14) {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            }

                            if (rd == 1 && from0 != 0) {
                                t0 = from0 - 1;
                                t1 = from1 - 1;
                                if (checkValue(map[t0][t1]) == 0) {
                                    illegal("Player 0");
                                    endgame<void>();
                                }
                            } else {
                                t0 = from0 + 1;
                                t1 = from1 + 1;
                            }
                        }
                        if (rd == 2 && from0 != 0 || rd == 1 && from1 != 14) {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 + 1;
                            t1 = from1 + 1;
                        }
                        if (rd == 3 && from0 != 14) {
                            t0 = from0 + 1;
                            t1 = from1 - 1;
                            if (checkValue(map[t0][t1]) == 0) {
                                illegal("Player 0");
                                endgame<void>();
                            }
                        } else {
                            t0 = from0 - 1;
                            t1 = from1 + 1;
                        }

                        isTrue = true;
                    }
                    isTrue = true;
                } else {
                    continue;
                }
            }
        }
    }
    a.act(from0,from1,t0,t1);
    return a;
}







//Player1 is our smart bot
//ITEM 3.c: Strategic Player bot

Action actionPlayerOne(const World world) {
    // TODO Implement some basic strategy and remove the lines below
    Action a;
    int from0 = 0;
    int from1 = 0;
    int t0 = 0;
    int t1 = 0;

    /*Our smartbot will travel from 9th row to reach f and win. If any of it's member gets dead
    along the way, it will start from other active member of 9th row. If 9th row is empty it
    will bring other active members to 9 to  avoid mountains. And travel once again on same path
    to reach f from 0th column.*/

    bool flag = false;

    if (!flag) {
        for (int i = 0; i < 1; i++) {
            if (checkValue(map[1][i]) == 1) {
                from0 = 1;
                from1 = i;
                t0 = 0;
                t1 = i;
                flag = true;
                a.act(from0, from1, t0, t1);
                break;
            }
        }
    }
    if (!flag) {
        for (int i = 0; i < 1; i++) {
            if (checkValue(map[2][i]) == 1) {
                from0 = 2;
                from1 = i;
                t0 = 1;
                t1 = i;
                flag = true;
                a.act(from0, from1, t0, t1);
                break;
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[3][i]) == 1) {
                    from0 = 3;
                    from1 = i;
                    t0 = 2;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[4][i]) == 1) {
                    from0 = 4;
                    from1 = i;
                    t0 = 3;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[5][i]) == 1) {
                    from0 = 5;
                    from1 = i;
                    t0 = 4;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[6][i]) == 1) {
                    from0 = 6;
                    from1 = i;
                    t0 = 5;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[7][i]) == 1) {
                    from0 = 7;
                    from1 = i;
                    t0 = 6;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[8][i]) == 1) {
                    from0 = 8;
                    from1 = i;
                    t0 = 7;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 1; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 8;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 2; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 3; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 4; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 4; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
                break;
            }
        }
        if (!flag) {
            for (int i = 0; i < 5; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 6; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 7; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 8; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[9][i]) == 1) {
                    from0 = 9;
                    from1 = i;
                    t0 = 9;
                    t1 = i - 1;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }





        //If 9th row is empty and there is no more winable Captial ahead
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[10][i]) == 1) {
                    from0 = 10;
                    from1 = i;
                    t0 = 9;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[10][i]) == 1) {
                    from0 = 10;
                    from1 = i;
                    t0 = 9;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[10][i]) == 1) {
                    from0 = 10;
                    from1 = i;
                    t0 = 9;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[10][i]) == 1) {
                    from0 = 10;
                    from1 = i;
                    t0 = 9;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[10][i]) == 1) {
                    from0 = 10;
                    from1 = i;
                    t0 = 9;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }





        //If 10th row is empty and there is no more winable Captial ahead
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[11][i]) == 1) {
                    from0 = 11;
                    from1 = i;
                    t0 = 10;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[11][i]) == 1) {
                    from0 = 11;
                    from1 = i;
                    t0 = 10;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[11][i]) == 1) {
                    from0 = 11;
                    from1 = i;
                    t0 = 10;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[11][i]) == 1) {
                    from0 = 11;
                    from1 = i;
                    t0 = 10;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[11][i]) == 1) {
                    from0 = 11;
                    from1 = i;
                    t0 = 10;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }




        //If 11th row is empty and there is no more winable Captial ahead
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[12][i]) == 1) {
                    from0 = 12;
                    from1 = i;
                    t0 = 11;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[12][i]) == 1) {
                    from0 = 12;
                    from1 = i;
                    t0 = 11;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[12][i]) == 1) {
                    from0 = 12;
                    from1 = i;
                    t0 = 11;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[12][i]) == 1) {
                    from0 = 12;
                    from1 = i;
                    t0 = 11;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[12][i]) == 1) {
                    from0 = 12;
                    from1 = i;
                    t0 = 11;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }




        //If 12th row is empty and there is no more winable Captial ahead
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[13][i]) == 1) {
                    from0 = 13;
                    from1 = i;
                    t0 = 12;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[13][i]) == 1) {
                    from0 = 13;
                    from1 = i;
                    t0 = 12;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[13][i]) == 1) {
                    from0 = 13;
                    from1 = i;
                    t0 = 12;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[13][i]) == 1) {
                    from0 = 13;
                    from1 = i;
                    t0 = 12;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[13][i]) == 1) {
                    from0 = 13;
                    from1 = i;
                    t0 = 12;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }




        //If 14th row is empty and there is no more winable Captial ahead
        if (!flag) {
            for (int i = 0; i < 9; i++) {
                if (checkValue(map[14][i]) == 1 && map[14][i] != 'F')
                    from0 = 14;
                from1 = i;
                t0 = 13;
                t1 = i;
                flag = true;
                a.act(from0, from1, t0, t1);
                break;
            }
        }
        if (!flag) {
            for (int i = 0; i < 10; i++) {
                if (checkValue(map[14][i]) == 1 && map[14][i] != 'F') {
                    from0 = 14;
                    from1 = i;
                    t0 = 13;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 11; i++) {
                if (checkValue(map[14][i]) == 1 && map[14][i] != 'F') {
                    from0 = 14;
                    from1 = i;
                    t0 = 13;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 12; i++) {
                if (checkValue(map[14][i]) == 1 && map[14][i] != 'F') {
                    from0 = 14;
                    from1 = i;
                    t0 = 13;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 13; i++) {
                if (checkValue(map[14][i]) == 1 && map[14][i] != 'F') {
                    from0 = 14;
                    from1 = i;
                    t0 = 13;
                    t1 = i;
                    flag = true;
                    a.act(from0, from1, t0, t1);
                    break;
                }
            }
        }
        return a;
    }
}
//End of Player1 bot





/**
 * The return is a pair: action and a boolean whether a timeout happened
 */

std::tuple<Action, bool> waitPlayer(Action (*f)(World), World world) {
    auto start = std::chrono::high_resolution_clock::now();
    // TODO Important. Below, action should be the result of calling the function passed as parameter
    Action action;
   action=f(ref(world));

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    // TODO This line can be removed

    if (elapsed.count() > TIMEOUT){ // if time > 0.3 s
        return make_tuple(action, true);} // player failed to answer in less than 400 ms
    else {return make_tuple(action, false);}
}







//To print our World
void print(vector<vector<char>> &v){
    vector<vector<char>> :: iterator row;
    vector<char>::iterator col;
    for(row=map.begin();row!=map.end();row++){
        for(col=row->begin();col!=row->end();col++){
            cout<<*col<<"  ";
        }
        cout<<endl;
    }
}






/*ITEM 3.d: Probability based on 2 factors, 1st is closeness in terms of orthogonal blocks-
 between the flag and closest active member, and second factor is ratio of active members-
 in comparison to other player.*/

//Probability of player0 based on closeness of either horizontal or vertical with F and alive members compared to capital
//Then probability of player1 is just 1-probability of player0
double probability(){
    double small;    //To store no. of alive member of player0
    double large;   //To store no. of alive member if player1
    int horizn;    //To store nearest horizontal block
    int vert;     //To store nearest vertical block
    int sum;     //To store sum of total characters alive
    double prob;//Probability of player0

    //Find the total alive member of each
    vector<vector<char>> :: iterator row;
    vector<char>::iterator col;
    for(row=map.begin();row!=map.end();row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if (checkValue(*col) == 0) {     //ITEM 3.j: STL vector using predicate bool function to check the flag-
                small = small + 1;           //and count only lowercase, player0 active members
            } else if (checkValue(*col) == 1) {
                large = large + 1;
            }
        }
    }
//ITEM 3.i: use of Decltype
    double storehoriz=0.0; //To store nearest horizontal member to F of player0
    decltype(storehoriz) storevert=0.0;  //To store nearest vertical member to F of player0


    for(int i=map.size();i<0;i--){
        for(int j=map.size();j<0;j--){
            if(checkValue(map[i][j])==0){
                if(i>storevert&&j>storehoriz){
                    storevert=i;
                    storehoriz=j;
                }
            }
        }
    }

    //To find and save nearest vertical path or horizonal path, whichever is efficient
    double interm;
    if(15-storehoriz>15-storevert){
        interm=(15-storevert);
    }
    else{
        interm=(15-storevert);
    }

    double counter_based=(small / (small + large)); //Ratio of player0 member to total characters
    double block_based = interm / 15; //Ratio of nearest block to 15

    prob=counter_based*block_based; //Our desired probability of Player0 winning based on nearest block to F and ratio
    // ratio of its active members to total members

    cout<<"Probability of Player 0 winning: "<<prob<<endl;
    cout<<"Probability of Player 1 winning: "<<(1-prob)<<endl; //Probability of Player1 winning.
    return prob;
}


int count=0;
void checkSwapable(int i, int j){
    if (count<1){
    if(map[i][j]=='p') {
        int a = i;
        int b = j;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map.size(); j++) {
                if (map[i][j] == 'f') {
                    swap(map[i][j], map[a][b]);
                    count = count + 1;
                }
            }
        }
    }
    }
}





//Main
int main() {
    // TODO Initialize the world
    //Initialization
    map={
            {'f', 'r', 'r', 'r', 'r', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 'p', 'p', 'p', 'p', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 's', 's', 's', 's', 's', ' ', ' ', ' ', ' ', 'M', ' ', 'M', ' ', ' '},
            {' ', 'r', 'r', 'r', 'r', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', 'p', 'p', 'p', 'p', 'p', ' ', ' ', ' ', 'M', ' ', ' ', ' ', 'M', ' '},
            {' ', 's', 's', 's', 's', 's', ' ', ' ', ' ', ' ', 'M', 'M', 'M', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', 'M', 'M', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'S', 'S', 'S', 'S', 'S', ' '},
            {' ', ' ', 'M', ' ', 'M', ' ', 'M', ' ', ' ', 'P', 'P', 'P', 'P', 'P', ' '},
            {' ', ' ', 'M', ' ', 'M', ' ', 'M', ' ', ' ', 'R', 'R', 'R', 'R', 'R', ' '},
            {' ', ' ', 'M', ' ', 'M', 'M', 'M', ' ', ' ', 'S', 'S', 'S', 'S', 'S', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P', 'P', 'P', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R', 'R', 'R', 'R', 'R', 'F'}
    };

    World world;
    Action action0;
    Action action1;

    //srand(time(0));
    //int sr=rand()%2;

    bool timeout0;
    bool timeout1;
    bool endGame = false;
    while (!endGame) {
        tie(action0, timeout0) = waitPlayer(actionPlayerZero, world);
        tie(action1, timeout1) = waitPlayer(actionPlayerOne, world);
        if (timeout0 || timeout1) {
            endGame = true;
            if (timeout0) {
                cout << "Player 0 caused timeout" << endl;
                cout << "Player 0 lost due to late response" << endl;
            } else {
                cout << "Player 1 caused time out" << endl;
                cout << "Player 1 lost due to late response" << endl;
            }
        } else {
            srand(time(0));
            int ran=rand()%15;
            int ran2=rand()%15;
            checkSwapable(ran,ran2);
            print(map);
            probability();
        }
    }

//print(r_map);
    cin.get();
    return 0;
}