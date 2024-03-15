#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to check if a text is a palindrome
bool isPalindrome(string text) {
    int left = 0, right = text.size() - 1;
    while (left < right) {
        if (text[left] != text[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to find all the texts in the binary tree
// and check if they are palindromes
int countPalindromes(vector<vector<int>>& tree, vector<char>& chars, int node, string text) {
    // Add the current node's character to the text
    text += chars[node];

    // If this node is a leaf, check if the text is a palindrome
    if (tree[node][0] == -1 && tree[node][1] == -1) {
        if (isPalindrome(text)) {
            return 1;
        } else {
            return 0;
        }
    }

    // Recurse on the left and right children and sum the number of palindromes
    int count = 0;
    if (tree[node][0] != -1) {
        count += countPalindromes(tree, chars, tree[node][0], text);
    }
    if (tree[node][1] != -1) {
        count += countPalindromes(tree, chars, tree[node][1], text);
    }
    return count;
}

int main() {
    // Read the input string
    string S;
    cin >> S;

    // Create a vector of characters from the input string
    vector<char> chars;
    for (char c : S) {
        chars.push_back(c);
    }

    // Read the binary tree in level order
    vector<vector<int>> tree(S.size(), vector<int>(2, -1));
    for (int i = 0; i < S.size(); i++) {
        cin >> tree[i][0] >> tree[i][1];
        tree[i][0]--;
        tree[i][1]--;
    }

    // Find the number of texts that form palindromes
    cout << countPalindromes(tree, chars, 0, "") << endl;

    return 0;
}
