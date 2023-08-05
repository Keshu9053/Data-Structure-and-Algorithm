class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        // if()
        int n  = words.size();
        int i = 0;

        while(i<n) {
            int j = i+1;
            int wc = words[i].size();
            int can = 0;
            
            while( j<n && wc + can + 1 + words[j].size() <= maxWidth) {
                wc += words[j].size();
                j++;
                can++;
            }
            
            int space = maxWidth - wc;
           
            int atleast = (can != 0) ? space/can : 0;
            int extra = (can != 0) ? space%can : 0;
            
            string temp ;
            if( j == n) {
                atleast = 1;
                extra = 0;
            }
        
            for(int k = i; k<j; ++k) {
                temp += words[k];
                if(k == j-1) break;
                for(int b = 0; b<atleast ; ++b) 
                    temp += " "; 

                if(extra > 0){
                    temp += " ";
                    extra--;
                }
            }
            while(temp.size() < maxWidth) {
                temp += " ";
            }
            ans.push_back(temp);
            i = j;   
        }
        return ans;
    }
};