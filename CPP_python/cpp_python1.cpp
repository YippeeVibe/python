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
    //�ַ�д���ˣ�����ᷢ�����󣬲�û�н��뵽C++�Ĵ�����Ϣ�С�����û��д��
    PyRun_SimpleString("from time import time,ctime\n"
                        "print('Todat is',ctime(time()))\n");
    if(Py_FinalizeEx()<0)
    {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
    

}