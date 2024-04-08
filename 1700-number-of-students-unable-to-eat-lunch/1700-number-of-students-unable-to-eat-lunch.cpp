class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        
        int count_0=0;
        int count_1 = 0;
        
        for(int i=0;i<students.size();i++){
            if(students[i]==0) count_0++;
            else count_1++;
        }
        
        stack<int> sand;
        queue<int> stud;
        for(int i=0;i<students.size();i++) stud.push(students[i]);
        
        for(int i=sandwiches.size()-1;i>=0;i--) sand.push(sandwiches[i]);
        

        
        while(stud.size()!=0){
            if(stud.front()==sand.top()){
                sand.pop();
                
                if(stud.front()==1) count_1--;
                if(stud.front()==0) count_0--;
                stud.pop();
                
            }
            else{
                if(sand.top() == 0 && count_0>0){
                    int x= stud.front();
                    stud.pop();
                    stud.push(x);
                }
                else if(sand.top() ==0 && count_0<=0) return stud.size();
                else if(sand.top() ==1 && count_1<=0) return stud.size();
                else if(sand.top() ==1 && count_1>0){
                    int x= stud.front();
                    stud.pop();
                    stud.push(x);
                }
                
                
            }
        }
        
        
        return stud.size();
    }
};