//PolkupyoraRekisteri.cpp
//This is the main file of the program. It contains the main function that is the entry point of the program.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "bicycle.h"
#include "velomobile.h"

using namespace std;

void saveLastId(const string& lastId) {
    ofstream outFile("lastId.txt");
    if (outFile) {
        outFile << lastId;
        outFile.close();
    }
    else {
        cerr << "Error saving the last ID." << endl;
    }
}

string loadLastId() {
    ifstream inFile("lastId.txt");
    string lastId;
    if (inFile) {
        inFile >> lastId;
        inFile.close();
    }
    else {
        cerr << "Error loading the last ID." << endl;
    }
    return lastId;
}

string generateId() {
    string lastId = loadLastId();

    if (lastId.empty()) {
        lastId = "AA-111";
        saveLastId(lastId);
		return "AA-111";
	}

    string prefix = lastId.substr(0, 2);
    int number = stoi(lastId.substr(3, 3));

    if (number < 999) {
        number++;
    }
    else {
        number = 111;
        if (prefix[1] < 'Z') {
            prefix[1]++;
        }
        else if (prefix[0] < 'Z') {
			prefix[1] = 'A';
            prefix[0]++;
		}
		else
        {
			std::cerr << "Error: Cannot generate more IDs." << std::endl;
            return "";
		}
    }
    lastId = prefix + "-" + to_string(number);
    saveLastId(lastId);
    return lastId;
}

void saveBicyclesToFile(const std::vector<Bicycle>& bicycles, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    for (const auto& bike : bicycles) {
        file << bike.getId() << ","
            << bike.getBrand() << ","
            << bike.getModel() << ","
            << bike.getYear() << ","
            << bike.getFrameSize() << ","
            << bike.getWheelSize() << ","
            << bike.getWheelAmount() << ","
            << bike.getFrameNumber() << ","
            << bike.getBikeType() <<  endl;
    }

    file.close();
}

void loadBicyclesFromFile(vector<Bicycle>& bicycles, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file for reading." << endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, brand, model, frameSize, wheelSize, frameNumber, bikeType;
        int year, wheelAmount;

        getline(ss, id, ',');
        getline(ss, brand, ',');
        getline(ss, model, ',');
        ss >> year;
        ss.ignore(1); // Ignore the comma
        getline(ss, frameSize, ',');
        getline(ss, wheelSize, ',');
        ss >> wheelAmount;
        ss.ignore(1); // Ignore the comma
        getline(ss, frameNumber, ',');
        getline(ss, bikeType);

        Bicycle bike;
        bike.setId(id);
        bike.setBrand(brand);
        bike.setModel(model);
        bike.setYear(year);
        bike.setFrameSize(frameSize);
        bike.setWheelSize(wheelSize);
        bike.setWheelAmount(wheelAmount);
        bike.setFrameNumber(frameNumber);
        bike.setBikeType(bikeType);

        bicycles.push_back(bike);
    }

    file.close();
}

int main()
{
    vector<Bicycle> bicycles;
    string filename = "bicycles.txt";

    loadBicyclesFromFile(bicycles, filename);

    int valinta
        ;
    
    do
    {
        cout << "Polkupyörärekisteri" <<  endl;
        cout << "1. Lisää polkupyörä" <<  endl;
        cout << "2. Näytä polkupyörät" <<  endl;
        cout << "3. Poista polkupyörä" <<  endl;
        cout << "4. Muokkaa pyörien tietoja" <<  endl;
        cout << "0. Lopeta" <<  endl;
        cout << "Valitse toiminto: ";
        cin >> valinta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (valinta)
        {
        case 1:
            cout << "Lisää polkupyörä" <<  endl;
            int subChoice;
            do {
                 cout << "1. Lisää polkupyörä" <<  endl;
                 cout << "2. Lisää velomobiili" <<  endl;
                 cout << "0. Palaa päävalikkoon" <<  endl;
                 cout << "Enter your choice: ";
                 cin >> subChoice;
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (subChoice) {
                case 1:
                    {
                    string id, brand, model, frameSize, wheelSize, frameNumber, bikeType;
                    int year, wheelAmount;
                    cout << "Lisää polkupyörän tiedot" << endl;
                    cout << "Merkki: ";
                    getline(cin, brand);
                    cout << "Malli: ";
                    getline(cin, model);
                    cout << "Vuosi: ";
                    cin >> year;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Runkokoko: ";
                    getline(cin, frameSize);
                    cout << "Pyörien koko: ";
                    getline(cin, wheelSize);
                    cout << "Runkonumero: ";
                    getline(cin, frameNumber);
                    cout << "Pyörätyyppi: ";
                    getline(cin, bikeType);

                    id = generateId();
                    wheelAmount = 2;

                    Bicycle bike;
                    bike.setId(id);
                    bike.setBrand(brand);
                    bike.setModel(model);
                    bike.setYear(year);
                    bike.setFrameSize(frameSize);
                    bike.setWheelSize(wheelSize);
                    bike.setWheelAmount(wheelAmount);
                    bike.setFrameNumber(frameNumber);
                    bike.setBikeType(bikeType);

                    bicycles.push_back(bike);

                    cout << "Rekisteritunnus: " << id << ", Polkupyörä: " << brand << " " << model << " vuodelta : " << year << " lisätty" << endl;
                    }
                    break;
                case 2:
                    // Handle Suboption 2
                    break;
                case 0:
                     cout << "Returning to Main Menu...\n";
                    break;
                default:
                     cout << "Invalid choice. Please try again.\n";
                }
            } while (subChoice != 0);
            break;
        case 2:
            cout << "Näytä polkupyörät" << endl;
            if (bicycles.empty()) {
                cout << "Ei polkupyöriä rekisterissä." << endl;
            }
            else {
                int lineNumber = 1;
                for (const auto& bike : bicycles) {
                    cout << lineNumber << ". Rekisteritunnus: "<< bike.getId() << ", Merkki: " << bike.getBrand() << ", Malli: " << bike.getModel()
                        << ", Vuosi: " << bike.getYear() << ", Runkokoko: " << bike.getFrameSize()
                        << ", Pyörien koko: " << bike.getWheelSize() << ", Pyörien määrä: " << bike.getWheelAmount()
                        << ", Runkonumero: " << bike.getFrameNumber() << ", Pyörätyyppi: " << bike.getBikeType() << endl;
                    lineNumber++;
                }
            }
            break;
        case 3:
             cout << "Poista polkupyörä" <<  endl;
            break;
        case 4:
             cout << "Muokkaa pyörien tietoja" <<  endl;
            break;
        case 0:
             cout << "Lopeta" <<  endl;
            break;
        default:
             cout << "Tuntematon valinta" <<  endl;
            break;
        }
    } while (valinta != 0);

    saveBicyclesToFile(bicycles, filename);

    return 0;
}