class Solution {
public:
    int findCelebrity(vector<vector<int>>& knows) {
        int n = knows.size();
        stack<int> s;

        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows[a][b] == 1){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int celeb = s.top();
        for(int i=0;i<n;i++){
            if(i != celeb && (knows[celeb][i] == 1 || knows[i][celeb] == 0)){
                return -1;
            }
        }
        return celeb;
       
    }
};