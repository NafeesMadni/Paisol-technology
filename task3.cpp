#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaItem
{
protected:
     string title;
     string genre;
     int year;

public:
     MediaItem(const string &title, const string &genre, int year)
         : title(title), genre(genre), year(year) {}

     virtual void displayInfo() const = 0;
     virtual string getTitle() const { return title; } // Define getTitle() function
     virtual string getGenre() const { return genre; } // Define getGenre() function
     virtual ~MediaItem() {}
};

class Book : public MediaItem
{
private:
     string author;

public:
     Book(const string &title, const string &author, const string &genre, int year)
         : MediaItem(title, genre, year), author(author) {}

     void displayInfo() const override
     {
          cout << "Book: " << title << " by " << author << ", Genre: " << genre << ", Year: " << year << endl;
     }
};

class Movie : public MediaItem
{
private:
     string director;
     vector<string> actors;

public:
     Movie(const string &title, const string &director, const vector<string> &actors, const string &genre, int year)
         : MediaItem(title, genre, year), director(director), actors(actors) {}

     void displayInfo() const override
     {
          cout << "Movie: " << title << "\ndirected by " << director << "\nGenre: " << genre << "\nYear: " << year << endl;
          cout << "Actors: ";
          for (const auto &actor : actors)
          {
               cout << actor << ", ";
          }
          cout << endl;
     }
};

class MusicAlbum : public MediaItem
{
private:
     string artist;

public:
     MusicAlbum(const string &title, const string &artist, const string &genre, int year)
         : MediaItem(title, genre, year), artist(artist) {}

     void displayInfo() const override
     {
          cout << "Music Album: " << title << " by " << artist << "\nGenre: " << genre << "\nYear: " << year << endl;
     }
};

class LibraryManager
{
private:
     vector<MediaItem *> library;

public:
     void addItem(MediaItem *item)
     {
          library.push_back(item);
     }

     void removeItem(const string &title)
     {
          for (auto it = library.begin(); it != library.end(); ++it)
          {
               if ((*it)->getTitle() == title)
               {
                    delete *it;
                    library.erase(it);
                    break;
               }
          }
     }

     void searchItem(const string &keyword) const
     {
          cout << "Search Results:" << endl;
          for (const auto &item : library)
          {
               if (item->getTitle().find(keyword) != string::npos || item->getGenre().find(keyword) != string::npos)
               {
                    item->displayInfo();
               }
          }
     }

     ~LibraryManager()
     {
          for (auto item : library)
          {
               delete item;
          }
     }
};

int main()
{
     LibraryManager library;

     Book book1("The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 1925);
     Movie movie1("Inception", "Christopher Nolan", {"Leonardo DiCaprio", "Ellen Page"}, "Thriller", 2010);
     MusicAlbum album1("Thriller", "Michael Jackson", "Pop", 1982);

     library.addItem(&book1);
     library.addItem(&movie1);
     library.addItem(&album1);

     library.searchItem("Thriller");

     library.removeItem("Inception");

     return 0;
}
