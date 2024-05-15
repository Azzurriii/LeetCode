class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> result;
        int n = words.size();
        int i = 0;
        while(i < n){
            int j = i + 1;
            int currentLength = words[i].size();
            while(j < n && currentLength + words[j].size() + (j - i) <= maxWidth){
                currentLength += words[j].size();
                ++j;
            }

            int diff = j - i - 1;

            string line = words[i];

            if(j < n){
                if(diff == 0){
                    line += string(maxWidth - currentLength, ' ');
                }
                else{
                    int spaces = (maxWidth - currentLength) / diff;
                    int extraSpaces = (maxWidth - currentLength) % diff;
                    for(int k = i + 1; k < j; ++k){
                        line += string(spaces, ' ');
                        if(extraSpaces-- > 0){
                            line += ' ';
                        }
                        line += words[k];
                    }
                }
            }
            else{
                for(int k = i + 1; k < j; ++k){
                    line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - currentLength - diff, ' ');
            }

            result.push_back(line);
            i = j;
        }

        return result;
    
    }
};