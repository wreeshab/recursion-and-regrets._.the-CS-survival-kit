// the first element determines everything as the different is same, itll be same with first element as well.

class Solution {
public:

    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {

        int n = original.size();

        // Let the first element in the copy array be x then array will be
        // [x , x + (original[1] - original[0]) , x + (original[2] - original[0]),.....]


        
        //left denotes minimum possible value of x and right denotes the maximum possible value of x
        int left = bounds[0][0], right = bounds[0][1]; // Initial valid range for x because (bounds[0][0] <= x <= bounds[0][1])


        // Now for each element in copy array we can ensure ith element belongs in bounds[i] range
        
        
        for (int i = 1; i < n; i++) {

            //The difference between ith element and x
            int diff = (original[i] - original[0]);
            
            // So,the ith element can be written as (x + diff)

            /* Now, for each i 
                    bounds[i][0] <= x+diff <= bounds[i][1]
                So,
                    bounds[i][0]-diff <= x <= bounds[i][1]-diff
            */ 

            left = max(left, bounds[i][0] - diff);   // Ensure x is at least this value
            right = min(right, bounds[i][1] - diff); // Ensure x is at most this value
            // cout<< left << ' '<< right<<endl;
        }
        
        // To ensure that if there exist a valid answer then it is returned otherwise there is no possible array
        return max(0, right - left + 1);
    }
};