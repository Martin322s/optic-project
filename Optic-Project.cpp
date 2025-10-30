#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Optic {
private:
    string type, material;
    double thickness, diopter;
public:
    Optic() {}
    Optic(string t, double th, double d, string m)
        : type(t), thickness(th), diopter(d), material(m) {}

    string getType() const { return type; }
    double getThickness() const { return thickness; }
    double getDiopter() const { return diopter; }
    string getMaterial() const { return material; }

    friend ostream& operator<<(ostream& os, const Optic& o) {
        os << o.type << " | " << o.thickness << "mm | " << o.diopter << "D | " << o.material;
        return os;
    }
};

class Supplier {
private:
    string bulstat, name, location, phone;
    vector<Optic> optics;
public:
    Supplier() {}
    Supplier(string b, string n, string l, string p)
        : bulstat(b), name(n), location(l), phone(p) {}

    string getName() const { return name; }
    string getBulstat() const { return bulstat; }
    string getLocation() const { return location; }
    string getPhone() const { return phone; }
    vector<Optic>& getOptics() { return optics; }

    void addOptic(const Optic& o) { optics.push_back(o); }

    friend ostream& operator<<(ostream& os, const Supplier& s) {
        os << "Name: " << s.name << endl;
        os << "Bulstat: " << s.bulstat << endl;
        os << "Location: " << s.location << endl;
        os << "Phone: " << s.phone << endl;
        os << "Optics:" << endl;
        for (size_t i = 0; i < s.optics.size(); i++)
            os << "  " << i + 1 << ". " << s.optics[i] << endl;
        return os;
    }
};

class SupplierManager {
private:
    vector<Supplier> suppliers;
public:
    void addSupplier(const Supplier& s) { suppliers.push_back(s); }

    void displaySuppliers() {
        if (suppliers.empty()) {
            cout << "No suppliers added yet." << endl;
            return;
        }
        for (size_t i = 0; i < suppliers.size(); i++)
            cout << i + 1 << ". " << suppliers[i].getName() << endl;
    }

    Supplier& getSupplier(int index) { return suppliers[index]; }

    double calculateOrderPrice(const Supplier& s, const string& opticType, int quantity) {
        for (const auto& o : s.getOptics())
            if (o.getType() == opticType)
                return o.getThickness() * o.getDiopter() * quantity;
        return 0.0;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        for (const auto& s : suppliers) {
            file << s << endl;
        }
        cout << "Saved to file: " << filename << endl;
    }
};

int main() {
    SupplierManager sm;
    int choice;

    while (true) {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Add Supplier" << endl;
        cout << "2. Add Optic to Supplier" << endl;
        cout << "3. Display Suppliers" << endl;
        cout << "4. Calculate Order Price" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, bulstat, location, phone;
            cout << "Name: "; getline(cin, name);
            cout << "Bulstat: "; getline(cin, bulstat);
            cout << "Location: "; getline(cin, location);
            cout << "Phone: "; getline(cin, phone);
            sm.addSupplier(Supplier(bulstat, name, location, phone));
        }
        else if (choice == 2) {
            sm.displaySuppliers();
            int index;
            cout << "Supplier index: ";
            cin >> index;
            cin.ignore();

            string type, material;
            double thickness, diopter;
            cout << "Optic type: "; getline(cin, type);
            cout << "Thickness (mm): "; cin >> thickness;
            cout << "Diopter (D): "; cin >> diopter;
            cin.ignore();
            cout << "Material: "; getline(cin, material);

            sm.getSupplier(index - 1).addOptic(Optic(type, thickness, diopter, material));
        }
        else if (choice == 3) {
            sm.displaySuppliers();
        }
        else if (choice == 4) {
            sm.displaySuppliers();
            int index, qty;
            string type;
            cout << "Supplier index: "; cin >> index; cin.ignore();
            cout << "Optic type: "; getline(cin, type);
            cout << "Quantity: "; cin >> qty;
            cout << "Total price: " << sm.calculateOrderPrice(sm.getSupplier(index - 1), type, qty) << endl;
        }
        else if (choice == 5) {
            string filename;
            cout << "Filename: ";
            getline(cin, filename);
            sm.saveToFile(filename);
        }
        else if (choice == 6) {
            cout << "Goodbye!" << endl;
            break;
        }
    }
    return 0;
}
