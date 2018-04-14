#include <iostream>

class tree_t {
 private:
  struct node_t {
    node_t* left;
    node_t* right;
    int value;
  };

 private:
  node_t* root_;

 public:
  tree_t() { root_ = nullptr; }

  node_t* root() { return root_; }
 
 tree_t(std::initializer_list<int> keys)
{
	int n = keys.size();
	const int* _ptr = keys.begin();
	for (int i=0; i < n; i++)
	{
		insert(_ptr[i]);
	}
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
  bool find(int value) const {
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

  void print(std::ostream& stream, int level, node_t* node) {
    if (node == nullptr) return;

    print(stream, level + 1, node->right);

    for (unsigned int i = 0; i < level; i++) {
      stream << "---";
    }
    stream << node->value << std::endl;

    print(stream, level + 1, node->left);
  }
 bool remove(int value) {
        if (!find(value))
            return false;
        node_t* node = root_;
        node_t* q = nullptr; // родитель элемента, которого нам нужно удалить
        while( (node!=nullptr) && (node->value!=value)) {
            q = node;
            if(value < node->value) node=node->left;
            else node=node->right;

        }
        node_t* v; // установить в сортировочном виде дерева.
        
        if (node->left==nullptr)  v = node->right;
        else if ( node->right==nullptr)  v = node->left;
        
        else  {
            node_t* s;
            node_t* t;
            t= node;
            v=node->right;
            s=v->left;
            while(s != nullptr){
                t=v;
                v= s;
                s =  v->left;
            }
           if(t !=node){
               t->left = v->right;
               v->left = node->left;
               v->right = node->right;
           }
           else {
               v->left = node->left;
               
           }
    }
        if(q == nullptr){
            root_ = v;
        }
        else if ( node == q->right) q->right = v;
        else q->left = v;
        delete node;
    }
	bool equally(node_t* first, node_t* second ) const{
         if( first == nullptr && second == nullptr) return true;
     
         else if( first != nullptr && second != nullptr && first->value == second->value){
             return equally(first->left,second->left) && equally(first->right, second->right);
         }
        
         else return false;
     }
     auto operator==(tree_t const & other) const{
         return(equally(root_,other.root()));
     }
  void act(char op, int value, std::ostream& stream) {
    switch (op) {
      case '?': {
        if (find(value)) {
          stream << "true";
        } else
          stream << "false";
        break;
      }
      case '=': {
        print(stream, 0, root_);
        break;
      }

      default: { std::cout << "invalid operation"; }
    }
  }

  void act1(char op, int value) {
    switch (op) {
      case '+': {
        insert(value);
        break;
      }
      case 'q': {
        exit(0);
        break;
      }
      default: { std::cout << "invalid operation"; }
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
};
