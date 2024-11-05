
#include <iostream>
using namespace std;

class Package {
   private:
      int value;
   public:
      Package() {
         value = 7;
         cout << value << endl;
      }
      Package(int v) {
         value = v;
         cout << value << endl;
      }
      ~Package() {
      cout << "goodbye" << endl;
      }
};

int main() {
   Package obj1(4);
   Package obj2;
   return 0;
}
