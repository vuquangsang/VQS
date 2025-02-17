#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>  // For system()

using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

// Hàm để in các ký tự pháo hoa, sử dụng màu sắc thay đổi
void displayFireworks(int colorChoice) {
    // Các ký tự pháo hoa
    string fireworks[] = {
        "        *        ",
        "       ***       ",
        "      *****      ",
        "     *******     ",
        "    *********    ",
        "   ***********   ",
        "  *************  ",
        "       | |       ",
        "       | |       ",
        "       | |       "
    };

    // Chọn màu sắc cho pháo hoa dựa trên giá trị colorChoice
    string color;
    switch (colorChoice) {
        case 1: color = RED; break;
        case 2: color = GREEN; break;
        case 3: color = YELLOW; break;
        case 4: color = BLUE; break;
        case 5: color = MAGENTA; break;
        case 6: color = CYAN; break;
        default: color = WHITE; break;
    }

    // Hiển thị pháo hoa với màu sắc lựa chọn
    for (int i = 0; i < 5; i++) {
        system("clear"); // Xoá màn hình (dùng "cls" nếu trên Windows)

        // In pháo hoa với màu sắc
        cout << color;
        for (int j = 0; j < 10; j++) {
            cout << fireworks[j % 8] << endl;
        }

        // Đặt lại màu sắc
        cout << RESET;

        // Tạm dừng một chút để hiệu ứng pháo hoa rõ ràng hơn
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    // Hiển thị lời chúc mừng sinh nhật
    cout << "Chuc Mung Sinh Nhat!" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));  // Đợi một chút

    // Lựa chọn màu sắc pháo hoa (ví dụ: chọn màu đỏ)
    int colorChoice = 1; // Chọn 1 cho màu đỏ
    displayFireworks(colorChoice); // Hiển thị pháo hoa

    return 0;
}
