#include "passwordManager.h"

passwordManager::passwordManager()
{

}

passwordManager::~passwordManager()
{
    outputter.open("pass.txt");
}