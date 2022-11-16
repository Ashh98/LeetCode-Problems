class OrderedStream {
public:
    vector<string> res;
    int ptr = 0;
    
    OrderedStream(int n) {
        res.resize(n+1, " ");
    }
    
    vector<string> insert(int idKey, string value) { 
        vector<string> currRes;
        res[idKey-1] = value;
        //cout << idKey-1 << " " << res[idKey-1] << endl;
        //int i = ptr;
        while (res[ptr] != " ") {
            currRes.push_back(res[ptr]);
            ptr++;
        }
        return currRes;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */