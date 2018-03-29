#include <iostream>
#include <algorithm>
#include <cassert>

class tree_t
{
private:
	struct node_t {
		node_t * left=nullptr;
		node_t * right = nullptr;
		int value = 0;
	};
private:
	node_t * root_;
public:
	tree_t() {
		root_ = nullptr;
	}
	node_t* root() { return root_; }
	~tree_t() {
		node_t * time_node = new node_t;
		time_node = root_;
		while (time_node!= nullptr) 
		{
			if (time_node->left != nullptr) 
			{
				time_node = time_node->left;
			}
			else if (time_node->right != nullptr)
			{
				time_node = time_node->right;
			}
			else if (time_node->left == nullptr && time_node->right == nullptr)
			{
				delete[] time_node->left;
				delete[] time_node->right;
				time_node = root_;
				if (time_node->left == nullptr && time_node->right == nullptr) 
				{
					time_node = nullptr;
					cout << "delete root";
				}
				cout << "udalil";
			}
		}
		delete[] time_node;
	}
	void insert(int value) {
		node_t* node = new node_t;
		node->value = value;
		node->right = nullptr;
		node->left = nullptr;
		if (root_ == nullptr) {
			root_ = node;
			return;
		}

		node_t* vetka = root_;
		while (vetka != nullptr) {
			if (vetka->value < value) {
				if (vetka->right != nullptr) {
					vetka = vetka->right;
				}
				else {
					vetka->right = node;
					return;
				}
			}
			else if (vetka->value > value) {
				if (vetka->left != nullptr) {
					vetka = vetka->left;
				}
				else {
					vetka->left = node;
					return;
				}
			}
			else
				return;
		}
	}
	bool find(int value) const {
		node_t * node = root_;
		while (node != nullptr) {
			if (node->value == value) {
				return true;
			}
			else {
				if (value <= node->value) {
					node = node->left;
				}
				else node = node->right;
			}
		}
		return false;
	}

	void print(std::ostream& stream, int level, node_t* node) {
		if (node == nullptr)
			return;

		print(stream, level + 1, node->right);

		for (unsigned int i = 0; i < level; i++) {
			stream << "---";
		}
		stream << node->value << endl;

		print(stream, level + 1, node->left);
	}
};
