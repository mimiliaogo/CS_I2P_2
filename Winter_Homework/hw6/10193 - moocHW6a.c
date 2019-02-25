#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* incomplete struct Atom */
struct Atom;

/* a pair of atom */
typedef struct Pair {
    struct Atom *left;
    struct Atom *right;
} Pair;

/* a list of atoms */
typedef struct List {
    struct Atom *data;
    struct List *next;
} List;

/* an atom can be a string, an int, a pair of atoms, or a list */
typedef struct Atom {
    char str[21];
    int val;
    Pair *pair;
    List *lst;
    int dtype; /* 0 for string, 1 for int, 2 for pair, 3 for list*/
} Atom;



/* functions for creating an atom */
Atom* atom_str(char *str);
Atom* atom_val(int val);

Atom* copy_atom(Atom *aptr);
void print_atom(Atom *aptr);
void free_atom(Atom *atpr);

/* convert an atom to a single-atom list */
List* atom_to_list(Atom *a);

/* this function is important */
/* useful for creating a new copy of an existing list */
List* cons(Atom *a, List *b);

void print_list(List *lptr);
void free_list(List *lptr);
int length(List *lptr);
List* read_list_helper(List *l, int n);
List* read_list(void);

Atom* head(List *lptr);
List* tail(List *lptr);

List* zip(List *lptr1, List *lptr2);
Pair* unzip(List *lptr);

List* take(int n, List *l);
List* drop(int n, List *l);

Pair* pair_list(List *lptr1, List *lptr2);
Pair* split_at(int n, List *l);

void print_pair(Pair* p);
void free_pair(Pair* p);

int main(void)
{
    List *s1, *s2, *s3;
    int N, i;

    s1 = read_list();
    s2 = read_list();
    s3 = NULL;

    scanf("%d", &N);
    for (i=0; i<N; i++) {
        s3 = zip(s1, s2);
        free_list(s1);
        s1 = s2;
        s2 = s3;
    }

    print_list(s3);
    printf("\n");


    return 0;
}

List* read_list_helper(List *l, int n)
{
    Atom *a;
    int x;
    char str[21];
    List *l1, *l2;

    if (n==0) {
        return l;
    } else {
        if (scanf("%d", &x)==1) {
            a = atom_val(x);
        } else {
            scanf("%20s", str);
            while(!isspace(getchar()));
            a = atom_str(str);
        }
        l1 = read_list_helper(l, n-1);
        l2 = cons(a, l1);
        free_atom(a);
        free_list(l1);
        return l2;
    }
}

List* read_list(void)
{
    int ndata;

    scanf("%d", &ndata);

    return read_list_helper(NULL, ndata);
}
/* Given a string, create a new atom */
Atom* atom_str(char *str)
{
    Atom *aptr = (Atom*) malloc(sizeof(Atom));
    if (str==NULL) {
        aptr->str[0] = '\0';
    } else {
        strncpy(aptr->str, str, 20);
    }
    aptr->val = 0;
    aptr->pair = NULL;
    aptr->lst = NULL;
    aptr->dtype = 0;
    return aptr;
}

/* Given a value, create a new atom */
Atom* atom_val(int val)
{
    Atom *aptr = (Atom*) malloc(sizeof(Atom));
    aptr->str[0] = '\0';
    aptr->val = val;
    aptr->pair = NULL;
    aptr->lst = NULL;
    aptr->dtype = 1;
    return aptr;
}


