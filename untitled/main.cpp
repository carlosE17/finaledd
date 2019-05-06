#include <QCoreApplication>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arbol;
 void dibujararreglo(){
     std::ofstream file;
          file.open("/home/carlos/final/lista.dot");
          file << "digraph r{\n";
          file << "node [shape=record];\n";
          for (int i=0; i<arbol.size(); ++i){
               file<< arbol[i];
               if((i+1)<arbol.size()){
                   file <<"->";

               }else{
                   file <<";";
               }
    }
          file << "}";

                   file.close();
                   std::system("dot -Tpng /home/carlos/final/lista.dot -o /home/carlos/final/lista.png");

 }
 void dibujararbol(){
     std::ofstream file;
          file.open("/home/carlos/final/arbol.dot");
          file << "digraph r{\n";
          file << "node [shape=record];\n";

     int raiz=arbol[arbol.size()-1];
     vector<int> subarbolizq;
     vector<int> subarbolder;
     vector<int> tmp=arbol;
     sort(tmp.begin(),tmp.end());

     cout << '\n';
                 for (auto it = tmp.begin(); it != tmp.end(); ++it){
                       cout << ' ' << *it;}

                 for(int i=0;i<tmp.size();i++){
                     if(tmp[i]<raiz){
                         subarbolizq.push_back(tmp[i]);
                     }else{
                         if(tmp[i]!=raiz){
                             subarbolder.push_back(tmp[i]);
                         }
                     }
                 }

for(int i=0;i<tmp.size();i++){
file<<"node";
file<<tmp[i];
file<<"[ label =\"<f0> | <f1>";
file<<tmp[i];
file<<"| <f2> \"];\n";
}
file<<"\"node";
file<<raiz;
file<<"\":f0->\"node";
file<<subarbolizq[subarbolizq.size()-1];
file<<"\":f1;\n";
file<<"\"node";
file<<raiz;
file<<"\":f2->\"node";
file<<subarbolder[0];
file<<"\":f1;\n";








                 file << "}";

                          file.close();
                          std::system("dot -Tpng /home/carlos/final/arbol.dot -o /home/carlos/final/arbol.png");
 }
 int buscar(int d){
     for(auto it = arbol.begin(); it != arbol.end(); ++it){
         int x=*it;
         if(d==arbol[x]){return x;}
     }
     return -1;
 }
 void insertar(int d){
     if(buscar(d)==-1){arbol.push_back(d);}

 }
 void eliminar(int d){
     int x=buscar(d);
     if(x!=-1){
    arbol.erase(arbol.begin()+x);
     }
 }
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    insertar(5);
    insertar(10);
    insertar(96);
    insertar(30);
    insertar(2);
    insertar(63);
    insertar(85);
    insertar(47);
    insertar(20);
    insertar(3);
    insertar(4);
    insertar(19);
      for (auto it = arbol.begin(); it != arbol.end(); ++it){
            cout << ' ' << *it;
}
            eliminar(3);
cout << '\n';
            for (auto it = arbol.begin(); it != arbol.end(); ++it){
                  cout << ' ' << *it;}
            cout << '\n';
            dibujararreglo();
            dibujararbol();
    return 0;
}

