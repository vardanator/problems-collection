#include <vector>
#include <iostream>

class BST
{
public:
    struct Node
    {
        int item;
        Node* left;
        Node* right;

        Node() {}
        Node(int i) : item(i), left(nullptr), right(nullptr) {}
    };

public:
    void Print()
    {
        Print_(root_);
        std::cout << std::endl;
    }

    void ConstructFromSortedArray(const std::vector<int>& arr)
    {
        root_ = ConstructFromSortedArrayRecursive_(arr, 0, arr.size());
    }

private:
    Node* ConstructFromSortedArrayRecursive_(const std::vector<int>& arr, int lo, int hi)
    {
        if (lo == hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        Node* cur = new Node(arr[mid]);
        cur->left = ConstructFromSortedArrayRecursive_(arr, lo, mid);
        cur->right = ConstructFromSortedArrayRecursive_(arr, mid + 1, hi);
        return cur;
    }

    void Print_(Node* node)
    {
        if (node == nullptr) return;
        Print_(node->left);
        std::cout << node->item << " ";
        Print_(node->right);
    }

private:
    Node* root_;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    BST b;
    b.ConstructFromSortedArray(std::vector<int>(arr, arr + 7));
    b.Print();

}
