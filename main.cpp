#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tree {
    string type;
    double price;
};

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void PrintTrees(const vector<Tree>& trees, int index = 0) {
    if (index == trees.size()) return;
    cout << index + 1 << ". Type: " << trees[index].type << ", Price: " << trees[index].price << " USD" << endl;
    PrintTrees(trees, index + 1);
}

void SortTreesByPrice(vector<Tree>& trees) {
    for (size_t i = 0; i < trees.size() - 1; i++) {
        for (size_t j = 0; j < trees.size() - i - 1; j++) {
            if (trees[j].price > trees[j + 1].price) {
                Swap(trees[j], trees[j + 1]);
            }
        }
    }
}

bool FindTree(const vector<Tree>& trees, const string& type) {
    for (const auto& tree : trees) {
        if (tree.type == type) {
            return true;
        }
    }
    return false;
}

void InputTrees(vector<Tree>& trees, int count) {
    for (int i = 0; i < count; i++) {
        Tree tree;
        cout << "Enter tree type " << i + 1 << ": ";
        cin.ignore();
        getline(cin, tree.type);
        cout << "Enter tree price " << i + 1 << " (USD): ";
        cin >> tree.price;
        trees.push_back(tree);
    }
}

int main() {
    vector<Tree> trees;

    cout << "Welcome to the Christmas Tree Sales App!\n";
    int count;
    cout << "How many types of trees would you like to add? ";
    cin >> count;

    InputTrees(trees, count);

    cout << "\nAvailable trees:\n";
    PrintTrees(trees);

    cout << "\nSorting trees by price...\n";
    SortTreesByPrice(trees);

    PrintTrees(trees);

    cout << "\nChecking the availability of a specific tree type. Enter the type to search: ";
    string searchType;
    cin.ignore();
    getline(cin, searchType);

    if (FindTree(trees, searchType)) {
        cout << "The tree type \"" << searchType << "\" is available.\n";
    }
    else {
        cout << "The tree type \"" << searchType << "\" is not available.\n";
    }

    cout << "\nThank you for using the app.\n";

    return 0;
}
