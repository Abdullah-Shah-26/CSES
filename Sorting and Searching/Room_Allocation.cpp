#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin(), a.end());

    // {departure, room id}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> ans(n);

    int rooms = 0;

    for (int i = 0; i < n; i++) {

        int start = a[i][0];
        int end = a[i][1];
        int idx = a[i][2];

        if (!pq.empty() && pq.top().first < start) {

            int room = pq.top().second;
            pq.pop();

            ans[idx] = room;
            pq.push({end, room});

        } else {

            rooms++;
            ans[idx] = rooms;
            pq.push({end, rooms});
        }
    }

    cout << rooms << '\n';

    for (int x : ans)
        cout << x << " ";
}