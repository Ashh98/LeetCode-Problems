class Solution {
public:
    double average(vector<int>& salary) {
        int x = 0;
        return (accumulate(salary.begin(), salary.end(), x) - *min_element(salary.begin(), salary.end()) - *max_element(salary.begin(), salary.end()))/(double) (salary.size()-2);
    }
};