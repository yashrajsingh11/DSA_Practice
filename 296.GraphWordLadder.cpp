// Approach : Use BFS in the wordlist to queue the elements which differ by only one letter.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool oneLetterDiff(string A, string B) {
    int count = 0;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] != B[i]) {
            count++;
            if(count > 1) {
                return false;
            }
        }
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    vector<bool> visited;
    for(int i = 0; i < wordList.size(); i++) {
        visited.push_back(false);
    }
    queue<string> q;
    q.push(beginWord);
    int answer = 1;
    int count = 1;
    int tempcount = 0;
    
    while(!q.empty()) {
        if(count == 0) {
            answer++;
            count = tempcount;
            tempcount = 0;
        }
        string temp = q.front();
        q.pop();
        if(temp == endWord) {
            return answer;
        }
        for(int i = 0; i < wordList.size(); i++) {
            if(visited[i] == false) {
                if(oneLetterDiff(wordList[i], temp) == true) {
                    q.push(wordList[i]);
                    tempcount++;
                    visited[i] = true;
                }
            }
        }
        count--;
    }
    return 0;
}

int main() {
	vector<string> wordList = {"hot", "dot", "dog", "lot", "cog", "log"};
	string beginWord = "hit";
	string endWord = "cog";
	cout << ladderLength(beginWord, endWord, wordList);
	return 0;
}