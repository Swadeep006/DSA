vector<int>x4={0,1,0,-1};
vector<int>y4={1,0,-1,0};
class Solution {
public:
    bool helper(vector<vector<char>>& board,int row, int col, string word, int index){
        if(index==word.size()) return true;
        for(int k=0;k<4;k++){
            int ni = x4[k]+row;
            int nj = y4[k]+col;
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size()){
                if(board[ni][nj]==word[index] ){
                    char temp = board[ni][nj];
                    board[ni][nj]='1';
                    bool flag = helper(board,ni,nj,word,index+1);
                    if(flag) return true;
                    board[ni][nj]=temp;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board[0].size()*board.size()<word.size()) return false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    char temp = board[i][j];
                    board[i][j] = '1';
                    bool ans = helper(board,i,j,word,1);
                    if(ans) return true;
                    board[i][j]=temp;
                }
            }
        }
        return false;
    }
};