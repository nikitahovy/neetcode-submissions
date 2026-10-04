class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> answer;
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacificA(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticA(rows, vector<bool>(cols, false));

        stack<pair<int, int>> pacific;
        stack<pair<int, int>> atlantic;
        pair<int, int> current;

    //     for (int i = 0; i < heights[0].size(); i++) {
    //         //Push the current next I onto the stack so that the next while loop goes through and iterates over that next I-th condition.

    //         pacific.push({0,i})

            // while (!pacific.empty()) {
            //     current = pacific.peek();
            //     pacific.pop();
            //     int value = heights[current.first][current.second];
            //     int x = current.first;
            //     int y = current.second;
            //     if (i + 1 < height[0].size() && heights[0][i + 1] >= value) {
            //         pacific.push({0,i});
            //         pacificA.push_back({0,i});
            //     }
            //     if (i - 1 >= 0 && heights[0][i - 1] >= value) {
            //         pacific.push({0, i - 1});
            //         pacificA.push_back({0,i-1});

            //     }
            //     if (x + 1 < height.size() && heights[x][i] >= value) {
            //         pacific.push({x+1, i});
            //         pacificA.push_back({x+1,i});

            //     }
            //     if (x - 1 >= 0 && heights[x][i] >= value) {
            //         pacific.push({x-1, i});
            //         pacificA.push_back({x-1,i});
            //     }
            // }
    //     }
    //     for (int i = 0; i < heights[0].size(), ) {
            // while (!atlantic.empty()) {
            //     int numRows = height.size();
            //     int x = i;
            //     int y = numRows - 1;
            //     if (i + 1 < height[0].size() && heights[y][i + 1] >= value) {
            //         atlantic.push({0,i});
            //         atlanticA.push_back({0,i});
            //     }
            //     if (i - 1 >= 0 && heights[0][i - 1] >= value) {
            //         atlantic.push({0, i - 1});
            //         atlanticA.push_back({0,i-1});

            //     }
            //     if (y + 1 < height.size() && heights[y][i] >= value) {
            //         atlantic.push({y+1, i});
            //         atlanticA.push_back({y+1,i});

            //     }
            //     if (y - 1 >= 0 && heights[y][i] >= value) {
            //         atlantic.push({y-1, i});
            //         atlanticA.push_back({y-1,i});
            //     }
            // }
    //     }
    //     //find the intersection between them and return them, right?

    for (int i = 0; i < heights[0].size(); i++) {
        pacific.push({0,i});
        pacificA[0][i] = true;

    }
    for (int i = 0; i < heights.size(); i++) {
        pacific.push({i,0});
        pacificA[i][0] = true;

    }
    for (int i = 0; i < heights[0].size(); i++) {
        atlantic.push({heights.size() - 1,i});
        atlanticA[heights.size() - 1][i] = true;

    }
    for (int i = 0; i < heights.size(); i++) {
        atlantic.push({i,heights[0].size() - 1});
        atlanticA[i][heights[0].size() - 1] = true;        
    }
    
    while (!pacific.empty()) {
        current = pacific.top();
        pacific.pop();
        int value = heights[current.first][current.second];
        int x = current.first;
        int y = current.second;
        if (y + 1 < heights[0].size() && heights[x][y + 1] >= value) {
            if (!pacificA[x][y + 1]) {
                pacific.push({x,y+1});
                // pacificA.push_back({0,y});
                pacificA[x][y+1] = true;
            }
        }
        if (y - 1 >= 0 && heights[x][y - 1] >= value) {
            if (!pacificA[x][y -1]) {

                pacific.push({x, y - 1});
                // pacificA.push_back({0,y-1});
                pacificA[x][y-1] = true;
            }

        }
        if (x + 1 < heights.size() && heights[x+1][y] >= value) {
            if (!pacificA[x+1][y]) {

                pacific.push({x+1, y});
                // pacificA.push_back({x+1,i});
                pacificA[x+1][y] = true;
            }


        }
        if (x - 1 >= 0 && heights[x-1][y] >= value) {
            if (!pacificA[x-1][y]) {
                pacific.push({x-1, y});
                // pacificA.push_back({x-1,y});
                
                pacificA[x-1][y] = true;
            }

        }
    }
    while (!atlantic.empty()) {
        current = atlantic.top();
        atlantic.pop();
        int value = heights[current.first][current.second];
        int x = current.first;
        int y = current.second;
        if (y + 1 < heights[0].size() && heights[x][y + 1] >= value) {
            if (!atlanticA[x][y+1]) {

                atlantic.push({x,y+1});
                // atlanticA.push_back({0,y});
                atlanticA[x][y+1] = true;
            }
        }
        if (y - 1 >= 0 && heights[x][y - 1] >= value) {
            if (!atlanticA[x][y -1]) {

                atlantic.push({x, y - 1});
                // atlanticA.push_back({0,y-1});
                atlanticA[x][y-1] = true;
            }

        }
        if (x + 1 < heights.size() && heights[x+1][y] >= value) {
            if (!atlanticA[x+1][y]) {

                atlantic.push({x+1, y});
                // atlanticA.push_back({x+1,y});
                atlanticA[x+1][y] = true;
            }


        }
        if (x - 1 >= 0 && heights[x -1][y] >= value) {
            if (!atlanticA[x-1][y]) {
    
                atlantic.push({x-1, y});
                // atlanticA.push_back({x-1,y});
                atlanticA[x-1][y] = true;
            }

        }
    }
    for (int i = 0; i< heights.size(); i++) {
        for (int j = 0; j < heights[0].size(); j++) {
            if (atlanticA[i][j] == true && pacificA[i][j] == true) {
                answer.push_back({i, j});
            }
        }
    }
    vector<vector<int>> answerA;
    for (int i = 0; i < answer.size(); i++) {
        current = answer[i];
        answerA.push_back({current.first, current.second});
    }
    return answerA;


    
    
    
    
    }
};
