#include <iostream>
#include <string>

    std::string subSeqFinder(std::string str1, std::string str2){

        std::string s1;
        std::string s2;

        //Shorter string is s1
        if(str1.length() > str2.length()){
            s1 = str2;
            s2 = str1;
        }else{
            s1 = str1;
            s2 = str2;
        }
        
        std::string commonLetters[s1.length()];

        for(int k=0; k < s1.length(); k++){
            int currentIndexOfJ = 0;

            for(int i=k;i < s1.length(); i++){

                for(int j=currentIndexOfJ; j < s2.length(); j++){
                    if(s1[i] == s2[j]){
                        commonLetters[k] += s1[i];
                        i++;
                        currentIndexOfJ = j+1;
                    }

                }

            }

        }

        int result = 0;
        for(int i=0; i<s1.length(); i++){
            if(commonLetters[i].length() > commonLetters[result].length()){
                result = i;
            }
        }
        std::cout << commonLetters[result] << std::endl;      
        
        return commonLetters[result];
    }

    int main (){

        std::string s1 = "ABAZDC";
        std::string s2 = "BACBAD";
        // Result of S1 vs S2 => "ABAD"

        s1= "AGGTAB";
        s2= "GXTXAYB";
        // Result of S1 vs S2 => "GTAB"

        subSeqFinder(s1, s2);

        return 0;
    }