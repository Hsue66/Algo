#include<stdio.h>

#include<iostream>
using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int N, idx, last =0, flag = 1;
		scanf("%d", &N);
		int rootLen = N - (N + 1) / 2;
		for (int i = 0; i < N; i++) {
			scanf("%d", &idx);
			char unknown[5];
			scanf("%s", unknown);
			if (idx <= rootLen ) {  // internal node 입력받기
				for (int k = 0; k < 2 && last != N; k++)
					scanf("%d", &last);
			}
			if ('0' <= unknown[0] && unknown[0] <= '9') {  // 숫자인데 internal인 경우
				if (idx <= rootLen)
					flag = 0;
			}
			else {   // 문자인데 leaf인 경우 
				if (rootLen < idx)
					flag = 0;
			}
		}
		printf("#%d %d\n", t + 1, flag);
	}
}
