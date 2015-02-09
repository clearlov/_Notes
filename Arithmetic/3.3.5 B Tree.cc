template <typename T>
class BinaryTree{
    protected:
    T curValue;
    BinaryTree * leftNode;
    BinaryTree * rightNode;
    public:
};

/**
 * Max/Min Tree: Value of every parent node is great/less or equal than its child's.
 * O = O(log_2(n))
 */

template <typename T>
class MaxTree: public BinaryTree<T>{
    public:
    MaxTree():lNode(0),rNode(0){};    // assign to null ptr
    // MaxTree(const T& v):curValue(v),lNode(0),rNode(0){};
    MaxTree(T& v, MaxTree<T> *l=0, MaxTree<T> *r=0):curValue(v),lNode(l),rNode(r){};
    friend void find(T node);
    friend void insert(T node);
    friend void del(T node);
    friend void traversal();
};