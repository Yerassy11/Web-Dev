#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <iomanip> // для аккуратного вывода

// Простой бинарный поиск (binary search tree, BST).
// Полезно: компилируется под C++11/14/17.

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t node_count;

    // ----- Вспомогательные приватные методы (рекурсивные) -----

    // Рекурсивная вставка. inserted = true если узел добавлен.
    Node* insertRec(Node* node, const T& val, bool& inserted) {
        if (!node) {
            inserted = true;
            ++node_count;
            return new Node(val);
        }
        if (val < node->value) {
            node->left = insertRec(node->left, val, inserted);
        } else if (val > node->value) {
            node->right = insertRec(node->right, val, inserted);
        } else {
            // равные значения — политика: не вставляем дубликаты
            inserted = false;
        }
        return node;
    }

    // Поиск значения (рекурсивно)
    bool containsRec(Node* node, const T& val) const {
        if (!node) return false;
        if (val == node->value) return true;
        if (val < node->value) return containsRec(node->left, val);
        return containsRec(node->right, val);
    }

    // Найти минимальный узел в поддереве
    Node* findMin(Node* node) const {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    // Рекурсивное удаление. removed = true если удалили.
    // Возвращает (возможно изменённый) корень поддерева.
    Node* removeRec(Node* node, const T& val, bool& removed) {
        if (!node) return nullptr;
        if (val < node->value) {
            node->left = removeRec(node->left, val, removed);
        } else if (val > node->value) {
            node->right = removeRec(node->right, val, removed);
        } else {
            // нашли узел для удаления
            removed = true;
            // Случай 1: нет левого ребёнка -> заменить на правого
            if (!node->left) {
                Node* r = node->right;
                delete node;
                --node_count;
                return r;
            }
            // Случай 2: нет правого ребёнка -> заменить на левого
            if (!node->right) {
                Node* l = node->left;
                delete node;
                --node_count;
                return l;
            }
            // Случай 3: есть оба ребёнка
            // Найдём минимальный элемент в правом поддереве (successor)
            Node* minRight = findMin(node->right);
            // Скопируем значение
            node->value = minRight->value;
            // Удалим тот минимальный узел из правого поддерева
            node->right = removeRec(node->right, minRight->value, removed);
            // (removed остаётся true)
        }
        return node;
    }

    // Очистка (удаление всех узлов)
    void deleteAll(Node* node) {
        if (!node) return;
        deleteAll(node->left);
        deleteAll(node->right);
        delete node;
    }

    // Глубина (высота) дерева, по узлам (пустое дерево -> 0, один узел -> 1)
    int heightRec(Node* node) const {
        if (!node) return 0;
        int hl = heightRec(node->left);
        int hr = heightRec(node->right);
        return 1 + std::max(hl, hr);
    }

    // Рекурсивные обходы с функцией-обработчиком
    void inorderRec(Node* node, const std::function<void(const T&)>& f) const {
        if (!node) return;
        inorderRec(node->left, f);
        f(node->value);
        inorderRec(node->right, f);
    }
    void preorderRec(Node* node, const std::function<void(const T&)>& f) const {
        if (!node) return;
        f(node->value);
        preorderRec(node->left, f);
        preorderRec(node->right, f);
    }
    void postorderRec(Node* node, const std::function<void(const T&)>& f) const {
        if (!node) return;
        postorderRec(node->left, f);
        postorderRec(node->right, f);
        f(node->value);
    }

    // Глубокое копирование поддерева
    Node* copyRec(Node* node) {
        if (!node) return nullptr;
        Node* n = new Node(node->value);
        n->left = copyRec(node->left);
        n->right = copyRec(node->right);
        return n;
    }

    // Печать "боковой" структуры дерева (для визуализации)
    void printSidewaysRec(Node* node, int level) const {
        if (!node) return;
        printSidewaysRec(node->right, level + 1);
        std::cout << std::setw(level * 4) << "" << node->value << "\n";
        printSidewaysRec(node->left, level + 1);
    }

public:
    // ----- Конструкторы / деструктор / копирование -----
    BinarySearchTree() : root(nullptr), node_count(0) {}
    ~BinarySearchTree() { clear(); }

    // Копирующий конструктор (глубокая копия)
    BinarySearchTree(const BinarySearchTree& other) : root(nullptr), node_count(0) {
        root = copyRec(other.root);
        node_count = other.node_count;
    }

    // Оператор присваивания (копирование)
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other) return *this;
        clear();
        root = copyRec(other.root);
        node_count = other.node_count;
        return *this;
    }

    // ----- Основные публичные методы -----

    // Вставка. Возвращает true если добавили, false если значение уже есть.
    bool insert(const T& val) {
        bool inserted = false;
        root = insertRec(root, val, inserted);
        return inserted;
    }

    // Удаление. Возвращает true если удалили, false если такого значения не было.
    bool remove(const T& val) {
        bool removed = false;
        root = removeRec(root, val, removed);
        return removed;
    }

    // Поиск значения
    bool contains(const T& val) const {
        return containsRec(root, val);
    }

    // Количество узлов
    size_t size() const { return node_count; }

    // Пусто?
    bool empty() const { return node_count == 0; }

    // Минимум/максимум по значению
    bool minValue(T& out) const {
        Node* n = findMin(root);
        if (!n) return false;
        out = n->value;
        return true;
    }
    bool maxValue(T& out) const {
        Node* n = root;
        if (!n) return false;
        while (n->right) n = n->right;
        out = n->value;
        return true;
    }

    // Высота дерева (в узлах)
    int height() const { return heightRec(root); }

    // Очистить дерево
    void clear() {
        deleteAll(root);
        root = nullptr;
        node_count = 0;
    }

    // Обходы (recursive)
    void inorder(const std::function<void(const T&)>& f) const { inorderRec(root, f); }
    void preorder(const std::function<void(const T&)>& f) const { preorderRec(root, f); }
    void postorder(const std::function<void(const T&)>& f) const { postorderRec(root, f); }

    // Интерактивный (итеративный) inorder, возвращает вектор значений
    std::vector<T> inorderIterative() const {
        std::vector<T> out;
        std::stack<Node*> st;
        Node* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            out.push_back(curr->value);
            curr = curr->right;
        }
        return out;
    }

    // Level-order (BFS) обход
    void levelOrder(const std::function<void(const T&)>& f) const {
        if (!root) return;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            f(cur->value);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }

    // Найти преемника (successor) по значению: smallest > val
    // Возвращает true + помещает значение в out, если найден successor.
    bool successor(const T& val, T& out) const {
        Node* cur = root;
        Node* succ = nullptr;
        while (cur) {
            if (val < cur->value) {
                succ = cur;
                cur = cur->left;
            } else if (val > cur->value) {
                cur = cur->right;
            } else {
                // нашли узел со значением val
                if (cur->right) {
                    Node* m = findMin(cur->right);
                    out = m->value;
                    return true;
                }
                break;
            }
        }
        if (succ) {
            out = succ->value;
            return true;
        }
        return false;
    }

    // Найти предшественника (predecessor) по значению: largest < val
    bool predecessor(const T& val, T& out) const {
        Node* cur = root;
        Node* pred = nullptr;
        while (cur) {
            if (val > cur->value) {
                pred = cur;
                cur = cur->right;
            } else if (val < cur->value) {
                cur = cur->left;
            } else {
                // нашли узел
                if (cur->left) {
                    Node* n = cur->left;
                    while (n->right) n = n->right;
                    out = n->value;
                    return true;
                }
                break;
            }
        }
        if (pred) {
            out = pred->value;
            return true;
        }
        return false;
    }

    // Печать дерева "боком" (правый поддерево сверху, левый снизу)
    void printSideways() const {
        printSidewaysRec(root, 0);
    }
};

// ----------------- Демонстрация использования -----------------
int main() {
    BinarySearchTree<int> tree;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : arr) tree.insert(v);

    std::cout << "In-order (recursive): ";
    tree.inorder([](const int& x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "In-order (iterative): ";
    auto v = tree.inorderIterative();
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Pre-order: ";
    tree.preorder([](const int& x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "Post-order: ";
    tree.postorder([](const int& x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "Level-order (BFS): ";
    tree.levelOrder([](const int& x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "Размер: " << tree.size() << ", высота: " << tree.height() << "\n";

    std::cout << "Дерево (боковой вид):\n";
    tree.printSideways();

    std::cout << "Удаляем 50 (корень) ...\n";
    tree.remove(50);

    std::cout << "In-order после удаления: ";
    tree.inorder([](const int& x){ std::cout << x << " "; });
    std::cout << "\n";

    int succ;
    if (tree.successor(40, succ)) std::cout << "Successor(40) = " << succ << "\n";
    else std::cout << "Successor(40) not found\n";

    int pred;
    if (tree.predecessor(60, pred)) std::cout << "Predecessor(60) = " << pred << "\n";
    else std::cout << "Predecessor(60) not found\n";

    return 0;
}
