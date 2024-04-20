#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> doc1 {"green", "red", "balck", "green"};
    vector<string> doc2 {"green", "white", "balck"};
    vector<string> query {"green", "black"};
    map<string, map<int, double>> TF;
    map<int, int> document_to_relevance;
    int count_words = doc1.size();
    for (const string& word:doc1){
        TF[word][1] +=1./count_words;
    };
    count_words = doc2.size();
    for (const string& word:doc2){
        TF[word][2] +=1./count_words;
    };
    for (const string& word_query:query){
        if (TF.count(word_query)!=0){
            for(const auto& [id, tf]:TF.at(word_query)){
                document_to_relevance[id] = 123;
            }
        }
    };
    return 0;
}

