#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(const vector<int>& v)
{
    vector<int>::size_type i;
    for (i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

class Traversal {
public:
    vector<int> preorder(TreeNode *root) {
        vector<int> ret;
        if (root == NULL)
            return ret;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if (cur->right != NULL)
                s.push(cur->right);
            if (cur->left != NULL)
                s.push(cur->left);
        }
        return ret;
    }

    vector<int> inorder(TreeNode *root) {
        vector<int> ret;
		if (root == NULL)
			return ret;

        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (true) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
			ret.push_back(cur->val);
            cur = cur->right;
        }
        return ret;
    }
};

// recursive3
class Solution {
public:
	TreeNode* removeNode(TreeNode* root, int value) {
		if (root == NULL)
			return root;

		if (value < root->val) {
			root->left = removeNode(root->left, value);
		} else if (value > root->val) {
			root->right = removeNode(root->right, value);
		} else {
			if (root->left == NULL)
				return root->right;
			else if (root->right == NULL)
				return root->left;

			TreeNode* p = minValNode(root->right);
			root->val = p->val;
			root->right = removeNode(root->right, p->val);
		}
		return root;
	}

private:
	TreeNode* minValNode(TreeNode* root) {
		if (root == NULL)
			return root;

		TreeNode* p = root;
		while (p->left != NULL)
			p = p->left;
		return p;
	}
};

class Solution_Recursive2 {
public:
	TreeNode* removeNode(TreeNode* root, int value) {
		if (root == NULL)
			return root;

		TreeNode dummy(0);
		dummy.left = root;
		rm(root, &dummy.left, value);
		return dummy.left;
	}

private:
	void rm(TreeNode* root, TreeNode** parentlink, int value) {
		if (root == NULL)
			return;

		if (value < root->val) {
			rm(root->left, &root->left, value);
		} else if (value > root->val) {
			rm(root->right, &root->right, value);
		} else {
			if (root->left==NULL && root->right==NULL) {
				*parentlink = NULL;
			} else if (root->left == NULL) {
				*parentlink = root->right;
			} else if (root->right == NULL) {
				*parentlink = root->left;
			} else {
				TreeNode* p = root->right;
				TreeNode* pre = NULL;
				while (p->left != NULL) {
					pre = p;
					p = p->left;
				}
				if (pre != NULL)
					pre->left = p->right;
				p->left = root->left;
				p->right = root->right;
				*parentlink = p;
			}
		}
	}
};

class Solution_Recursive1 {
public:
    TreeNode* removeNode(TreeNode* root, int value) {
		if (root == NULL)
			return root;

		rm(root, NULL, value);
		return root;
	}

private:
	void rm(TreeNode* root, TreeNode* parent, int value) {
		if (root == NULL)
			return;

		if (value == root->val) {
			if (root->left==NULL && root->right==NULL) {
				if (parent->left == root)
					parent->left = NULL;
				else
					parent->right = NULL;
			} else if (root->left == NULL) {
				if (parent->left == root)
					parent->left = root->right;
				else
					parent->right = root->right;
			} else if (root->right == NULL) {
				if (parent->left == root)
					parent->left = root->left;
				else
					parent->right = root->left;
			} else {
				TreeNode* p = root->right;
				TreeNode* pre = NULL;
				while (p->left != NULL) {
					pre = p;
					p = p->left;
				}
				if (pre != NULL)
					pre->left = p->right;
				p->left = root->left;
				if (parent->left == root)
					parent->left = p;
				else
					parent->right = p;
			}
		} else if (value < root->val) {
			rm(root->left, root, value);
		} else {
			rm(root->right, root, value);
		}
	}
};

class Solution_Iter {
public:
    TreeNode* removeNode(TreeNode* root, int value) {
		if (root == NULL)
			return NULL;

		if (find(root, value) == NULL)
			return root;

		if (root->val == value) {
			if (root->left==NULL && root->right==NULL)
				return NULL;
			else if (root->left == NULL)
				return root->right;
			else if (root->right == NULL)
				return root->left;
			else
				return del_root(root, value);
		} else {
			TreeNode* cur = find(root, value);
			TreeNode* fat = father(root, value);
			if (cur->left==NULL && cur->right==NULL) {
				if (fat->left == cur)
					fat->left = NULL;
				else
					fat->right = NULL;
				return root;
			}
			if (cur->left==NULL) {
				if (fat->left == cur)
					fat->left = cur->right;
				else
					fat->right = cur->right;
				return root;
			}
			if (cur->right==NULL) {
				if (fat->left == cur)
					fat->left = cur->left;
				else
					fat->right = cur->left;
				return root;
			}
			return del(root, cur, fat, value);
		}
    }

private:
	TreeNode* del(TreeNode* root, TreeNode* cur, TreeNode* fat, int value) {
		if (cur->right->left == NULL) {
			cur->right->left = cur->left;
			if (fat->right == cur)
				fat->right = cur->right;
			else
				fat->left = cur->right;
		} else {
			TreeNode* p = cur->right;
			TreeNode* pre = p;
			while (p->left != NULL) {
				pre = p;
				p = p->left;
			}
			pre->left = p->right;
			p->left = cur->left;
			p->right = cur->right;
			if (fat->right == cur)
				fat->right = p;
			else
				fat->left = p;
		}
		return root;
	}

	TreeNode* del_root(TreeNode* root, int value) {
		if (root->right->left == NULL) {
			root->right->left = root->left;
			return root->right;
		} else {
			TreeNode* cur = root->right;
			TreeNode* pre = cur;
			while (cur->left != NULL) {
				pre = cur;
				cur = cur->left;
			}
			pre->left = cur->right;
			cur->left = root->left;
			cur->right = root->right;
			return cur;
		}
	}

	TreeNode* father(TreeNode* root, int value) {
		if (root == NULL)
			return NULL;

		if (root->left == NULL) {
			if (root->right->val == value)
				return root;
			return father(root->right, value);
		} else if (root->right == NULL) {
			if (root->left->val == value)
				return root;
			return father(root->left, value);
		} else {
			if (root->left->val == value)
				return root;
			if (root->right->val == value)
				return root;
			TreeNode* cur = father(root->left, value);
			if (cur != NULL)
				return cur;
			return father(root->right, value);
		}
	}

	TreeNode* find(TreeNode* root, int value) {
		if (root == NULL)
			return NULL;

		if (value == root->val)
			return root;
		else if (value < root->val)
			return find(root->left, value);
		else
			return find(root->right, value);
	}
};

int main(int argc, char *argv[])
{
    // TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(50);
    TreeNode *t3 = new TreeNode(15);
    t3->left = t1;
    t3->right = t2;
    TreeNode *t4 = new TreeNode(80);
    TreeNode *t5 = new TreeNode(60);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(30);
    t2->left = t6;
    // TreeNode *t7 = new TreeNode(10);
    // t1->right = t7;

	Solution s;
	TreeNode *root = s.removeNode(t5, 15);

	Traversal tra;
    print(tra.preorder(root));
	print(tra.inorder(root));

    return 0;
}
