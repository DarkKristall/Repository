#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    int count_word;
    vector<string> words{};
    cin >> count_word;
    for (int i = 0; i < count_word; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    };
    auto my_sort = [](const string& st1, const string& st2){
        return lexicographical_compare(st1.begin(), st1.end(), 
        st2.begin(), st2.end(),
        [](char left, char right){
            return tolower(left) < tolower(right);
        });
    };
    sort(words.begin(), words.end(), my_sort);
    for (string word: words){
        cout << word << " ";
    }
    cout << endl;
    vector<int> numbers {11, 4, 6, 3, 2, 7, 5, 8, 9, 2, 1, 5};
    sort(numbers.begin(), numbers.end(),[](int left, int right){
        if (left%2 == 0 && right%2 == 0) return left < right;
        else if (left%2 == 0 && right%2 != 0) return true;
        else if (left%2 != 0 && right%2 == 0) return false;
        else return left > right;
    });
    for (int number: numbers){
        cout << number << " "s;
    }
}