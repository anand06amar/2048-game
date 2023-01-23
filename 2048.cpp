#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

int board[4][4];
int dirline[]={1,0,-1,0};
int dircolumn[]={0,1,0,-1};

pair<int,int> generateUnoccupiedPosition(){
    int occupied =1, line, column;
    while(occupied){
        line=rand()%4;
        column=rand()%4;
        if (board[line][column]==0)
        occupied=0;
    }
    return make_pair(line,column);
}
void addpiece(){
    pair<int,int> pos= generateUnoccupiedPosition();
        board[pos.first][pos.second]=2;
}
void newgame(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        board[i][j]=0;
        addpiece();
}
    void printUI(){
        system("cls");
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
            if (board[i][j]==0)
            cout<< setw(4)<<".";
            else
            cout<<setw(4)<<board [i][j];
            cout<< "\n";
        }
        cout<<"n: new game, w: up, s: down, d: right, a: left, q:quit\n";

        }
        bool canDoMove(int line, int column, int nextline, int nextcolumn){
            if (nextline<0||nextcolumn<0||nextline>=4||nextcolumn>=4
            ||(board[line][column]!=board[nextline][nextcolumn]&&board[nextline][nextcolumn]!=0))
            return false;
            return true;
        }
        void applymove(int direction){
            int startline= 0, startcolumn=0,linestep=1,columnstep=1;
            if (direction==0){
                startline=3;
                linestep=-1;
}
            if (direction==1){
                startcolumn=3;
                columnstep=-1;
}
            int movepossible, canAddPiece=0;
            do{
                movepossible=0;
                for(int i=startline;i>=0&&i<4;i+=linestep)
                for(int j=startcolumn;j>=0&&j<4;j+=columnstep){
                int nextI=i+dirline[direction],nextJ=j+dircolumn[direction];
                if(board[i][j]&&canDoMove(i,j,nextI,nextJ)){
                    board[nextI][nextJ]+=board[i][j];
                    board[i][j]=0;
                    movepossible=canAddPiece=1;
                }
            }
            printUI();
            } while(movepossible);
            if (canAddPiece)
            addpiece();
        }
        int main()
        {
            srand(time(0));
            char commandToDir[128];
            commandToDir['s']=0;
            commandToDir['d']=1;
            commandToDir['w']=2;
            commandToDir['a']=3;
            while(true){
                printUI();
                char command;
                cin>>command;
                if(command=='n')
                newgame();
                else if(command=='q')
                break;
                else{
                    int currentdirection=commandToDir[command];
                    cout<<currentdirection<<"\n";
                    applymove(currentdirection);

                }
                            
        }
        return 0;
        }