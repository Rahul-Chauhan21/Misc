#include <iostream>
#include <stdio.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw = false;
void display_board()
{
    cout<<"\n\n\tT i c k  T a c  T o e  G a m e"<<endl;
    cout<<"\tPlayer1 [X]\n\tPlayer2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n";
}
void player_turn()
{
    int choice;
    //int flag=0;
    if(turn=='X')
        cout<<"\n\tPlayer [X] turn ";
    if(turn=='O')
        cout<<"\n\tPlayer [O] turn ";
    cin>>choice;
    switch(choice)
    {
    case 1: row=0;column=0; break;
    case 2: row=0;column=1; break;
    case 3: row=0;column=2; break;
    case 4: row=1;column=0; break;
    case 5: row=1;column=1; break;
    case 6: row=1;column=2; break;
    case 7: row=2;column=0; break;
    case 8: row=2;column=1; break;
    case 9: row=2;column=2; break;
    default:{
    cout<<"invalid choice"<<endl;
    //flag=1;
    player_turn();
    return;
    }
    }
    if(turn == 'X'&&board[row][column]!='X'&&board[row][column]!='O')
    {
        board[row][column]='X';
        turn='O';
    }
    else if(turn == 'O'&&board[row][column]!='X'&&board[row][column]!='O')
    {
        board[row][column]='O';
        turn='X';
    }
    else
    {
        cout<<"\n\tAlready filled"<<endl;
        player_turn();
    }

display_board();
}
bool gameover()
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0]==board[i][1]&&board[i][0]==board[i][2])||(board[0][i]==board[1][i]&&board[0][i]==board[2][i]))
            return false;
    }
        if((board[0][0]==board[1][1]&&board[0][0]==board[2][2])||(board[0][2]==board[1][1]&&board[0][2]==board[2][0]))
            return false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            if(board[i][j]!='X'&&board[i][j]!='O')
            return true;
    }
    draw=true;
    return false;
}
int main(void)
{
    display_board();
    while(gameover()){
    player_turn();}
    if(turn=='X'&&draw==false)
        cout<<"Player [O] wins"<<endl;
    else if(turn=='O'&&draw==false)
        cout<<"Player [X] wins"<<endl;
    else
    {
        cout<<"Game draw!"<<endl;
    }
    return 0;
}
