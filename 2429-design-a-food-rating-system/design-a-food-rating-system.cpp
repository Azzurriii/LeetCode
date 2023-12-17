class FoodRatings{
    unordered_map<string,string>cuisineMap; //food cusine
    unordered_map<string,set<pair<int,string>>>foodMap; // cusine , rating
    unordered_map<string,int>rating; // food rating
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            cuisineMap[foods[i]]=cuisines[i];
            foodMap[cuisines[i]].insert({-ratings[i],foods[i]});
            rating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cusine=cuisineMap[food];
        auto rate=rating[food];
        foodMap[cusine].erase({-rate,food});
        foodMap[cusine].insert({-newRating,food});
        rating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return foodMap[cuisine].begin()->second;
    }

};