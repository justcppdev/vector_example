#include <iostream>
using namespace std;
template <typename T>
class tree_t {
private:
    struct node_t {
        node_t* left;
        node_t* right;
        T value;
    };

private:
    node_t* root_;

public:
    tree_t() { root_ = nullptr; }

    node_t* root() const { return root_; }
    tree_t(std::initializer_list<int> keys) : tree_t() {
        for (auto key : keys) {
            insert(key);
        }
    }
    void insert(T value) {
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
                } else {
                    vetka->right = node;
                    return;
                }
            } else if (vetka->value > value) {
                if (vetka->left != nullptr) {
                    vetka = vetka->left;
                } else {
                    vetka->left = node;
                    return;
                }
            } else
                return;
        }
    }
    bool find(T value) const {
        node_t* node = root_;
        while (node != nullptr) {
            if (node->value == value) {
                return true;
            } else {
                if (value <= node->value) {
                    node = node->left;
                } else
                    node = node->right;
            }
        }
        return false;
    }

    void print(std::ostream& stream, int level, node_t* node) const {
        if (node == nullptr) return;

        print(stream, level + 1, node->right);

        for (unsigned int i = 0; i < level; i++) {
            stream << "---";
        }
        stream << node->value << endl;

        print(stream, level + 1, node->left);
    }
    void operation(std::ostream& stream, char op, int value) {
        switch (op) {
            case '+': {
                insert(value);
                break;
            }
            case '?': {
                find(value);
                break;
            }
            case '=': {
                print(stream, 0, root_);
                break;
            }
            case 'q': {
                exit(0);
                break;
            }
            default: { cout << "invalid operation"; }
        }
    }
    bool remove(T value) {
        auto pair = find_(value);
        if (!pair.first) {
            return false;
        }

        auto removed_node = pair.first;
        auto removed_node_parent = pair.second;

        if (!removed_node->left && !removed_node->right) {
            if(removed_node == removed_node_parent->right) removed_node_parent->right = nullptr;
            if(removed_node == removed_node_parent->left) removed_node_parent->left = nullptr;
        } else if (removed_node->left && !removed_node->right) {
            transplant(removed_node->left, removed_node_parent, false);
        } else if (removed_node->right && !removed_node->left) {
            transplant(removed_node->right, removed_node_parent, false);
        }

        else {  //когда есть два сына у удаляемого элемента
            auto pair = min_(removed_node->right, removed_node);
            auto leftest_node = pair.first;
            auto leftest_node_parent = pair.second;

            transplant(leftest_node->right, leftest_node_parent, false);
            if(leftest_node == leftest_node_parent->right) leftest_node_parent->right = nullptr;
            if(leftest_node == leftest_node_parent->left) leftest_node_parent->left = nullptr;
            transplant(leftest_node, removed_node_parent, true);

        }

        delete removed_node;

    }

    std::pair<node_t*, node_t*> find_(T value) {
        node_t* node = root_;
        node_t* parent = nullptr;  // родитель элемента, которого нам нужно удалить
        while ((node != nullptr) && (node->value != value)) {
            parent = node;
            if (value < node->value)
                node = node->left;
            else
                node = node->right;
        }
        return {node, parent};
    };

    std::pair<node_t*, node_t*> min_(node_t* node, node_t* parent) {
        assert(node);

        while (node->left) {
            parent = node;
            node = node->left;
        }
        return {node, parent};
    };
    void transplant(node_t* node, node_t* parent, bool move_children) {
        if (!node) {
            return;
        }
        node_t* child = nullptr;
        if (parent == nullptr) {
            node->left = root_->left;
            node->right = root_->right;
            root_ = node;

        } else {
            if (parent->value < node->value) {
                child = parent->right;
                parent->right = node;
            } else {
                child = parent->left;
                parent->left = node;
            }

            if (move_children && child) {
                 node->left = child->left;
                 node->right = child->right;
                child->left = nullptr;
                child->right = nullptr;
            }
        }
    }
    void destroy(node_t* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    ~tree_t() { destroy(root_); }
    bool euqal(node_t* lhs, node_t* rhs) const {
        if (lhs == nullptr && rhs == nullptr)
            return true;

        else if (lhs != nullptr && rhs != nullptr && lhs->value == rhs->value) {
            return (euqal(lhs->left, rhs->left) && euqal(lhs->right, rhs->right));
        } else
            return false;
    }

    bool operator==(tree_t const& other) const {
        return euqal(root_, other.root_);
    }

    void print(std::ostream& stream) const { print(stream, 0, root_); }
};
