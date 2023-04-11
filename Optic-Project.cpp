#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Optic {
private:
    string type, material;
    double thickness, diopter;
public:
	Optic optic () {}
    Optic(string t, double th, double d, string m): type(t), thickness(th), diopter(d), material(m) {}
    
    string getType() const { return type; }
	void setType(string t) { type = t; }
    
	double getThickness() const { return thickness; }
	void setThickness(double th) { thickness = th; }
    
	double getDiopter() const { return diopter; }
	void setDiopter(double d) { diopter = d; }
    
	string getMaterial() const { return material; }
	void setMaterial(string m) { material = m; }
	
    friend ostream& operator<<(ostream& os, const Optic& o) {
        os << o.type << " " << o.thickness << "mm " << o.diopter << "D " << o.material;
        return os;
    }
};

class Supplier {
private:
    string bulstat, name, location, phone;
    vector<Optic> optics;
public:
    Supplier(string b, string n, string l, string p): bulstat(b), name(n), location(l), phone(p) {}
    Supplier(string b, string n, string l, string p, vector<Optic> o): bulstat(b), name(n), location(l), phone(p), optics(o) {}
    
    string getBulstat() const { return bulstat; }
	void setBulstat(string b) { bulstat = b; }
    
	string getName() const { return name; }
	void setName(string n) { name = n; }
    
	string getLocation() const { return location; }
	void setLocation(string l) { location = l; }
    
	string getPhone() const { return phone; }
	void setPhone(string p) { phone = p; }
    
	vector<Optic> getOptics() const { return optics; }
	void setOptics(vector<Optic> o) { optics = o; }

    void addOptic(Optic o) { optics.push_back(o); }
    friend ostream& operator<<(ostream& os, const Supplier& s) {
        os << "Name: " << s.name << endl << "Bulstat: " << s.bulstat << endl << "Location: " << s.location << endl << "Phone: " << s.phone << endl << "Optics:" << endl;
        for (int optic = 0; optic < s.optics.size(); optic++) {
            os << "- " << optic << endl;
        }
        return os;
    }
};

class SupplierManager {
private:
    vector<Supplier> suppliers;
public:
    void addSupplier(Supplier s) {
        suppliers.push_back(s);
    }
    
    void displaySuppliers() {
        for (int i = 0; i < suppliers.size(); i++) {
            cout << i+1 << ". " << suppliers[i].getName() << endl;
        }
    }
    
    Supplier& getSupplier(int index) {
        return suppliers[index];
    }
    
    double calculateOrderPrice(Supplier s, string opticType, int quantity) {
        double totalPrice = 0;
        vector<Optic> supplierOptics = s.getOptics();
        for (int i = 0; i < supplierOptics.size(); i++) {
            if (supplierOptics[i].getType() == opticType) {
                totalPrice += supplierOptics[i].getDiopter() * supplierOptics[i].getThickness() * quantity;
            }
        }
        return totalPrice;
    }
    
    void saveToFile(string filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "Total suppliers count: " << suppliers.size() << endl;
        for (int i = 0; i < suppliers.size(); i++) {
            file << "Supplier name " << suppliers[i].getName() << endl;
            vector<Optic> supplierOptics = suppliers[i].getOptics();
            file << "Total Optics count: " << supplierOptics.size() << endl;
            for (int j = 0; j < supplierOptics.size(); j++) {
                file << supplierOptics[j].getType() << " Diopter: " << supplierOptics[j].getDiopter() << " Thinckness: " << supplierOptics[j].getThickness() << endl;
            }
        }
        file.close();
        cout << "Data saved to file " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file " << filename << endl;
    }
}

    
    friend ostream& operator<<(ostream& os, const SupplierManager& sm) {
        os << "Suppliers:" << endl;
        for (int i = 0; i < sm.suppliers.size(); i++) {
            os << "- " << sm.suppliers[i].getName() << endl;
        }
        return os;
    }
};

int main() {
	SupplierManager supplierManager;
	int choice, supplierIndex, quantity;
	string filename, opticType, supplierName, bulstat, location, phone, opticName, material;
	double thickness, diopter;
	do {
		cout << "==== MENU ====" << endl;
		cout << "1. Add Supplier" << endl;
		cout << "2. Add Optic to Supplier" << endl;
		cout << "3. Display Suppliers" << endl;
		cout << "4. Calculate Order Price" << endl;
		cout << "5. Save Suppliers to File" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter choice: ";
		cout << "Enter choice: ";
		while (!(cin >> choice) || choice < 1 || choice > 6) {
    		cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
    		cin.clear();
		}
		cin.ignore();
    	switch (choice) {
        	case 1:
            	cout << "Enter supplier name: ";
            	getline(cin, supplierName);
            	cout << "Enter supplier bulstat: ";
            	getline(cin, bulstat);
            	cout << "Enter supplier location: ";
            	getline(cin, location);
            	cout << "Enter supplier phone: ";
            	getline(cin, phone);
            	supplierManager.addSupplier(Supplier(bulstat, supplierName, location, phone));
            	break;
        	case 2:
            	supplierManager.displaySuppliers();
            	cout << "Enter supplier index: ";
            	cin >> supplierIndex;
            	cin.ignore();
            	cout << "Enter optic name: ";
            	getline(cin, opticName);
            	cout << "Enter optic thickness (mm): ";
            	while (!(cin >> thickness) || thickness < 0) {
    				cout << "Invalid thickness. Please enter a non-negative number." << endl;
    				cin.clear();
				}
            	cout << "Enter optic diopter (D): ";
            	while (!(cin >> diopter)) {
    				cout << "Invalid diopter. Please enter a valid number." << endl;
    				cin.clear();
				}
            	cin.ignore();
            	cout << "Enter optic material: ";
            	getline(cin, material);
            	supplierManager.getSupplier(supplierIndex-1).addOptic(Optic(opticName, thickness, diopter, material));
            	break;
        	case 3:
            	cout << supplierManager;
            	break;
        	case 4:
            	supplierManager.displaySuppliers();
            	cout << "Enter supplier index: ";
            	cin.ignore();
            	cout << "Enter optic name: ";
            	getline(cin, opticType);
            	cout << "Enter quantity: ";
            	while (!(cin >> quantity) || quantity < 0) {
    				cout << "Invalid quantity. Please enter a non-negative number." << endl;
    				cin.clear();
				}
            	cout << "Total price: $" << supplierManager.calculateOrderPrice(supplierManager.getSupplier(supplierIndex-1), opticType, quantity) << endl;
            	break;
        	case 5:
            	cout << "Enter filename: ";
            	getline(cin, filename);
            	if (filename.empty()) {
    				cout << "Invalid filename. Please enter a non-empty string." << endl;
    				continue;
				} else {
					supplierManager.saveToFile(filename);
				}
            	break;
        	case 6:
            	cout << "Exiting program..." << endl;
            	break;
        	default:
            	cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            	break;
    		}
		} while (choice != 6);
	return 0;
}
