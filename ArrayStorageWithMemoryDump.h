char* two_d_alloc(int rows, int columns, size_t t);
void two_d_dealloc(char *matrix);
void two_d_store(char* matrix, int row, int column, int columns, size_t t, int value);

int two_d_fetch(char* matrix, int row, int column, int columns, size_t t);

void memoryDump(char *arr, size_t t);
