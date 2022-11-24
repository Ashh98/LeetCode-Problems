class Solution {
public:
        
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int hole;
        for (int i = 1; i < heights.size(); i++) {
            hole = i;
            while (hole > 0 && heights[hole-1] < heights[hole]) {
                swap(heights[hole-1], heights[hole]);
                swap(names[hole-1], names[hole]);
                hole--;
            }
        }
        return names;
    }
};