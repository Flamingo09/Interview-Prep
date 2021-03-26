enum UserCategory {
    SuperAdmin(100);
    Admin(50);
    Critic(20);
    
    upgradeReq(User u) {
        string currType = getType(u);
    }
    
    string getType(User u) {
        
    }
}
abstarct class User {
    public:
        string name;
        unordered_map<string, <int, string>> movieRatings;
        int avgQaulity;
    
        User(string name) {
            this->name=name;
            this->type="User";
            this->movieRatings={};
        }
    
        void upgradeUser() {
            upgradeReq(this);
        }
        int giveRating(rating) {
            return rating;
        }
        User upgrade(User u) {
            if(u.ratingCnt > 5)
                return new Critic();
        }
};
class Critic extends User {
    public:
        int giveRating(int rating) {
            return rating*2;
        }
}
class Admin extends User,Critic {
    public:
        bool hasVetoPower();
        int giveRating(int rating);
}

class Movie {
    public:
        string movieName;
        int yearOfRelease;
        unordered_set<string> genre;
        int reviewScore;
        int criticScore;
    
        Movie(string movieName, int yearOfRelease, unordered_set<string> genre) {
            this->movieName=movieName;
            this->yearOfRelease=yearOfRelease;
            this->genre=genre;
            this->reviewScore=0;
            this->criticScore=0;
        }
};

class MovieReviews {
    string movieName;
    map<userName, review> reviews;
}
    
class Ratings {
    public:
        unordered_map<string, User*> userList;
        unordered_map<string, Movie*> movieList;
    
        static bool movieComp(const Movie* a, const Movie* b) {
            return a->reviewScore > b->reviewScore; 
        }
    
        static bool movieCompForCritic(const Movie* a, const Movie* b) {
            return a->criticScore > b->criticScore; 
        }
    
        Ratings() {
            this->userList={};
            this->movieList={};
        }
        
        void addUser(string name) {
            if(userList.find(name) != userList.end()) {
                cout<<"A user already exist with given name \n";
                return;
            }
            userList[name]=new User(name);
            return;
        }
    
        void addMovie(string movieName, int yearOfRelease, unordered_set<string> genre) {
            if(movieList.find(movieName) != movieList.end()) {
                cout<<"A movie already exists with the given name \n";
                return;
            }
            movieList[movieName]= new Movie(movieName, yearOfRelease, genre);
            return;
        }
    
        void addReview(string userName, string movieName, int rating) {
            if(!isReviewValid(userName,movieName,rating)) return;
            
            string type = userList[userName]->type;
            if(type == "Critic")   {         
                movieList[movieName]->reviewScore += (rating*2);
                movieList[movieName]->criticScore += (rating*2);
                userList[userName]->movieRatings[movieName]=(rating*2);
            }
            else {
                movieList[movieName]->reviewScore += rating;
                userList[userName]->movieRatings[movieName]=rating;
            }
            
            if(userList[userName]->movieRatings.size() > 3) userList[userName]->upgradeUser();
            
            return;
        }
    
        bool isReviewValid(string userName, string movieName, int rating) {
            if(userList.find(userName) == userList.end() || movieList.find(movieName) == movieList.end() || rating < 0 || rating > 10) {
                cout<<"Invalid Input, please check again \n";
                return false;
            }
            User* user = userList[userName];
            if(user->movieRatings.find(movieName) != user->movieRatings.end()) {
                cout<<"The user has already given rating for this movie";
                return false;
            }
            
            if(movieList[movieName]->yearOfRelease > 2020) {
                cout<<"The Moview hasn't been released yet, cannot review it \n";
                return false;
            }
            return true;
        }
    
    void getTopByReviewScore(int n, string genreName="") {
        int i=0;
        vector<Movie*> result;
        for(auto it= movieList.begin(); it!=movieList.end(); it++) {
            if(it->second->reviewScore != 0)
                if(genreName == "" || it->second->genre.find(genreName) != it->second->genre.end())
                    result.push_back(it->second);
        }
        
        sort(result.begin(), result.end(), movieComp);
        
        for(int i=0; i<min((int)result.size(), n); i++)
            cout<<result[i]->movieName<<endl;
    }
    
    void getTopByCriticScore(int n,string genreName="") {
        int i=0;
        vector<Movie*> result;
        for(auto it= movieList.begin(); it!=movieList.end(); it++) {
            if(it->second->reviewScore != 0)
                if(genreName == "" || it->second->genre.find(genreName) != it->second->genre.end())
                    result.push_back(it->second);
        }
        
        sort(result.begin(), result.end(), movieCompForCritic);
        
        for(int i=0; i<min((int)result.size(), n); i++)
            cout<<result[i]->movieName<<endl;
    }
    
    
};

int main() {
    std::cout << "Welcome to Rating App by Flipkart! \n";
    Ratings ratings=Ratings();
    ratings.addUser("Prem");
    ratings.addUser("Ashwini");
    
    ratings.addMovie("Don", 2006, {"Action", "Comedy"});
    ratings.addMovie("Tiger", 2008, {"Drama"});
    ratings.addMovie("Tiger1", 2008, {"Drama"});
    ratings.addMovie("Tiger2", 2021, {"Comedy"});
    
    ratings.addReview("Prem", "Don", 9);
    ratings.addReview("Prem", "Tiger", 5);
    ratings.addReview("Prem", "Tiger1", 4);
    ratings.addReview("Prem", "Tiger2", 6);
    
    
    ratings.addReview("Ashwini", "Tiger2", 7);
    ratings.addReview("Ashwini", "Don", 5);
    
    cout<<"top 10 \n";
    ratings.getTopByReviewScore(10);
    cout<<"Top 10 comedy \n";
    ratings.getTopByReviewScore(10,"Comedy");
    
    cout<<"Top 10 critic \n";
    ratings.getTopByCriticScore(10);
}
