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
if(!subarbolizq.empty()){
    file<<"\"node";
    file<<raiz;
    file<<"\":f0->\"node";
    file<<subarbolizq[subarbolizq.size()-2];
    file<<"\":f1;\n";

int anterior=subarbolizq[subarbolizq.size()-2];
int mayor=subarbolizq[subarbolizq.size()-2];
for(int i=arbol.size()-1;i>-1;i--){

    for(int j=0;j<subarbolizq.size();j++){
        if(arbol[i]==subarbolizq[j]){
            if(subarbolizq[j]<anterior){
                file<<"\"node";
                file<<anterior;
                file<<"\":f0->\"node";
                file<<subarbolizq[j];
                file<<"\":f1;\n";
                anterior=subarbolizq[j];
                 cout<<anterior;
            }else {
                if(mayor==raiz &&subarbolizq[j]!=subarbolizq[subarbolizq.size()-2]){
                file<<"\"node";
                file<<anterior;
                file<<"\":f2->\"node";
                file<<subarbolizq[j];
                file<<"\":f1;\n";
                mayor=subarbolizq[j];



            }else if(subarbolizq[j]<mayor){


                        if(subarbolizq[j]<anterior){
                            file<<"\"node";
                            file<<anterior;
                            file<<"\":f0->\"node";
                            file<<subarbolizq[j];
                            file<<"\":f1;\n";

                            anterior=subarbolizq[j];
                              cout<<"linea98";

                        }else{
                            if(subarbolizq[j]!=subarbolizq[subarbolizq.size()-2]){
                            file<<"\"node";
                            file<<subarbolizq[j+1];;
                            file<<"\":f0->\"node";
                            file<<subarbolizq[j];
                            file<<"\":f1;\n";

                            anterior=subarbolizq[j];
                            }
                        }

                }
            else{
                    if(subarbolizq[j]!=subarbolizq[subarbolizq.size()-2]){
                file<<"\"node";
                file<<mayor;
                file<<"\":f2->\"node";
                file<<subarbolizq[j];
                file<<"\":f1;\n";
               anterior=mayor;
                mayor=subarbolizq[j];
                cout<<mayor;
                    }
            }
            }
        }
    }

}
}
if(!subarbolder.empty()){
file<<"\"node";
file<<raiz;
file<<"\":f2->\"node";
file<<subarbolder[0];
file<<"\":f1;\n";
int anterior=subarbolder[0];

for(int i=arbol.size()-1;i>-1;i--){
for(int j=1;j<subarbolder.size();j++){

    if(arbol[i]==subarbolder[j]){
        if(subarbolder[j]>anterior){
        file<<"\"node";
        file<<anterior;
        file<<"\":f2->\"node";
        file<<subarbolder[j];
        file<<"\":f1;\n";
        anterior=subarbolder[j];
        }else{
            for(int z=0;z<subarbolder.size();z++){
                if(subarbolder[j]<subarbolder[z]){
                file<<"\"node";
                file<<subarbolder[z];
                file<<"\":f0->\"node";
                file<<subarbolder[j];
                file<<"\":f1;\n";
z=subarbolder.size()+5;
                }
            }
        }
    }

}

}
}






                 file << "}";

                          file.close();
                          std::system("dot -Tpng /home/carlos/final/arbol.dot -o /home/carlos/final/arbol.png");
 }
 int buscar(int d){
     for(int i=0; i<arbol.size();i++){

         if(d==arbol[i]){

             return i;}
     }
     return -1;
 }
 int mascercano(int d){
     int v=1000;
     int r=-1;
     for(int i=arbol.size()-1; i>-1;i--){
         if((d-arbol[i])<=v &&(d-arbol[i])>0) {

             cout << '\n';

              cout<<v;
              cout<<"-";
              cout<<r;
              r=arbol[i];
              v=d-arbol[i];

              cout << '\n';

              cout<<v;
              cout<<"-";
              cout<<r;
         }else if((-1*(d-arbol[i]))<=v &&(d-arbol[i])<0){

             cout << '\n';

              cout<<v;
              cout<<"-";
              cout<<r;

              r=arbol[i];
              v=-1*(d-arbol[i]);
              cout << '\n';

               cout<<v;
               cout<<"-";
               cout<<r;
         }
     }
     cout << '\n';

 cout<<"106-";
 cout<<r;
 cout << '\n';

     return r;
 }
 void eliminar(int d){
     int x=buscar(d);
     if(x!=-1){
         int n=mascercano(arbol[x]);
         cout << '\n';

          cout<<n;
          cout << '\n';
          cout<<n;
         cout << '\n';
         int y=buscar(n);
         arbol.erase(arbol.begin()+x);
         arbol.erase(arbol.begin()+y);
         arbol.push_back(n);


     }
 }
 void insertar(int d){
     int a=mascercano(d);
     if(a!=-1){
         int b=buscar(a);
         arbol.erase(arbol.begin()+b);
        arbol.push_back(a);
     }

     if(buscar(d)==-1){

         arbol.push_back(d);}else{

         eliminar(d);
         arbol.push_back(d);
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

      for (int i=0; i<arbol.size();i++){
            cout << ' ' << arbol[i];
}

cout << '\n';
for (int i=0; i<arbol.size();i++){
      cout << ' ' << arbol[i];
}
            cout << '\n';


            dibujararreglo();
            dibujararbol();
             cout << '\n';
    return 0;
}

