class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum+= 1;
                i++;
                continue;
            }
            int peak =1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int tro = 1;
            while(i < n&& ratings[i] < ratings[i-1]){
                sum+=tro;
                tro++;
                i++;
            }
            // here you need not check for tro == peak , because tro is one index advances afer after adding
            // 1 2 3 4 5 6 1 2 3 4 5
            // 0 1 2 3 4 5 4 3 2 1    so here tro == peak but since tro already advanced , its compensated for.
            if(tro>peak){
                sum += (tro - peak);
            }

            
        }
        return sum;
    }
};