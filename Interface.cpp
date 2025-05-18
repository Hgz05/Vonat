#include "Interface.h"
#include <iostream>
int Interface::InterfaceInit(Allomas *FirstAllomas, Vonat **VonatArray, JaratWrapper *FirstJarat, JegyList *JegyList) {
    char UserInputChar = '1';
    int UserInput = UserInputChar - '0';
    do {
        std::cin >> UserInputChar;
        if (isalpha(UserInputChar)) {
            std::cout << "Invalid Input!" << std::endl;
            continue;
        }
        UserInput = UserInputChar - '0';
        switch (UserInput) {
            case 0:

                break;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            default:
                std::cout << "Invalid Input!\n";
                break;
        }


    }while(UserInput != 0 );

    JegyList::SaveJegyList(JegyList);
    JaratWrapper::SaveJaratWrapper(FirstJarat);
    Vonat::SaveVonat(VonatArray);
    Allomas::SaveAllomas(FirstAllomas);

    return 0;
}
