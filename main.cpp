
#include "Jarat.h"
#include "JaratWrapper.h"
#include "Allomas.h"
#include "JegyList.h"
#include "Interface.h"




int main(int argc, char const *argv[]) {
    Allomas* FirstAllomas = Allomas::InitAllomas();
    Vonat** VonatArray = Vonat::InitVonat();
    JaratWrapper* FirstJarat = JaratWrapper::InitJaratWrapper(FirstAllomas, VonatArray);
    JegyList* JegyList = JegyList::InitJegyList(FirstJarat,FirstAllomas);
    if ( Interface::InterfaceInit(FirstAllomas,VonatArray,FirstJarat,JegyList) == 0) {
        return 0;
    }
}
