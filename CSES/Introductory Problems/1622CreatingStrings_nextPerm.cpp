#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	// perms is a sorted list of all the permutations of the given string
	vector<string> perms;
	do { perms.push_back(s); } while (next_permutation(s.begin(), s.end()));

	cout << perms.size() << endl;
	for (const string &perm : perms) { cout << perm << endl; }
}