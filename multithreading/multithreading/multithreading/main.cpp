#include <iostream>
#include <thread>
#include <chrono>

using namespace std;



void DoVork()
{
    for(int i = 0; i<10;++i)
    {
    cout << "id potoks :" << cout << this_thread::get_id();
    this_thread::sleep_for(chrono::milliseconds(2000));
    }
}


int main()
{
    cout<<"start main"<<endl;
    
    this_thread::sleep_for(chrono::milliseconds(2000));
  
    cout<<this_thread::get_id();
    
    cout<<"end main";
    
    
    
    return 0;
}


