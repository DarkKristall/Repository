#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//Считывает строку
string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

//Считывет число
int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}
//Разбивает строку на vector слов
vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
//Разбивает строку на set слов
set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}
//Возвращает vector без стоп-слов
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    // проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    // вернём результат без стоп-слов
    return words;
}
//Возвращает vector vector'ов документов без стоп-слов
void AddDocument(vector<pair<int,vector<string>>>& documents, const set<string>& stop_words, const string& document, int id) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(pair<int,vector<string>>{id, words});
}
//Разбивает строку на set без стоп-слов
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    vector<string> vText = SplitIntoWordsNoStop(text, stop_words);
    query_words = set(vText.begin(), vText.end());
    // Напишите код функции

    return query_words;
}

int MatchDocument(const pair<int, vector<string>>& document_words, const set<string>& query_words) {
    int relevance = 0;
    for (const string& st:document_words.second){
        
        if (query_words.count(st)) ++relevance;
    }

    return relevance;
}
// Возвращает vector id документов, подходящих под запрос query исключая стоп-слова
vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents, const set<string>& stop_words, const string& query) {
    vector<pair<int, int>> matched_documents;
    set<string> sQuery = ParseQuery(query, stop_words);
    int relevance = 0;

    for (const auto& document:documents){
        relevance = MatchDocument(document, sQuery);
        if (relevance){
            matched_documents.push_back(pair<int, int>{document.first, relevance});
        }
    }

    return matched_documents;
    /*В функции FindDocuments сначала разберите поисковый запрос, используя ParseQuery. Затем в цикле переберите все документы и соберите id тех из них, которые подходят под критерии поискового запроса. Чтобы проверить документ на соответствие запросу, используйте MatchDocument.*/
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Считываем документы
    vector<pair<int, vector<string>>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, ReadLine(), document_id);
    }

    const string query = ReadLine();
    // Выводим результаты поиска по запросу query
    for (auto [document_id, relevance] : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
    }
} 