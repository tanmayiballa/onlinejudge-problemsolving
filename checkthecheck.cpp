#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char chess_board[8][8];

// Function to span through the diagonal/lines when there are no pieces in the current block. Used to check attacks from queen, rook, and bishop.
bool span_danger(int x, int y, char enemy1, char enemy2, int dirX, int dirY){
  if(x<0 || x>=8 || y<0 || y>=8) return false;

  if(chess_board[x][y] == enemy1 || chess_board[x][y] == enemy2) {
    return true;
  }

  while(chess_board[x][y] == '.' && (x>=0 && x<8) && (y>=0 && y<8)){
    x+=dirX;
    y+=dirY;
  }

  if(x<0 || x>=8 || y<0 || y>=8) return false;

  if(chess_board[x][y] == enemy1 || chess_board[x][y] == enemy2) {
    return true;
  }

  return false;

}

// Function to check danger in the given position. Used by checkknight and checkpawn function.
bool check_danger(int x, int y, char enemy){
  if(x<0 || x>=8 || y<0 || y>=8) return false;
  if(chess_board[x][y] == enemy) return true;
  return false;
}

// Function to check danger from the opponent's knight.
bool checkknight(int x,int y, char enemy){
  if(x<0 || x>=8 || y<0 || y>=8) return false;

  bool result = false;
  result = check_danger(x-2,y-1,enemy);
  if(!result) result = check_danger(x-2,y+1, enemy);
  if(!result) result = check_danger(x-1,y-2, enemy);
  if(!result) result = check_danger(x-1,y+2, enemy);
  if(!result) result = check_danger(x+1,y-2, enemy);
  if(!result) result = check_danger(x+1,y+2, enemy);
  if(!result) result = check_danger(x+2,y-1, enemy);
  if(!result) result = check_danger(x+2,y+1, enemy);
  return result;
}

// Function to check danger from the opponent's queen and bishop.
bool checkcross(int x, int y, char enemy1, char enemy2){
  bool result = false;
  result = span_danger(x-1,y-1, enemy1, enemy2, -1, -1);
  if(!result) result = span_danger(x-1, y+1, enemy1, enemy2, -1, 1);
  if(!result) result = span_danger(x+1, y-1, enemy1, enemy2, 1, -1);
  if(!result) result = span_danger(x+1,y+1,enemy1,enemy2, 1, 1);
  return result;
}

// Function to check danger from the opponent's pawn.
bool checkpawn(int x, int y, char enemy, int turn){
  if(x<0 || x>=8 || y<0 || y>=8) return false;
  bool result = false;
  if(turn){
    result = check_danger(x-1,y-1,enemy);
    if(!result) result = check_danger(x-1,y+1, enemy);
  }
  else{
    result = check_danger(x+1,y+1,enemy);
    if(!result) result = check_danger(x+1,y-1,enemy);
  }
  return result;

}

// Function to check danger from the opponent's rook and queen.
bool checkstraight(int x,int y, char enemy1, char enemy2){
  bool result = false;
  result = span_danger(x-1,y,enemy1,enemy2,-1,0);
  if(!result) result = span_danger(x+1, y, enemy1,enemy2, 1, 0);
  if(!result) result = span_danger(x, y-1, enemy1,enemy2,0,-1);
  if(!result) result = span_danger(x, y+1, enemy1, enemy2, 0, 1);
  return result;
}

// Overall function that triggers all the above functions to check danger for the king.
bool checkthecheck(int x, int y, int turn){
  int n = 5;
  bool danger = false;

  char army_white[5] = {'P', 'B', 'N', 'Q', 'R'};
  char army_black[5] = {'p', 'b', 'n', 'q', 'r'};

  char *enemy;
  if(turn) enemy = army_black;
  else enemy = army_white;

  danger = checkpawn(x,y,enemy[0], turn);

  if(!danger) danger = checkknight(x,y,enemy[2]);

  if(!danger) danger = checkcross(x,y,enemy[3],enemy[1]);

  if(!danger) danger = checkstraight(x,y,enemy[3], enemy[4]);


  return danger;

}


int main(){
  int game_count = 1;
  cout<<"";
  while(true){
    int k_x,k_y,K_x,K_y;
    k_x = k_y = K_x = K_y = -1;

    char ch;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        cin>>ch;
        chess_board[i][j] = ch;
        if(ch == 'k'){
          k_x = i;
          k_y = j;
        }

        if(ch == 'K'){
          K_x = i;
          K_y = j;
        }
      }
    }

    if(k_x==-1) break;

    bool result = false;
    result = checkthecheck(k_x,k_y,0);
    if(result) {
      cout<<"Game #"<<game_count<<": black king is in check.\n";
      game_count++;
      continue;
    }
    else{
      result = checkthecheck(K_x,K_y,1);
      if(result) {
        cout<<"Game #"<<game_count<<": white king is in check.\n";
        game_count++;
        continue;
      }
    }
    cout<<"Game #"<<game_count<<": no king is in check.\n";
    game_count++;

  }
  return 0;
}
