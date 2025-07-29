#include <bits/stdc++.h>
using namespace std;

#define MAXN (100)
int N;
char map[MAXN + 10][MAXN + 10];

char ans;//구매자 이름 Buyer's name
int areacnt;//구매자 영역 개수 Number of buyer's area

void InputData(void) {
	scanf("%d", &N);
	for (int h = 0; h < N; h++) {
		scanf("%s", map[h]);
	}
}

int main(void) {
	InputData();// 입력받는 부분 Input

	// 여기서부터 작성 Write from here

	printf("%c %d\n", ans, areacnt);// 출력하는 부분 Output
	return 0;
}