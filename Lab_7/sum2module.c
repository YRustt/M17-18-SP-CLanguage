#include <Python.h>

static PyObject* sum2module_digit_sum(PyObject *self, PyObject *args) {
    int x, ans = 0;
    if (!PyArg_ParseTuple(args, "i", &x)) return NULL;

    while (x != 0) {
        ans += x % 10;
        x /= 10;
    }

    return Py_BuildValue("i", ans);
}


static PyMethodDef sum2_funcs[] = {
    {"digit_sum", (PyCFunction)sum2module_digit_sum, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef sum2module = {
    PyModuleDef_HEAD_INIT,
    "sum2",
    NULL,
    -1,
    sum2_funcs
};


PyMODINIT_FUNC PyInit_sum2(void) {
    return PyModule_Create(&sum2module);
}


int main(int argc, char *argv[]) {
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    PyImport_AppendInittab("sum2", PyInit_sum2);
    Py_SetProgramName(program);
    Py_Initialize();

    PyImport_ImportModule("sum2");

    PyMem_RawFree(program);
    return 0;
}
