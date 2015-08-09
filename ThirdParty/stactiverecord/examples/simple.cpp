#include "stactiverecord/stactive_record.h"
#include <iostream>
using namespace stactiverecord;
using namespace std;

/**
   This is a simple example for saving/finding a simple object.
**/


Sar_Dbi* Sar_Dbi::dbi;

class Person : public Record<Person>
{
public:
    SAR_INIT();
    int age;
    tstring fullname;
    Person() : Record<Person>()
    {
        age = 0;
        fullname = SAR_TEXT("Unknown");
    };
    Person( int id ) : Record<Person>( id )
    {
        get( SAR_TEXT("age"), age, 0 );
        get( SAR_TEXT("fullname"), fullname, SAR_TEXT("Unknown") );
    };
    void save()
    {
        set( SAR_TEXT("age"), age );
        set( SAR_TEXT("fullname"), fullname );
        Record<Person>::save();
    };
    void sayage()
    {
        std::cout << "I'm " << SAR_T2S(fullname) << " and I'm " << age << " years old.\n";
    };
};
SAR_SET_CLASSNAME( Person, SAR_TEXT("Person") );

int main( int argc, char* argv[] )
{
	//为了更好的输出中文，需要设置locale为中文
	std::locale m_origin_locale = std::locale::global(std::locale("chs"));

	std::cout<<"你好xxxx\n";
	std::cout<<SAR_T2S(SAR_TEXT("aaa你好"));

    if( argc != 2 )
    {
        std::cout << "Usage: ./simple <scheme://[user[:password]@host[:port]/]database>\n";
        return 1;
    }
    Sar_Dbi::dbi = Sar_Dbi::makeStorage( SAR_S2T(std::string( argv[1] )) );

    Person bob;
    bob.fullname = SAR_TEXT("Robert Somethingorother");
    bob.age = 50;
    bob.save();

    ObjGroup<Person> people = Person::find( Q( SAR_TEXT("age"), between( 40, 100 ) ) && Q( SAR_TEXT("fullname"), startswith( SAR_TEXT("Robert") ) ) );
    people[0].sayage();
    cout << "Name is: " << SAR_T2S(people[0].fullname) << "\n";
    delete Sar_Dbi::dbi; // only cleanup necessary

	//恢复原来的locale设置
	std::locale::global(m_origin_locale);

    return 0;
};
