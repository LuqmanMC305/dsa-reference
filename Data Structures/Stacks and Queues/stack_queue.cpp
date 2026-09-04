#include <iostream>
#include <stack>
#include <queue>
#include <deque>

int main() {
    // ---------- STACK (LIFO) ----------
    std::stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.emplace(40);          // construct in-place on top

    std::cout << "Stack top: " << s.top() << "\n"; // 40
    std::cout << "Stack size: " << s.size() << "\n"; // 4

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();             // pop() returns nothing, must read top() first
    }
    std::cout << "\n"; // 40 30 20 10


    // ---------- QUEUE (FIFO) ----------
    std::queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);            // construct in-place at back

    std::cout << "Queue front: " << q.front() << "\n"; // 1
    std::cout << "Queue back: " << q.back() << "\n";   // 4
    std::cout << "Queue size: " << q.size() << "\n";   // 4

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();              // pop() returns nothing, must read front() first
    }
    std::cout << "\n"; // 1 2 3 4


    // ---------- DEQUE (double-ended, push/pop both sides) ----------
    std::deque<int> dq;

    dq.push_back(100);
    dq.push_front(50);
    dq.push_back(200);

    std::cout << "Deque front: " << dq.front() << "\n"; // 50
    std::cout << "Deque back: " << dq.back() << "\n";   // 200

    dq.pop_front();
    dq.pop_back();
    std::cout << "Deque after pops, remaining: " << dq.front() << "\n"; // 100


    // ---------- STACK WITH CUSTOM UNDERLYING CONTAINER ----------
    std::stack<int, std::vector<int>> vecStack;
    vecStack.push(1);
    vecStack.push(2);
    std::cout << "Vector-backed stack top: " << vecStack.top() << "\n"; // 2

    return 0;
}