#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  // emptyProb[x][y] = probability that (x,y) has no robot
  ld emptyProb[8][8];

  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      emptyProb[x][y] = 1.0;

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  // Start one robot from every square
  for (int sx = 0; sx < 8; sx++) {
    for (int sy = 0; sy < 8; sy++) {

      ld dp[8][8] = {};

      // This robot starts here
      dp[sx][sy] = 1.0;

      // Move this robot k times
      for (int step = 0; step < k; step++) {
        ld ndp[8][8] = {};

        for (int x = 0; x < 8; x++) {
          for (int y = 0; y < 8; y++) {

            if (dp[x][y] == 0)
              continue;

            // Count legal moves from (x,y)
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
              int nx = x + dx[d];
              int ny = y + dy[d];

              if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                cnt++;
            }

            // Spread probability equally
            for (int d = 0; d < 4; d++) {
              int nx = x + dx[d];
              int ny = y + dy[d];

              if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                ndp[nx][ny] += dp[x][y] / cnt;
            }
          }
        }

        memcpy(dp, ndp, sizeof(dp));
      }

      // This robot must NOT land on (x,y)
      for (int x = 0; x < 8; x++) 
        for (int y = 0; y < 8; y++) 
          emptyProb[x][y] *= (1.0 - dp[x][y]);
    }
  }

  // Sum probability of every square being empty
  ld ans = 0;

  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      ans += emptyProb[x][y];

  cout << fixed << setprecision(6) << ans << '\n';

  return 0;
}