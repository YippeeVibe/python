#include <iostream>
#include <Python.h>
/*
1. C++充满技术想象力
2. 首先看文档，一般都是英文的，如果发现看不懂，仍然选择看文档，中文搜索网上很多过时的东西。。
3. python 一切皆对象，一切皆对象，PyObject.
*/
int main(int argc,char*argv[]) 
{
    PyObject* pName;
    PyObject* pModule;
    PyObject* pFunc;
    PyObject* pArgs;

    //初始化，并启动python环境
    Py_Initialize();

    //导入运行库，并设置次级目录
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"../../\")");


    //导入库名称
    pName = PyUnicode_DecodeFSDefault("sg");
    //生成一个模块指针
    pModule = PyImport_Import(pName);

    //释放掉不用的指针 pName
    Py_DECREF(pName);

    if(pModule == NULL)
    {
        std::cout<<"pModule == NULL"<<std::endl;
        return 0;
    }

    //导入函数  注意不应该起 test fun 什么的，以免和python 本身的库冲突
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

   //生成一个二元的元组
   pArgs = PyTuple_New(2);
    //填满元组参数
   PyObject* pValue1 = PyLong_FromLong(2);
   PyObject* pValue2 = PyLong_FromLong(3);
   PyTuple_SetItem(pArgs,0,pValue1);
   PyTuple_SetItem(pArgs,1,pValue2);

   PyObject* pCallBackValue = PyObject_CallObject(pFunc,pArgs);





   std::cout<<PyLong_AsLong(pCallBackValue)<<std::endl;
   // free 内存
   Py_DECREF(pArgs);
   Py_XDECREF(pFunc);
   Py_DECREF(pModule);
   Py_DECREF(pCallBackValue);
  //关闭python 环境
   Py_FinalizeEx();
}