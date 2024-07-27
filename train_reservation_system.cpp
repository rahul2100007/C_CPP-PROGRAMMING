#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BaseTicket {
protected:
    int Cid;
    string Cname;
    bool isBooked;
    bool isCancelled;

public:
    BaseTicket() : Cid(0), Cname(""), isBooked(false), isCancelled(false) {}

    virtual void fillForm() {
        cout << "Enter Customer ID: ";
        cin >> Cid;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, Cname);
        isBooked = true;
        isCancelled = false;
    }

    virtual void displayInformation() const {
        cout << "Customer ID: " << Cid << endl;
        cout << "Customer Name: " << Cname << endl;
    }

    virtual void checkStatus() const {
        if (isCancelled) {
            cout << "Ticket is cancelled." << endl;
        } else if (isBooked) {
            cout << "Ticket is booked." << endl;
        } else {
            cout << "Ticket is not booked." << endl;
        }
    }

    virtual void cancelTicket() {
        if (isBooked && !isCancelled) {
            isCancelled = true;
            cout << "Ticket cancelled successfully!" << endl;
        } else if (isCancelled) {
            cout << "Ticket is already cancelled." << endl;
        } else {
            cout << "Ticket is not booked yet." << endl;
        }
    }

    int getCid() const {
        return Cid;
    }

    virtual ~BaseTicket() {}
};

class Ticket : public BaseTicket {
private:
    string Trainname;
    string SStation;
    string Dstation;
    string Tickettype;
    double Fair;

public:
    Ticket() : BaseTicket(), Trainname(""), SStation(""), Dstation(""), Tickettype(""), Fair(0.0) {
        fillForm();
    }
    
    void fillForm()  {
        BaseTicket::fillForm();
        cout << "Enter Train Name: ";
        getline(cin, Trainname);
        cout << "Enter Starting Station: ";
        getline(cin, SStation);
        cout << "Enter Destination Station: ";
        getline(cin, Dstation);
        cout << "Enter Ticket Type: ";
        getline(cin, Tickettype);
        cout << "Enter Fair: ";
        cin >> Fair;
    }

    void displayInformation() const  {
        BaseTicket::displayInformation();
        cout << "Train Name: " << Trainname << endl;
        cout << "Starting Station: " << SStation << endl;
        cout << "Destination Station: " << Dstation << endl;
        cout << "Ticket Type: " << Tickettype << endl;
        cout << "Fair: " << Fair << endl;
        cout << "Booking Status: " << (isBooked ? "Booked" : "Not Booked") << endl;
        cout << "Cancellation Status: " << (isCancelled ? "Cancelled" : "Not Cancelled") << endl;
    }
};

class reservesys {
private:
    vector<Ticket> tickets;

public:
    void bookTicket() {
        Ticket t;
        t.fillForm();
        tickets.push_back(t);
        cout << "Ticket booked successfully!" << endl;
    }

    void searchTicket(int Cid) const {
        for (const auto& t : tickets) {
            if (t.getCid() == Cid) {
                t.displayInformation();
                return;
            }
        }
        cout << "Ticket not found!" << endl;
    }

    void displayAllTickets() const {
        cout << "-----------------------------------" << endl;
        if (tickets.empty()) {
            cout << "No tickets to display." << endl;
            return;
        }
        for (const auto& t : tickets) {
            t.displayInformation();
            cout << "-----------------------------------" << endl;
        }
    }

    void cancelTicket(int Cid) {
        for (auto& t : tickets) {
            if (t.getCid() == Cid) {
                t.cancelTicket();
                return;
            }
        }
        cout << "Ticket not found!" << endl;
    }

    void chkstatus(int Cid) const {
        for (const auto& t : tickets) {
            if (t.getCid() == Cid) {
                t.checkStatus();
                return;
            }
        }
        cout << "Ticket not found!" << endl;
    }
};

int main() {
    reservesys rs;
    int choice, Cid;

    while (true) {
        cout << "1. Form fill-up for Booking Ticket" << endl;
        cout << "2. Display Information" << endl;
        cout << "3. Check Ticket Status" << endl;
        cout << "4. Cancellation of ticket" << endl;
        cout << "5. Search Ticket" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.bookTicket();
                break;
            case 2:
                rs.displayAllTickets();
                break;
            case 3:
                cout << "Enter Customer ID: ";
                cin >> Cid;
                rs.chkstatus(Cid);
                break;
            case 4:
                cout << "Enter Customer ID: ";
                cin >> Cid;
                rs.cancelTicket(Cid);
                break;
            case 5:
                cout << "Enter Customer ID: ";
                cin >> Cid;
                rs.searchTicket(Cid);
                break;
            case 6:
                cout << "Exiting Program" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}