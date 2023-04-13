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
//                                    n head diff
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]  9  1    1
// arr = [2, 4, 6, 8]                 4  2    2 
// arr = [2, 6]                       2  2    4
// arr = [6]                          1  6    8

// Logic :- diff = diff*2 (on every traversal)
// head it will be update when (left || n%2 != 0) both the condn will be true
