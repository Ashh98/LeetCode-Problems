class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> array;
        array.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            first = encoded[i] ^ first;
            array.push_back(first);
        }
        return array;
    }
};