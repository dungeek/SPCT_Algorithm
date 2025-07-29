/*
Có n cuộc họp đánh số từ 1 đến n đăng ký làm việc tại một phòng hội thảo. Cuộc họp i cần được bắt đầu ngay sau thời điểm si và kết thúc tại thời điểm f­i. Hỏi có thể bố trí phòng hội thảo phục vụ được nhiều nhất bao nhiêu cuộc họp, sao cho khoảng thời gian làm việc của hai cuộc họp bất kỳ là không giao nhau.

Input
Dòng đầu tiên chứa số nguyên dương n ( n <= 10000)
Dòng thứ i trong số n dòng tiếp theo chứa hai số nguyên dương si, fi (si < fi <= 32000) ( 1 <= i <= n).
Output
Dòng đầu tiên ghi số K là số các cuộc họp được chấp nhận phục vụ

Input:
5

7 9

2 4

1 3

1 6

3 7

Output:
3
*/

#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; ++i) {
        cin >> meetings[i].first >> meetings[i].second; // (start, end)
    }

    // Sort meetings by finish time
    sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int count = 0;
    int last_end = 0;

    for (const auto& m : meetings) {
        int start = m.first, end = m.second;
        if (start >= last_end) {                 // Nếu điểm đầu của khoảng vượt ra khỏi khoảng trước đó thì +1 meeting
            count++;
            last_end = end;
        }
    }

    cout << count << endl;

    return 0;
}
