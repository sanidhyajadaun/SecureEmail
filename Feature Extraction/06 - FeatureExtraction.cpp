#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
#include<vector>
#include<fstream>
#include "01 - Preprocessing.cpp"
#pragma once
class FeatureExtraction
{
    public :
        //declaration
        void bagOfWords(std::vector<std::vector<std::string>> processedData);
};

void FeatureExtraction::bagOfWords(std::vector<std::vector<std::string>> processedData)
{
    /*
    Basic steps to perform bag of words
    1. read the unique words (set)

    2. vector<vector<string>> 
    =>  [["hi","hello"],
         ["you","there","hello"]]

    map[word[i][j]]++;
    

    hi -> 1
    helllo -> 1

    index    hi      hello       you     there
    0         1       1           0       0
    1         0       1           1       1
    */

    //1. Reading the unique words from the unique words.text
    std::vector<std::string> uniquewords;
    std::unordered_map<std::string,int> m;

    std::ifstream in;
    in.open("05 - unique words.txt");
    std::ofstream out;
    out.open("08 - BagOfWords.csv");

    std::string str;
    int z=0;
    while(in>>str)
    {
        std::cout<<"Reading...."<<z+1<<" "<<str<<std::endl;
        z++;
        uniquewords.push_back(str);
    }
    //should be 21768 unique words 
    std::cout<<"Unique words : "<<uniquewords.size()<<std::endl;

    //2. writing the columns in the output BagOfWords.csv file
    for(int i=0;i<uniquewords.size();i++)
    {
        out<<uniquewords[i]<<",";
    }
    out<<std::endl;

    // std::cout<<processedData.size()<<std::endl;
    // std::cout<<processedData[0].size()<<std::endl;

    //3. creating the bag of words file
    for(int i=0;i<processedData.size();i++)
    {
        for(int j=0;j<processedData[i].size();j++)
        {
            m[processedData[i][j]]++;
            // std::cout<<m[processedData[i][j]]<<std::endl;
        }
        // 1    2     3

        for(int k = 0;k<uniquewords.size();k++)
        {
            if(m.find(uniquewords[k]) == m.end())
            {
                out<<0<<",";
            }
            else
            {
                // std::cout<<"hello"<<std::endl;
                out<<m[uniquewords[k]]<<",";
            }
        }
        if(i!=processedData.size()-1)
        out<<std::endl;
        m.clear();

        std::cout<<i+1<<std::endl;
    }

    //1 unique words (file) -> vector 
    //ek order rhenge
    //bag of words mein column same rhega har run pe
    //2 bagofwords.csv -> column (unique words)

    //
}