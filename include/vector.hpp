#include <iostream>

class tree_t
{
private:
    struct node_t
    {
        node_t* left = nullptr;
        node_t* right = nullptr;
        int value = 0;
    };

private:
    node_t* root_;

public:
    tree_t()
    {
        root_ = nullptr;
    }
    node_t* root()
    {
        return root_;
    }

    void check_operator(std::ostream& stream, char op, int value)
    {
        switch (op)
        {
            case '+':
            {
                insert(value);
                break;
            }
            case '?':
            {
                find(value);
                break;
            }
            case '=':
            {
                print(stream, 0, root_);
                break;
            }
            case 'q':
            {
                exit(0);
                break;
            }
            default:
            {
               throw std::invalid_argument("Error of use operator");
            }
        }
    }

    void insert(int value)
    {
        node_t* node = new node_t;
        node->value = value;
        node->right = nullptr;
        node->left = nullptr;
        if (root_ == nullptr)
        {
            root_ = node;
            return;
        }

        node_t* vetka = root_;
        while (vetka != nullptr)
        {
            if (vetka->value < value)
            {
                if (vetka->right != nullptr)
                {
                    vetka = vetka->right;
                }
                else
                {
                    vetka->right = node;
                    return;
                }
            }
            else if (vetka->value > value)
            {
                if (vetka->left != nullptr)
                {
                    vetka = vetka->left;
                }
                else
                {
                    vetka->left = node;
                    return;
                }
            }
            else
                return;
        }
    }
    bool find(int value) const
    {
        node_t* node = root_;
        while (node != nullptr)
        {
            if (node->value == value)
            {
                return true;
            }
            else
            {
                if (value <= node->value)
                {
                    node = node->left;
                }
                else
                    node = node->right;
            }
        }
        return false;
    }

    void print(std::ostream& stream, int level, node_t* node)
    {
        if (node == nullptr)
            return;

        print(std::stream, level + 1, node->right);

        for (unsigned int i = 0; i < level; i++)
        {
            std::stream << "---";
        }
          std::stream << node->value <<   std::endl;

        print(std::stream, level + 1, node->left);
    }

    void destroy(node_t* node)
    {
        node_t* time = node;
        while (time != nullptr)
        {
            if (time->left != nullptr)
            {
                time = time->left;
            }
            else if (time->right != nullptr)
            {
                time = time->right;
            }
            else if (time == node && node->left == nullptr && node->right == nullptr)
            {
                delete time;
                break;
            }
            else if (time->left == nullptr && time->right == nullptr)
            {
                delete time;
                time = node;
            }
        }
    }
    ~tree_t()
    {
        destroy(root_);
    }
};
