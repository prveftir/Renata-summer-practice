#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

struct FabricQuantity {
    string code;
    int quantity;
};

struct FabricInfo {
    string code;
    string name;
    double price;
};

struct FabricResult {
    string code;
    string name;
    int quantity;
    double totalCost;
};

vector<FabricQuantity> readFileF(const string& filename) {
    vector<FabricQuantity> data;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return data;
    }
    
    FabricQuantity item;
    while (file >> item.code >> item.quantity) {
        data.push_back(item);
    }
    
    file.close();
    return data;
}

vector<FabricInfo> readFileG(const string& filename) {
    vector<FabricInfo> data;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return data;
    }
    
    FabricInfo item;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(' ');
        if (pos1 == string::npos) continue;
        
        size_t pos2 = line.find(' ', pos1 + 1);
        if (pos2 == string::npos) continue;
        
        item.code = line.substr(0, pos1);
        item.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        item.price = stod(line.substr(pos2 + 1));
        
        data.push_back(item);
    }
    
    file.close();
    return data;
}

void createFileH(const string& filename, const vector<FabricResult>& results) {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Не удалось создать файл " << filename << endl;
        return;
    }
    
    file << left << setw(10) << "Шифр" << setw(20) << "Название"
         << setw(10) << "Кол-во" << setw(15) << "Общая стоимость" << endl;
    
    for (const auto& item : results) {
        file << left << setw(10) << item.code
             << setw(20) << item.name
             << setw(10) << item.quantity
             << setw(15) << fixed << setprecision(2) << item.totalCost << endl;
    }
    
    file.close();
}

int main() {
    auto dataF = readFileF("F.txt");
    auto dataG = readFileG("G.txt");
    
    map<string, FabricInfo> fabricMap;
    for (const auto& item : dataG) {
        fabricMap[item.code] = item;
    }
    
    vector<FabricResult> results;
    for (const auto& item : dataF) {
        if (fabricMap.find(item.code) != fabricMap.end()) {
            const auto& info = fabricMap[item.code];
            FabricResult result;
            result.code = item.code;
            result.name = info.name;
            result.quantity = item.quantity;
            result.totalCost = item.quantity * info.price;
            results.push_back(result);
        }
    }
    
    createFileH("H.txt", results);
    
    cout << "Файл H.txt успешно создан с результатами обработки." << endl;
    
    return 0;
}
