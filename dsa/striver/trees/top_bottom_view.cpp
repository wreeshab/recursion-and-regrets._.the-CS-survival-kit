//Top View (only the first node at each horizontal distance)
//
vector<int> topView(Node* root) {
    map<int, int> hd_node; // hd -> node value
    queue<pair<Node*, int>> q; // node, hd
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        if (hd_node.count(hd) == 0) // first time this hd seen
            hd_node[hd] = node->data;
        
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (auto& [hd, val] : hd_node) result.push_back(val);
    return result;
}


//Bottom View (last node seen at each horizontal distance) overwrite.
vector<int> bottomView(Node* root) {
    map<int, int> hd_node; // hd -> node value
    queue<pair<Node*, int>> q; // node, hd
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        hd_node[hd] = node->data; // overwrite every time
        
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (auto& [hd, val] : hd_node) result.push_back(val);
    return result;
}

