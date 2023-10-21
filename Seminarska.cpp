#include<iostream>
#include<string.h>
using namespace std;

class Film_Festival 
{
    char name[50];
    char location[50];
    int ticketPrice;
    static float seasonSale;
public:
    Film_Festival() {};

    Film_Festival(const char* name, const char* location, int ticketPrice)
    {
        strcpy_s(this->name, name);
        strcpy_s(this->location, location);
        this->ticketPrice = ticketPrice;
    }

    static void setSeasonSale(float New) 
    {
        seasonSale = New;
    }

    static float getSeasonSale() 
    {
        return seasonSale;
    }

    virtual int Price() 
    {
        return ticketPrice * (1 - seasonSale);
    }
    char* getName() 
    {
        return name;
    }
    char* getLocation()
    {
        return location;
    }
};
float Film_Festival::seasonSale = 0.2;

class ThreeDFilm :public Film_Festival 
{
    char Producer[100];
    float hours;
    bool day;
public:
    ThreeDFilm(){};

    ThreeDFilm (const char* name , const char* location , int ticketPrice , const char* Producer , float hours = 0, bool day = false) :Film_Festival(name, location, ticketPrice) 
    {
        strcpy_s(this->Producer, Producer);
        this->hours = hours;
        this->day = day;
    }

    int Price() 
    {
        float sPrice = Film_Festival::Price();
        if (hours > 3)
        {
           sPrice += 360;
        }
        else if (hours > 2)
        {
            sPrice += 150;
        }
        if (day)
            sPrice -= 50;
        else
           sPrice += 100;
        return sPrice;
    }
    char* getProducer()
    {
        return Producer;
    }
    int getHours()
    {
        return hours;
    }
    void getDayOrNight()
    {
        if (day == true)
            cout << "It's screening on the day light" << endl;
        else
            cout << "It's screening in the evning" << endl;
    }
};

template <class T> void MostExpenciveFilm(T* movies[], int n)
{
    int max = movies[0]->Price();
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (movies[i]->Price() > max)
        {
            max = movies[i]->Price();
            maxIndex = i;
        }
    }
    
    cout << movies[maxIndex]->getName() << " " << movies[maxIndex]->Price() << endl;
}
 