Atom* copy_atom(Atom *aptr)
{
    Atom *aptr_new;

    aptr_new = (Atom*) malloc(sizeof(Atom));

    if (aptr_new==NULL) return NULL;
    if (aptr==NULL) return NULL;

    aptr_new->dtype = aptr->dtype;

    if (aptr->dtype == 0) {
        strncpy(aptr_new->str, aptr->str, 20);
    } else if (aptr->dtype == 1) {
        aptr_new->val = aptr->val;
    } else if (aptr->dtype == 2) {
        if (aptr->pair == NULL) {
            aptr_new->pair = NULL;
        } else {
            aptr_new->pair = (Pair *) malloc(sizeof(Pair));
            aptr_new->pair->left = copy_atom(aptr->pair->left);
            aptr_new->pair->right = copy_atom(aptr->pair->right);
        }
    } else if (aptr->dtype == 3) {
        if (aptr->lst==NULL) {
            aptr_new->lst = NULL;
        } else {
            aptr_new->lst = cons(head(aptr->lst), tail(aptr->lst));
        }
    }
    return aptr_new;
}

void print_atom(Atom *aptr)
{
    if (aptr==NULL) {
        printf("Empty");
        return;
    }
    switch (aptr->dtype) {
    case 0:
        printf("\"%s\"", aptr->str);
        break;
    case 1:
        printf("%d", aptr->val);
        break;
    case 2:
        print_pair(aptr->pair);
        break;
    case 3:
        print_list(aptr->lst);
        break;
    default:
        printf("Undefined.");
    }

}
/* Given an atom, create a list containing the atom. */
List* atom_to_list(Atom *a)
{
    List *b;
    b = (List*) malloc(sizeof(List));
    b->next = NULL;
    b->data = copy_atom(a);
    return b;
}

/* create a new list and add the atom to the head */
List* cons(Atom *a, List *b)
{
    List *c;

    c = atom_to_list(a);
    if (b!=NULL) {
        c->next = cons(head(b), tail(b));
    }

    return c;
}

void print_list(List *lptr)
{
    printf("[");
    while (lptr!=NULL) {
        print_atom(lptr->data);
        if (lptr->next != NULL)
            printf(",");
        lptr = lptr->next;
    }
    printf("]");
}

int len_helper(List *lptr, int len)
{
    if (lptr==NULL) return len;
    else return len_helper(lptr->next, len+1);
}
int length(List *lptr)
{
    return len_helper(lptr, 0);
}

void free_atom(Atom *aptr)
{
    if (aptr != NULL) {
        if (aptr->dtype==2) {
            free_pair(aptr->pair);
        } else if (aptr->dtype==3) {
            free_list(aptr->lst);
        }
        free(aptr);
    }
}

void free_list(List *lptr)
{
    List *p;
    if (lptr!=NULL) {
        p = tail(lptr);
        if (head(lptr)!=NULL) {
            free_atom(head(lptr));
        }
        free_list(p);
    }
}

Atom* head(List *lptr)
{
    return lptr->data;
}

List* tail(List *lptr)
{
    return (lptr==NULL) ? NULL : lptr->next;
}

/* create a new list combining a string list and a value list
If the two input lists have different lengths, the new list will be
of the same length as the shorter one.
*/
List* zip(List *lptr1, List *lptr2)
{
    Atom a;
    List *l1, *l2;

    if ( lptr1==NULL || lptr2==NULL ) { // lptr1 或 lptr2 兩者有一個是 NULL
        return NULL;
    } else {
        a.pair = (Pair*) malloc(sizeof(Pair)); // malloc 取得一塊 Pair 空間
        a.pair->left = copy_atom(lptr1->data); // 利用  copy_atom  複製 lptr1 的開頭第一個 atom
        a.pair->right = copy_atom(lptr2->data); // 利用  copy_atom  複製 lptr2 的開頭第一個 atom
        a.dtype = 2;
        l1 = zip(lptr1->next, lptr2->next); // 利用 zip 處理剩下的 lists  (提示: 用遞迴)
        l2 = cons(&a, l1); // 利用 cons 造出新的 list
        free_pair(a.pair);
        free_list(l1);
        return l2;
    }
}

void print_pair(Pair *p)
{
    printf("(");
    print_atom(p->left);
    printf(",");
    print_atom(p->right);
    printf(")");
}

void free_pair(Pair* p)
{
    if (p!=NULL) {
        free_atom(p->left);
        free_atom(p->right);
        free(p);
    }
}
