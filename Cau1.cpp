#include <iostream>
#include <set>
#include <sstream>
using namespace std;

// Hàm nhập tập hợp nhanh từ 1 dòng nhập
set<string> nhapTapHopNhanh(const string &ten) {
    set<string> tap;
    cout << "Nhập các phần tử của " << ten << " (cách nhau bởi dấu cách): ";
    string line, x;
    getline(cin >> ws, line); // Đọc cả dòng (loại bỏ khoảng trắng trước đó)
    stringstream ss(line);
    while (ss >> x) {
        tap.insert(x);
    }
    return tap;
}

// Hàm tính phủ định của tập hợp (U - A)
set<string> phuDinh(set<string> tapDayDu, set<string> tap) {
    set<string> ketQua;
    for (const auto &x : tapDayDu) {
        if (tap.find(x) == tap.end()) {
            ketQua.insert(x);
        }
    }
    return ketQua;
}

// Hàm hiệu hai tập hợp
set<string> hieu(const set<string> &A, const set<string> &B) {
    set<string> ketQua;
    for (const auto &x : A) {
        if (B.find(x) == B.end()) {
            ketQua.insert(x);
        }
    }
    return ketQua;
}

// Hàm giao hai tập hợp
set<string> giao(const set<string> &A, const set<string> &B) {
    set<string> ketQua;
    for (const auto &x : A) {
        if (B.find(x) != B.end()) {
            ketQua.insert(x);
        }
    }
    return ketQua;
}

// Hàm in tập hợp
void inTapHop(const set<string> &tap) {
    for (const auto &x : tap) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // Giả sử tập đầy đủ là {a, b, c, d, e, f, g, h}
    set<string> tapDayDu = {"a", "b", "c", "d", "e", "f", "g", "h"};

    // Nhập nhanh các tập A, B, C
    set<string> A = nhapTapHopNhanh("A");
    set<string> B = nhapTapHopNhanh("B");
    set<string> C = nhapTapHopNhanh("C");

    // Tính toán
    set<string> notA = phuDinh(tapDayDu, A);
    set<string> notAminusB = hieu(notA, B);
    set<string> not_notAminusB = phuDinh(tapDayDu, notAminusB);
    set<string> ketQua = giao(not_notAminusB, C);

    // In kết quả
    cout << "Kết quả: ";
    inTapHop(ketQua);

    return 0;
}
