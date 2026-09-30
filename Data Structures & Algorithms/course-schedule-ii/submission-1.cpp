class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> answer(0);
        for (auto& p: prerequisites) {
            int classs = p[0];
            int pre = p[1];

            graph[pre].push_back(classs);
            inDegree[classs]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            answer.push_back(current);

            for (int next : graph[current]) {
                inDegree[next]--;

                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }

        }
        if (answer.size() != numCourses) {
            return {};
        }
        return answer;
    }
};
