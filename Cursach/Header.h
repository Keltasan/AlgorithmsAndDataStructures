#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define rib pair<int,int>  //�������� ��� ������ ������ rib ����� ������������� pair<int,int>
class Graph {
private:
    vector<pair<int, rib>>  graph;  //����
    vector<pair<int, rib>>  minOstTree;  //�����������  ��������  ������

    int* parent; //��� ������� �������� �� ������ ������ �� ��� ������ � ������
    /*��� ������ �������� �� ������ � ��� ���� (�.�. ������ ������������� � ���� �����).*/
    int topsNumber = 0; //����������  ������  �����
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
    
    void addWeightRib(int f, int s, int w) { //�����������  �  ����  ������,  ���  �����
        graph.push_back(make_pair(w, rib(f, s)));
    }
    
    void makeSet(int i){ //��������� ����� ������� i, ������� ��� � ����� ���������, ��������� �� ������ ����
    //����� ������� ����� ������� (make_set(int i),
    //������ ������ � ������ � ������� i, �������, ��� � ������ � ��� ��� ����.
        parent[i] = i;
    }

    int find_set(int i) //����������, � ����� ��������� ��������� ��������� �������
    /*���� ����� find\_set() ��� �����-�� ���� ��������� ������ ���� � �� �� ��������,
    �� ��� ��������, ��� ��� �������� ��������� � ����� � ��� �� ���������, � � ��������� ������ � � ������ ����������.*/
    { //����������� �� ������� �� ������� i, ���� �� ����� �� �����, �.�. ���� ������ �� ������ �� ���� � ����
        if (i == parent[i])
            return i;
        return find_set(parent[i]);
    }

    void union_set(int f, int  s) //���������� ��� ��������� ���������
    //(���������, � ������� ��������� ������� f, � ���������, � ������� ��������� ������� s)
    {
        /*����� ���������� ��� ��������� union_sets(f,s),  ������� ����� ������� ���������, � ������� ��������� f,
        � ���������, � ������� ��������� s. ���� ������ �������, �� ������ �� ������ �
        ��� ������, ��� ��������� � ��� ��� ���� ����������.
        � ��������� ������ ����� ������ �������, ��� ������ ������� s ����� f (��� ��������) �
        ��� ����� ����������� ���� ������ � �������.*/
        
        f = find_set(f);
        s = find_set(s);
        if (f != s) {
            parent[s] = f;
        }
    }

    void kraskal() {//�������� ��������
        int i, First, Second;
        sort(graph.begin(), graph.end()); //�� ������ �� ����� �����

        for (i = 0; i < graph.size(); i++) {
            First = find_set(graph[i].second.first); //��  �����  ��������  ����  ������,  �  ��  ���  ������
            Second = find_set(graph[i].second.second); //����� ������

            if (First != Second) { //���� ������� �� �����
                minOstTree.push_back(graph[i]);//   ���������  �����  �  ������,  ����  ��  ��������  �����
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