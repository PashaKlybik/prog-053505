#include "functions.h"

void* Malloc(long long ByteCount) {
    if (ByteCount < 0) {
        printf("Warning: try to alloc wrong byte amount!\n");
        return NULL;
    }
    void* ptr = malloc(ByteCount);
    while (!ptr) {
        printf("\n");
        printf("Failed allocation of %lld bytes!\n", ByteCount);
        printf("Not enough heap memory!\n");
        printf("Please close Google Chrome or that program!\n");
        printf("And press any key\n");
        ptr = malloc(ByteCount);
    }
    return ptr;
}

bool CmpChar(void* a, void* b) {
    return TO(char)a < TO(char)b;
}

Vector* VectorNew(int sizeof_element) {
    Vector* t = (Vector*)Malloc(sizeof(Vector));
    t->elemsize = sizeof_element;
    t->size = 0;
    t->begin = NULL;
    t->alloc = 0;
    t->comp = NULL;
    return t;
}

void VectorClear(Vector* that) {
    free(that->begin);
    that->begin = NULL;
    that->size = 0;
    that->alloc = 0;
    that->comp = NULL;
}

void VectorDelete(Vector* that) {
    VectorClear(that);
    free(that);
    /* that = NULL; */
}

void VectorAddElem(Vector* that, void* what) {
    if (that->size + 1 > that->alloc) {
        VectorRealloc(that, that->alloc * 2 + 1);
    }
    that->size += 1;
    VectorSetElem(that, that->size - 1, what);
}

int VectorSize(Vector* that) {
    return that->size;
}

void* VectorGetElem(Vector* that, int index) {
    if (index < 0 || VectorSize(that) <= index) {
        printf("Error: Wrond index (in VectorGetElem)");
        return NULL;
    }
    return (void*)((char*)(that->begin) + index * that->elemsize);
}

void VectorSetElem(Vector* that, int index, void* what) {
    if (index < 0 || VectorSize(that) <= index) {
        printf("Error: Wrond index (in VectorSetElem)");
        return;
    }
    memcpy(((char*)(that->begin) + index * that->elemsize), what, that->elemsize);
}

void VectorSetComp(Vector* that, bool (*comparator) (void* a, void* b)) {
    that->comp = comparator;
}

void VectorRealloc(Vector* that, int newalloc) {
    if (newalloc < that->size) {
        printf("Warning: Wrong Vector Realloc!\n");
        return;
    }
    that->alloc = newalloc;
    if (newalloc == 0) {
        free(that->begin);
        that->begin = NULL;
        return;
    }
    void* t = Malloc(newalloc * that->elemsize);
    memcpy(t, that->begin, that->size * that->elemsize);
    free(that->begin);
    that->begin = t;
}

char NullChar = 0;

String* StringNew(void) {
    String* t = VectorNew(sizeof(char));
    VectorSetComp(t, CmpChar);
    VectorAddElem(t, &NullChar);
    return t;
}

void StringClear(String* that) {
    VectorClear(that);
    VectorAddElem(that, &NullChar);
}

void StringDelete(String* that) {
    VectorDelete(that);
}

void StringAddElem(String* that, char what) {
    VectorAddElem(that, &NullChar);
    VectorSetElem(that, StringSize(that) - 1, &what);
}

int StringSize(String* that) {
    return that->size - 1;
}

void StringIgnore(FILE* from) {
    char sym;
    fscanf(from, "%c", &sym);
    while (sym != '\n') {
        fscanf(from, "%c", &sym);
    }
}

void StringRead(String* that, char until, FILE* from) {
    StringClear(that);
    char sym;
    if (!feof(from)) {
        fscanf(from, "%c", &sym);
    }
    while ((sym == ' ' || sym == '\n' || sym == until) && !feof(from)) {
        fscanf(from, "%c", &sym);
    }
    while (sym != until && sym != '\n' && !feof(from)) {
        StringAddElem(that, sym);
        fscanf(from, "%c", &sym);
    }
    if (!feof(from)) {
        ungetc(sym, from);
    }
}

bool StringToInt(char* from, long long* towhat, long long MinBound, long long MaxBound) {
    if (MinBound > MaxBound || MinBound < -MAXLL || MAXLL < MaxBound) {
        printf("Wrong StringToInt bounds!\n");
        return false;
    }
    if (!from[0]) {
        return false;
    }
    bool Minus = false;
    if (from[0] == '-') {
        Minus = true;
    }
    unsigned long long t = 0;
    int i;
    for (i = Minus; from[i]; i++) {
        if (from[i] < '0' || '9' < from[i]) {
            return false;
        }
        else if (t * 10 + (from[i] - '0') > MAXLL) {
            return false;
        }
        else {
            t *= 10;
            t += (from[i] - '0');
        }
    }
    if (t > MAXLL) {
        return false;
    }
    long long tmp = t;
    if (Minus) {
        tmp = -tmp;
    }
    if (tmp < MinBound || MaxBound < tmp) {
        return false;
    }
    *towhat = tmp;
    return true;
}

long long StringReadInt(FILE* from, long long MinBound, long long MaxBound) {
    String* s = StringNew();
    StringRead(s, ' ', from);
    long long t;
    while (!StringToInt((char*)(s->begin), &t, MinBound, MaxBound)) {
        printf("Wrong integer \"%s\".\n Try again:\n", s->begin);
        if (feof(from)) {
            printf("Not enough data in file!\n");
            exit(42);
        }
        StringRead(s, ' ', from);
    }
    StringDelete(s);
    return t;
}