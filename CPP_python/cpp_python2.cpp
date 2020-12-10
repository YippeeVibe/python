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
    pFunc = PyObject_GetAttrString(pModule,"multiply1");
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
   pArgs = PyTuple_New(2);
    //����Ԫ�����
   PyObject* pValue1 = PyLong_FromLong(2);
   PyObject* pValue2 = PyLong_FromLong(3);
   PyTuple_SetItem(pArgs,0,pValue1);
   PyTuple_SetItem(pArgs,1,pValue2);

   PyObject* pCallBackValue = PyObject_CallObject(pFunc,pArgs);





   std::cout<<PyLong_AsLong(pCallBackValue)<<std::endl;
   // free �ڴ�
   Py_DECREF(pArgs);
   Py_XDECREF(pFunc);
   Py_DECREF(pModule);
   Py_DECREF(pCallBackValue);
  //�ر�python ����
   Py_FinalizeEx();
}