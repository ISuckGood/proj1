#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void calculateSquare(std::promise<int> &&p) {
    int x = 5;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    p.set_value(x * x);
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();
     std::thread t(calculateSquare, std::move(p));

    auto status = f.wait_for(std::chrono::seconds(1));
    if (status == std::future_status::ready) {
        std::cout << "Result: " << f.get() << std::endl;
    } else {
        std::cout << "Result not yet available." << std::endl;
    }

    t.join();
    return 0;
}