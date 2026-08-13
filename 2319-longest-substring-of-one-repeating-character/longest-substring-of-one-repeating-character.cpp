#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;
    int prefix_len;
    int suffix_len;
    char first_char;
    char last_char;
    int segment_len;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.segment_len = left.segment_len + right.segment_len;
        res.first_char = left.first_char;
        res.last_char = right.last_char;

        res.max_len = max(left.max_len, right.max_len);

        // Check merge at the boundary
        if (left.last_char == right.first_char) {
            res.max_len = max(res.max_len, left.suffix_len + right.prefix_len);
        }

        // Calculate prefix length
        if (left.prefix_len == left.segment_len && left.last_char == right.first_char) {
            res.prefix_len = left.prefix_len + right.prefix_len;
        } else {
            res.prefix_len = left.prefix_len;
        }

        // Calculate suffix length
        if (right.suffix_len == right.segment_len && left.last_char == right.first_char) {
            res.suffix_len = right.suffix_len + left.suffix_len;
        } else {
            res.suffix_len = right.suffix_len;
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMax() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryIndices.size();
        vector<int> ans(k);
        SegmentTree st(s);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};