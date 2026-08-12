class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>x; //record list
        for(int i =0; i < operations.size(); i++) { // for loop to go through operations
            if(operations[i] == "+"){
                x.push_back(x[x.size() - 1] + x[x.size() - 2]);
            }
            else if(operations[i] == "D"){
                x.push_back(2*x.back());
            }
            else if(operations[i] == "C") {
                x.pop_back();
            }
            else {
                x.push_back(stoi(operations[i]));
            }
        }
        int result = accumulate(x.begin(), x.end(), 0); //accumulate sums up all elements of the list, starting with sum 0 at start
        return result;
    }
};
