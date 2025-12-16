class Solution {
public:
    int vowelCount(const string& word) {
        int count = 0;
        for (char ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u') {
                count++;
            }
        }
        return count;
    }

    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for (char ch : s) {
            if (ch == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }
        words.push_back(word);

   
        int firstVowelCount = vowelCount(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (vowelCount(words[i]) == firstVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }

    
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
