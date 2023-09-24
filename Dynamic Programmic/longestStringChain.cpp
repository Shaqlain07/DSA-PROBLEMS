class Solution {
public:
    unordered_map<string,int> chain_length;//tells length from this word
    unordered_map<string,bool> word_set;
    int helper(string words) {
        //if word doesn't exit
        if(word_set.find(words)==word_set.end()) {
            return 0;
        }

        // Now check if we have calculated it earlier
        if(chain_length.find(words)!=chain_length.end()) {
            return chain_length[words];
        }

        int chain=1;
        //iterate on words[i]..and erase every word and call
        for(int i=0;i<words.size();i++) {
            string sub=words;
            sub.erase(sub.begin()+i);
            chain=max(chain,1+helper(sub));
        }
        return chain_length[words]=chain;
    }
    int longestStrChain(vector<string>& words) {
        //all strings are marked
        for(int i=0;i<words.size();i++) {
            word_set[words[i]]=true;
        }
        int chain_length=-1;
        for(int i=0;i<words.size();i++) {
            chain_length=max(chain_length,max(chain_length,helper(words[i])));
        }
        return chain_length;

    }
};
