//PolkupyoraRekisteri.cpp
//This is the main file of the program. It contains the main function that is the entry point of the program.
#include <iostream>

int main()
{
    std::cout << "Polkupyörärekisteri" << std::endl;
    std::cout << "1. Lisää polkupyörä" << std::endl;
    std::cout << "2. Näytä polkupyörät" << std::endl;
    std::cout << "3. Poista polkupyörä" << std::endl;
    std::cout << "4. Muokkaa pyörien tietoja" << std::endl;
    std::cout << "0. Lopeta" << std::endl;
    std::cout << "Valitse toiminto: ";
    int valinta;
    std::cin >> valinta;
    do
    {
        switch (valinta)
        {
        case 1:
            std::cout << "Lisää polkupyörä" << std::endl;
            break;
        case 2:
            std::cout << "Näytä polkupyörät" << std::endl;
            break;
        case 3:
            std::cout << "Poista polkupyörä" << std::endl;
            break;
        case 4:
            std::cout << "Muokkaa pyörien tietoja" << std::endl;
            break;
        case 0:
            std::cout << "Lopeta" << std::endl;
            break;
        default:
            std::cout << "Tuntematon valinta" << std::endl;
            break;
        }
    } while (valinta != 0);

    return 0;
}