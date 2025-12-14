// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n)
{
    // check colomn
    for(int i=0;i<row;i++)
    {
        if(board[i][col])
            return false;
    }
    
    // upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    
    // upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
            return false;
    }
    return true;
}

void solve(int row,vector<vector<int>> &board,int n)
{
    if(row==n){
        printBoard(board,n);
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]=1;
            solve(row+1,board,n);
            board[row][col]=0;
        }
    }
}

int main() {
    int n;
    cout<<"enter n : ";
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0,board,n);

    return 0;
}
