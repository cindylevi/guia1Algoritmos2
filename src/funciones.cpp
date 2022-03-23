#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> set_s;
    for (int i = 0; i < s.size(); ++i) {
        set_s.insert(s[i]);
    }
    vector<int> res;
    for(int n:set_s){
        res.push_back(n);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_s;
    for (int i = 0; i < s.size(); ++i) {
        set_s.insert(s[i]);
    }
    vector<int> res;
    for(int n:set_s){
        res.push_back(n);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> set_a;
    for (int i = 0; i < a.size(); ++i) {
        set_a.insert(a[i]);
    }
    set<int> set_b;
    for (int i = 0; i < b.size(); ++i) {
        set_b.insert(b[i]);
    }
    return set_a == set_b;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_a;
    for (int i = 0; i < a.size(); ++i) {
        set_a.insert(a[i]);
    }
    set<int> set_b;
    for (int i = 0; i < b.size(); ++i) {
        set_b.insert(b[i]);
    }
    return set_a == set_b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]] ++;
    }
    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int, int> apariciones = contar_apariciones(s);
    for (pair<int, int> par: apariciones) {
        if(par.second == 1){
            res.push_back(par.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> inter;
    for(int n:a){
        if(b.count(n) == 1){
            inter.insert(n);
        }
    }
    return inter;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i] % 10].insert(s[i]);
    }
    return m;
}
set<LU> interseccionDeAlumnos(set<LU> a, set<LU> b) {
    set<LU> inter;
    for(LU n:a){
        if(b.count(n) == 1){
            inter.insert(n);
        }
    }
    return inter;
}
// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> dicc;
    for(pair<char, char> palabra:tr){
        dicc[palabra.first] = palabra.second;
    }
    vector<char> res;
    for (int i = 0; i < str.size(); ++i) {
        if(dicc.count(str[i]) == 1 ){
            res.push_back(dicc[str[i]]);
        }else{
            res.push_back(str[i]);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool hayRepetidos = false;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            set<LU> inter = interseccionDeAlumnos(s[i].libretas(), s[j].libretas());
            if( inter != set<LU>{} && s[i].libretas() != s[j].libretas()){
                hayRepetidos = true;
                break;
            }
        }
    }
    return hayRepetidos;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> entregas;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i].adjunto()){
            entregas[s[i].libretas()] = s[i];
        }
    }
  return entregas;
}
