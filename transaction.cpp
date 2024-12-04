#include <stdexcept>
#include <iostream>
#include "transaction.h"

using namespace std;

void Transaction::begin_transaction() {
   if(transactionCount <= 1) {
        isOpen = true;
        transactionCount++;  
   }
   else {
        throw runtime_error("A transaction is already in progress.");
   }
}

// create new key with provided value
void Transaction::put(string key, int val) {
    if(isOpen == true) {
        uncommitedData[key] = val;
    }
    else {
        throw runtime_error("No transaction in progress.");
    }    
}

int Transaction::get(string key) {
    if(uncommitedData.find(key) != uncommitedData.end()) {
        return uncommitedData[key];
    }
    else if(committedData.find(key) != committedData.end()) {
        return committedData[key];
    }
    return NULL;
}
void Transaction::commit() {
    if(isOpen == false) {
        throw runtime_error("No transaction in progress to commit.");
    }
    for(const auto& pair : uncommitedData) {
        committedData[pair.first] = pair.second;
    }
    uncommitedData.clear();
    isOpen = false;
    transactionCount--;
}

void Transaction::rollback() {
    if(isOpen == false) {
        throw runtime_error("No transaction to rollback.");
    }
    uncommitedData.clear();
    isOpen = false;
    transactionCount++;
}

int main() {
    //NOTE: To see all of the error handling functionality, uncomment each error one at a time, then recompile the executable.
    // Example command: g++ -o transaction transaction.cpp

    Transaction transaction;

    // should return null, because A doesn’t exist in the DB yet
    //transaction.get("A");

    // should throw an error because a transaction is not in progress
    //transaction.put("A", 5);

    // starts a new transaction
    transaction.begin_transaction();

    // set’s value of A to 5, but its not committed yet
    transaction.put("A", 5);

    // should return null, because updates to A are not committed yet
    transaction.get("A");

    // update A’s value to 6 within the transaction
    transaction.put("A", 6);

    // commits the open transaction
    transaction.commit();

    // should return 6, that was the last value of A to be committed
    transaction.get("A");

    // throws an error, because there is no open transaction
    //transaction.commit();

    // throws an error because there is no ongoing transaction
    //transaction.rollback();

    // should return null because B does not exist in the database
    transaction.get("B");

    // starts a new transaction
    transaction.begin_transaction();

    // Set key B’s value to 10 within the transaction
    transaction.put("B", 10);

    // Rollback the transaction - revert any changes made to B
    transaction.rollback();

    // Should return null because changes to B were rolled back
    transaction.get("B");
    return 0;
}