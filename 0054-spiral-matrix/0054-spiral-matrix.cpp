class Solution {
public:
    bool in_bound(int i, int j, vector<vector<int>>& array) {
      int height = array.size();
      int width = array[0].size();
      if ((i < height && i >= 0) && (j < width && j >= 0)) {
        if (array[i][j] == INT_MIN) return false;
        else return true;
      } else return false;
    }

    string def_direction(int i, int j, string dir, vector<vector<int>>& array) {
      if (dir == "right" || dir == "left") {
        if (in_bound(i+1, j, array) ) return "down";
        else if (in_bound(i-1, j, array)) return "up";
      } else if (dir == "up" || dir == "down") {
        if (in_bound(i, j+1, array)) return "right";
        else if (in_bound(i, j-1, array)) return "left";
      } 
      return "";
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      // Write your code here.
      vector<int> res;
      int i = 0, j = -1;
      string dir = "right";

      while (dir != "") {
        if (dir == "left") {
          j--;
          while (in_bound(i, j, matrix)) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            j--;
          }
          j++;
        } else if (dir == "right") {
          j++;
          while (in_bound(i, j, matrix)) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            j++;
          }
          j--;
        } else if (dir == "down") {
          i++;
          while (in_bound(i, j, matrix)) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            i++;
          }
          i--;
        } else if (dir == "up") {
          i--;
          while (in_bound(i, j, matrix)) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            i--;
          }
          i++;
        }
        dir = def_direction(i, j, dir, matrix);
      }
      return res;
    }
};