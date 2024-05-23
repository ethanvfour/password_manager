#include <iostream>
#include "passwordManager.h"

using namespace std;





int main()
{
    
    cout<<"ko"<<endl;
    
    std::string lop = "Ethan Guillem";
    
    encryptString(&lop[0], lop.length());
    
    std::cout<<lop<<std::endl<<std::flush;
    decryptString(&lop[0], lop.length());
    std::cout<<lop<<std::endl;
    
    
}