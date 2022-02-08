// πÈ¡ÿ 1764 - µË∫∏¿‚

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void yapp(vector<string> vec) {
	int count = 0;
	sort(vec.begin(), vec.end());
	auto pos = unique(vec.begin(), vec.end());
	for (auto it=vec.begin(); it < pos; it++) {
		count++;
	}
	cout << count << endl;
	for (auto ir = vec.begin(); ir < pos; ir++) {
		cout << *ir << endl;
	}
}

int main() {
	int N, M;
	int maxNum, minNum;
	cout << "µËX, ∫∏X => ";
	cin >> N >> M;

	if (N > M) {
		maxNum = N; minNum = M;
	}
	else {
		maxNum = M; minNum = N;
	}
	
	vector<string> list;
	for (int i = 0; i < M+N; i++) {
		cin >> list[i];
	}


	/*
	vector<string> NH_list(maxNum);
	vector<string> NS_list(maxNum);
	
	
	for (int i = 0; i < N; i++) {
		cin >> NH_list[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> NS_list[i];
	}
	
	for (int i = 0; i < maxNum; i++) {
		for (int k = 0; k < minNum; k++) {
			if (N >= M) {
				if (NH_list[i] == NS_list[k]) {
					list.push_back(NH_list[i]);
				}
			}
			else {
				if (NH_list[k] == NS_list[i]) {
					list.push_back(NS_list[i]);
				}
			}
		}
	} */

	yapp(list);
}