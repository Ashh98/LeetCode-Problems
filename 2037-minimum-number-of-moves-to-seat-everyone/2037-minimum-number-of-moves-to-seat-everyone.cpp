class Solution {
public:
    void bubbleSort(vector<int>& arr) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < arr.size()-1; i++) {
                if (arr[i+1] < arr[i]) {
                    swap(arr[i], arr[i+1]);
                    flag = true;
                }
            }
        }
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        bubbleSort(seats); bubbleSort(students);
        int c = 0;
        for (int i = 0; i < seats.size(); i++) {
            c += abs(seats[i] - students[i]);
        }
        return c;
    }
};