// Approach 1: Using an arryay of size m+n and storing the element of a in c like(a[0] = 6, c[6] = 1) "faster"
// Approach 2: Using set from stl 
// Approach 3: Sorting then searching "didnt do since it wasnt a fasrer approach"

// ---------------->> Approach 1 <<--------------------

int doUnion(int a[], int n, int b[], int m)  {
    int c[200000] = {0};
    int temp = 0;

    for(int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }

    for(int i = 0; i < m; i++) {
        c[b[i]] = c[b[i]] + 1;
    }

    for(int i = 0; i < 200000; i++) {
        if(c[i] != 0) {
            temp++;
        }
    }

    return temp;
}

// ---------------->> Approach 2 <<--------------------

// int doUnion(int a[], int n, int b[], int m)  {
//     set<int> s;
//     int temp = 0;

//     for(int i = 0; i < n; i++) {
//         s.insert(a[i]);
//     }

//     for(int i = 0; i < m; i++) {
//         s.insert(b[i]);
//     }

//     for(auto i = s.begin(); i != s.end(); i++) {
//         temp++;
//     }

//     return temp;
// }