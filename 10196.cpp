#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
    bool quit = false;
    char board[10][10];
    int cnt = 1;
    while(!quit){
        quit = true;
        int bKingR, bKingC, wKingR, wKingC;
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                board[i][j] = '0';
        for(int m=1; m<=8; m++){
            for(int n=1; n<=8; n++){
                board[m][n] = getchar();
                if(board[m][n] != '.')
                    quit = false;
                if(board[m][n] == 'k'){
                    bKingR = m;
                    bKingC = n;
                }
                else if(board[m][n] == 'K'){
                    wKingR = m;
                    wKingC = n;
                }
            }
            getchar();
        }
        if(quit) break;
        getchar();

        bool finish = false, blackKing;
        for(int i=1; i<=8; i++){
            for(int j=1; j<=8; j++){
                if(!isalpha(board[i][j])) continue;
                char ch = toupper(board[i][j]);
                int tmpR, tmpC;
                int direction[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
                int knight[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                    {1, 2}, {-1, 2}, {1, -2}, {-1, -2} };
                switch(ch)
                {
                case 'P':
                    if(isupper(board[i][j])){
                        if((i-1==bKingR) && ((j-1==bKingC)||(j+1==bKingC))){
                            finish = true;
                            blackKing = true;
                        }
                    }
                    else{
                        if((i+1==wKingR) && ((j-1==wKingC)||(j+1==wKingC))){
                            finish = true;
                            blackKing = false;
                        }
                    }
                    break;
                case 'R':
                    for(int dir=0; dir<4; dir++){
                        tmpR = i;
                        tmpC = j;
                        while(true){
                            tmpR+=direction[dir][0];
                            tmpC+=direction[dir][1];
                            if((board[tmpR][tmpC]=='K') && (board[i][j]=='r')){
                                finish = true;
                                blackKing = false;
                                break;
                            }
                            else if((board[tmpR][tmpC]=='k') && (board[i][j]=='R')){
                                finish = true;
                                blackKing = true;
                                break;
                            }
                            if(board[tmpR][tmpC] != '.') break;
                        }
                    }
                    break;
                case 'B':
                    for(int dir=4; dir<8; dir++){
                        tmpR = i;
                        tmpC = j;
                        while(true){
                            tmpR+=direction[dir][0];
                            tmpC+=direction[dir][1];
                            if((board[tmpR][tmpC]=='K') && (board[i][j]=='b')){
                                finish = true;
                                blackKing = false;
                                break;
                            }
                            else if((board[tmpR][tmpC]=='k') && (board[i][j]=='B')){
                                finish = true;
                                blackKing = true;
                                break;
                            }
                            if(board[tmpR][tmpC] != '.') break;
                        }
                    }
                    break;
                case 'Q':
                //---R
                for(int dir=0; dir<4; dir++){
                    tmpR = i;
                    tmpC = j;
                    while(true){
                        tmpR+=direction[dir][0];
                        tmpC+=direction[dir][1];
                        if((board[tmpR][tmpC]=='K') && (board[i][j]=='q')){
                            finish = true;
                            blackKing = false;
                            break;
                        }
                        else if((board[tmpR][tmpC]=='k') && (board[i][j]=='Q')){
                            finish = true;
                            blackKing = true;
                            break;
                        }
                        if(board[tmpR][tmpC] != '.') break;
                    }
                }

                //---B
                for(int dir=4; dir<8; dir++){
                    tmpR = i;
                    tmpC = j;
                    while(true){
                        tmpR+=direction[dir][0];
                        tmpC+=direction[dir][1];
                        if((board[tmpR][tmpC]=='K') && (board[i][j]=='q')){
                            finish = true;
                            blackKing = false;
                            break;
                        }
                        else if((board[tmpR][tmpC]=='k') && (board[i][j]=='Q')){
                            finish = true;
                            blackKing = true;
                            break;
                        }
                        if(board[tmpR][tmpC] != '.') break;
                    }
                }
                    break;
                case 'K':
                    break;
                case 'N':
                    for(int dir=0; dir<8; dir++){
                        if((bKingR+knight[dir][0]==i) && (bKingC+knight[dir][1]==j) && (board[i][j]=='N')){
                            finish = true;
                            blackKing = true;
                            break;
                        }
                        else if((wKingR+knight[dir][0]==i) && (wKingC+knight[dir][1]==j) && (board[i][j]=='n')){
                            finish = true;
                            blackKing = false;
                            break;
                        }
                    }
                    break;
                }
                if(finish) break;
            }
            if(finish) break;
        }

        cout << "Game #" << cnt << ": ";
        if(finish){
            if(blackKing){
                cout << "black king is in check." << endl;
            }
            else{
                cout << "white king is in check." << endl;
            }
        }
        else{
            cout << "no king is in check." << endl;
        }
        cnt++;
    }

    return 0;
}
