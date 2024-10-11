#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

// Classe Subject che gestisce gli osservatori
class Subject {
private:
    std::vector<Observer*> observers;

public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Notify(const wxString& imagePath) {
        for (Observer* observer : observers) {
            observer->Update(imagePath);
        }
    }
};

#endif
