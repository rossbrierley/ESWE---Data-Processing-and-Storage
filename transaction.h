#include <string>
#include <map>
using namespace std;

class Transaction {
public:
    void begin_transaction();
    void put(string key, int val);
    int get(string key);
    void commit();
    void rollback();
    map<string, int> uncommitedData;
    map<string, int> committedData;
    bool isOpen = false;
    int transactionCount = 0;
};