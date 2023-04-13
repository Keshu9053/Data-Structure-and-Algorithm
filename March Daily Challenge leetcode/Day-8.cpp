class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int diff = 1;
        bool left = true;
        
        while(n>1){
            if(left || n%2 != 0) 
                head = head + diff;
            diff = diff*2;
            n/=2;
            left = !left;
        }
        return head;
    }
};
