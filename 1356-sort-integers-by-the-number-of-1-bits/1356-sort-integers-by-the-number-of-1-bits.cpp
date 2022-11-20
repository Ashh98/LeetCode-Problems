class Solution {
public:
    
    int countOnes(int x) {
        int c = 0;
        while (x) {
            if (x%2 == 1) c++;
            x >>= 1;
        }
        return c;
    }
    
    void insertionSort(vector<int>& arr) {
        int hole;
        for (int i = 1; i < arr.size(); i++) {
            hole = i;
            while (hole > 0 && arr[hole-1] > arr[hole]) {
                swap(arr[hole-1], arr[hole]);
                hole--;
            }
        }
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> arrOnes(arr.size(), 0);
        int max = 0;
        for (int i = 0; i < arr.size(); i++) {
            arrOnes[i] = countOnes(arr[i]);
            if (arrOnes[i] > max) max = arrOnes[i];
        }

        vector<vector<int>> x(max+1, {0});
        for (auto& i : x) {
            i.pop_back();
        }
        
        for (int i = 0; i < arr.size(); i++) {
            x[arrOnes[i]].push_back(arr[i]);
        }
                
        vector<int> res;
        for (auto& i : x) {
            insertionSort(i);
            for (auto& j : i) {
                res.push_back(j);
            }
        }
        
        return res;
        
    }
};