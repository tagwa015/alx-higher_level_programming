#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints basic info about Python lists.
 * @p: A PyObject list object.
 */
void print_python_list(PyObject *p)
{
    int size, alloc, i;
    const char *type;
    PyListObject *list = (PyListObject *)p;

    size = Py_SIZE(list);
    alloc = list->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %d\n", size);
    printf("[*] Allocated = %d\n", alloc);

    for (i = 0; i < size; i++)
    {
        type = Py_TYPE(list->ob_item[i])->tp_name;
        printf("Element %d: %s\n", i, type);

        if (strcmp(type, "bytes") == 0)
            print_python_bytes(list->ob_item[i]);
    }
}

/**
 * print_python_bytes - Prints basic info about Python byte objects.
 * @p: A PyObject byte object.
 */
void print_python_bytes(PyObject *p)
{
    unsigned char i, size;
    PyBytesObject *bytes = (PyBytesObject *)p;

    printf("[.] Bytes object info\n");
    if (strcmp(Py_TYPE(p)->tp_name, "bytes") != 0)
    {
        printf("  [ERROR] invalid Bytes Object\n");
        return;
    }

    size = Py_SIZE(p);
    printf("  Size: %u\n", size);
    printf("  Trying string: %s\n", bytes->ob_sval);

    if (size > 10)
        size = 10;

    printf("  First %u bytes: ", size);
    for (i = 0; i < size; i++)
        printf("%02hhx ", bytes->ob_sval[i]);
    printf("\n");
}
