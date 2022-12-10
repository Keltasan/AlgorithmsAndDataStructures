#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define rib pair<int,int>  //означает что дальше вместо rib будет подставляться pair<int,int>
class Graph {
private:
    vector<pair<int, rib>>  graph;  //Граф
    vector<pair<int, rib>>  minOstTree;  //Минимальное  остовное  дерево

    int* parent; //для каждого элемента мы храним ссылку на его предка в дерева
    /*Для корней деревьев их предок — они сами (т.е. ссылка зацикливается в этом месте).*/
    int topsNumber = 0; //Количество  вершин  графа
public:
    Graph(int numberOfTops) {
        topsNumber = numberOfTops;
        parent = new int[topsNumber];

        for (int i = 0; i < topsNumber; i++)
        {
            parent[i] = i;
        }

        graph.clear();
        minOstTree.clear();
    }
    
    void addWeightRib(int f, int s, int w) { //Привязываем  к  паре  вершин,  вес  ребра
        graph.push_back(make_pair(w, rib(f, s)));
    }
    
    void makeSet(int i){ //добавляет новый элемент i, помещая его в новое множество, состоящее из одного него
    //Чтобы создать новый элемент (make_set(int i),
    //создаём дерево с корнем в вершине i, отмечая, что её предок — это она сама.
        parent[i] = i;
    }

    int find_set(int i) //возвращает, в каком множестве находится указанный элемент
    /*если вызов find\_set() для каких-то двух элементов вернул одно и то же значение,
    то это означает, что эти элементы находятся в одном и том же множестве, а в противном случае — в разных множествах.*/
    { //поднимаемся по предкам от вершины i, пока не дойдём до корня, т.е. пока ссылка на предка не ведёт в себя
        if (i == parent[i])
            return i;
        return find_set(parent[i]);
    }

    void union_set(int f, int  s) //объединяет два указанных множества
    //(множество, в котором находится элемент f, и множество, в котором находится элемент s)
    {
        /*Чтобы объединить два множества union_sets(f,s),  сначала найдём лидеров множества, в котором находится f,
        и множества, в котором находится s. Если лидеры совпали, то ничего не делаем —
        это значит, что множества и так уже были объединены.
        В противном случае можно просто указать, что предок вершины s равен f (или наоборот) —
        тем самым присоединив одно дерево к другому.*/
        
        f = find_set(f);
        s = find_set(s);
        if (f != s) {
            parent[s] = f;
        }
    }

    void kraskal() {//алгоритм Краскала
        int i, First, Second;
        sort(graph.begin(), graph.end()); //от начала до конца графа

        for (i = 0; i < graph.size(); i++) {
            First = find_set(graph[i].second.first); //Из  графа  получаем  пару  вершин,  а  из  них  первую
            Second = find_set(graph[i].second.second); //далее вторую

            if (First != Second) { //если вершины не равны
                minOstTree.push_back(graph[i]);//   Добавляем  ребро  в  дерево,  если  не  образует  цикла
                union_set(First, Second);
            }
        }
    }
    
    void print() {
        int  k = 0;

        cout << "Rib - " << "Weight" << endl;

        for (int i = 0; i < minOstTree.size(); i++) {
            cout << char(minOstTree[i].second.first + 'A') << " - " << char(minOstTree[i].second.second + 'A') << "   :  "
                << minOstTree[i].first;
            k += minOstTree[i].first;
            cout << endl;
        }

        cout << "Sum weight  =  " << k << endl;
    }
};