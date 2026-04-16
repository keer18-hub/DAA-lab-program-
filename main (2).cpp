#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for priority queue (min heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Leaf node
    if (root->ch != '$')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char ch[n];
    int freq[n];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> ch[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes and push into queue
    for (int i = 0; i < n; i++) {
        pq.push(new Node(ch[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}