#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    // https://www.geeksforgeeks.org/dsa/topological-sorting-indegree-based-solution/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nextCourses(numCourses);
        vector<int> remainingPrereqs(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int pre = prerequisites[i][1];
            int course = prerequisites[i][0];
            nextCourses[pre].push_back(course);
            remainingPrereqs[course]++;
        }
        queue<int> readyCourses;
        for (int i = 0; i < numCourses; i++) {
            if (remainingPrereqs[i] == 0) {
                readyCourses.push(i);
            }
        }
        int finishedCourses = 0;
        while (!readyCourses.empty()) {
            int course = readyCourses.front();
            readyCourses.pop();
            finishedCourses++;

            for (int i = 0; i < nextCourses[course].size(); i++) {
                int next = nextCourses[course][i];
                remainingPrereqs[next]--;
                if (remainingPrereqs[next] == 0) {
                    readyCourses.push(next);
                }
            }
        }
        if (finishedCourses < numCourses) {
            return false;
        } else {
            return true;
        }
    }
};
