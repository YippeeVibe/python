#include<iostream>
#include <Python.h>

int main(int argc,char* argv[])
{
    wchar_t* program = Py_DecodeLocale(argv[0],NULL);
    if(program == NULL)
    {
        std::cout<<"program == NULL";
        exit(1);
    }

    Py_SetProgramName(program);
    Py_Initialize();
    //字符写错了，这个会发生错误，并没有接入到C++的错误信息中。（我没有写）
    PyRun_SimpleString("from time import time,ctime\n"
                        "print('Todat is',ctime(time()))\n");
    if(Py_FinalizeEx()<0)
    {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
    

}