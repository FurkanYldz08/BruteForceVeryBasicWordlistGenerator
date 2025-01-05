#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Bir kelimeyi belirli bir formatta wordlist'e ekler
void generateWordlist(const string& firstName, const string& lastName, const string& birthDate) {
    vector<string> wordlist;

    // Kullanıcı bilgilerini farklı kombinasyonlarda ekleyelim
    wordlist.push_back(firstName);
    wordlist.push_back(lastName);
    wordlist.push_back(birthDate);

    wordlist.push_back(firstName + lastName); // Ad ve soyadı birleştir
    wordlist.push_back(lastName + firstName); // Soyadı ve adı tersten birleştir

    wordlist.push_back(firstName + birthDate); // Ad + doğum tarihi
    wordlist.push_back(lastName + birthDate);  // Soyad + doğum tarihi

    wordlist.push_back(birthDate + firstName); // Doğum tarihi + ad
    wordlist.push_back(birthDate + lastName);  // Doğum tarihi + soyad

    // Adın ilk harfi ve soyadı
    wordlist.push_back(firstName.substr(0, 1) + lastName);
    wordlist.push_back(firstName + lastName.substr(0, 1));

    // Hepsinin küçük harf kombinasyonları
    for (const auto& word : wordlist) {
        if (word.empty()) {
            cout << "Found an empty string in wordlist." << endl;
            continue;
        }
        string lowerWord;
        for (char c : word) {
            lowerWord += tolower(c);
        }
        // Do something with lowerWord
    }


    // Wordlist'i bir dosyaya yazalım
    ofstream wordlistFile("wordlist.txt");
    if (wordlistFile.is_open()) {
        for (const string& word : wordlist) {
            wordlistFile << word << endl; // Her bir kelimeyi yeni satıra yaz
        }
        wordlistFile.close();
        cout << "Wordlist başarıyla oluşturuldu! Dosya: wordlist.txt" << endl;
    }
    else {
        cout << "Dosya oluşturulamadı!" << endl;
    }
}

int main() {
    string firstName, lastName, birthDate;

    // Kullanıcıdan bilgiler alalım
    cout << "Adınızı girin: ";
    cin >> firstName;

    cout << "Soyadınızı girin: ";
    cin >> lastName;

    cout << "Doğum tarihinizi (YYYYMMDD) formatında girin: ";
    cin >> birthDate;

    // Wordlist oluştur
    generateWordlist(firstName, lastName, birthDate);

    return 0;
}
