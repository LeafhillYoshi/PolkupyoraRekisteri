//PolkupyoraRekisteri.cpp
//This is the main file of the program. It contains the main function that is the entry point of the program.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <clocale>
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
    cout << "Tiedot tallennettu." << endl;
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
    setlocale(LC_ALL, "fi-FI");
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
        cout << "5. Tallenna tietokanta" <<  endl;
        cout << "0. Lopeta" <<  endl;
        cout << "Valitse toiminto: ";
        cin >> valinta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (valinta)
        {
        case 1:
            cout << "Lisää polkupyörä" << endl;
            int subChoice;
            do {
                cout << "1. Lisää polkupyörä" << endl;
                cout << "2. Lisää velomobiili" << endl;
                cout << "0. Palaa päävalikkoon" << endl;
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
                    int bikeTypeChoice;
                    cout << "1. Maantiepyörä" << endl;
                    cout << "2. Kaupunkipyörä" << endl;
                    cout << "3. Hybridi" << endl;
                    cout << "4. Lastenpyörä" << endl;
                    cout << "5. Taittopyörä" << endl;
                    cout << "6. Maastopyörä" << endl;
                    cout << "7. Maastopyörä/Täysjousto" << endl;
                    cout << "8. Retkipyörä" << endl;
                    cout << "9. Fatbike" << endl;
                    cout << "10. Kilpapyörä" << endl;
                    cout << "11. Sähköpyörä" << endl;
                    cout << "12. Muu" << endl;
                    cout << "Valitse pyörätyyppi: ";

                    cin >> bikeTypeChoice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    switch (bikeTypeChoice) {
                    case 1:
                        bikeType = "Maantiepyörä";
                        break;
                    case 2:
                        bikeType = "Kaupunkipyörä";
                        break;
                    case 3:
                        bikeType = "Hybridi";
                        break;
                    case 4:
                        bikeType = "Lastenpyörä";
                        break;
                    case 5:
                        bikeType = "Taittopyörä";
                        break;
                    case 6:
                        bikeType = "Maastopyörä";
                        break;
                    case 7:
                        bikeType = "Maastopyörä/Täysjousto";
                        break;
                    case 8:
                        bikeType = "Retkipyörä";
                        break;
                    case 9:
                        bikeType = "Fatbike";
                        break;
                    case 10:
                        bikeType = "Kilpapyörä";
                        break;
                    case 11:
                        bikeType = "Sähköpyörä";
                        break;
                    case 12:
                        bikeType = "Muu";
                        break;
                    }


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
                {
                    string id, brand, model, frameSize, wheelSize, frameNumber, bikeType;
                    int year, wheelAmount;
                    cout << "Lisää velomobiilin tiedot" << endl;
                    cout << "Merkki: ";
                    getline(cin, brand);
                    cout << "Malli: ";
                    getline(cin, model);
                    cout << "Vuosi: ";
                    cin >> year;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Runkokoko: ";
                    getline(cin, frameSize);
                    cout << "Renkaan koko: ";
                    getline(cin, wheelSize);
                    cout << "Renkaiden määrä: ";
                    cin >> wheelAmount;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Runkonumero: ";
                    getline(cin, frameNumber);

                    bikeType = "Velomobiili";
                    id = generateId();

                    Velomobile velo;
                    velo.setId(id);
                    velo.setBrand(brand);
                    velo.setModel(model);
                    velo.setYear(year);
                    velo.setFrameSize(frameSize);
                    velo.setWheelSize(wheelSize);
                    velo.setWheelAmount(wheelAmount);
                    velo.setFrameNumber(frameNumber);
                    velo.setBikeType(bikeType);

                    bicycles.push_back(velo);
                    cout << "Rekisteritunnus: " << id << ", Velomobiili: " << brand << " " << model << " vuodelta : " << year << " lisätty" << endl;

                    break;
                }
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
                    cout << lineNumber << ". Rekisteritunnus: " << bike.getId() << ", Merkki: " << bike.getBrand() << ", Malli: " << bike.getModel()
                        << ", Vuosi: " << bike.getYear() << ", Runkokoko: " << bike.getFrameSize()
                        << ", Pyörien koko: " << bike.getWheelSize() << ", Pyörien määrä: " << bike.getWheelAmount()
                        << ", Runkonumero: " << bike.getFrameNumber() << ", Pyörätyyppi: " << bike.getBikeType() << endl;
                    lineNumber++;
                }
            }
            break;
        case 3:
        {
            cout << "Poista polkupyörä" << endl;
            if (bicycles.empty()) {
                cout << "Ei polkupyöriä rekisterissä." << endl;
            }
            else {
                string idToDelete;
                cout << "Anna poistettavan polkupyörän rekisteritunnus: ";
                getline(cin, idToDelete);
                auto it = find_if(bicycles.begin(), bicycles.end(), [idToDelete](const Bicycle& bike) {
                    return bike.getId() == idToDelete;
                    });
                if (it != bicycles.end()) {
                    bicycles.erase(it);
                    cout << "Polkupyörä rekisteritunnuksella " << idToDelete << " poistettu." << endl;
                }
                else {
                    cout << "Polkupyörää rekisteritunnuksella " << idToDelete << " ei löytynyt." << endl;
                }
                break;
            }
        }
        case 4:
        {
            cout << "Muokkaa pyörien tietoja" << endl;

            if (bicycles.empty()) {
                cout << "Ei polkupyöriä rekisterissä." << endl;
                break;
            }

            int editChoice;
            cout << "1. Muokkaa polkupyörää" << endl;
            cout << "2. Muokkaa velomobiilia" << endl;
            cout << "0. Palaa päävalikkoon" << endl;
            cout << "Valitse toiminto: ";
            cin >> editChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (editChoice) {
            case 1:
            {
                string idToEdit;
                cout << "Anna muokattavan polkupyörän rekisteritunnus: ";
                getline(cin, idToEdit);

                auto it = find_if(bicycles.begin(), bicycles.end(), [&idToEdit](const Bicycle& bike) {
                    return bike.getId() == idToEdit;
                    });

                if (it != bicycles.end()) {
                    cout << "Nykyiset tiedot: " << endl;
                    cout << "Rekisteritunnus: " << it->getId() << ", Merkki: " << it->getBrand() << ", Malli: " << it->getModel()
                        << ", Vuosi: " << it->getYear() << ", Runkokoko: " << it->getFrameSize()
                        << ", Pyörien koko: " << it->getWheelSize() << ", Pyörien määrä: " << it->getWheelAmount()
                        << ", Runkonumero: " << it->getFrameNumber() << ", Pyörätyyppi: " << it->getBikeType() << endl;

                    string brand, model, frameSize, wheelSize, frameNumber, bikeType;
                    int year;

                    cout << "Anna uusi merkki (tyhjä syöte ohittaa): ";
                    getline(cin, brand);
                    if (!brand.empty()) {
                        it->setBrand(brand);
                    }
                    cout << "Anna uusi malli (tyhjä syöte ohittaa): ";
                    getline(cin, model);
                    if (!model.empty()) {
                        it->setModel(model);
                    }
                    cout << "Anna uusi vuosi (0 ohittaa): ";
                    cin >> year;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (year != 0) {
                        it->setYear(year);
                    }
                    cout << "Anna uusi runkokoko (tyhjä syöte ohittaa): ";
                    getline(cin, frameSize);
                    if (!frameSize.empty()) {
                        it->setFrameSize(frameSize);
                    }
                    cout << "Anna uusi pyörien koko (tyhjä syöte ohittaa): ";
                    getline(cin, wheelSize);
                    if (!wheelSize.empty()) {
                        it->setWheelSize(wheelSize);
                    }

                    cout << "Anna uusi runkonumero (tyhjä syöte ohittaa): ";
                    getline(cin, frameNumber);
                    if (!frameNumber.empty()) {
                        it->setFrameNumber(frameNumber);
                    }
                    cout << "Anna uusi pyörätyyppi (tyhjä syöte ohittaa): ";
                    getline(cin, bikeType);
                    if (!bikeType.empty()) {
                        it->setBikeType(bikeType);
                    }

                    cout << "Tiedot päivitetty." << endl;
                }
                else {
                    cout << "Polkupyörää rekisteritunnuksella " << idToEdit << " ei löytynyt." << endl;
                }
                break;
            }
            case 2:
            {
                string idToEdit;
                cout << "Anna muokattavan velomobiilin rekisteritunnus: ";
                getline(cin, idToEdit);

                auto it = find_if(bicycles.begin(), bicycles.end(), [&idToEdit](const Bicycle& bike) {
                    return bike.getId() == idToEdit;
                    });

                if (it != bicycles.end()) {
                    cout << "Nykyiset tiedot: " << endl;
                    cout << "Rekisteritunnus: " << it->getId() << ", Merkki: " << it->getBrand() << ", Malli: " << it->getModel()
                        << ", Vuosi: " << it->getYear() << ", Runkokoko: " << it->getFrameSize()
                        << ", Pyörien koko: " << it->getWheelSize() << ", Pyörien määrä: " << it->getWheelAmount()
                        << ", Runkonumero: " << it->getFrameNumber() << ", Pyörätyyppi: " << it->getBikeType() << endl;

                    string brand, model, frameSize, wheelSize, frameNumber;
                    int year, wheelAmount;

                    cout << "Anna uusi merkki (tyhjä syöte ohittaa): ";
                    getline(cin, brand);
                    if (!brand.empty()) {
                        it->setBrand(brand);
                    }
                    cout << "Anna uusi malli (tyhjä syöte ohittaa): ";
                    getline(cin, model);
                    if (!model.empty()) {
                        it->setModel(model);
                    }
                    cout << "Anna uusi vuosi (0 ohittaa): ";
                    cin >> year;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (year != 0) {
                        it->setYear(year);
                    }
                    cout << "Anna uusi runkokoko (tyhjä syöte ohittaa): ";
                    getline(cin, frameSize);
                    if (!frameSize.empty()) {
                        it->setFrameSize(frameSize);
                    }
                    cout << "Anna uusi pyörien koko (tyhjä syöte ohittaa): ";
                    getline(cin, wheelSize);
                    if (!wheelSize.empty()) {
                        it->setWheelSize(wheelSize);
                    }

                    cout << "Anna uusi pyörien määrä (0 ohittaa): ";
                    cin >> wheelAmount;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (wheelAmount != 0) {
                        it->setWheelAmount(wheelAmount);
                    }

                    cout << "Anna uusi runkonumero (tyhjä syöte ohittaa): ";
                    getline(cin, frameNumber);
                    if (!frameNumber.empty()) {
                        it->setFrameNumber(frameNumber);
                    }

                    cout << "Tiedot päivitetty." << endl;
                }
                else {
                    cout << "Polkupyörää rekisteritunnuksella " << idToEdit << " ei löytynyt." << endl;
                }
                break;
            }
            case 0:
				break;
            }
        }
        case 5:
            cout << "Tallenna tietokanta" << endl;
            saveBicyclesToFile(bicycles, filename);
            break;
        case 0:
            cout << "Lopeta" << endl;
            break;
        default:
            cout << "Tuntematon valinta" << endl;
            break;
        }
    } while (valinta != 0);

    saveBicyclesToFile(bicycles, filename);

    return 0;
}