// class Solution {
// public:
//     vector<int> countVisitedNodes(vector<int>& edges) {
//         int n = edges.size();
//         vector<int> ans(n, -1);      // -1 means not yet computed.
//         vector<int> inStack(n, -1); 
        
//         for (int i = 0; i < n; i++) {
//             if (ans[i] != -1) continue;
            
//             vector<int> stack;  
//             int cur = i;
            
//             while (true) {
//                 if (ans[cur] != -1) {
//                     int count = ans[cur];
//                     while (!stack.empty()) {
//                         int node = stack.back();
//                         stack.pop_back();
//                         count++;
//                         ans[node] = count;
//                         inStack[node] = -1;  
//                     }
//                     break;
//                 }
//                 if (inStack[cur] != -1) {
//                     int cycleStartIndex = inStack[cur];
//                     int cycleLen = stack.size() - cycleStartIndex;
//                     for (int j = cycleStartIndex; j < stack.size(); j++) {
//                         ans[stack[j]] = cycleLen;
//                     }
//                     int count = cycleLen;
//                     for (int j = cycleStartIndex - 1; j >= 0; j--) {
//                         count++;
//                         ans[stack[j]] = count;
//                     }
//                     for (int node : stack) {
//                         inStack[node] = -1;
//                     }
//                     break;
//                 }
//                 inStack[cur] = stack.size();
//                 stack.push_back(cur);
//                 cur = edges[cur];
//             }
//         }
//         return ans;
//     }


// };

// // class Solution {
// // public:
// //     vector<int> dist, ans;
// //     int dfs(int node, int currDist, auto& edges, int& c) {
// //         dist[node] = currDist;

// //         int res = 0;

// //         int v = edges[node];
// //         if (!dist[v]) {
// //             res += dfs(v, dist[node] + 1, edges, c);
// //         } else {
// //             // already visited and we computed the ans previously now correct
// //             // answer is the ans backtrack time;
// //             if (ans[v] != 0) {
// //                 //  You reuse the value and propagate it backward, incrementing
// //                 //  by 1 for the current node.
// //                 // This is how the path outside a cycle propagates its result.

// //                 ans[node] = ans[v] + 1;
// //                 return ans[node]; // return the current distance
// //             }

// //             // else cycle detected here
// //             c = v;
// //             int len = dist[node] - dist[v] + 1; // store the length of the cycle

// //             ans[node] = len;

// //             return len; // current length return karo
// //             // so that when backtrack each node inside the cycle can get this
// //             // length
// //         }

// //         // how to check the node is in cycle or not
// //         // we pass c as pass by reference so in backtrack stage the c value
// //         // store the starting node of the cycle if  c != node then it is the end
// //         // of the cycle node and reset c to -1;

// //         if (c != -1 && c != node) {
// //             ans[node] = res;
// //             return res;
// //         }

// //         //end of the cycle node 
// //         //so reset c = -1 becoz c is pass by reference
// //         if (c == node) {
// //             ans[node] = res;
// //             c = -1;
// //             return res;
// //         }
// //         // out of the cycle so add one plus with len
// //         ans[node] = res + 1;
// //         return ans[node];
// //     }
// //     vector<int> countVisitedNodes(vector<int>& edges) {
// //         int n = edges.size();
// //         dist.resize(n, 0);
// //         ans.resize(n, 0);

// //         for (int i = 0; i < n; i++) {
// //             if (dist[i] == 0) {
// //                 int c = -1;
// //                 dfs(i, 1, edges, c);
// //             }
// //         }

// //         return ans;
// //     }
// // };

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, -1);
        vector<int> inStack(n, -1);

        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                continue;
            }
            vector<int> stack;
            int cur = i;
            while (true) {
                if (ans[cur] != -1) {
                    int count = ans[cur];
                    while (!stack.empty()) {
                        int node = stack.back(); stack.pop_back();
                        count++;
                        ans[node] = count;
                        inStack[node] = -1;
                    }
                    break;
                }
                if (inStack[cur] != -1) {
                    int cycleStart = inStack[cur];
                    int cycleLen = stack.size() - cycleStart;

                    for (int j = cycleStart; j < stack.size(); j++) {
                        ans[stack[j]] = cycleLen;
                    }
                    int count = cycleLen;
                    for (int j = cycleStart - 1; j >= 0; j--) {
                        count++;
                        ans[stack[j]] = count;
                    }

                    for (int node : stack) {
                        inStack[node] = -1;
                    }
                    break;
                }
                inStack[cur] = stack.size();
                stack.push_back(cur);
                cur = edges[cur];
            }
        }
        return ans;
    }
};
