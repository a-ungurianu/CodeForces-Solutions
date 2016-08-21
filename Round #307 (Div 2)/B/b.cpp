#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> subtract(const vector<int> &a, const vector<int> &b) {
	if(a.size() != b.size()) {
		throw "Sizes must be equal!";
	}

	vector<int> res(a.size());
	for(int i = 0; i < a.size(); ++i) {
		res[i] = a[i] - b[i];
	}

	return res;
}

bool has_negatives(const vector<int> &v) {
	for(int val:v) {
		if(val < 0) {
			return true;
		}
	}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	string a,b,c;

	cin >> a >> b >> c;

	vector<int> letters_a('z'-'a' + 1, 0);
	vector<int> letters_b('z'-'a' + 1, 0);
	vector<int> letters_c('z'-'a' + 1, 0);

	for(char cc:a) {
		letters_a[cc-'a']++;
	}
	for(char cc:b) {
		letters_b[cc-'a']++;
	}
	for(char cc:c) {
		letters_c[cc-'a']++;
	}

	if(a.size() < b.size() && a.size() < c.size()) {
		cout << a << '\n';
		return 0;
	}

	if(a.size() < b.size()) {
		string res = "";	
		while(true) {
			if(has_negatives(subtract(letters_a,letters_c))) {
				break;
			}
			res += c;
			letters_a = subtract(letters_a,letters_c);
		}
		for(int i = 0;i < letters_a.size(); ++i) {
			res += string(letters_a[i],'a' + i);
		}
		cout << res << '\n';
		return 0;
	}

	if(a.size() < c.size()) {
		string res = "";	
		while(true) {
			if(has_negatives(subtract(letters_a,letters_b))) {
				break;
			}
			res += b;
			letters_a = subtract(letters_a,letters_b);
		}
		for(int i = 0;i < letters_a.size(); ++i) {
			res += string(letters_a[i],'a' + i);
		}
		cout << res << '\n';
		return 0;
	}

	vector<int> saved_letters_a = letters_a;

	string res1 = "";
	int sub_count1 = 0;	
	while(true) {
		if(has_negatives(subtract(letters_a,letters_b))) {
			break;
		}
		res1 += b;
		letters_a = subtract(letters_a,letters_b);
		sub_count1++;
	}
	while(true) {
		if(has_negatives(subtract(letters_a,letters_c))) {
			break;
		}
		res1 += c;
		letters_a = subtract(letters_a,letters_c);
		sub_count1++;
	}
	for(int i = 0;i < letters_a.size(); ++i) {
		res1 += string(letters_a[i],'a' + i);
	}

	letters_a = saved_letters_a;

	string res2 = "";
	int sub_count2 = 0;
	while(true) {
		if(has_negatives(subtract(letters_a,letters_c))) {
			break;
		}
		res2 += c;
		letters_a = subtract(letters_a,letters_c);
		sub_count2++;
	}
	while(true) {
		if(has_negatives(subtract(letters_a,letters_b))) {
			break;
		}
		res2 += b;
		letters_a = subtract(letters_a,letters_b);
		sub_count2++;
	}
	for(int i = 0;i < letters_a.size(); ++i) {
		res2 += string(letters_a[i],'a' + i);
	}

	if(sub_count1 > sub_count2) {
		cout << res1 << '\n';
	}
	else {
		cout << res2 << '\n';
	}

	return 0;
}