class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            string currWord=q.front().first;
            int num=q.front().second;
            q.pop();
            if(endWord==currWord) return num;
            for(int i=0;i<beginWord.size();i++){
                char original = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currWord[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(currWord) != st.end())
                    {
                        st.erase(currWord);
                        q.push({currWord, num + 1});
                    }
                }
                currWord[i] = original;
            }
        }
        return 0;
    }
};
