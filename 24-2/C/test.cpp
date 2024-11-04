#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> v, int m, int n) {
    queue<pair<int, int>> q;  // dfs를 위한 큐 생성, x,y좌표.
    bool visited[n + 1][m + 1] = {
        {
            false,
        },
    };  // 해당 좌표를 들렀는지 확인하기 위함

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {        // 값이 1부터 시작
                q.push({i, j});        // 처음 시작하는 좌표들을 큐에 푸쉬
                visited[i][j] = true;  // 방문했슴
            }
        }
    }

    while (!q.empty()) {  // 큐가 비워지기 전까지 반복
        int x1, y1;

        y1 = q.front().first;
        x1 = q.front().second;

        q.pop();
        // 밑에는 모든 방향확인하기 조건
        if (x1 + 1 < m) {
            if (v[y1][x1 + 1] == 0 && visited[y1][x1 + 1] == false) {
                q.push({y1, x1 + 1});
                visited[y1][x1 + 1] = true;
                v[y1][x1 + 1] = v[y1][x1] + 1;
            }
        }
        if (x1 - 1 >= 0) {
            if (v[y1][x1 - 1] == 0 && visited[y1][x1 - 1] == false) {
                q.push({y1, x1 - 1});
                visited[y1][x1 - 1] = true;
                v[y1][x1 - 1] = v[y1][x1] + 1;
            }
        }
        if (y1 + 1 < n) {
            if (v[y1 + 1][x1] == 0 && visited[y1 + 1][x1] == false) {
                q.push({y1 + 1, x1});
                visited[y1 + 1][x1] = true;
                v[y1 + 1][x1] = v[y1][x1] + 1;
            }
        }
        if (y1 - 1 >= 0) {
            if (v[y1 - 1][x1] == 0 && visited[y1 - 1][x1] == false) {
                q.push({y1 - 1, x1});
                visited[y1 - 1][x1] = true;
                v[y1 - 1][x1] = v[y1][x1] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] > max) {
                max = v[i][j];
            }
            if (v[i][j] == 0) {  // 만약 bfs로 갈수 없는 곳이 있어 0인곳이 있다면, 토마토가 다 변할 수 없기에 -1출력
                cout << -1;
                return;
            }
        }
    }

    cout << max - 1;
}

int main() {
    int m, n;

    cin >> m >> n;  // 가로 세로

    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        vector<int> v1;
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            v1.push_back(t);
        }
        v.push_back(v1);
    }

    dfs(v, m, n);

    return 0;
}