class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> t;
    int getintFromChar(char ch){
        return (ch == 'S' ? 0 : ch-'0');
    }
    bool isValid(int i , int j ,vector<string>& board){
        if(i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X')
            return true;
        
        return false;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        t.assign(n , vector<pair<int,int>>(n , {0 , 0}));

        t[0][0] = {0 ,1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(board[i][j] == 'E') continue;

                if(board[i][j] == 'X') continue;

                int upScore = 0 , upPaths = 0;
                int leftScore = 0 , leftPaths = 0;
                int diagScore = 0 , diagPaths = 0;

                char ch = board[i][j];

                //up
                if(isValid(i-1 , j , board)){
                    auto [score , paths] = t[i-1][j];
                    upScore = score;
                    upPaths = paths;

                    if(upPaths > 0){
                        upScore += getintFromChar(ch);
                    }
                }
                //left
                if(isValid(i , j-1 , board)){
                    auto [score , paths] = t[i][j-1];
                    leftScore = score;
                    leftPaths = paths;

                    if(leftPaths > 0){
                        leftScore += getintFromChar(ch);
                    }
                }

                //diag(up-left)
                if(isValid(i-1 , j-1 , board)){
                    auto [score , paths] = t[i-1][j-1];
                    diagScore = score;
                    diagPaths = paths;

                    if(diagPaths > 0){
                        diagScore += getintFromChar(ch);
                    }
                }

                //now we will find the bestScore and bestPaths
                int bestScore  = 0, bestPaths = 0;

                if(upScore == leftScore && leftScore == diagScore){
                    bestScore = leftScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                }else if(upScore == leftScore){
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;

                    if(diagScore > bestScore ){
                        bestScore = diagScore;
                        bestPaths = diagPaths;
                    }
                }else if(leftScore == diagScore){
                    bestScore = leftScore;
                    bestPaths = leftPaths + diagPaths;

                    if(upScore > bestScore ){
                        bestScore = upScore;
                        bestPaths = upPaths;
                    }
                }else{
                    bestScore = upScore;
                    bestPaths = upPaths;

                    if(bestScore < leftScore ){
                        bestScore = leftScore;
                        bestPaths = leftPaths;
                    }else if(bestScore < diagScore){
                        bestScore = diagScore;
                        bestPaths = diagPaths;
                    }
                }

                t[i][j] =  {bestScore , bestPaths % MOD};
            }
        }
        auto result = t[n-1][n-1]  ;
        return {result.first , result.second};
    }
};