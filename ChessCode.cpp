/* Author : G.Akhil Venkat*/

/* Instructions to play the game

-> The top pieces are black && Bottom pieces are white.
-> At every turn it displays whether it is white turn or black turn.
-> At that time you have give direction just like if we want to move piece from B2 to D5 then simply enter:

B2
D5

->you have  enter the initial destination and final destination seperatley.
-> after piece gain it shows your current pieces for both players.
-> after each turn it asks for undo option you can enter 1 for undo the  move else 0.
-> Be careful of undo as there is no undo option for En passant / Castling / promotion moves even it ask dont go for undo. Please avoid undo option use it oftenly.
-> If pawn is promoted the promoting pieces are shown you can opt any one of them by entering its index displayed at that time. 


Note:

-> Be careful of each move as it doesnt show any error/alert (like checks or anything ) even if invalid move is made,you have to take care of everything.
-> Assume it like an chess board where two persons are playing chess in offline mode.  

*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>board;
unordered_map<string,int>type;
unordered_map<string,int>mp;
vector<string>points_black;
vector<string>points_white;
vector<string>common;
long long int a,b,d,c;
vector<string>white_promoted={"♖","♘","♗","♕"};
vector<string>black_promoted={"♜","♞","♝","♛"};


void insertion()
{
    long long int i,j,k,l,m,n;
  vector<string>insert = {"1","♜","♞","♝","♛","♚","♝","♞","♜"};
  for(i=0;i<insert.size();i++)
    type[insert[i]] = 1;
  board.push_back(insert);
  insert.clear();
  insert={"2","♟","♟","♟","♟","♟","♟","♟","♟"};
  for(i=0;i<insert.size();i++)
    type[insert[i]]=1;
  board.push_back(insert);
  long long int c = 3;
  for(i=0;i<4;i++)
    {
      vector<string>v1;
      for(j=0;j<9;j++)
        {
          if(j==0)
          {
            v1.push_back(to_string(c));
            c++;
          }
          else
        v1.push_back(" ");
        }
      board.push_back(v1);
    }
  insert.clear();
   insert = {"7","♙","♙","♙","♙","♙","♙","♙","♙"};
  for(i=0;i<insert.size();i++)
    type[insert[i]] = 2;
  board.push_back(insert);
  insert.clear();
  insert = {"8","♖","♘","♗","♕","♔","♗","♘","♖"};
  for(i=0;i<insert.size();i++)
    type[insert[i]] = 2;
   board.push_back(insert);
}


void display()
{
  long long int i,j,k,l,m,n;
  cout<<endl;
  cout<<"           |";
  vector<char>v = {'A','B','C','D','E','F','G','H'};
  for(i=0;i<8;i++)
    {
    cout<<"  "<<v[i]<<"   |";
    }
  cout<<endl;
   for(j=0;j<9;j++)
      {
        for(k=0;k<7;k++)
          {
            if(j==0)
            {
              cout<<"           |";
              break;
            }
            else
            {
            if(k==6&&j==0)
              cout<<"|    ";
            if(k==6)
              cout<<'|';
            else
            cout<<'_';
              }
          }
      }
  cout<<endl;cout<<endl;cout<<endl;
      for(j=0;j<9;j++)
      {
        for(k=0;k<7;k++)
          {
            if(k==6&&j==0)
              cout<<".    ";
            if(k==6)
              cout<<'.';
            else
            cout<<'_';
          }
      }
      cout<<endl;
  for(i=0;i<board.size();i++)
    {
      for(j=0;j<board[0].size();j++)
        {
          if(j==0)
            cout<<"  "<<board[i][j]<<"   |    |";
          else
          cout<<"  "<<board[i][j]<<"   |";
          if(j==board[0].size()-1)
            cout<<endl;
        }
    for(j=0;j<9;j++)
      {
        for(k=0;k<7;k++)
          {
            if(k==6&&j==0)
              cout<<"|    ";
            if(k==6)
              cout<<'|';
            else
            cout<<'_';
          }
      }
      cout<<endl;
    }
}


int input(int num,int cat)
{
  string s1,s2;
  long long int i,j,k,l,m,n;
  if(num==1)
  {
    board[b][a] = board[d][c];
    board[d][c] = common[common.size()-1];
    if(type[common[common.size()-1]]==2)
      points_black.pop_back();
    if(type[common[common.size()-1]]==1)
      points_white.pop_back();
    common.pop_back();
    display();
    input(0,cat);
    return 0;
  }
  else
  {
    if(cat==0)
    {
      cout<<"white's turn"<<endl;
      cout<<"enter present position and destination seperately"<<endl;
    }
    if(cat==1)
    {
      cout<<"Black's turn"<<endl;
      cout<<"enter present position and destination seperately"<<endl;
    }
  cin>>s1>>s2;
      a=s1[0]-'A';
      a++;
      b=s1[1]-'0';
      b--;
      c=s2[0]-'A';
      c++;
      d=s2[1]-'0';
      d--;
      if(board[d][c] == " ")
      {
        //En Passant CheckPoint
    if(abs(a-c)==1 && abs(b-d)==1 && (board[b][a]=="♙"||board[b][a]=="♟"))
      {
      board[d][c]=board[b][a];
      board[b][a]=" ";
      string dest = board[b][a+1];
      board[b][a+1]=" ";
      common.push_back(" ");
      common.push_back(dest);
      if(type[dest] == 2)
      {
      points_white.push_back(dest);
      for(i=0;i<points_white.size();i++)
           cout<<points_white[i]<<" ";
      }
      else
      {
        points_black.push_back(dest);
          for(i=0;i<points_black.size();i++)
           cout<<points_black[i]<<" ";
      }
         display();
      }
      else
      {
        mp[board[b][a]]++;
        common.push_back(" ");
        board[d][c] = board[b][a];
        board[b][a] = " ";
        display();
      }
      }
    else if(board[d][c] != " " && type[board[d][c]] != type[board[b][a]])
     {
       mp[board[b][a]]++;
       if(type[board[b][a]] == 2)
       {
         points_white.push_back(board[d][c]);
         for(i=0;i<points_white.size();i++)
           cout<<points_white[i]<<" ";
       }
       else
       {
         points_black.push_back(board[d][c]);
          for(i=0;i<points_black.size();i++)
           cout<<points_black[i]<<" ";
       }
        common.push_back(board[d][c]);
        board[d][c] = board[b][a];
        board[b][a] = " "; 
        display();
     }
      
      //Castling CheckPoint
      
    else if((board[d][c] == "♖"&&board[b][a] == "♔")||(board[d][c] == "♜"&&board[b][a] == "♚")&&(abs(a-c) == 3||abs(a-c)==4))
    {
      if(abs(a-c)==3&& board[b][a]=="♔"&&mp[board[b][a]]==0)
      {
        board[b][a] = " ";
        board[7][7] = "♔";
        board[7][6] = "♖";
        board[d][c] = " ";
        display();
      }
      else if(abs(a-c)==3&& board[b][a]=="♚"&&mp[board[b][a]]==0)
      {
        board[b][a] = " ";
        board[0][7] = "♚";
        board[0][6] = "♜";
        board[d][c] = " ";
        display();
      }
      else if(abs(a-c) == 4&& board[b][a] == "♚"&&mp[board[b][a]] == 0)
      {
        board[b][a] = " ";
        board[0][3] = "♚";
        board[0][4] = "♜";
        board[d][c] = " ";
        board[d][c+1] = " ";
        display();
      }
      else if(abs(a-c) == 4 && board[b][a] == "♔" && mp[board[b][a]] == 0)
      {
        board[b][a] = " ";
        board[7][3] = "♔";
        board[7][4] = "♖";
        board[d][c] = " ";
        board[d][c+1] = " ";
        display();
      }
      else
      {
        display();
       cout<<"Invalid Move Castling is not possible"<<endl;
        return 1; 
      }
    }
      else
      {
        cout<<"Invalid Move Enter Again"<<endl;
        return 1;
      } 
    
    //Pawn Promotion CheckPoint
    
    if(board[d][c] == "♙" && d==0)
       {
        cout<<"Select the Promoted Piece "<<endl;
         int u;
        for(i=0;i<white_promoted.size();i++)
            cout<<" "<<white_promoted[i]<<" |";
         cout<<endl;
         for(i=0;i<white_promoted.size();i++)
           cout<<" _"<<"_|";
         cout<<endl;
         for(i=0;i<white_promoted.size();i++)
             cout<<" "<<i<<" |";
         cout<<endl;
         cout<<"Enter: ";
         cin>>u;
         board[d][c] = white_promoted[u];
         display();
       }
    if(board[d][c]=="♟"&&d==7)
    {
       cout<<"Select the Promoted Piece "<<endl;
         int u;
        for(i=0;i<black_promoted.size();i++)
            cout<<" "<<black_promoted[i]<<" |";
          cout<<endl;
         for(i=0;i<black_promoted.size();i++)
           cout<<" _"<<"_|";
         cout<<endl;
         for(i=0;i<black_promoted.size();i++)
             cout<<" "<<i<<" |";
         cout<<endl;
         cout<<"Enter: ";
         cin>>u;
         board[d][c] = black_promoted[u];
         display();
    }
    return 0;
    }
}


int main()
{
  long long int i,j,k,l,m,n;
  insertion(); 
  display();
  cout<<endl;
  cout<<endl;
  while(1)
    {
      cout<<endl;
      long long int err=0;
      do
      {
      if(input(0,0))
        err++;
      else
        err=0;
      }
      while(err!=0);
      cout<<"Undo the Previous step ? press 1 else 0"<<endl;
        long long int num;
        cin>>num;
        if(num)
        input(num,0);  
      err=0;
      cout<<endl;
      do
      {
      if(input(0,1))
        err++;
      else
        err=0;
      }
      while(err!=0);
        cout<<"Undo the Previous step ? press 1 else 0"<<endl;
        cin>>num;
        if(num)
        input(num,1);  
    }
}
