class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(auto sentence:sentences){
            string sent = sentence;
            int count =0;
            for(int i=0;i<sent.length();i++){
                char ch = sent[i];
                if(ch ==' '){
                    count++;
                    maxi = max(maxi,count);
                }
            }
        }
        return maxi+1;
    }
};