#include <iostream>
#include <Python.h>
/*
1. C++��������������
2. ���ȿ��ĵ���һ�㶼��Ӣ�ĵģ�������ֿ���������Ȼѡ���ĵ��������������Ϻܶ��ʱ�Ķ�������
3. python һ�нԶ���һ�нԶ���PyObject.
*/
int main(int argc,char*argv[]) 
{
    PyObject* pName;
    PyObject* pModule;
    PyObject* pFunc;
    PyObject* pArgs;

    //��ʼ����������python����
    Py_Initialize();

    //�������п⣬�����ôμ�Ŀ¼
    PyRun_SimpleString("import sys");
    //PyRun_SimpleString("import time");
    //PyRun_SimpleString("import csv");
    PyRun_SimpleString("sys.path.append(\"../../\")");


    //���������
    pName = PyUnicode_DecodeFSDefault("sg");
    //����һ��ģ��ָ��
    pModule = PyImport_Import(pName);

    //�ͷŵ����õ�ָ�� pName
    Py_DECREF(pName);

    if(pModule == NULL)
    {
        std::cout<<"pModule == NULL"<<std::endl;
        return 0;
    }

    //���뺯��  ע�ⲻӦ���� test fun ʲô�ģ������python ����Ŀ��ͻ
    pFunc = PyObject_GetAttrString(pModule,"readcsv");
    if(!pFunc)
    {
        std::cout<<"pFunc == 0 "<<std::endl;
        return 0;
    }
    if(!PyCallable_Check(pFunc))
    {
        std::cout<<"PyCallable_Check(pFunc) == 0 "<<std::endl;
        return 0;
    }

   //����һ����Ԫ��Ԫ��
   pArgs = PyTuple_New(1);
    //����Ԫ�����
   PyObject* pValue1 =PyBytes_FromString("002568.csv");
   //002558.csv�ļ��Լ��ص�exe�ļ���Ŀ¼Ϊ��׼���������Ϊ��python.exeִ��python�ű������exeִ��python�ű�
   //����������Ŀ¼�϶��ǲ�ͬ�ģ���Ȼpython�ű�����һ��Ŀ¼��ǰ���л�Ŀ¼�����ؽű���������ִ��python�ű��Ļ���
   //ȷʵ��exe��Ŀ¼��
   PyTuple_SetItem(pArgs,0,pValue1);


   PyObject* pCallBackValue = PyObject_CallObject(pFunc,pArgs);





    if(!PyList_Check(pCallBackValue))
    {
        std::cout<<"No a list";

    }
    
    //�õ�һ����Ԫ����
   //return 0;
   int n = PyList_Size(pCallBackValue);
   std::cout<<"n:"<<n<<std::endl;
    for(int i = 0;i<n;++i)
    {
        PyObject* it = PyList_GetItem(pCallBackValue,i);
        int m = PyList_Size(it);
        for(int j = 0;j<m;++j)
        {
            if(j == 0)
            {
                std::cout<<(int)(PyFloat_AsDouble(PyList_GetItem(it,j)))<<",";

            }
            else
            {
                std::cout<<PyFloat_AsDouble(PyList_GetItem(it,j))<<",";
            }
        }
       std::cout<<std::endl;
       //Py_DECREF(it);
    }
  // std::cout<<PyLong_AsLong(pCallBackValue)<<std::endl;
   // free �ڴ�
   Py_DECREF(pArgs);
   Py_XDECREF(pFunc);
   Py_DECREF(pModule);
   Py_DECREF(pCallBackValue);
  //�ر�python ����
   Py_FinalizeEx();
}