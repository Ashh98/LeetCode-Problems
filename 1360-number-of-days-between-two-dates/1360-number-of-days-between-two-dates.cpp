class Solution {
public:
    int days[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool isLeap(int y){
        return y%4==0 and (y%100!=0 || y%400==0);
    }
    
    int daysfrom1971(string s){
        int y = stoi(s.substr(0,4)) , m = stoi(s.substr(5,2)) , d = stoi(s.substr(8));
        
        for(int iy =1971;iy<y;iy++){
            d+=(isLeap(iy)?366:365);
        }
        return d + (m>2 and isLeap(y)) + accumulate(begin(days), begin(days)+m-1,0);
    }
    
    int daysBetweenDates(string date1, string date2) {
            
        int d1 = daysfrom1971(date1) , d2 = daysfrom1971(date2);
    
        return abs(d2-d1);
        
    }
};