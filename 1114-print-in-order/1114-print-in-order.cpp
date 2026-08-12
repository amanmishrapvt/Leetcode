#include <functional>
#include <mutex>
#include <condition_variable>

class Foo {
private:
    std::mutex m;
    std::condition_variable cv;
    int turn;

public:
    Foo() {
        turn = 0;
    }

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        {
            std::lock_guard<std::mutex> lock(m);
            turn = 1;
        }
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this]() { return turn == 1; });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        turn = 2;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this]() { return turn == 2; });

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};