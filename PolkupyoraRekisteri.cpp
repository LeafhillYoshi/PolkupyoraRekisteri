#include <iostream>

int main()
{
    std::cout << "Polkupy�r�rekisteri" << std::endl;
    std::cout << "1. Lis�� polkupy�r�" << std::endl;
    std::cout << "2. N�yt� polkupy�r�t" << std::endl;
    std::cout << "3. Poista polkupy�r�" << std::endl;
    std::cout << "4. Muokkaa py�rien tietoja" << std::endl;
    std::cout << "0. Lopeta" << std::endl;
    std::cout << "Valitse toiminto: ";
    int valinta;
    std::cin >> valinta;
    switch (valinta)
    {
    case 1:
        std::cout << "Lis�� polkupy�r�" << std::endl;
        break;
    case 2:
        std::cout << "N�yt� polkupy�r�t" << std::endl;
        break;
    case 3:
        std::cout << "Poista polkupy�r�" << std::endl;
        break;
    case 4:
        std::cout << "Muokkaa py�rien tietoja" << std::endl;
        break;
    case 0:
        std::cout << "Lopeta" << std::endl;
        break;
    default:
        std::cout << "Tuntematon valinta" << std::endl;
        break;
    }
}