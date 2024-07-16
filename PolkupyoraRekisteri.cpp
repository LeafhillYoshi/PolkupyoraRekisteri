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

void saveBicyclesToFile(const std::vector<Bicycle>& bicycles, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    for (const auto& bike : bicycles) {
        file << bike.getBrand() << ","
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
        string brand, model, frameSize, wheelSize, frameNumber, bikeType;
        int year, wheelAmount;

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

    int valinta;
    
    do
    {
        cout << "Polkupyörärekisteri" <<  endl;
        cout << "1. Lisää polkupyörä" <<  endl;
        cout << "2. Näytä polkupyörät" <<  endl;
        cout << "3. Poista polkupyörä" <<  endl;
        cout << "4. Muokkaa pyörien tietoja" <<  endl;
        /*
        cout << "5. Tallenna rekisterin tiedot" << endl;
        cout << "6. Lataa rekisteri" << endl;
        */
        cout << "0. Lopeta" <<  endl;
        cout << "Valitse toiminto: ";
        cin >> valinta;
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

                switch (subChoice) {
                case 1:
                    {
                    string brand, model, frameSize, wheelSize, frameNumber, bikeType;
                    int year, wheelAmount;
                    cout << "Lisää polkupyörän tiedot" << endl;
                    cout << "Merkki: ";
                    cin >> brand;
                    cout << "Malli: ";
                    cin >> model;
                    cout << "Vuosi: ";
                    cin >> year;
                    cout << "Runkokoko: ";
                    cin >> frameSize;
                    cout << "Pyörien koko: ";
                    cin >> wheelSize;
                    cout << "Pyörien määrä: ";
                    cin >> wheelAmount;
                    cout << "Runkonumero: ";
                    cin >> frameNumber;
                    cout << "Pyörätyyppi: ";
                    cin >> bikeType;

                    bicycles.push_back(Bicycle());
                    bicycles.back().setBrand(brand);
                    bicycles.back().setModel(model);
                    bicycles.back().setYear(year);
                    bicycles.back().setFrameSize(frameSize);
                    bicycles.back().setWheelSize(wheelSize);
                    bicycles.back().setWheelAmount(wheelAmount);
                    bicycles.back().setFrameNumber(frameNumber);
                    bicycles.back().setBikeType(bikeType);

                    cout << "Polkupyörä: " << brand << " " << model << "vuodelta : " << year << " lisätty" << endl;
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
                for (const auto& bike : bicycles) {
                    cout << "Merkki: " << bike.getBrand() << ", Malli: " << bike.getModel()
                        << ", Vuosi: " << bike.getYear() << ", Runkokoko: " << bike.getFrameSize()
                        << ", Pyörien koko: " << bike.getWheelSize() << ", Pyörien määrä: " << bike.getWheelAmount()
                        << ", Runkonumero: " << bike.getFrameNumber() << ", Pyörätyyppi: " << bike.getBikeType() << endl;
                }
            }
            break;
        case 3:
             cout << "Poista polkupyörä" <<  endl;
            break;
        case 4:
             cout << "Muokkaa pyörien tietoja" <<  endl;
            break;
            /*
        case 5:
            cout << "Tallenna rekisteri" << endl;
        case 6:
            cout << "Lataa rekisteri" << endl;
            */
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