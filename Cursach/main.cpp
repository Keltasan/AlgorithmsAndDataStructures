#include<iostream>
#include"Header.h"

int main() {
    size_t size;

    cout << "Number of ribs:  ";
    
    cin >> size;
    
    char a, b;
    int c;
    
    Graph g(size);
    
    cout << "Tops and rib weight:" << endl;
    
    for (size_t i = 0; i < size; ++i) {
        cin >> a >> b >> c;
        g.addWeightRib(a - 'A', b - 'A', c);
    }

    g.kraskal();
    g.print();
    return 0;
}