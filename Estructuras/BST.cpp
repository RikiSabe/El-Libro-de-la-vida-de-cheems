struct Nodo{
    int dato;
    Nodo *izq, *der;
};

Nodo* nuevoNodo(int dato){
    Nodo* nuevo = new Nodo();
    nuevo -> dato = dato;
    nuevo -> izq = NULL;
    nuevo -> der = NULL;
    return nuevo;
}

Nodo* insert(Nodo* nodo, int dato){
    if( nodo == NULL ){
        return nuevoNodo(dato);
    }
    if( dato < (nodo -> dato) ){
        nodo -> izq = insert(nodo -> izq, dato);
    }else{
        nodo -> der = insert(nodo -> der, dato);
    }
    return nodo;
}

void preOrden(struct Nodo* nodo){
    if( nodo == NULL ) return;
    cout << " " << nodo -> dato;
    preOrden(nodo -> izq);
    preOrden(nodo -> der);
}

void inOrden(struct Nodo* nodo){
    if( nodo == NULL ) return;
    inOrden(nodo -> izq);
    cout << " " << nodo -> dato;
    inOrden(nodo -> der);
}

void posOrden(struct Nodo* nodo){
    if( nodo == NULL ) return;
    posOrden(nodo -> izq);
    posOrden(nodo -> der);
    cout << " " << nodo -> dato;
}

void solve(int testCase) {
    Nodo* nodo = NULL;
    int n; cin >> n;
    FOR(i,0,n){
        int x; cin >> x;
        nodo = insert(nodo, x);
    }
    cout << "Pre.:"; preOrden(nodo); cout << '\n';
    cout << "In..:"; inOrden(nodo); cout << '\n';
    cout << "Post:"; posOrden(nodo); cout << '\n';
}
