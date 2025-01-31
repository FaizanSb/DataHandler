#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
template<class T>
class dyenamicArray{
	vector<T> vec1;
	public:
//		dyenamicArray(T v,int s){
//			vec1.push_back(v);
//		}
		void Insert(T a){
			vec1.push_back(a);
		}
		void Delete(T n){
			typename vector<T>::iterator it;
			it=find(vec1.begin(),vec1.end(),n);
			if(it!=vec1.end()){
				vec1.erase(it);
			}
			else
			cout<<"Name Not Exist in vector: "<<endl;
		}
		void Search(T x){
			typename vector<T>::iterator it;
			it=find(vec1.begin(),vec1.end(),x);
			if(it!=vec1.end()){
				cout<<"Number is available: "<<x<<endl;
			}
			else
			cout<<"Number is not available: "<<endl;
			}
		void Display(){
	
			for(int i=0;i<vec1.size();i++){
				cout<<vec1[i]<<endl;
			}
			}
};
int main(){
	//int array[]={3,4,5,6,7};
	dyenamicArray<string> v1;
	v1.Insert("Muneeb");
	v1.Insert("Hamid");
	v1.Insert("Anas");
	v1.Insert("Mujeeb");
	v1.Insert("Faizan");
	v1.Display();
	v1.Delete("Faizan");
	cout<<"After Delete: "<<endl;
	v1.Display();
	v1.Search("Muneeb");
	v1.Insert("Momina");
	v1.Display();
	v1.Delete("Kalowal");
	
}