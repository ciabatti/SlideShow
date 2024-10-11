#ifndef OBSERVER_H
#define OBSERVER_H

// Interfaccia Observer
class Observer {
public:
    virtual void Update(const wxString& imagePath) = 0;
};

#endif
