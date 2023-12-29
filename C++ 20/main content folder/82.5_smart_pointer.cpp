#include <iostream>
#include <string>
#include <memory>           //to use smart pointer
using namespace std;

//smart pointer:
//ways to automate the process of 'new' & 'delete'
//allow you to not to call delete after calling new
//a wrapper around a real raw pointer

class Entity{
    public:
        Entity(){
            cout << "Created Entity!" << endl;
        }
        ~Entity(){
            cout << "desroyed Entity!" << endl;
        }
        void test(){
            cout << "test!" << endl;
        }
};

int main(){

    cout << "unique pointer:" << endl;
    //1.unique pointer ('unique_ptr' keyword)
    //  when pointer go out of scope it will get destory
    //  unique pointer can't be copied because only one pointer point to one address at a single time
    {   
        //Create a raw pointer
        Entity* entity_raw = new Entity;

        //create a smart pointer
        /*
        Ways to create:
        unique_ptr <class type> pointer_name {new 'class type'}
                                or
        unique_ptr <class type> pointer_name (new 'class type')
                                or
        unique_ptr <class type> pointer_name = make_unique <class type>()         -> this is the desire way

        No assign initialization:
        unique_ptr <class type> pointer_name = new 'class type'   -> error: because explicit
        */                                                        //'explicit' mean don't allow implicit conversion
        
        unique_ptr<Entity> entity_1{new Entity};
        unique_ptr<Entity> entity_2 = make_unique<Entity>();      //prevent exception when creating (prevent dangling pointer)
      //unique_ptr<Entity> entity_3 = new Entity;                 -> error: because explicit
        cout << endl;

        //smart pointer function like a raw pointer
        entity_raw->test();
        entity_1->test();
        entity_2->test();

        //cannot copy unique pointer
      //unique_ptr<Entity> entity_4 = entity_1;                   -> error: no copy constructor for unique pointer

        cout << endl;
    }// smart unique pointer will auto call delete when go out of scope,
     // raw pointer will not
    cout << endl;
    
    cout << "shared pointer:" << endl;
    //2.shared pointer ('shared_ptr' keyword)
    //  use refernece counting, keep track of how many references you have to the pointer
    //  when that count reach 0, it will get deleted

    //declare outside
    shared_ptr<Entity> sharedEntity_0;
    {
        //create a smart pointer
        /*
        shared_ptr <class type> pointer_name = make_shared <class type>()       -> use this, no other ways
        */
        shared_ptr<Entity> sharedEntity_1 = make_shared<Entity>();       //count 1  created

        //allow copy of shared pointer
        shared_ptr<Entity> sharedEntity_2 = sharedEntity_1;              //count 2  copied

        //assigning shared pointer into shared pointer
        sharedEntity_0 = sharedEntity_1;                                 //count 3  copied

        //assigning shared pointer into weak pointer
        weak_ptr<Entity> weakEntity = sharedEntity_1;                    //count 3  no increase for weak pointer

    }//sharedEntity_1 & sharedEntity_2 will die when go out of scope -> count-2
     //at this point sharedEntity_0 is still alive, therefore count is 1 and will no die until main() ended
    cout << endl;
    
    cout << "weak pointer:" << endl;
    //3.weak pointer('weak_ptr' keyword)
    //  don't increase the count, only to ask if the pointer are still valid

    //declare outside
    weak_ptr<Entity> weakEntity_0;
    {   
        //create a smart pointer
        shared_ptr<Entity> sharedEntity_1 = make_shared<Entity>();       //count 1  created

        //assigning shared pointer into weak pointer
        weakEntity_0 = sharedEntity_1;                                   //count 1  no increase for weak pointer
    }//sharedEntity_1 die here -> count-1                                //count 0 deleted
    cout << endl;

    cout << "shared pointer:" << endl;

    return 0;
}//sharedEntity_0 die here                                               //count 0 deleted