int main()
{

    Film_Festival* FILM[5];

    FILM[0] = new Film_Festival("What happened to Monday", "Arena Boris Trajkovski", 300);
    FILM[1] = new Film_Festival("Invisible man", "Arena Boris Trajkovski", 350);
    FILM[2] = new Film_Festival("Like a boss", "Arena Boris Trajkovski", 250);
    FILM[3] = new Film_Festival("Fantasy island", "Arena Boris Trajkovski", 300);
    FILM[4] = new Film_Festival("Cruella", "Arena Boris Trajkovski", 400);

    ThreeDFilm* threeDFilmArray[4];

    threeDFilmArray[0] = new ThreeDFilm("Frozen 2", "Arena Boris Trajkovski", 250, "Peter Del Vecho", 1.43, true);
    threeDFilmArray[1] = new ThreeDFilm("Jumanji, the next level", "Arena Boris Trajkovski", 350, "Dwayne Johnson, Dany Garcia, Hiram Garcia, Matt Tolmach, Jake Kasdan", 2.03, false);
    threeDFilmArray[2] = new ThreeDFilm("Dolittle", "Arena Boris Trajkovski", 300, "Joe Roth, Jeff Kirschenbaum, Susan Downey", 1.01, true);
    threeDFilmArray[3] = new ThreeDFilm("Godzilla vs Kong", "Arena Boris Trajkovski", 400, "Thomas Tull, Jon Jashni, Brian Rogers, Mary Parent, Alex Garcia, Eric McLeod", 1.53, false);
   
    int x = 0;
    
        cout << "------------------------------------------------Film Menu------------------------------------------------" << endl;
        cout << "Press 1 for list of 2D films" << endl;
        cout << "Press 2 for list of 3D films" << endl;
        cout << "Press 3 for setting season sale and get Price with new season sale" << endl;
        cout << "Press 4 for Most expencive 2D and 3D film" << endl;
        cout << "Press 5 for exit from the program" << endl;
        cin >> x;
        while (x != 5)
        {
            if (x == 1)
            {
                cout << "------------------------------------------------Film------------------------------------------------" << endl;

                int filmArraySize = sizeof FILM / sizeof FILM[0];
                for (int i = 0; i < filmArraySize; i++)
                {
                    cout << endl;
                    Film_Festival filmFestival = *FILM[i];
                    cout << i + 1 << "." << filmFestival.getName() << endl;
                    cout << "Location: " << filmFestival.getLocation() << endl;
                    cout << "Price: " << filmFestival.Price() << endl;
                    cout << endl;
                }
            }
            else if (x == 2)
            {
                cout << "------------------------------------------------3D Film------------------------------------------------" << endl;

                int threeDFilmArraySize = sizeof threeDFilmArray / sizeof threeDFilmArray[0];
                for (int i = 0; i < threeDFilmArraySize; i++)
                {
                    cout << endl;
                    ThreeDFilm threeDFilm = *threeDFilmArray[i];
                    cout << i + 1 << "." << threeDFilm.getName() << endl;
                    cout << "Location:" << threeDFilm.getLocation() << endl;
                    cout << "Price: " << threeDFilm.Price() << endl;
                    cout << "Producer: " << threeDFilm.getProducer() << endl;
                    cout << "Hours: " << threeDFilm.getHours() << endl;
                    threeDFilm.getDayOrNight();
                    cout << endl;
                }
            }
            else if (x == 3)
            {
                float newSale;
                cout << "Enter the new sale in format: For 30% you enter 0.3" << endl;
                cin >> newSale;

                int filmArraySize = sizeof FILM / sizeof FILM[0];
                int threeDFilmArraySize = sizeof threeDFilmArray / sizeof threeDFilmArray[0];
                for (int i = 0; i < filmArraySize; i++)
                {
                    cout << endl;
                    Film_Festival filmFestival = *FILM[i];
                    filmFestival.setSeasonSale(newSale);
                    cout << i + 1 << "." << filmFestival.getName() << endl;
                    cout << "Location: " << filmFestival.getLocation() << endl;
                    cout << "Price: " << filmFestival.Price() << endl;
                    cout << endl;
                }

                for (int i = 0; i < threeDFilmArraySize; i++)
                {
                    cout << endl;
                    ThreeDFilm threeDFilm = *threeDFilmArray[i];
                    threeDFilm.setSeasonSale(newSale);
                    cout << i + 1 << "." << threeDFilm.getName() << endl;
                    cout << "Location:" << threeDFilm.getLocation() << endl;
                    cout << "Price: " << threeDFilm.Price() << endl;
                    cout << "Producer: " << threeDFilm.getProducer() << endl;
                    cout << "Hours: " << threeDFilm.getHours() << endl;
                    threeDFilm.getDayOrNight();
                    cout << endl;
                }
            }
            else if (x == 4)
            {
                cout << "The most expensive 2D film is: ";
                MostExpenciveFilm(FILM, 5);
                cout << endl;
                cout << "The most expencive 3D film is: ";
                MostExpenciveFilm(threeDFilmArray, 4);
            }
            else if (x == 5)
            {
                delete[] FILM;
                delete[]threeDFilmArray;
                return 0;
            }
            
            cout << "------------------------------------------------Film Menu------------------------------------------------" << endl;
            cout << "Press 1 for list of 2D films" << endl;
            cout << "Press 2 for list of 3D films" << endl;
            cout << "Press 3 for setting season sale and get Price with new season sale" << endl;
            cout << "Press 4 for Most expencive 2D and 3D film" << endl;
            cout << "Press 5 for exit from the program" << endl;
            cin >> x;
            system("CLS");
        }
}

