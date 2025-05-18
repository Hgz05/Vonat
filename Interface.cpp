#include "Interface.h"
#include <iostream>

int Interface::InterfaceInit(Allomas *FirstAllomas, Vonat **VonatArray, JaratWrapper *FirstJarat, JegyList *JegyList) {
    int UserInput;

    do {
        std::cout << "1. Jaratok Megtekintese\n2. Jegy Vasarlasa\n3. Menedzser Mod (Jaratok, Vonatok Modositasa)\n0. Kilepes\n";
        UserInput = UserInputChecker();
        if (UserInput < 0 || UserInput > 3) {
            std::cout << "Invalid Input!\n";
        }
        switch (UserInput) {
            case 0:
                break;
            case 1:
                JaratInterface(FirstJarat);
                break;
            case 2:
                JegyListInterface(FirstJarat, JegyList);
                break;
            case 3:
                ManagerInterface(VonatArray,FirstJarat);
                break;
                default:
                break;
        }

    }while(UserInput != 0 );
    JaratWrapper::SaveJaratWrapper(FirstJarat);
    FirstJarat->DelJaratWrapper();
    try {
        JegyList::SaveJegyList(JegyList);
    }catch (const char* e) {
        std::cout << e;
    }
    Vonat::SaveVonat(VonatArray);

    return 0;
}

void Interface::JaratInterface(JaratWrapper *FirstJarat) {
    int UserInput;
    FirstJarat->PrintJarat();
    do {
        std::cout << "0. Vissza\n";
        UserInput = UserInputChecker();
        if (UserInput != 0) {
            std::cout << "Invalid Input!\n";
        }
    }while(UserInput != 0 );

}

void Interface::JegyListInterface(JaratWrapper *FirstJarat, JegyList *JegyList) {
    int UserInput;
    do {
        std::cout << "1. Jaratok Megtekintese\n2. Jegy Vasarlasa\n3. Jegyeim Megtekintese\n0. Kilepes\n";
        UserInput = UserInputChecker();
        if (UserInput < 0 || UserInput > 3) {
            std::cout << "Invalid Input!\n";
        }
        switch (UserInput) {
            case 0:
                break;
            case 1:
                JaratInterface(FirstJarat);
                break;
            case 2:
                JegyList->BuyJegy(FirstJarat);
                break;
            case 3:
                JegyList->PrintJegyList();
                break;
            default:
                break;
        }

    }while (UserInput != 0);
}

void Interface::ManagerInterface(Vonat **VonatArray, JaratWrapper *FirstJarat) {
    int UserInput;
    do {
        std::cout << "1. Vonat Hozzaadasa\n2. Keses Bejelentese\n0. Kilepes\n";
        UserInput = UserInputChecker();
        if (UserInput < 0 || UserInput > 2) {
            std::cout << "Invalid Input!\n";
        }
        switch (UserInput) {
            case 0:
                break;
            case 1:
            try {
                VonatArray = Vonat::CreateNewVonat(VonatArray);
            }catch (const char * e ) {
                std::cout << e;
            }
                break;
            case 2:
                try {
                    FirstJarat->AddKeses();
                }catch (const char * e ) {
                    std::cout << e;
                }
                break;
            default:
                break;
        }

    }while (UserInput != 0);
}

int Interface::UserInputChecker() {
    std::string UserInputString;
    std::cin >> UserInputString;
    if (UserInputString.length() > 1) {
        return -1;
    }
    char UserInputChar = UserInputString[0];
    if (isalpha(UserInputChar)) {
        return -1;
    }
    return UserInputChar - '0';
}
