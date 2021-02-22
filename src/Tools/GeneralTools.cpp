//
// Created by Erick on 2/21/2021.
//
#include <string>
#include "../Elements/Entities/Entity.h"

using namespace std;
string toLower(string input){
    string temp;
    for(int i = 0; i<input.length(); i++){
        temp += tolower(input[i]);
    }
    return temp;
}

string toUpper(string input){
    string temp;
    for(int i = 0; i<input.length(); i++){
        temp += toupper(input[i]);
    }
    return temp;
}

bool contains(string input, string keyword){
    if(keyword.length()>input.length()){
        return false;
    }
    if(input==keyword){
        return true;
    }
    for(int i = 0; (i+keyword.length())<input.length(); i++){
        if(input.substr(i,keyword.length())==keyword){
            return true;
        }
    }
    return false;

}

void vecRemove(Entity *ent, vector<Entity*> vector){
    for(int i = 0; i<vector.size(); i++){
        if(vector[i]==ent){
            delete ent;
            vector.erase(vector.begin()+i);
        }
    }
}

void vecRemove(Tile *tile, vector<Tile*> vector){
    for(int i = 0; i<vector.size(); i++){
        if(vector[i] == tile){
            delete tile;
            vector.erase(vector.begin()+i);
        }
    }
}